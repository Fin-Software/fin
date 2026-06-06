#include "clang/Driver/Compilation.h"
#include "clang/Driver/Driver.h"
#include "clang/Frontend/TextDiagnosticPrinter.h"
#include "clang/Basic/DiagnosticOptions.h"
#include "llvm/Support/Allocator.h"
#include "llvm/Support/CrashRecoveryContext.h"
#include "llvm/Support/StringSaver.h"
#include "llvm/Support/TargetSelect.h"
#include "llvm/Support/VirtualFileSystem.h"
#include "llvm/TargetParser/Host.h"

using namespace clang;
using namespace clang::driver;

extern int cc1_main(llvm::ArrayRef<const char*> Argv, const char* Argv0, void* MainAddr);
extern int cc1as_main(llvm::ArrayRef<const char*> Argv, const char* Argv0, void* MainAddr);

extern "C" int fin_clang_main(char* prefix, int argc, char** argv) {
    llvm::InitializeAllTargets();
    llvm::InitializeAllTargetMCs();
    llvm::InitializeAllAsmParsers();
    llvm::InitializeAllAsmPrinters();
    auto VFS = llvm::vfs::getRealFileSystem();

    DiagnosticOptions DiagOpts;
    DiagOpts.ShowColors = llvm::errs().has_colors();
    auto* DiagClient = new TextDiagnosticPrinter(llvm::errs(), DiagOpts);
    DiagClient->setPrefix(prefix);
    DiagnosticsEngine Diags(DiagnosticIDs::create(), DiagOpts, DiagClient);

    std::string ExePath = llvm::sys::fs::getMainExecutable(argv[0], (void*)(intptr_t)fin_clang_main);
    Driver TheDriver(ExePath, llvm::sys::getDefaultTargetTriple(), Diags, prefix, VFS);
    TheDriver.Name = prefix;

    auto CC1MainFn = [](llvm::SmallVectorImpl<const char*>& ArgV) -> int {
        void* MainAddr = (void*)(intptr_t)fin_clang_main;
        llvm::StringRef Tool = ArgV[1];
        if (Tool == "-cc1") return cc1_main(llvm::ArrayRef(ArgV).slice(1), ArgV[0], MainAddr);
        if (Tool == "-cc1as") return cc1as_main(llvm::ArrayRef(ArgV).slice(2), ArgV[0], MainAddr);
        llvm::errs() << "fin: unknown cc1 tool: " << Tool << "\n";
        return 1;
    };
    TheDriver.CC1Main = CC1MainFn;
    llvm::CrashRecoveryContext::Enable();

    // 1. Initialize the allocator and saver
    llvm::BumpPtrAllocator Alloc;
    llvm::StringSaver Saver(Alloc);

    llvm::SmallVector<const char*, 64> Args;

    // 2. We can just use StringRefs now because the Saver owns the memory
    llvm::StringRef LDExe;
    llvm::StringRef LDSubcmd;

    for (int i = 0; i < argc; ++i) {
        if (llvm::StringRef(argv[i]) == "-ld-path" && i + 1 < argc) {
            llvm::StringRef Val(argv[++i]);
            auto Space = Val.find(' ');
            if (Space == llvm::StringRef::npos) {
                // Saver.save() duplicates the string and ensures null-termination
                LDExe = Saver.save(Val);
            } else {
                LDExe = Saver.save(Val.slice(0, Space));
                LDSubcmd = Saver.save(Val.substr(Space + 1));
            }
        } else {
            Args.push_back(argv[i]);
        }
    }

    std::unique_ptr<Compilation> C(TheDriver.BuildCompilation(Args));
    if (!C || C->containsError()) return 1;

    // If the user didn't specify an -ld-path, set a default based on the target
    if (LDExe.empty()) {
        // ExePath is the absolute path to this compiler binary
        LDExe = Saver.save(ExePath);

        // Grab the fully resolved target triple from the compilation
        const llvm::Triple& T = C->getDefaultToolChain().getTriple();
        llvm::StringRef Format = "elf"; // default fallback

        switch (T.getObjectFormat()) {
        case llvm::Triple::COFF: Format = "coff"; break;
        case llvm::Triple::MachO: Format = "macho"; break;
        case llvm::Triple::Wasm: Format = "wasm"; break;
        case llvm::Triple::ELF:
        default: Format = "elf"; break;
        }

        // Construct "ld <format>" and save it so the memory lives long enough
        LDSubcmd = Saver.save((llvm::Twine("ld ") + Format).str());
    }

    if (!LDExe.empty()) {
        for (auto& Job: C->getJobs()) {
            if (auto* Cmd = llvm::dyn_cast<Command>(&Job)) {
                if (llvm::isa<LinkJobAction>(Cmd->getSource())) {

                    // 3. .data() is safe here because StringSaver guarantees null-termination
                    Cmd->replaceExecutable(LDExe.data());

                    if (!LDSubcmd.empty()) {
                        llvm::opt::ArgStringList NewArgs;

                        // Split the subcommand by spaces so "ld elf" becomes two arguments
                        llvm::SmallVector<llvm::StringRef, 2> SubCmds;
                        LDSubcmd.split(SubCmds, ' ', -1, false);
                        for (auto Cmd: SubCmds) {
                            // Safe because Saver.save() was used earlier,
                            // but we need to ensure each split part is null-terminated
                            // for execve. If splitting, it's safer to save the split strings.
                            NewArgs.push_back(Saver.save(Cmd).data());
                        }

                        for (const char* A: Cmd->getArguments()) { NewArgs.push_back(A); }
                        Cmd->replaceArguments(std::move(NewArgs));
                    }
                }
            }
        }
    }

    int Ret = 0;
    void* MainAddr = (void*)(intptr_t)fin_clang_main;

    for (auto& Job: C->getJobs()) {
        auto* Cmd = llvm::dyn_cast<Command>(&Job);
        if (!Cmd) continue;

        bool isCC1 = !Cmd->getArguments().empty()
                     && (llvm::StringRef(Cmd->getArguments()[0]) == "-cc1"
                         || llvm::StringRef(Cmd->getArguments()[0]) == "-cc1as");
        if (isCC1) {
            llvm::SmallVector<const char*, 64> CC1Args;
            CC1Args.push_back(Cmd->getExecutable());
            for (const char* A: Cmd->getArguments()) CC1Args.push_back(A);
            llvm::StringRef Tool = CC1Args[1];
            if (Tool == "-cc1")
                Ret = cc1_main(llvm::ArrayRef(CC1Args).slice(2), CC1Args[0], MainAddr);
            else if (Tool == "-cc1as")
                Ret = cc1as_main(llvm::ArrayRef(CC1Args).slice(2), CC1Args[0], MainAddr);
            else {
                llvm::errs() << "fin: unknown cc1 tool: " << Tool << "\n";
                Ret = 1;
            }
        } else {
            const Command* FailingCmd = nullptr;
            Ret = C->ExecuteCommand(*Cmd, FailingCmd);
        }
        if (Ret) break;
    }

    return Ret;
}

#include "lld/Common/Driver.h"

LLD_HAS_DRIVER(coff)
LLD_HAS_DRIVER(elf)
LLD_HAS_DRIVER(macho)
LLD_HAS_DRIVER(wasm)

extern "C" int fin_lld_main(char* prefix, int argc, char** argv) {
    llvm::SmallVector<const char*, 256> Args(argv, argv + argc);
    Args[0] = prefix;
    llvm::ArrayRef<const char*> ArgsRef(Args.data(), Args.size());
    lld::Result R = lld::lldMain(ArgsRef, llvm::outs(), llvm::errs(), {
        {lld::WinLink, &lld::coff::link},
        {lld::Gnu, &lld::elf::link},
        {lld::Darwin, &lld::macho::link},
        {lld::Wasm, &lld::wasm::link},
    });
    return R.retCode;
}
