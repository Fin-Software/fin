// SPDX-License-Identifier: Apache-2.0
// Copyright © 2025 The Fin Authors. All rights reserved.
// Contributors responsible for this file:
// @p7r0x7 <mattrbonnette@pm.me>

#pragma once

#include "types.h"
#include <stdckdint.h>

#define FRAGILE_OPS(T) /* Checks against undefined math */ \
    [[gnu::always_inline]] T T##_div(T a, T b) {           \
        if (b == 0) panic();                               \
        return a / b;                                      \
    }                                                      \
    [[gnu::always_inline]] T T##_mod(T a, T b) {           \
        if (b == 0) panic();                               \
        return a % b;                                      \
    }

#ifdef SAFETY
    #define FALLIBLE_OPS(T) /* Checks against incorrect but well-defined math */ \
        [[gnu::always_inline]] T T##_add(T a, T b) {                             \
            T r;                                                                 \
            if (__builtin_add_overflow(a, b, &r)) panic();                       \
            return r;                                                            \
        }                                                                        \
        [[gnu::always_inline]] T T##_sub(T a, T b) {                             \
            T r;                                                                 \
            if (__builtin_sub_overflow(a, b, &r)) panic();                       \
            return r;                                                            \
        }                                                                        \
        [[gnu::always_inline]] T T##_mul(T a, T b) {                             \
            T r;                                                                 \
            if (__builtin_mul_overflow(a, b, &r)) panic();                       \
            return r;                                                            \
        }                                                                        \
        FRAGILE_OPS(T)
#else
    #define FALLIBLE_OPS(T) /* Unchecked modular integer math */     \
        [[gnu::always_inline]] T T##_add(T a, T b) { return a + b; } \
        [[gnu::always_inline]] T T##_sub(T a, T b) { return a - b; } \
        [[gnu::always_inline]] T T##_mul(T a, T b) { return a * b; } \
        FRAGILE_OPS(T)
#endif

FALLIBLE_OPS(uptr) FALLIBLE_OPS(u8) FALLIBLE_OPS(u16) FALLIBLE_OPS(u32) FALLIBLE_OPS(u64) FALLIBLE_OPS(u128)
FALLIBLE_OPS(iptr) FALLIBLE_OPS(i8) FALLIBLE_OPS(i16) FALLIBLE_OPS(i32) FALLIBLE_OPS(i64) FALLIBLE_OPS(i128)