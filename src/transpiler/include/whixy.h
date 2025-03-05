// SPDX-License-Identifier: Apache-2.0
// Copyright © 2025 The Whixy Authors. All rights reserved.
// Contributors responsible for this file:
// @p7r0x7 <mattrbonnette@pm.me>

#pragma once

#if __CHAR_BIT__ != 8
    #error "Whixy only supports octal bytes."
#endif
#if __GNUC__ && __STDC_VERSION__ < 202000L
    #error "Lowercase whixy's C backend requires GNU C23."
#endif
#if __BITINT_MAXWIDTH__ < 128
    #error "Lowercase whixy's C backend requires C23 BitInt(N) compiler support."
#endif

#include "ops.h"
#include "lazy.h"
#include "types.h"

[[noreturn, gnu::always_inline]] void unreachable(void) { __builtin_unreachable(); }
