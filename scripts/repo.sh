#!/bin/sh

# SPDX-License-Identifier: Apache-2.0
# Copyright © 2025 The Fin Authors. All rights reserved.
# Contributors responsible for this file:
# @p7r0x7 <maxibonnette@pm.me>

#    Does shit.

set -eu; umask 0022; install -dm 0755 src/frontend/lrstar .build

# Build LRSTAR
opt='-pipe -O3 -mllvm -polly -mllvm -polly-vectorizer=stripmine -fno-omit-frame-pointer'
[ -f .build/lrstar ] || clang++ $opt -w -lc++ -o .build/lrstar vendor/lrstar-master/source_lrstar/*.cpp &
[ -f .build/dfa ] || clang++ $opt -w -lc++ -o .build/dfa vendor/lrstar-master/source_dfa/*.cpp & wait

# Run LRSTAR
cd src/frontend/lrstar; ln ../Fin.grm Fin.grm; ln ../Fin.lgr Fin.lgr
printf '\033[1;33m'; { ../../../.build/lrstar Fin.grm /crr /csr /wk /k=2 /o /m
    echo; ../../../.build/dfa Fin.lgr /crr /csr /sto /m; } || true
rm -f -- *.grm *.lgr *.lex *grammar.txt *states.txt *log.txt make.bat memory.txt; cd ../../..

# Normalize repo
find . \( -path ./vendor -o -path '*/.*' \) -prune -o \
    \( \
        -type f \
        \( -name '*.c' -o -name '*.cpp' -o -name '*.h' -o -name '*.hpp' \) \
        -exec clang-format -i {} + \
    \) -o \
    \( \
        -type f \
        -exec sh -c '
        set -e; file -b --mime "$1" | grep -q text || exit 0
        expand -t 4 "$1" > "$1.tmp" && mv "$1.tmp" "$1"
        [ -z "$(tail -c1 "$1")" ] || echo >>"$1"
        ' sh {} \; \
    \)
chmod a+x scripts/*sh

# Run Lexer+Parser
clang++ -O0 -w -lc++ -include sys/stat.h -Ivendor/lrstar-master -o .build/finlp src/frontend/lrstar/*.cpp
mawk '
function spaces(n, gap) {
    if ((gap = n-length(SPACES)) > 0) SPACES = SPACES sprintf("%*s", gap, "")
    return substr(SPACES, 1, n)
}
function whiteoutnontab(s, out, parts, n, i) {
    n = split(s, parts, "\t")
    for (i = 1; i < n; i++) out = out spaces(length(parts[i])) "\t"
    return out spaces(length(parts[n]))
}
{
    while (length($0)) {
        if (!depth) {
            sl = index($0, "##"); mlopen = index($0, "<><")
            if (!sl && !mlopen) { printf "%s", $0; break }
            if (sl && (!mlopen || sl <= mlopen)) {
                printf "%s%s", substr($0, 1, sl-1), spaces(length($0)-sl+1)
                break
            }
            printf "%s   ", substr($0, 1, mlopen-1)
            depth++; $0 = substr($0, mlopen+3)
        } else {
            mlopen = index($0, "<><"); mlclose = index($0, "><>")
            if (!mlopen && !mlclose) { printf "%s", whiteoutnontab($0); break }
            if (mlopen && (!mlclose || mlopen < mlclose)) {
                printf "%s   ", whiteoutnontab(substr($0, 1, mlopen-1))
                depth++; $0 = substr($0, mlopen+3)
            } else {
                printf "%s   ", whiteoutnontab(substr($0, 1, mlclose-1))
                depth--; $0 = substr($0, mlclose+3)
            }
        }
    }; printf "\n"  # Always ends files with a newline
}
' research/finfile.fn >research/finfile.wo.fn
sz1=$(wc -c <research/finfile.fn) sz2=$(wc -c <research/finfile.wo.fn); [ $sz1 -eq $sz2 ] || [ $sz1 -eq $((sz2 - 1)) ]
.build/finlp research/finfile.wo.fn || true; printf '\033[0m\n'
rm research/finfile.wo.fn lrstar.txt research/finfile.output.txt 2>/dev/null || true

# Print git status
(GIT_INDEX_FILE=.git/index.tmp; export GIT_INDEX_FILE; git read-tree HEAD; git add .; git --no-pager diff --stat HEAD)
