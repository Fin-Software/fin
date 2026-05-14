#!/bin/sh

# SPDX-License-Identifier: Apache-2.0
# Copyright © 2026 The Fin Authors. All rights reserved.
# Contributors responsible for this file:
# @p7r0x7 <maxibonnette@pm.me>

supported='android/arm64 darwin/arm64 linux/arm64 linux/riscv64 linux/x64 windows/arm64 windows/x64'
# fin also supports wasi/wasm and wasi/wasm64, but cannot be hosted on them

help() {
    [ $# = 2 ] && printf 'error: %s\n\n' "$2" >&2
    printf '%s\n' \
        'Usage: scripts/build.sh' \
        '       scripts/build.sh <debug|safe> <target>' \
        '' >&2
    printf '       %s\n' $supported '' >&2; exit $1
}

settings() {
    set -eu; umask 0022; tabs -4; install='install -dm 0755'; $install .build
    for _arg in "$@"; do case "$_arg" in -h|--help) help 0 ;; esac; done
    case $# in
    0)
        _os=$(uname -s | tr '[:upper:]' '[:lower:]') _arch=$(uname -m | tr '[:upper:]' '[:lower:]')
        case "$_arch" in x86_64|amd64) _arch=x64 ;; aarch64) _arch=arm64 ;; esac
        [ -f /system/build.prop ] || [ -f /vendor/build.prop ] && _os=android
        mode=safe target="$_os/$_arch" ;;
    2)
        mode="$1" target="$2"
        case "$mode" in safe|debug) ;; *) help 1 'mode must be either safe or debug' ;; esac ;;
    *)
        help 1 'invalid argument count' ;;
    esac
    case "$target" in
        android/arm64) triple=aarch64-linux-android ;;
        darwin/arm64)  triple=aarch64-apple-macosx ;;
        linux/arm64)   triple=aarch64-linux-gnu ;;
        linux/riscv64) triple=riscv64-linux-gnu ;;
        linux/x64)     triple=x86_64-linux-gnu ;;
        windows/arm64) triple=aarch64-windows-msvc ;;
        windows/x64)   triple=x86_64-windows-msvc ;;
        *) help 1 "$(printf 'target %s unsupported' "$target" )" ;;
    esac
    case ${target%/*} in darwin) lld=ld64.lld ;; android|linux) lld=ld.lld ;; windows) lld=lld-link ;; esac
    [ ${target%/*} = darwin ] && gc=-dead_strip || gc=--gc-sections
}

libs() {
    _flags='-pipe -Wno-unused-command-line-argument -fno-omit-frame-pointer
        -O3 -flto=thin -mllvm -polly -mllvm -polly-vectorizer=stripmine'

    [ -f .build/hash ] || {
        c3c compile-only hash.c3 -O0 -g0 --single-module=yes --emit-llvm --no-obj --llvm-out /tmp/fin
        clang -fuse-ld="$(command -v $lld)" $_flags -Wl,$gc /tmp/fin/*.ll -o .build/hash
    }
    [ "$(.build/hash vendor)" = '0niZ8ZayS6I6O4SXaE2vwpSmhZuNP4GLWjgWEQKRoRg=' ]  # CODE REVIEW POISON
    target=${target%/*}-${target#*/}; $install .build/$target/build

    set -- -Wno-dev -G Ninja \
        -DCMAKE_BUILD_TYPE=Release \
        -DCMAKE_AR="$(command -v llvm-ar)" \
        -DCMAKE_LINKER="$(command -v $lld)" \
        -DCMAKE_EXE_LINKER_FLAGS_RELEASE=-O3 \
        -DCMAKE_C_COMPILER="$(command -v clang)" \
        -DCMAKE_CXX_COMPILER="$(command -v clang++)" \
        -DCMAKE_C_FLAGS_RELEASE="$(printf '%s ' $_flags)" \
        -DCMAKE_CXX_FLAGS_RELEASE="$(printf '%s ' $_flags)" \
        -DCMAKE_OBJCOPY=false -DCMAKE_RANLIB=false -DCMAKE_NM=false

    buildzlib=.build/$target/build/zlib zlib=.build/$target/install/zlib
    $install $buildzlib; cmake -S vendor/zlib-* -B $buildzlib "$@" \
        -DZLIB_BUILD_TESTING=OFF \
        -DZLIB_BUILD_SHARED=OFF \
        -DZLIB_BUILD_STATIC=ON \
        -DCMAKE_INSTALL_PREFIX=$zlib; echo

    rm -rf $zlib; ninja -C $buildzlib libz.a; echo

    $install .build/$target/prefix; mv .build/$target/install/zlib/include #kaboom

    buildzstd=.build/$target/build/zstd; zstd=.build/$target/install/zstd
    $install $buildzstd; cmake -S vendor/zstd-*/build/cmake -B $buildzstd "$@" \
        -DZSTD_MULTITHREAD_SUPPORT=ON \
        -DZSTD_LEGACY_SUPPORT=OFF \
        -DZSTD_BUILD_PROGRAMS=OFF \
        -DZSTD_BUILD_SHARED=OFF \
        -DCMAKE_INSTALL_PREFIX=$zstd; echo

    rm -rf $zstd; ninja -C $buildzstd libzstd.a; ninja -C $buildzstd install >/dev/null; echo

    buildllvm=.build/$target/build/llvm llvm=.build/$target/llvm
    $install $buildllvm; cmake -S vendor/llvm-*/llvm -B $buildllvm "$@" \
        -DLLVM_OPTIMIZED_TABLEGEN=ON \
        -DLLVM_UNREACHABLE_OPTIMIZE=ON \
        -DLLVM_ENABLE_ASSERTIONS=OFF \
        -DLLVM_ENABLE_EH=OFF \
        -DLLVM_ENABLE_RTTI=OFF \
        -DLLVM_ENABLE_THREADS=ON \
        -DLLVM_ENABLE_LTO=Thin \
        -DCLANG_ENABLE_PROTO_FUZZER=OFF \
        -DCLANG_ENABLE_OBJC_REWRITER=OFF \
        -DCLANG_ENABLE_STATIC_ANALYZER=OFF \
        -DLLVM_ENABLE_BACKTRACES=OFF \
        -DLLVM_ENABLE_BINDINGS=OFF \
        -DLLVM_ENABLE_CRASH_OVERRIDES=OFF \
        -DLLVM_ENABLE_LIBEDIT=OFF \
        -DLLVM_ENABLE_LIBPFM=OFF \
        -DLLVM_ENABLE_LIBXML2=OFF \
        -DLLVM_ENABLE_OCAMLDOC=OFF \
        -DLLVM_ENABLE_PLUGINS=OFF \
        -DLLVM_ENABLE_Z3_SOLVER=OFF \
        -DLLVM_ENABLE_ZLIB=ON \
        -DLLVM_ENABLE_ZSTD=ON \
        -DLLVM_INCLUDE_DOCS=OFF \
        -DLLVM_INCLUDE_TESTS=OFF \
        -DLLVM_INCLUDE_EXAMPLES=OFF \
        -DLLVM_INCLUDE_BENCHMARKS=OFF \
        -DCOMPILER_RT_BUILD_XRAY=OFF \
        -DCOMPILER_RT_BUILD_PROFILE=ON \
        -DCOMPILER_RT_BUILD_BUILTINS=ON \
        -DCOMPILER_RT_BUILD_SANITIZERS=ON \
        -DLLVM_ENABLE_PROJECTS="clang;lld;polly" \
        -DLLVM_ENABLE_RUNTIMES="compiler-rt;openmp" \
        -DLLVM_TARGETS_TO_BUILD="X86;AArch64;ARM;RISCV;WebAssembly;LoongArch" \
        -DCMAKE_PREFIX_PATH=$codecs \
        -DCMAKE_INSTALL_PREFIX=$llvm; echo

    rm -rf $llvm; ninja -C $buildllvm \
        install-clangDriver \
        install-lldCOFF \
        install-lldCommon \
        install-lldELF \
        install-lldMachO \
        install-lldWasm \
        install-LLVMFrontendOpenMP \
        install-LLVMOrcJIT \
        install-Polly
    ninja -C $buildllvm install-llvm-headers install-clang-headers install-lld-headers >/dev/null; echo

    #{
    #	cd $prefixllvm/include/lld; $install COFF ELF MachO wasm; cd ../../../..
    #	for dir in COFF ELF MachO wasm; do ln $buildllvm/tools/lld/$dir/Options.inc $prefixllvm/include/lld/$dir; done
    #	ln $buildllvm/tools/lld/include/lld/Common/Version.inc $prefixllvm/include/lld/Common
    #	rm -rf .build/include .build/libzstd.a; mv $prefixllvm/include .build/include; mv $prefixzstd/include .build/include/zstd
    #	mv $prefixzstd/lib/libzstd.a .build; rm -rf $prefixzstd &
    #} &
    #{
    #	cd $prefixllvm/lib
    #	for lib in *.a; do { dir=${lib%%.a}; $install $dir; cd $dir; llvm-ar -x ../$lib; } & done; wait; rm -- *.a
    #	for dir in $(echo * | LC_ALL=C sort); do { du -csh $(echo $dir/* | LC_ALL=C sort); echo; } done
    #	set -- $(echo */* | LC_ALL=C sort); [ -e ../../libLLVM.a ] && rm ../../libLLVM.a
    #	llvm-ar rcs ../../libLLVM.a "$@"; rm -rf ../../installllvm &
    #	printf -- '--------------------------------------------------------\n %s    objects archived   %s    total bytes\n' \
    #		$# "$(wc -c < ../../libLLVM.a)"
    #} &
    #wait
}

build() { true; }

settings "$@"; libs; build
