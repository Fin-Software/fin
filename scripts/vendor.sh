#!/bin/sh

# SPDX-License-Identifier: Apache-2.0
# Copyright © 2025 The Fin Authors. All rights reserved.
# Contributors responsible for this file:
# @p7r0x7 <mattrbonnette@pm.me>

# vendor/ must be kept current in VCS with this file that publicly defines its deterministic generation.
# And for security reasons, only @p7r0x7 may sign and push commits changing vendor.sh and vendor/.
# I refactor this mostly for the joy of programming, but now it's hyper optimized.

szip() { m=$1; shift; $zip $m -bd -ssc "$@"; }
command -v 7zz >/dev/null && zip=7zz || zip=7z
command -v gfind >/dev/null && find=gfind || find=find
srcs=/tmp/fin/srcs install='install -dm 0755' rm='rm -rf --'
set -eu; umask 0022; [ $# = 0 ] || return 0  # . ends

start() { name=$1; . ../scripts/vendor.sh; pkg=/tmp/fin/$name; $rm $pkg; $install $pkg; }  # . borrows $@
get() {
    hash=$1; [ -f $srcs/$base ] || curl --fail-with-body -sSL $url -o $srcs/$base
    real="$(szip h -scrcBLAKE2SP $srcs/$base | awk '/^BLAKE2sp for/ {print $4}')"
    [ "$real" = $hash ] && return 0 || curl --fail-with-body -sSL $url -o $srcs/$base
    real="$(szip h -scrcBLAKE2SP $srcs/$base | awk '/^BLAKE2sp for/ {print $4}')"
    [ "$real" = $hash ] || { printf 'get %s !=\n%s\n' $hash "$real"; return 1; }
}
finish() { $find $pkg -type d -empty -delete; for dir in $pkg/*; do $rm ${dir##*/}; done; mv $pkg/* .; rmdir $pkg; }

#
#    Separate collections of parallelly-acquiesced dependencies.
#
llvm() {
    start llvm; semv=21.1.5 base=llvm-project-$semv.src.tar.xz
    deps='clang cmake compiler-rt lld llvm openmp polly runtimes third-party'
    url=https://github.com/llvm/llvm-project/releases/download/llvmorg-$semv/$base
    (
        get 419fa6cd82f8914e13352cb8222f9126e3dec99091f24ced011c6ae14fcde9f2
        set -f; szip e -so $srcs/$base | szip x -o$pkg -si -ttar $(printf -- '-x!*/%s ' */bindings */docs       \
            */examples */test */unittests */www llvm/benchmarks polly/lib/External/isl/test_inputs) $(printf -- \
            '-xr!%s ' .* Maintainers.* CREDITS.* *.png *.bmp) $(printf '*/%s ' $deps) >/dev/null; set +f

        cd $pkg; mv llvm-project-$semv.src llvm-$semv; sed -i '' '1000,1004d' llvm-$semv/llvm/CMakeLists.txt
        guard='s|^[[:space:]]*add_subdirectory[[:space:]]*\(([^)]+)\)|if(EXISTS  "${CMAKE_CURRENT_SOURCE_DIR}/\1")\n  add_subdirectory(\1)\nendif()|'
        find . -name CMakeLists.txt -exec sed -i '' -E "$guard" {} +
    ); finish
}
other() {
    start other; semv=master base=LRSTAR-$semv.tar.gz url=https://github.com/p7r0x7/LRSTAR/archive/$semv.tar.gz
    (
        get 941148c9b8d00a4bff1137019a3875442c952e381b30f11ea2e5be6ba3b2b5e8
        set -f; szip e -so $srcs/$base | szip x -o$pkg -si -ttar \
            -x!'*/bin' -xr!'?G.*.txt' $(printf '*/*/*.%s ' h hpp cpp txt grm lgr) >/dev/null; set +f
        cd $pkg; mv LRSTAR-$semv lrstar-$semv
    ) &

    semv=1.5.7 base=zstd-$semv.tar.zst url=https://github.com/facebook/zstd/releases/download/v$semv/$base
    (
        get fbc3aeb165872f848a53a1d197b80289a06a3ae570d3abb2fa69616d5059b5f1
        set -f; szip e -so $srcs/$base | szip x -o$pkg -si -ttar $(printf -- '-x!*/%s ' zlibWrapper \
            lib/deprecated lib/legacy build/meson build/VS* *T*.md Package.swift CHANGELOG)         \
            $(printf -- '-xr!%s ' contrib/ example*/ programs/ tests/ *.png .*) >/dev/null; set +f
    ) & wait; finish
}

$install $srcs vendor; cd vendor; llvm & other & wait
