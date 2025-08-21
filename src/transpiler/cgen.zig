// SPDX-License-Identifier: Apache-2.0
// Copyright © 2025 The Fin Authors. All rights reserved.
// Contributors responsible for this file:
// @p7r0x7 <mattrbonnette@pm.me>

// TODO(@p7r0x7): Keep in sync with include/types.h.
const types = enum {
    bool,
};

const phrase = enum { include, include_fin, gnu_const, alignas };

const c = union(phrase) {
    include: "#include ",
    include_fin: "#include \"fin.h\"\n",
    gnu_const: "[[gnu::const]] ",
    alignas: "alignas(",
};
