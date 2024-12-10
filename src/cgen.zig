// SPDX-License-Identifier: Apache-2.0
// Copyright © 2024 The Whixy Authors. All rights reserved.
// Contributors responsible for this file:
// @p7r0x7 <mattrbonnette@pm.me>

const phrase = enum { unsequenced, alignas, thread_local, @"volatile" };

const c = union(phrase) {
    unsequenced: "[[unsequenced]]",
    alignas: "alignas",
    thread_local: "thread_local",
    @"volatile": "volatile",
};
