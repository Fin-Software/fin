#!/bin/sh

# SPDX-License-Identifier: Apache-2.0
# Copyright © 2025 The Fin Authors. All rights reserved.
# Contributors responsible for this file:
# @p7r0x7 <maxibonnette@pm.me>

#    Does shit.

set -eu; umask 0022; install -dm 0755 src/lrstar .build

opt='-pipe -O3 -mllvm -polly -mllvm -polly-vectorizer=stripmine -fno-omit-frame-pointer'
[ -f .build/lrstar ] || clang++ $opt -w -lc++ -o .build/lrstar vendor/lrstar-master/source_lrstar/*.cpp &
[ -f .build/dfa ] || clang++ $opt -w -lc++ -o .build/dfa vendor/lrstar-master/source_dfa/*.cpp & wait

cd src/lrstar; ln ../Fin.grm Fin.grm; ln ../Fin.lgr Fin.lgr

printf '\033[1;33m'; { ../../.build/lrstar Fin.grm /crr /csr /wk /k=2 /o /m; echo
    ../../.build/dfa Fin.lgr /crr /csr /sto /m; } || true; printf '\033[0m\n'

rm -f -- *.grm *.lgr *.lex *grammar.txt *log.txt make.bat memory.txt; cd ../..
find . \( -path ./vendor -o -name '.[!.]*' \) -prune -o \
    \( ! -type d \( \
        \( -name '*.c' -o -name '*.cpp' -o -name '*.h' -o -name '*.hpp' \) \
            -exec clang-format -i {} + \
    \) \)

ln -sf vendor/lrstar-master/code code
clang++ -O0 -w -lc++ -include sys/stat.h -o .build/finlp src/lrstar/*.cpp
time awk '{
    out = ""; n = length($0); i = 1
    while (i <= n) {
        s1 = substr($0, i, 1); s2 = substr($0, i, 2); s3 = substr($0, i, 3)
        if (depth == 0 && s2 == "##")
            { out = out sprintf("%*s", n - i + 1, ""); break }
        if (depth == 0 && s3 == "<><")
            { depth++; out = out "   "; i += 3; continue }
        if (depth > 0 && s3 == "><>")
            { depth--; out = out "   "; i += 3; continue }
        out = out (depth > 0 ? (s1 == "\t" ? "\t" : " ") : s1); i++
    }; print out
}' research/finfile.fn >research/finfile.wo.fn
[ $(wc -c <research/finfile.fn) = $(wc -c <research/finfile.wo.fn) ]
.build/finlp research/finfile.wo.fn || true
rm code research/finfile.wo.fn lrstar.txt 2>/dev/null || true

[ -n "$(git status --porcelain)" ] && git add .; git --no-pager diff --stat HEAD; git reset >/dev/null