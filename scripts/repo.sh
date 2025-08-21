#!/bin/sh

# SPDX-License-Identifier: Apache-2.0
# Copyright © 2025 The Fin Authors. All rights reserved.
# Contributors responsible for this file:
# @p7r0x7 <mattrbonnette@pm.me>

set -eu; umask 0022; rm -rf src/lrstar; install -dm 0755 src/lrstar .build

opt="-O3 -mllvm -polly -mllvm -polly-vectorizer=stripmine"
[ -f .build/lrstar ] || clang $opt -w -lc++ -o .build/lrstar vendor/lrstar-master/source_lrstar/*.cpp &
[ -f .build/dfa ] || clang $opt -w -lc++ -o .build/dfa vendor/lrstar-master/source_dfa/*.cpp & wait

cd src/lrstar; ln ../Fin.grm Fin.grm; ln ../Fin.lgr Fin.lgr
{ ../../.build/lrstar Fin.grm /crr /csr /o; echo; ../../.build/dfa Fin.lgr /crr /csr /sto; } || true
rm -f -- *.grm *.lex *.lgr *grammar.txt *states.txt make.bat memory.txt
cd ../..

find . \( -path ./vendor -o -name '.[!.]*' \) -prune -o \
    \( ! -type d \( \
        -name '*.zig' -exec zig fmt {} + -o \
        \( -name '*.c' -o -name '*.cpp' -o -name '*.h' -o -name '*.hpp' \) \
            -exec clang-format -i --style file:.clang-format {} + \
    \) \)

git add .; git diff --stat HEAD; git reset