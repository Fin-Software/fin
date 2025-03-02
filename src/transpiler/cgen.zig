// SPDX-License-Identifier: Apache-2.0
// Copyright © 2025 The Whixy Authors. All rights reserved.
// Contributors responsible for this file:
// @p7r0x7 <mattrbonnette@pm.me>

// TODO(@p7r0x7): Keep in sync with include/types.h.
const types = enum {
    bool,
};

const phrase = enum { include, include_whixy, gnu_const, alignas };

const c = union(phrase) {
    include: "#include ",
    include_whixy: "#include \"whixy.h\"\n",
    gnu_const: "[[gnu::const]] ",
    alignas: "alignas(",
};
