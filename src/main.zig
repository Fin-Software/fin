// SPDX-License-Identifier: Apache-2.0
// Copyright © 2024 The Whixy Authors. All rights reserved.
// Contributors responsible for this file:
// @p7r0x7 <mattrbonnette@pm.me>

extern fn doJIT(c_int, [*][*]c_char) void;

fn main() void {
    doJIT(0, &[_]c_char{&[_]c_char{""}});
}
