// SPDX-License-Identifier: Apache-2.0
// Copyright © 2026 The Fin Authors. All rights reserved.
// Contributors responsible for this file:
// @p7r0x7 <maxibonnette@pm.me>

#include "clang/Basic/Stack.h"
#include "clang/Driver/Compilation.h"
#include "clang/Driver/Driver.h"
#include "clang/Frontend/ChainedDiagnosticConsumer.h"
#include "clang/Frontend/SerializedDiagnosticPrinter.h"
#include "clang/Frontend/TextDiagnosticPrinter.h"
#include "llvm/Support/CommandLine.h"
#include "llvm/Support/Process.h"
#include "llvm/Support/VirtualFileSystem.h"
#include "llvm/TargetParser/Host.h"

using namespace clang;
using namespace clang::driver;

extern int cc1_main(llvm::ArrayRef<const char*> Argv, const char* Argv0, void* MainAddr);
extern int cc1as_main(llvm::ArrayRef<const char*> Argv, const char* Argv0, void* MainAddr);

static void getCLEnvVarOptions(llvm::StringRef EnvValue, llvm::StringSaver& Saver, SmallVectorImpl<const char*>& Opts) {
    llvm::cl::TokenizeWindowsCommandLine(EnvValue, Saver, Opts);
    for (const char* Opt: Opts)
        if (char* NumberSignPtr = const_cast<char*>(::strchr(Opt, '#'))) *NumberSignPtr = '=';
}

extern "C" int fin_clang_main(char* Prefix, int Argc, char** Argv) {
    noteBottomOfStack();
    auto VFS = llvm::vfs::getRealFileSystem();
    void* MainAddr = (void*)(intptr_t)fin_clang_main;

    //    Diagnostics
    auto DiagOpts = std::make_shared<DiagnosticOptions>();
    DiagOpts->ShowColors = llvm::errs().has_colors();
    DiagOpts->DiagnosticSuppressionMappingsFile.clear();
    auto DiagClient = std::make_unique<TextDiagnosticPrinter>(llvm::errs(), *DiagOpts);
    DiagClient->setPrefix(Prefix);
    DiagnosticsEngine Diags(DiagnosticIDs::create(), *DiagOpts, DiagClient.release());
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

    //    Fill DriverArgs, handling special -ld-path parsing.
    llvm::StringRef LDExe;
    llvm::SmallVector<const char*, 16> LDPrefixArgs;
    for (int i = 0; i < Argc; ++i) {
        if (llvm::StringRef(Argv[i]) == "-ld-path" && i + 1 < Argc) {
            llvm::SmallVector<const char*, 16> Tokens;
            std::string Val(Argv[++i]);
#ifdef _WIN32
            llvm::cl::TokenizeWindowsCommandLine(Val, Saver, Tokens);
#else
            llvm::cl::TokenizeGNUCommandLine(Val, Saver, Tokens);
#endif
            if (Tokens.empty()) {
                llvm::errs() << "-ld-path requires an executable\n";
                return 1;
            }
            LDExe = Tokens.front();
            LDPrefixArgs.append(Tokens.begin() + 1, Tokens.end());
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
        if (auto OptCL = llvm::sys::Process::GetEnv("CL")) {
            SmallVector<const char*, 8> PrependedOpts;
            getCLEnvVarOptions(*OptCL, Saver, PrependedOpts);
            DriverArgs.insert(DriverArgs.begin() + 1, PrependedOpts.begin(), PrependedOpts.end());
        }
        if (auto Opt_CL_ = llvm::sys::Process::GetEnv("_CL_")) {
            SmallVector<const char*, 8> AppendedOpts;
            getCLEnvVarOptions(*Opt_CL_, Saver, AppendedOpts);
            DriverArgs.append(AppendedOpts.begin(), AppendedOpts.end());
        }
    }

    //    Get resources, possibly macOS sysroot, and build pipeline
    std::string ExePath = llvm::sys::fs::getMainExecutable(DriverArgs[0], MainAddr);
    Driver TheDriver(ExePath, llvm::sys::getDefaultTargetTriple(), Diags, Prefix, VFS);
    const llvm::Triple Triple(TheDriver.getTargetTriple());
    TheDriver.Name = Prefix;
    if (Triple.isOSDarwin() && TheDriver.SysRoot.empty()) {
        if (FILE* F = ::popen("/usr/bin/xcrun --show-sdk-path 2>/dev/null", "r")) {
            char Buf[256];
            if (::fgets(Buf, sizeof(Buf), F)) TheDriver.SysRoot = llvm::StringRef(Buf).rtrim().str();
            ::pclose(F);
        }
    }
    std::unique_ptr<Compilation> Compile(TheDriver.BuildCompilation(DriverArgs));
    if (!Compile || Compile->containsError()) return 1;

    //    Fix ld jobs according to -ld-path, setting default
    if (LDExe.empty()) {
        LDExe = Saver.save(ExePath);
        llvm::StringRef Format = "elf";
        switch (Triple.getObjectFormat()) {
        case llvm::Triple::COFF: Format = "coff"; break;
        case llvm::Triple::MachO: Format = "macho"; break;
        case llvm::Triple::Wasm: Format = "wasm"; break;
        default: break;
        }
        LDPrefixArgs.push_back("ld");
        LDPrefixArgs.push_back(Saver.save(Format).data());
    }
    for (auto& Job: Compile->getJobs()) {
        if (auto* Cmd = llvm::dyn_cast<Command>(&Job)) {
            if (llvm::isa<LinkJobAction>(Cmd->getSource())) {
                Cmd->replaceExecutable(LDExe.data());
                if (!LDPrefixArgs.empty()) {
                    llvm::opt::ArgStringList NewArgs;
                    NewArgs.append(LDPrefixArgs.begin(), LDPrefixArgs.end());
                    NewArgs.append(Cmd->getArguments().begin(), Cmd->getArguments().end());
                    Cmd->replaceArguments(std::move(NewArgs));
                }
            }
        }
    }

    //    Execute cc jobs in-process
    int Ret = 0;
    const bool Verbose = llvm::is_contained(DriverArgs, llvm::StringRef("-v"));
    for (auto& Job: Compile->getJobs()) {
        auto* Cmd = llvm::dyn_cast<Command>(&Job);
        if (!Cmd) continue;

        llvm::StringRef Tool = Cmd->getArguments().empty() ? "" : Cmd->getArguments()[0];
        if (Tool == "-cc1" || Tool == "-cc1as") {
            llvm::SmallVector<const char*, 64> CC1Args;
            CC1Args.push_back(Cmd->getExecutable());
            CC1Args.append(Cmd->getArguments().begin(), Cmd->getArguments().end());
            if (Verbose) {
                llvm::errs() << " (in-process)";
                for (const char* Arg: CC1Args) llvm::errs() << ' ' << Arg;
                llvm::errs() << '\n';
            }
            if (Tool == "-cc1") {
                Ret = cc1_main(llvm::ArrayRef(CC1Args).slice(2), CC1Args[0], MainAddr);
            } else {
                Ret = cc1as_main(llvm::ArrayRef(CC1Args).slice(2), CC1Args[0], MainAddr);
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
    static constexpr lld::DriverDef Linkers[] = {
        {lld::WinLink,  &lld::coff::link},
        {    lld::Gnu,   &lld::elf::link},
        { lld::Darwin, &lld::macho::link},
        {   lld::Wasm,  &lld::wasm::link},
    };
    return lld::lldMain(DriverArgs, llvm::outs(), llvm::errs(), Linkers).retCode;
}
