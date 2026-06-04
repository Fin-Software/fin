#include "clang/Driver/Driver.h"
#include "clang/Driver/Compilation.h"
#include "clang/Driver/Job.h" // Required to inspect and mutate scheduled jobs
#include "clang/Frontend/TextDiagnosticPrinter.h"
#include "clang/Basic/DiagnosticOptions.h"
#include "clang/Basic/DiagnosticIDs.h"
#include "llvm/Support/TargetSelect.h"
#include "llvm/Support/CommandLine.h"
#include "llvm/Support/CrashRecoveryContext.h"
#include "llvm/Support/VirtualFileSystem.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/TargetParser/Host.h"

using namespace clang;

extern int cc1_main(llvm::ArrayRef<const char*> Argv, const char* Argv0, void* MainAddr);
extern int cc1as_main(llvm::ArrayRef<const char*> Argv, const char* Argv0, void* MainAddr);

std::string GetExecutablePath(const char* Argv0, bool CanonicalPrefixes);

static int ExecuteCC1InProcess(SmallVectorImpl<const char*>& ArgV) {
    llvm::cl::ResetAllOptionOccurrences();

    llvm::BumpPtrAllocator A;
    llvm::cl::ExpansionContext ECtx(A, llvm::cl::TokenizeGNUCommandLine, llvm::vfs::getRealFileSystem().get());
    if (llvm::Error Err = ECtx.expandResponseFiles(ArgV)) {
        llvm::errs() << toString(std::move(Err)) << '\n';
        return 1;
    }

    llvm::StringRef Tool = ArgV[1];
    void* GetExecutablePathVP = (void*)(intptr_t)GetExecutablePath;

    if (Tool == "-cc1") return cc1_main(llvm::ArrayRef(ArgV).slice(1), ArgV[0], GetExecutablePathVP);
    if (Tool == "-cc1as") return cc1as_main(llvm::ArrayRef(ArgV).slice(2), ArgV[0], GetExecutablePathVP);

    return 1;
}

extern "C" {

int fin_clang_main(const char* real_exe, int argc, char** argv) {
    // 1. Target Initialization
    llvm::InitializeAllTargets();

    // 2. Subprocess Interception
    // Look for "-cc1" or "-cc1as" in the early arguments (e.g., "fin cc -cc1 ...")
    int cc1_idx = -1;
    for (int i = 1; i < argc && i < 3; ++i) {
        if (llvm::StringRef(argv[i]) == "-cc1" || llvm::StringRef(argv[i]) == "-cc1as") {
            cc1_idx = i;
            break;
        }
    }

    // If caught, normalize the argument layout for the in-process runner
    if (cc1_idx != -1) {
        SmallVector<const char*, 256> WorkerArgs;
        WorkerArgs.push_back(argv[0]); // fin binary path
        for (int i = cc1_idx; i < argc; ++i) { WorkerArgs.push_back(argv[i]); }
        return ExecuteCC1InProcess(WorkerArgs);
    }

    // 3. Parse and Expand Response Files (@files)
    SmallVector<const char*, 256> Args(argv, argv + argc);
    llvm::BumpPtrAllocator A;
    auto VFS = llvm::vfs::getRealFileSystem();

    if (llvm::Error Err = clang::driver::expandResponseFiles(Args, /*ClangCLMode=*/false, A, VFS.get())) {
        llvm::errs() << toString(std::move(Err)) << '\n';
        return 1;
    }

    // 4. Set diagnostic prefix
    auto DiagOpts = std::make_unique<DiagnosticOptions>();
    DiagOpts->ShowColors = llvm::errs().has_colors();
    auto* DiagClient = new TextDiagnosticPrinter(llvm::errs(), *DiagOpts);
    if (argc > 0 && argv[0] != nullptr) {
        DiagClient->setPrefix(argv[0]);
    } else {
        DiagClient->setPrefix("fin");
    }
    DiagnosticsEngine Diags(DiagnosticIDs::create(), *DiagOpts, DiagClient);

    // 5. Initialize Driver
    std::string Path = GetExecutablePath(real_exe, true);
    driver::Driver TheDriver(Path, llvm::sys::getDefaultTargetTriple(), Diags, "fin clang compiler", VFS);

    // 6. Setup In-Process Engine Fallbacks
    TheDriver.CC1Main = ExecuteCC1InProcess;
    llvm::CrashRecoveryContext::Enable();

    // 7. Build Compilation Pipeline
    std::unique_ptr<driver::Compilation> C(TheDriver.BuildCompilation(Args));
    if (!C || C->containsError()) { return 1; }

    // 8. Rewrite Worker Pipeline Arguments
    // Sneak our public "cc" subcommand into the front of any generated worker processes
    // so that it routes cleanly back through your outer CLI router if a fork happens.
    for (auto& Job: C->getJobs()) {
        const llvm::opt::ArgStringList& JobArgs = Job.getArguments();
        if (!JobArgs.empty() && (llvm::StringRef(JobArgs[0]) == "-cc1" || llvm::StringRef(JobArgs[0]) == "-cc1as")) {
            llvm::opt::ArgStringList NewArgs;
            NewArgs.push_back("cc"); // Inject the safe subcommand
            for (const char* Arg: JobArgs) { NewArgs.push_back(Arg); }
            Job.replaceArguments(NewArgs);
        }
    }

    // 9. Execute Compilation Pipeline
    SmallVector<std::pair<int, const driver::Command*>, 4> FailingCommands;
    int Res = TheDriver.ExecuteCompilation(*C, FailingCommands);

    Diags.getClient()->finish();
    return Res;
}

} // extern "C"

#include "llvm/Support/LLVMDriver.h"
#include <string>

int lld_main(int Argc, char** Argv, const llvm::ToolContext& ToolContext);

extern "C" {

int fin_lld_main(const char* real_exe, int argc, char** argv) {
    std::string path = GetExecutablePath(real_exe, true);
    llvm::ToolContext tc{path.c_str(), nullptr, false};
    return lld_main(argc, argv, tc);
}

} // extern "C"
