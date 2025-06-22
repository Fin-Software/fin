// SPDX-License-Identifier: Apache-2.0
// Copyright © 2025 The Whixy Authors. All rights reserved.
// Contributors responsible for this file:
// @p7r0x7 <mattrbonnette@pm.me>

#pragma once

#define INTS(x) unsigned typedef _BitInt(x) u##x; typedef _BitInt(x) i##x;
INTS(2)   INTS(3)   INTS(4)   INTS(5)   INTS(6)   INTS(7)   INTS(8)   INTS(9)
INTS(10)  INTS(11)  INTS(12)  INTS(13)  INTS(14)  INTS(15)  INTS(16)  INTS(17)
INTS(18)  INTS(19)  INTS(20)  INTS(21)  INTS(22)  INTS(23)  INTS(24)  INTS(25)
INTS(26)  INTS(27)  INTS(28)  INTS(29)  INTS(30)  INTS(31)  INTS(32)  INTS(33)
INTS(34)  INTS(35)  INTS(36)  INTS(37)  INTS(38)  INTS(39)  INTS(40)  INTS(41)
INTS(42)  INTS(43)  INTS(44)  INTS(45)  INTS(46)  INTS(47)  INTS(48)  INTS(49)
INTS(50)  INTS(51)  INTS(52)  INTS(53)  INTS(54)  INTS(55)  INTS(56)  INTS(57)
INTS(58)  INTS(59)  INTS(60)  INTS(61)  INTS(62)  INTS(63)  INTS(64)  INTS(65)
INTS(66)  INTS(67)  INTS(68)  INTS(69)  INTS(70)  INTS(71)  INTS(72)  INTS(73)
INTS(74)  INTS(75)  INTS(76)  INTS(77)  INTS(78)  INTS(79)  INTS(80)  INTS(81)
INTS(82)  INTS(83)  INTS(84)  INTS(85)  INTS(86)  INTS(87)  INTS(88)  INTS(89)
INTS(90)  INTS(91)  INTS(92)  INTS(93)  INTS(94)  INTS(95)  INTS(96)  INTS(97)
INTS(98)  INTS(99)  INTS(100) INTS(101) INTS(102) INTS(103) INTS(104) INTS(105)
INTS(106) INTS(107) INTS(108) INTS(109) INTS(110) INTS(111) INTS(112) INTS(113)
INTS(114) INTS(115) INTS(116) INTS(117) INTS(118) INTS(119) INTS(120) INTS(121)
INTS(122) INTS(123) INTS(124) INTS(125) INTS(126) INTS(127) INTS(128)

#if __SIZEOF_POINTER__ == 8
    typedef u64 uptr; typedef i64 iptr;
#elif __SIZEOF_POINTER__ == 4 || __SIZEOF_POINTER__ == 2
    typedef u32 uptr; typedef i32 iptr;
#else
    #error "Whixy only supports 64-, 32-, and 16-bit nominal pointer sizes."
#endif

typedef _Float16    f16;
typedef __bf16      bf16;
typedef float       f32;
typedef double      f64;
typedef long double f80;
typedef __float128  f128;
typedef u2          u1;   // 0 or 1
typedef i2          i1;   // 0 or -1
