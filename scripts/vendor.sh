#!/bin/sh

# SPDX-License-Identifier: Apache-2.0
# Copyright © 2025 The Fin Authors. All rights reserved.
# Contributors responsible for this file:
# @p7r0x7 <mattrbonnette@pm.me>

# vendor/ must be kept current in VCS with this file that publicly defines its deterministic generation.
# And for security reasons, only @p7r0x7 may sign and push commits changing vendor.sh and vendor/.
# I refactor this mostly for the joy of programming, but now it's hyper optimized.

command -v gsed >/dev/null && sed=gsed || sed=sed
$sed -i '' '' /dev/null 2>/dev/null && sed="$sed -i ''" || sed="$sed -i"
srcs=/tmp/fin/srcs vend=${srcs%/*}vend install='install -dm 0755' print='printf --' rm='rm -rf --'
command -v 7zz >/dev/null && zip=7zz || zip=7z; command -v gfind >/dev/null && find=gfind || find=find

szip() { _mode=$1; shift; $zip $_mode -bd -ssc "$@"; }
get() {
    _hash=$1; [ -f $srcs/$base ] || curl --fail-with-body -sSL https://$url -o $srcs/$base
    _real="$(szip h -scrcSHA3-256 $srcs/$base | awk '/^SHA3-256 for/ {print $4}')"
    [ "$_real" = $_hash ] && return 0 || curl --fail-with-body -sSL https://$url -o $srcs/$base
    _real="$(szip h -scrcSHA3-256 $srcs/$base | awk '/^SHA3-256 for/ {print $4}')"
    [ "$_real" = $_hash ] || { $print 'get %s !=\n%s\n' $_hash "$_real"; return 1; }
}

set -eu; umask 0022; $rm $vend; $install $srcs $vend vendor; cd vendor

deps='clang cmake compiler-rt lld llvm openmp polly runtimes third-party'
semv=22.1.2 base=llvm-project-$semv.src.tar.xz url=github.com/llvm/llvm-project/releases/download/llvmorg-$semv/$base
(
    get e25036d460357ec4c542d5507feceb8a21d23f98f86234291a902392a8bcde07; set -f
        szip e -so $srcs/$base | szip x -o$vend -si -ttar $($print '-x!*/%s ' */bindings */docs */www */examples \
        */test */unittests llvm/benchmarks polly/lib/External/isl/test_inputs) $($print '-xr!%s ' Maintainers.*  \
        CREDITS.* *.png *.bmp .*) $($print '*/%s ' $deps) >/dev/null

    cd $vend; mv llvm-project-$semv.src llvm-$semv
    _guard='s|^[[:space:]]*add_subdirectory[[:space:]]*\(([^)]+)\)|if(EXISTS  '
    _guard=$_guard'"${CMAKE_CURRENT_SOURCE_DIR}/\1")\n  add_subdirectory(\1)\nendif()|'
    $sed '/# Use libtool instead of ar/{N;N;N;N;d;}' llvm-$semv/llvm/CMakeLists.txt
    $find llvm-$semv -name CMakeLists.txt -exec $sed -E "$_guard" {} +; set +f
) &

semv=master base=LRSTAR-$semv.tar.gz url=github.com/p7r0x7/LRSTAR/archive/${base#*-}
(
    get f6b33c1ea42ebdd1793728daa82a30095848345958b9498b3fbb6e9da00534a2; set -f
        szip e -so $srcs/$base | szip x -o$vend -si -ttar $($print '-i!*/*/*.%s ' h hpp cpp txt grm lgr) \
        -x!*/bin -xr!?G.*.txt >/dev/null; mv $vend/LRSTAR-$semv $vend/lrstar-$semv; set +f
) &

semv=1.5.7 base=zstd-$semv.tar.zst url=github.com/facebook/zstd/releases/download/v$semv/$base
(
    get faf88aa26fa06f469e05fcb48434804905f70eb36c7760916f2f4de4287c85f6; set -f
        szip e -so $srcs/$base | szip x -o$vend -si -ttar $($print '-x!*/%s ' zlibWrapper lib/deprecated lib/legacy  \
        build/meson build/VS* *T*.md Package.swift CHANGELOG) $($print '-xr!%s ' contrib/ example*/ programs/ tests/ \
        *.png .*) >/dev/null; set +f
) &

semv=1.3.2 base=zlib-$semv.tar.xz url=github.com/madler/zlib/releases/download/v$semv/$base
(
    get d60ffcfad05908d1efb932177340d2c80c9db123cf9eadff5657945f214a2214; set -f
        szip e -so $srcs/$base | szip x -o$vend -si -ttar >/dev/null  # 7zip refused to cooperate

        $find $vend/zlib-$semv -maxdepth 1 -mindepth 1 ! \( -name *.c -o -name *.h -o -name *in -o -name \
        CMakeLists.txt \) -exec $rm {} +; set +f
) &

wait; $find $vend -type d -empty -delete; for _dir in $vend/*; do $rm ${_dir##*/}; done; mv $vend/* .; rmdir $vend
