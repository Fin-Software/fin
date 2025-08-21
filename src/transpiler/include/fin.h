// SPDX-License-Identifier: Apache-2.0
// Copyright © 2025 The Fin Authors. All rights reserved.
// Contributors responsible for this file:
// @p7r0x7 <mattrbonnette@pm.me>

#pragma once

#if __CHAR_BIT__ != 8
    #error "Fin only supports octal bytes."
#endif
#if __GNUC__ && __STDC_VERSION__ < 202000L
    #error "Lowercase fin's C artifacts require GNU C23."
#endif

#include "lazy.h"
#include "ops.h"
#include "types.h"

[[noreturn, gnu::always_inline]] void unreachable(void) { __builtin_unreachable(); }
