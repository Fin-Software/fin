// SPDX-License-Identifier: Apache-2.0
// Copyright © 2025 The Fin Authors. All rights reserved.
// Contributors responsible for this file:
// @p7r0x7 <maxibonnette@pm.me>

#pragma once

#include "types.h"

extern fin_u8 fin_main(void);

[[noreturn]] extern void fin_panic(struct { fin_u8 *ptr; fin_u32 len; });

#define WINDOWS()      defined(_WIN32)
#define LINUX()        defined(__linux__)
#define DARWIN()       defined(__APPLE__)
#define FREEBSD()      defined(__FreeBSD__)
#define ANDROID()      defined(__ANDROID__)
#define FREESTANDING() !__STDC_HOSTED__

#define X64()     defined(__x86_64__)
#define WASM64()  defined(__wasm64__)
#define ARM64()   defined(__aarch64__)
#define WASM()    (!WASM64() && defined(__wasm__))
#define RISCV64() (defined(__riscv__) && __riscv_xlen == 64)
#define LOONG64() (defined(__loongarch__) && __loongarch_grlen == 64)

[[noreturn]] void fin_start(void) {
#if WASM64() || WASM()
#elif X64()
    #if WINDOWS()

    #elif LINUX()

    #elif FREEBSD()

    #elif FREESTANDING()

    #else
        #error "fin doesn't support this target host OS for x64."
    #endif
#elif ARM64()
    #if WINDOWS()

    #elif LINUX() || ANDROID()

    #elif DARWIN()

    #elif FREEBSD()

    #elif FREESTANDING()

    #else
        #error "fin doesn't support this target host OS for arm64."
    #endif
#elif RISCV64()
    #if LINUX()

    #elif FREEBSD()

    #elif FREESTANDING()

    #else
        #error "fin doesn't support this target host OS for riscv64."
    #endif
#elif LOONG64()
    #if LINUX()

    #elif FREESTANDING()

    #else
        #error "fin doesn't support this target host OS for loong64."
    #endif
#else
    #error "fin doesn't support this target architecture."
#endif

#if FREESTANDING()
    while (true) {}
#else
    __builtin_unreachable();
#endif
}
