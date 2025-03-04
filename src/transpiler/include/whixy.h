// SPDX-License-Identifier: Apache-2.0
// Copyright © 2025 The Whixy Authors. All rights reserved.
// Contributors responsible for this file:
// @p7r0x7 <mattrbonnette@pm.me>

#pragma once

#ifndef __GNUC__
    #error "GNU C required."
#endif
#if __STDC_VERSION__ < 202000L
    #error "C23 required."
#endif
#if __CHAR_BIT__ != 8
    #error "Whixy only supports octal bytes."
#endif

#include "lazy.h"
#include "ops.h"
#include "types.h"

[[noreturn, gnu::always_inline]] void unreachable(void) { __builtin_unreachable(); }
