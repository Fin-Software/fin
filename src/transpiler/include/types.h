// SPDX-License-Identifier: Apache-2.0
// Copyright © 2025 The Fin Authors. All rights reserved.
// Contributors responsible for this file:
// @p7r0x7 <mattrbonnette@pm.me>

#pragma once

#define INTS(x) typedef unsigned _BitInt(x) fin_u##x; typedef _BitInt(x) fin_i##x;

INTS(8) INTS(16) INTS(32) INTS(64) INTS(128)

typedef __fp16 fin_f16; typedef __bf16 fin_bf16; typedef float fin_f32; typedef double fin_f64;

#if __SIZEOF_POINTER__ == 8
    typedef fin_u64 fin_uptr; typedef fin_i64 fin_iptr;
#elif __SIZEOF_POINTER__ == 4
    typedef fin_u32 fin_uptr; typedef fin_i32 fin_iptr;
#else
    #error "Fin only supports 64- and 32-bit pointer sizes."
#endif
