#!/bin/sh

# SPDX-License-Identifier: Apache-2.0
# Copyright © 2026 The Fin Authors. All rights reserved.
# Contributors responsible for this file:
# @p7r0x7 <maxibonnette@pm.me>

supported='android/arm64 darwin/arm64 linux/arm64 linux/riscv64 linux/x64 windows/arm64 windows/x64'
# fin also supports wasi/wasm and wasi/wasm64, but won't be hostable on them

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
    [ ${target%/*} = darwin ] && gc=-dead_strip || gc=--gc-sections
}

libs() {
    _flags='-pipe -Wno-unused-command-line-argument -fno-omit-frame-pointer
        -O3 -fuse-ld=lld -flto=thin -mllvm -polly -mllvm -polly-vectorizer=stripmine'

    [ -f .build/hash ] || {
        c3c compile-only hash.c3 -O0 -g0 --single-module=yes --emit-llvm --no-obj --llvm-out /tmp/fin
        clang $_flags -Wl,$gc /tmp/fin/*.ll -o .build/hash
    }
    [ "$(.build/hash vendor)" = 'F4A5KDNBEClzDoGXZ9NCq8irGBVrwwZJQYQl5pR/f7w=' ]  # CODE REVIEW POISON
    libcpp=$(clang -print-resource-dir); libcpp="-isystem ${libcpp%/lib/clang/*}/include/c++/v1"
    target=${target%/*}-${target#*/}; $install .build/$target/build
    prefix=.build/$target/prefix; $install $prefix

    set -- -Wno-dev -G Ninja \
        -DCMAKE_BUILD_TYPE=Release \
        -DCMAKE_C_COMPILER_TARGET=$triple \
        -DCMAKE_CXX_COMPILER_TARGET=$triple \
        -DCMAKE_AR="$(command -v llvm-ar)" \
        -DCMAKE_C_COMPILER="$(command -v clang)" \
        -DCMAKE_CXX_COMPILER="$(command -v clang++)" \
        -DCMAKE_C_FLAGS_RELEASE="$(printf '%s ' $_flags)" \
        -DCMAKE_CXX_FLAGS_RELEASE="-nostdinc++ $libcpp $(printf '%s ' $_flags)" \
        -DCMAKE_OBJCOPY=false -DCMAKE_RANLIB=false -DCMAKE_NM=false

    buildzstd=.build/$target/build/zstd; $install $buildzstd; cmake -S vendor/zstd-*/build/cmake -B $buildzstd "$@" \
        -DZSTD_BUILD_SHARED=OFF \
        -DZSTD_BUILD_PROGRAMS=OFF \
        -DZSTD_LEGACY_SUPPORT=OFF \
        -DZSTD_MULTITHREAD_SUPPORT=ON \
        -DCMAKE_INSTALL_PREFIX=$prefix; echo

    ninja -C $buildzstd install; echo

    buildzlib=.build/$target/build/zlib; $install $buildzlib; cmake -S vendor/zlib-* -B $buildzlib "$@" \
        -DZLIB_COMPAT=ON \
        -DBUILD_TESTING=OFF \
        -DWITH_REDUCED_MEM=ON \
        -DBUILD_SHARED_LIBS=OFF \
        -DCMAKE_INSTALL_PREFIX=$prefix; echo

    ninja -C $buildzlib install; echo

    buildllvm=.build/$target/build/llvm; $install $buildllvm; cmake -S vendor/llvm-*/llvm -B $buildllvm "$@" \
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
        -DZLIB_LIBRARY=$prefix/lib/libz.a \
        -DZLIB_INCLUDE_DIR=$prefix/include \
        -Dzstd_LIBRARY=$prefix/lib/libzstd.a \
        -Dzstd_INCLUDE_DIR=$prefix/include \
        -DLLVM_ENABLE_PROJECTS="clang;lld;polly" \
        -DLLVM_ENABLE_RUNTIMES="compiler-rt;openmp" \
        -DLLVM_TARGETS_TO_BUILD="X86;AArch64;ARM;RISCV;WebAssembly" \
        -DLLVM_DEFAULT_TARGET_TRIPLE=$triple \
        -DCMAKE_INSTALL_PREFIX=$prefix; echo

    ninja -C $buildllvm $(printf 'install-%s ' \
        clangDriver lldCOFF lldCommon lldELF lldMachO lldWasm LLVMFrontendOpenMP LLVMOrcJIT Polly)

    ninja -C $buildllvm $(printf 'install-%s-headers ' llvm clang lld clang-resource) >/dev/null; echo

    #{
    #   cd $prefixllvm/include/lld; $install COFF ELF MachO wasm; cd ../../../..
    #   for dir in COFF ELF MachO wasm; do ln $buildllvm/tools/lld/$dir/Options.inc $prefixllvm/include/lld/$dir; done
    #   ln $buildllvm/tools/lld/include/lld/Common/Version.inc $prefixllvm/include/lld/Common
    #   rm -rf .build/include .build/libzstd.a; mv $prefixllvm/include .build/include; mv $prefixzstd/include .build/include/zstd
    #   mv $prefixzstd/lib/libzstd.a .build; rm -rf $prefixzstd &
    #} &
    #{
    #   cd $prefixllvm/lib
    #   for lib in *.a; do { dir=${lib%%.a}; $install $dir; cd $dir; llvm-ar -x ../$lib; } & done; wait; rm -- *.a
    #   for dir in $(echo * | LC_ALL=C sort); do { du -csh $(echo $dir/* | LC_ALL=C sort); echo; } done
    #   set -- $(echo */* | LC_ALL=C sort); [ -e ../../libLLVM.a ] && rm ../../libLLVM.a
    #   llvm-ar rcs ../../libLLVM.a "$@"; rm -rf ../../installllvm &
    #   printf -- '--------------------------------------------------------\n %s    objects archived   %s    total bytes\n' \
    #       $# "$(wc -c < ../../libLLVM.a)"
    #} &
    #wait
}

build() { true; }

settings "$@"; libs; build
