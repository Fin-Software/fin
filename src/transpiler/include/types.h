// SPDX-License-Identifier: Apache-2.0
// Copyright © 2025 The Fin Authors. All rights reserved.
// Contributors responsible for this file:
// @p7r0x7 <mattrbonnette@pm.me>

#pragma once

#define INTS(x) typedef unsigned _BitInt(x) u##x; typedef _BitInt(x) i##x;

INTS(8) INTS(16) INTS(32) INTS(64) INTS(128)

typedef __fp16 f16; typedef __bf16 bf16; typedef float f32; typedef double f64;

#if __SIZEOF_POINTER__ == 8
    typedef u64 uptr; typedef i64 iptr;
#elif __SIZEOF_POINTER__ == 4 || __SIZEOF_POINTER__ == 2
    typedef u32 uptr; typedef i32 iptr;
#else
    #error "Fin only supports 64-, 32-, and 16-bit nominal pointer sizes."
#endif
