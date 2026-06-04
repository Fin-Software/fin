#include "llvm/Support/LLVMDriver.h"
#include <string>

int clang_main(int Argc, char** Argv, const llvm::ToolContext& ToolContext);
int lld_main(int Argc, char** Argv, const llvm::ToolContext& ToolContext);
std::string GetExecutablePath(const char* Argv0, bool CanonicalPrefixes);

extern "C" {

int fin_clang_main(const char* real_exe, int argc, char** argv) {
    std::string path = GetExecutablePath(real_exe, true);
    llvm::ToolContext tc{path.c_str(), nullptr, false};
    return clang_main(argc, argv, tc);
}

int fin_lld_main(const char* real_exe, int argc, char** argv) {
    std::string path = GetExecutablePath(real_exe, true);
    llvm::ToolContext tc{path.c_str(), nullptr, false};
    return lld_main(argc, argv, tc);
}

} // extern "C"
