#!/bin/sh

# SPDX-License-Identifier: Apache-2.0
# Copyright © 2025 The Whixy Authors. All rights reserved.
# Contributors responsible for this file:
# @p7r0x7 <mattrbonnette@pm.me>

set -eu; umask 0022; rm -rf src/lrstar; install -dm 0755 src/lrstar .build

#opt="-O3 -mllvm -polly -mllvm -polly-vectorizer=stripmine -fopenmp -mllvm -polly-parallel"
[ -f .build/lrstar ] || zig c++ -O3 -w -lc++ -o .build/lrstar vendor/lrstar-master/source_lrstar/*.cpp &
[ -f .build/dfa ] || zig c++ -O3 -w -lc++ -o .build/dfa vendor/lrstar-master/source_dfa/*.cpp & wait

cd src/lrstar; ln ../Whixy.grm Whixy.grm; ln ../Whixy.lgr Whixy.lgr
{ ../../.build/lrstar Whixy.grm /crr /csr /ast /o; echo; ../../.build/dfa Whixy.lgr /crr /csr /sto; } || true
rm -f -- *.grm *.lex *.lgr *grammar.txt *states.txt make.bat memory.txt
cd ../..

find . \( -path ./vendor -o -name '.[!.]*' \) -prune -o \
    \( ! -type d \( \
        -name '*.zig' -exec zig fmt {} + -o \
        \( -name '*.c' -o -name '*.cpp' -o -name '*.h' -o -name '*.hpp' \) \
            -exec clang-format -i --style file:.clang-format {} + \
    \) \)

#find .. \( -path '../vendor' -o -name '.[!.]*' \) -prune -o -type f -exec tokei {} +

#git add .; git diff --stat HEAD; git reset >/dev/null