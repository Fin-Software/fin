#!/bin/sh

# SPDX-License-Identifier: Apache-2.0
# Copyright © 2025 The Fin Authors. All rights reserved.
# Contributors responsible for this file:
# @p7r0x7 <maxibonnette@pm.me>

#    Does shit.

set -eu; umask 0022; install -dm 0755 src/lrstar .build

opt='-pipe -O3 -flto=thin -mllvm -polly -mllvm -polly-vectorizer=stripmine -fno-omit-frame-pointer'
[ -f .build/lrstar ] || clang $opt -w -lc++ -o .build/lrstar vendor/lrstar-master/source_lrstar/*.cpp &
[ -f .build/dfa ] || clang $opt -w -lc++ -o .build/dfa vendor/lrstar-master/source_dfa/*.cpp & wait

cd src/lrstar; ln ../Fin.grm Fin.grm; ln ../Fin.lgr Fin.lgr

printf '\033[1;33m'; { ../../.build/lrstar Fin.grm /crr /csr /st /wk /k=2 /o; echo
  ../../.build/dfa Fin.lgr /crr /csr /sto; } || true; printf '\033[0m\n'

rm -f -- *.grm *.lgr *.lex *grammar.txt *log.txt make.bat memory.txt; cd ../..

find . \( -path ./vendor -o -name '.[!.]*' \) -prune -o \
    \( ! -type d \( \
        \( -name '*.c' -o -name '*.cpp' -o -name '*.h' -o -name '*.hpp' \) \
            -exec clang-format -i --style file:.clang-format {} + \
    \) \)

git add .; git --no-pager diff --stat HEAD; git reset >/dev/null