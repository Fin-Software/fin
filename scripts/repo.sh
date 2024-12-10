#!/bin/sh

# SPDX-License-Identifier: Apache-2.0
# Copyright © 2024 The Whixy Authors. All rights reserved.
# Contributors responsible for this file:
# @p7r0x7 <mattrbonnette@pm.me>

set -eu; umask 0022

cd src; rm -rf antlr; install -dm 0755 antlr

antlr4 -Dlanguage=Cpp -no-visitor -listener -o antlr -package Whixy -encoding utf-8 WhixyParser.g4 WhixyLexer.g4 \
    || printf '\n\t\033[33mantlr4 failed to execute successfully: continuing...\033[0m\n\n'
rm antlr/*.interp antlr/*.tokens

find .. -path '../vendor' -prune -not -path '*/.*' -name '*.zig' -exec zig fmt {} + \
    -o \( -name '*.cpp' -o -name '*.h' \) -exec clang-format -i --style='file:../.clang-format' {} +

git add .; git diff --stat HEAD; git reset >/dev/null