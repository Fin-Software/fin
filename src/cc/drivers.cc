#include "clang/Basic/DiagnosticOptions.h"
#include "clang/Basic/Stack.h"
#include "clang/Driver/Compilation.h"
#include "clang/Driver/Driver.h"
#include "clang/Frontend/ChainedDiagnosticConsumer.h"
#include "clang/Frontend/SerializedDiagnosticPrinter.h"
#include "clang/Frontend/TextDiagnosticPrinter.h"
#include "llvm/Option/ArgList.h"
#include "llvm/Support/Allocator.h"
#include "llvm/Support/CommandLine.h"
#include "llvm/Support/CrashRecoveryContext.h"
#include "llvm/Support/Process.h"
#include "llvm/Support/StringSaver.h"
#include "llvm/Support/VirtualFileSystem.h"
#include "llvm/TargetParser/Host.h"

using namespace clang;
using namespace clang::driver;

extern int cc1_main(llvm::ArrayRef<const char*> Argv, const char* Argv0, void* MainAddr);
extern int cc1as_main(llvm::ArrayRef<const char*> Argv, const char* Argv0, void* MainAddr);

static void getCLEnvVarOptions(std::string& EnvValue, llvm::StringSaver& Saver, SmallVectorImpl<const char*>& Opts) {
    llvm::cl::TokenizeWindowsCommandLine(EnvValue, Saver, Opts);
    for (const char* Opt: Opts)
        if (char* NumberSignPtr = const_cast<char*>(::strchr(Opt, '#'))) *NumberSignPtr = '=';
}

extern "C" int fin_clang_main(char* Prefix, int Argc, char** Argv) {
    noteBottomOfStack();
    auto VFS = llvm::vfs::getRealFileSystem();

    //    Diagnostics
    auto DiagOpts = std::make_shared<DiagnosticOptions>();
    DiagOpts->ShowColors = llvm::errs().has_colors();
    DiagOpts->DiagnosticSuppressionMappingsFile.clear();
    TextDiagnosticPrinter* DiagClient = new TextDiagnosticPrinter(llvm::errs(), *DiagOpts);
    DiagClient->setPrefix(Prefix);
    DiagnosticsEngine Diags(DiagnosticIDs::create(), *DiagOpts, DiagClient);
    if (!DiagOpts->DiagnosticSerializationFile.empty()) {
        auto SerializedConsumer =
            clang::serialized_diags::create(DiagOpts->DiagnosticSerializationFile, *DiagOpts, /*MergeChildRecords=*/true);
        Diags.setClient(new ChainedDiagnosticConsumer(Diags.takeClient(), std::move(SerializedConsumer)));
    }
    ProcessWarningOptions(Diags, *DiagOpts, *VFS, /*ReportDiags=*/false);

    llvm::BumpPtrAllocator Ally;
    llvm::StringSaver Saver(Ally);
    llvm::SmallVector<const char*, 256> DriverArgs;
    DriverArgs.reserve(Argc);

    //   Fill DriverArgs, handling special -ld-path parsing.
    llvm::StringRef LDExe, LDArgs;
    for (int i = 0; i < Argc; ++i) {
        if (llvm::StringRef(Argv[i]) == "-ld-path" && i + 1 < Argc) {
            llvm::StringRef Val(Argv[++i]);
            auto Space = Val.find(' ');
            if (Space == llvm::StringRef::npos) {
                LDExe = Saver.save(Val);
            } else {
                LDExe = Saver.save(Val.slice(0, Space));
                LDArgs = Saver.save(Val.substr(Space + 1));
            }
        } else {
            DriverArgs.push_back(Argv[i]);
        }
    }

    //    Handle Windows Mode
    bool ClangCLMode = false;
    for (const char* Arg: DriverArgs)
        if (llvm::StringRef(Arg).starts_with("--driver-mode=cl")) ClangCLMode = true;
    if (llvm::Error Err = expandResponseFiles(DriverArgs, ClangCLMode, Ally, VFS.get())) {
        llvm::errs() << toString(std::move(Err)) << '\n';
        return 1;
    }
    if (ClangCLMode) {
        std::optional<std::string> OptCL = llvm::sys::Process::GetEnv("CL");
        if (OptCL) {
            SmallVector<const char*, 8> PrependedOpts;
            getCLEnvVarOptions(*OptCL, Saver, PrependedOpts);
            DriverArgs.insert(DriverArgs.begin() + 1, PrependedOpts.begin(), PrependedOpts.end());
        }
        std::optional<std::string> Opt_CL_ = llvm::sys::Process::GetEnv("_CL_");
        if (Opt_CL_) {
            SmallVector<const char*, 8> AppendedOpts;
            getCLEnvVarOptions(*Opt_CL_, Saver, AppendedOpts);
            DriverArgs.append(AppendedOpts.begin(), AppendedOpts.end());
        }
    }

    std::string ExePath = llvm::sys::fs::getMainExecutable(DriverArgs[0], (void*)(intptr_t)fin_clang_main);
    Driver TheDriver(ExePath, llvm::sys::getDefaultTargetTriple(), Diags, Prefix, VFS);
    TheDriver.Name = Prefix;
    std::unique_ptr<Compilation> Compile(TheDriver.BuildCompilation(DriverArgs));
    if (!Compile || Compile->containsError()) return 1;

    //    Fix ld jobs according to -ld-path, setting default
    if (LDExe.empty()) {
        LDExe = Saver.save(ExePath);
        const llvm::Triple& Triple = Compile->getDefaultToolChain().getTriple();
        llvm::StringRef Format = "elf";
        switch (Triple.getObjectFormat()) {
        case llvm::Triple::COFF: Format = "coff"; break;
        case llvm::Triple::MachO: Format = "macho"; break;
        case llvm::Triple::Wasm: Format = "wasm"; break;
        default: break;
        }
        LDArgs = Saver.save((llvm::Twine("ld ") + Format).str());
    }
    for (auto& Job: Compile->getJobs()) {
        if (auto* Cmd = llvm::dyn_cast<Command>(&Job)) {
            if (llvm::isa<LinkJobAction>(Cmd->getSource())) {
                Cmd->replaceExecutable(LDExe.data());
                if (!LDArgs.empty()) {
                    llvm::opt::ArgStringList NewArgs;
                    llvm::SmallVector<llvm::StringRef, 8> Split;
                    LDArgs.split(Split, ' ', -1, false);
                    for (auto Arg: Split) NewArgs.push_back(Saver.save(Arg).data());
                    for (const char* Arg: Cmd->getArguments()) NewArgs.push_back(Arg);
                    Cmd->replaceArguments(std::move(NewArgs));
                }
            }
        }
    }

    //    Execute cc jobs in-process
    int Ret = 0;
    void* MainAddr = (void*)(intptr_t)fin_clang_main;

    for (auto& Job: Compile->getJobs()) {
        auto* Cmd = llvm::dyn_cast<Command>(&Job);
        if (!Cmd) continue;

        bool isCC1 = !Cmd->getArguments().empty()
                     && (llvm::StringRef(Cmd->getArguments()[0]) == "-cc1"
                         || llvm::StringRef(Cmd->getArguments()[0]) == "-cc1as");
        if (isCC1) {
            llvm::SmallVector<const char*, 64> CC1Args;
            CC1Args.push_back(Cmd->getExecutable());
            for (const char* DriverArgs: Cmd->getArguments()) CC1Args.push_back(DriverArgs);
            llvm::StringRef Tool = CC1Args[1];
            if (Tool == "-cc1") {
                if (llvm::is_contained(DriverArgs, llvm::StringRef("-v"))) {
                    llvm::errs() << " (in-process)";
                    for (const char* Arg: CC1Args) llvm::errs() << ' ' << Arg;
                    llvm::errs() << '\n';
                }
                Ret = cc1_main(llvm::ArrayRef(CC1Args).slice(2), CC1Args[0], MainAddr);
            } else if (Tool == "-cc1as") {
                if (llvm::is_contained(DriverArgs, llvm::StringRef("-v"))) {
                    llvm::errs() << " (in-process)";
                    for (const char* Arg: CC1Args) llvm::errs() << ' ' << Arg;
                    llvm::errs() << '\n';
                }
                Ret = cc1as_main(llvm::ArrayRef(CC1Args).slice(2), CC1Args[0], MainAddr);
            } else {
                llvm::errs() << "unknown cc1 tool: " << Tool << "\n";
                Ret = 1;
            }
        } else {
            const Command* FailingCmd = nullptr;
            Ret = Compile->ExecuteCommand(*Cmd, FailingCmd);
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

extern "C" int fin_lld_main(char* Prefix, int Argc, char** Argv) {
    llvm::SmallVector<const char*, 256> DriverArgs(Argv, Argv + Argc);
    DriverArgs[0] = Prefix;
    lld::DriverDef Linkers[] = {
        {lld::WinLink,  &lld::coff::link},
        {    lld::Gnu,   &lld::elf::link},
        { lld::Darwin, &lld::macho::link},
        {   lld::Wasm,  &lld::wasm::link},
    };
    return lld::lldMain(DriverArgs, llvm::outs(), llvm::errs(), Linkers).retCode;
}
