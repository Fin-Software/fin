// SPDX-License-Identifier: Apache-2.0
// Copyright © 2025 The Whixy Authors. All rights reserved.
// Contributors responsible for this file:
// @p7r0x7 <mattrbonnette@pm.me>

#pragma once

#include "types.h"
#include <stdckdint.h>

#define SAFETY    // not real
void panic(void); // not real

// 1-bit integer lines have intended 0 op 0, 0 op 1, 1 op 0, and 1 op 1 results after them.
// These "1-bit" integers must always have bit patterns of either 0b00 or 0b11 to represent valid values.

[[gnu::always_inline]] u1 u1_add(u1 a, u1 b) { if (a & b) panic(); return a | b; }
[[gnu::always_inline]] u1 u1_sub(u1 a, u1 b) { if (a < b) panic(); return a ^ b; }
[[gnu::always_inline]] u1 u1_mul(u1 a, u1 b) { return a & b; }
[[gnu::always_inline]] u1 u1_div(u1 a, u1 b) { if (b == 0) panic(); return a; }
[[gnu::always_inline]] u1 u1_mod(u1 a, u1 b) { if (b == 0) panic(); return 0; }
[[gnu::always_inline]] u1 u1_shl(u1 a, u1 b) { if (b > 0) panic(); return a; }
[[gnu::always_inline]] u1 u1_shr(u1 a, u1 b) { if (b > 0) panic(); return a; }
[[gnu::always_inline]] u1 u1_rotl(u1 a, u1 b) { return a; }
[[gnu::always_inline]] u1 u1_rotr(u1 a, u1 b) { return a; }

[[gnu::always_inline]] i1 i1_add(i1 a, i1 b) { if (a & b) panic(); return a + b; }
[[gnu::always_inline]] i1 i1_sub(i1 a, i1 b) { if (a == 0 && b == -1) panic(); return a - b; }
[[gnu::always_inline]] i1 i1_mul(i1 a, i1 b) { if (a == -1 && b == -1) panic(); return a & b; } // -1 * -1 = 1 (overflow)
[[gnu::always_inline]] i1 i1_div(i1 a, i1 b) { if (b == 0) panic(); return a; }
[[gnu::always_inline]] i1 i1_mod(i1 a, i1 b) { if (b == 0) panic(); return 0; }
[[gnu::always_inline]] i1 i1_shl(i1 a, i1 b) { if (b > 0) panic(); return a; }
[[gnu::always_inline]] i1 i1_shr(i1 a, i1 b) { if (b > 0) panic(); return a; }
[[gnu::always_inline]] i1 i1_rotl(i1 a, i1 b) { return a; }
[[gnu::always_inline]] i1 i1_rotr(i1 a, i1 b) { return a; }

#define FRAGILE_OPS(T) /* Checks against undefined math */                            \
    [[gnu::always_inline]] T T##_div(T a, T b) { if (b == 0) panic(); return a / b; } \
    [[gnu::always_inline]] T T##_mod(T a, T b) { if (b == 0) panic(); return a % b; }

#ifdef SAFETY
    #define FALLIBLE_OPS(T) /* Checks against incorrect but well-defined integer math */                             \
        [[gnu::always_inline]] T T##_add(T a, T b) { T r; if (__builtin_add_overflow(a, b, &r)) panic(); return r; } \
        [[gnu::always_inline]] T T##_sub(T a, T b) { T r; if (__builtin_sub_overflow(a, b, &r)) panic(); return r; } \
        [[gnu::always_inline]] T T##_mul(T a, T b) { T r; if (__builtin_mul_overflow(a, b, &r)) panic(); return r; } \
        FRAGILE_OPS(T)
#else
    #define FALLIBLE_OPS(T) /* Unchecked modular integer math */     \
        [[gnu::always_inline]] T T##_add(T a, T b) { return a + b; } \
        [[gnu::always_inline]] T T##_sub(T a, T b) { return a - b; } \
        [[gnu::always_inline]] T T##_mul(T a, T b) { return a * b; } \
        FRAGILE_OPS(T)
#endif

FALLIBLE_OPS(uptr) FALLIBLE_OPS(u2)   FALLIBLE_OPS(u3)   FALLIBLE_OPS(u4)   FALLIBLE_OPS(u5)   FALLIBLE_OPS(u6)
FALLIBLE_OPS(u7)   FALLIBLE_OPS(u8)   FALLIBLE_OPS(u9)   FALLIBLE_OPS(u10)  FALLIBLE_OPS(u11)  FALLIBLE_OPS(u12)
FALLIBLE_OPS(u13)  FALLIBLE_OPS(u14)  FALLIBLE_OPS(u15)  FALLIBLE_OPS(u16)  FALLIBLE_OPS(u17)  FALLIBLE_OPS(u18)
FALLIBLE_OPS(u19)  FALLIBLE_OPS(u20)  FALLIBLE_OPS(u21)  FALLIBLE_OPS(u22)  FALLIBLE_OPS(u23)  FALLIBLE_OPS(u24)
FALLIBLE_OPS(u25)  FALLIBLE_OPS(u26)  FALLIBLE_OPS(u27)  FALLIBLE_OPS(u28)  FALLIBLE_OPS(u29)  FALLIBLE_OPS(u30)
FALLIBLE_OPS(u31)  FALLIBLE_OPS(u32)  FALLIBLE_OPS(u33)  FALLIBLE_OPS(u34)  FALLIBLE_OPS(u35)  FALLIBLE_OPS(u36)
FALLIBLE_OPS(u37)  FALLIBLE_OPS(u38)  FALLIBLE_OPS(u39)  FALLIBLE_OPS(u40)  FALLIBLE_OPS(u41)  FALLIBLE_OPS(u42)
FALLIBLE_OPS(u43)  FALLIBLE_OPS(u44)  FALLIBLE_OPS(u45)  FALLIBLE_OPS(u46)  FALLIBLE_OPS(u47)  FALLIBLE_OPS(u48)
FALLIBLE_OPS(u49)  FALLIBLE_OPS(u50)  FALLIBLE_OPS(u51)  FALLIBLE_OPS(u52)  FALLIBLE_OPS(u53)  FALLIBLE_OPS(u54)
FALLIBLE_OPS(u55)  FALLIBLE_OPS(u56)  FALLIBLE_OPS(u57)  FALLIBLE_OPS(u58)  FALLIBLE_OPS(u59)  FALLIBLE_OPS(u60)
FALLIBLE_OPS(u61)  FALLIBLE_OPS(u62)  FALLIBLE_OPS(u63)  FALLIBLE_OPS(u64)  FALLIBLE_OPS(u65)  FALLIBLE_OPS(u66)
FALLIBLE_OPS(u67)  FALLIBLE_OPS(u68)  FALLIBLE_OPS(u69)  FALLIBLE_OPS(u70)  FALLIBLE_OPS(u71)  FALLIBLE_OPS(u72)
FALLIBLE_OPS(u73)  FALLIBLE_OPS(u74)  FALLIBLE_OPS(u75)  FALLIBLE_OPS(u76)  FALLIBLE_OPS(u77)  FALLIBLE_OPS(u78)
FALLIBLE_OPS(u79)  FALLIBLE_OPS(u80)  FALLIBLE_OPS(u81)  FALLIBLE_OPS(u82)  FALLIBLE_OPS(u83)  FALLIBLE_OPS(u84)
FALLIBLE_OPS(u85)  FALLIBLE_OPS(u86)  FALLIBLE_OPS(u87)  FALLIBLE_OPS(u88)  FALLIBLE_OPS(u89)  FALLIBLE_OPS(u90)
FALLIBLE_OPS(u91)  FALLIBLE_OPS(u92)  FALLIBLE_OPS(u93)  FALLIBLE_OPS(u94)  FALLIBLE_OPS(u95)  FALLIBLE_OPS(u96)
FALLIBLE_OPS(u97)  FALLIBLE_OPS(u98)  FALLIBLE_OPS(u99)  FALLIBLE_OPS(u100) FALLIBLE_OPS(u101) FALLIBLE_OPS(u102)
FALLIBLE_OPS(u103) FALLIBLE_OPS(u104) FALLIBLE_OPS(u105) FALLIBLE_OPS(u106) FALLIBLE_OPS(u107) FALLIBLE_OPS(u108)
FALLIBLE_OPS(u109) FALLIBLE_OPS(u110) FALLIBLE_OPS(u111) FALLIBLE_OPS(u112) FALLIBLE_OPS(u113) FALLIBLE_OPS(u114)
FALLIBLE_OPS(u115) FALLIBLE_OPS(u116) FALLIBLE_OPS(u117) FALLIBLE_OPS(u118) FALLIBLE_OPS(u119) FALLIBLE_OPS(u120)
FALLIBLE_OPS(u121) FALLIBLE_OPS(u122) FALLIBLE_OPS(u123) FALLIBLE_OPS(u124) FALLIBLE_OPS(u125) FALLIBLE_OPS(u126)
FALLIBLE_OPS(u127) FALLIBLE_OPS(u128)

FALLIBLE_OPS(iptr) FALLIBLE_OPS(i2)   FALLIBLE_OPS(i3)   FALLIBLE_OPS(i4)   FALLIBLE_OPS(i5)   FALLIBLE_OPS(i6)
FALLIBLE_OPS(i7)   FALLIBLE_OPS(i8)   FALLIBLE_OPS(i9)   FALLIBLE_OPS(i10)  FALLIBLE_OPS(i11)  FALLIBLE_OPS(i12)
FALLIBLE_OPS(i13)  FALLIBLE_OPS(i14)  FALLIBLE_OPS(i15)  FALLIBLE_OPS(i16)  FALLIBLE_OPS(i17)  FALLIBLE_OPS(i18)
FALLIBLE_OPS(i19)  FALLIBLE_OPS(i20)  FALLIBLE_OPS(i21)  FALLIBLE_OPS(i22)  FALLIBLE_OPS(i23)  FALLIBLE_OPS(i24)
FALLIBLE_OPS(i25)  FALLIBLE_OPS(i26)  FALLIBLE_OPS(i27)  FALLIBLE_OPS(i28)  FALLIBLE_OPS(i29)  FALLIBLE_OPS(i30)
FALLIBLE_OPS(i31)  FALLIBLE_OPS(i32)  FALLIBLE_OPS(i33)  FALLIBLE_OPS(i34)  FALLIBLE_OPS(i35)  FALLIBLE_OPS(i36)
FALLIBLE_OPS(i37)  FALLIBLE_OPS(i38)  FALLIBLE_OPS(i39)  FALLIBLE_OPS(i40)  FALLIBLE_OPS(i41)  FALLIBLE_OPS(i42)
FALLIBLE_OPS(i43)  FALLIBLE_OPS(i44)  FALLIBLE_OPS(i45)  FALLIBLE_OPS(i46)  FALLIBLE_OPS(i47)  FALLIBLE_OPS(i48)
FALLIBLE_OPS(i49)  FALLIBLE_OPS(i50)  FALLIBLE_OPS(i51)  FALLIBLE_OPS(i52)  FALLIBLE_OPS(i53)  FALLIBLE_OPS(i54)
FALLIBLE_OPS(i55)  FALLIBLE_OPS(i56)  FALLIBLE_OPS(i57)  FALLIBLE_OPS(i58)  FALLIBLE_OPS(i59)  FALLIBLE_OPS(i60)
FALLIBLE_OPS(i61)  FALLIBLE_OPS(i62)  FALLIBLE_OPS(i63)  FALLIBLE_OPS(i64)  FALLIBLE_OPS(i65)  FALLIBLE_OPS(i66)
FALLIBLE_OPS(i67)  FALLIBLE_OPS(i68)  FALLIBLE_OPS(i69)  FALLIBLE_OPS(i70)  FALLIBLE_OPS(i71)  FALLIBLE_OPS(i72)
FALLIBLE_OPS(i73)  FALLIBLE_OPS(i74)  FALLIBLE_OPS(i75)  FALLIBLE_OPS(i76)  FALLIBLE_OPS(i77)  FALLIBLE_OPS(i78)
FALLIBLE_OPS(i79)  FALLIBLE_OPS(i80)  FALLIBLE_OPS(i81)  FALLIBLE_OPS(i82)  FALLIBLE_OPS(i83)  FALLIBLE_OPS(i84)
FALLIBLE_OPS(i85)  FALLIBLE_OPS(i86)  FALLIBLE_OPS(i87)  FALLIBLE_OPS(i88)  FALLIBLE_OPS(i89)  FALLIBLE_OPS(i90)
FALLIBLE_OPS(i91)  FALLIBLE_OPS(i92)  FALLIBLE_OPS(i93)  FALLIBLE_OPS(i94)  FALLIBLE_OPS(i95)  FALLIBLE_OPS(i96)
FALLIBLE_OPS(i97)  FALLIBLE_OPS(i98)  FALLIBLE_OPS(i99)  FALLIBLE_OPS(i100) FALLIBLE_OPS(i101) FALLIBLE_OPS(i102)
FALLIBLE_OPS(i103) FALLIBLE_OPS(i104) FALLIBLE_OPS(i105) FALLIBLE_OPS(i106) FALLIBLE_OPS(i107) FALLIBLE_OPS(i108)
FALLIBLE_OPS(i109) FALLIBLE_OPS(i110) FALLIBLE_OPS(i111) FALLIBLE_OPS(i112) FALLIBLE_OPS(i113) FALLIBLE_OPS(i114)
FALLIBLE_OPS(i115) FALLIBLE_OPS(i116) FALLIBLE_OPS(i117) FALLIBLE_OPS(i118) FALLIBLE_OPS(i119) FALLIBLE_OPS(i120)
FALLIBLE_OPS(i121) FALLIBLE_OPS(i122) FALLIBLE_OPS(i123) FALLIBLE_OPS(i124) FALLIBLE_OPS(i125) FALLIBLE_OPS(i126)
FALLIBLE_OPS(i127) FALLIBLE_OPS(i128)
