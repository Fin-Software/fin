#include "clang/Driver/Driver.h"

// Forward declare clang_main so we can call it
int clang_main(int argc, char **argv);

extern "C" int clang_main_c(int argc, char **argv) {
    return clang_main(argc, argv);
}
