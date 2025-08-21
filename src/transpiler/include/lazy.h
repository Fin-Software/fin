// SPDX-License-Identifier: Apache-2.0
// Copyright © 2025 The Fin Authors. All rights reserved.
// Contributors responsible for this file:
// @p7r0x7 <mattrbonnette@pm.me>

#pragma once

#define ARGS_0
#define ARGS_1 void*
#define ARGS_2 ARGS_1, void*
#define ARGS_3 ARGS_2, void*
#define ARGS_4 ARGS_3, void*
#define ARGS_5 ARGS_4, void*
#define ARGS_6 ARGS_5, void*
#define ARGS_7 ARGS_6, void*
#define ARGS_8 ARGS_7, void*
#define ARGS_9 ARGS_8, void*
#define ARGS_10 ARGS_9, void*
#define ARGS_11 ARGS_10, void*
#define ARGS_12 ARGS_11, void*
#define ARGS_13 ARGS_12, void*
#define ARGS_14 ARGS_13, void*
#define ARGS_15 ARGS_14, void*
#define ARGS_16 ARGS_15, void*
#define ARGS_17 ARGS_16, void*
#define ARGS_18 ARGS_17, void*
#define ARGS_19 ARGS_18, void*
#define ARGS_20 ARGS_19, void*
#define ARGS_21 ARGS_20, void*
#define ARGS_22 ARGS_21, void*
#define ARGS_23 ARGS_22, void*
#define ARGS_24 ARGS_23, void*
#define ARGS_25 ARGS_24, void*
#define ARGS_26 ARGS_25, void*
#define ARGS_27 ARGS_26, void*
#define ARGS_28 ARGS_27, void*
#define ARGS_29 ARGS_28, void*
#define ARGS_30 ARGS_29, void*
#define ARGS_31 ARGS_30, void*

#define FIELDS_0
#define FIELDS_1 void* arg0;
#define FIELDS_2 FIELDS_1 void* arg1;
#define FIELDS_3 FIELDS_2 void* arg2;
#define FIELDS_4 FIELDS_3 void* arg3;
#define FIELDS_5 FIELDS_4 void* arg4;
#define FIELDS_6 FIELDS_5 void* arg5;
#define FIELDS_7 FIELDS_6 void* arg6;
#define FIELDS_8 FIELDS_7 void* arg7;
#define FIELDS_9 FIELDS_8 void* arg8;
#define FIELDS_10 FIELDS_9 void* arg9;
#define FIELDS_11 FIELDS_10 void* arg10;
#define FIELDS_12 FIELDS_11 void* arg11;
#define FIELDS_13 FIELDS_12 void* arg12;
#define FIELDS_14 FIELDS_13 void* arg13;
#define FIELDS_15 FIELDS_14 void* arg14;
#define FIELDS_16 FIELDS_15 void* arg15;
#define FIELDS_17 FIELDS_16 void* arg16;
#define FIELDS_18 FIELDS_17 void* arg17;
#define FIELDS_19 FIELDS_18 void* arg18;
#define FIELDS_20 FIELDS_19 void* arg19;
#define FIELDS_21 FIELDS_20 void* arg20;
#define FIELDS_22 FIELDS_21 void* arg21;
#define FIELDS_23 FIELDS_22 void* arg22;
#define FIELDS_24 FIELDS_23 void* arg23;
#define FIELDS_25 FIELDS_24 void* arg24;
#define FIELDS_26 FIELDS_25 void* arg25;
#define FIELDS_27 FIELDS_26 void* arg26;
#define FIELDS_28 FIELDS_27 void* arg27;
#define FIELDS_29 FIELDS_28 void* arg28;
#define FIELDS_30 FIELDS_29 void* arg29;
#define FIELDS_31 FIELDS_30 void* arg30;

#define FUNC(n, ...) void* (*func)(__VA_ARGS__)
#define LAZY(n) typedef struct { FUNC(n, ARGS_##n); FIELDS_##n } lazy_##n;

LAZY(0)  LAZY(1)  LAZY(2)  LAZY(3)  LAZY(4)  LAZY(5)  LAZY(6)  LAZY(7)
LAZY(8)  LAZY(9)  LAZY(10) LAZY(11) LAZY(12) LAZY(13) LAZY(14) LAZY(15)
LAZY(16) LAZY(17) LAZY(18) LAZY(19) LAZY(20) LAZY(21) LAZY(22) LAZY(23)
LAZY(24) LAZY(25) LAZY(26) LAZY(27) LAZY(28) LAZY(29) LAZY(30) LAZY(31)
