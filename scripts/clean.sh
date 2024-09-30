#!/bin/sh

# SPDX-License-Identifier: Apache-2.0
# Copyright © 2024 The Whixy Authors. All rights reserved.
# Contributors responsible for this file:
# @p7r0x7 <mattrbonnette@pm.me>

set -exu
umask 0022
cd src
rm -rf antlr
install -dm 0755 antlr
antlr4 -Dlanguage=Cpp -Werror -o antlr -package Whixy WhixyParser.g4 WhixyLexer.g4
rm antlr/*.interp antlr/*.tokens
find .. \( -name '*.cpp' -o -name '*.h' \) -exec clang-format -i {} +
find .. -name '*.zig' -exec zig fmt {} +
git status