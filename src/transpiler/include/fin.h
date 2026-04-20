// SPDX-License-Identifier: Apache-2.0
// Copyright © 2025 The Fin Authors. All rights reserved.
// Contributors responsible for this file:
// @p7r0x7 <maxibonnette@pm.me>

#pragma GCC diagnostic error "-Wuninitialized"
#pragma GCC diagnostic error "-Wstrict-aliasing"
#pragma GCC diagnostic error "-Wint-to-pointer-cast"

#if __CHAR_BIT__ != 8
    #error "Fin only supports octal bytes."
#endif
#if !__clang__
    #warning "fin's C artifacts are optimally compiled with LLVM Clang."
#endif
#if !defined(__GNUC__) || __STDC_VERSION__ < 202000L
    #error "fin's C artifacts strictly require GNU C23, lest UB."
#endif

#include "builtins.h"
#include "types.h"
#include "ops.h"

#undef X64
#undef X86
#undef ARM64
#undef RISCV64
#undef WASM64
#undef WASM
#undef LOONG64
