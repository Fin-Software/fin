#!/bin/sh

# SPDX-License-Identifier: Apache-2.0
# Copyright © 2026 The Fin Authors. All rights reserved.
# Contributors responsible for this file:
# @p7r0x7 <maxibonnette@pm.me>

vendor='4Mw4k/XHD1iWlCsAjs3T1/aU3kgt9D5vCfjWrPEd6Ko='  # CODE REVIEW POISON
flags="-pipe -fuse-ld=lld -O3 -mllvm -polly -mllvm -polly-vectorizer=stripmine
    -Wno-unused-command-line-argument -fno-omit-frame-pointer -fno-rtti -DNDEBUG"
# fin also supports wasi/wasm and wasi/wasm64, but won't be made hostable on them
supported='android/arm64 darwin/arm64 linux/arm64 linux/riscv64 linux/x64 windows/arm64 windows/x64'
bar=----------------------------------------------------------------------------------------------------

help() {
    [ $# = 2 ] && printf 'error: %s\n\n' "$2" >&2
    printf '%s\n' \
        'Usage: scripts/build.sh' \
        '       scripts/build.sh <debug|safe> <target>' \
        '' >&2
    printf '       %s\n' $supported '' >&2; exit $1
}

settings() {
    set -eu; umask 0022; install='install -dm 0755'; $install .build
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
        darwin/arm64)  triple=aarch64-apple-darwin ;;
        linux/arm64)   triple=aarch64-linux-gnu ;;
        linux/riscv64) triple=riscv64-linux-gnu ;;
        linux/x64)     triple=x86_64-linux-gnu ;;
        windows/arm64) triple=aarch64-pc-windows-msvc ;;
        windows/x64)   triple=x86_64-pc-windows-msvc ;;
        *) help 1 "$(printf 'target %s unsupported' "$target" )" ;;
    esac
    [ ${target%/*} = windows ] && stdlib= || stdlib=-stdlib=libc++
    [ ${target%/*} = darwin ] && gc=-dead_strip || gc=--gc-sections
    target=${target%/*}-${target#*/}
}

libs() {
    prefix=.build/$target/prefix; [ -f .build/hash ] || {
        c3c compile-only hash.c3 -O0 -g0 --single-module=yes --no-obj --emit-llvm --llvm-out .build/build/hash
        clang $flags -Wl,$gc .build/build/hash/* -o .build/hash; rm -rf .build/build; echo
    }
    [ -f .build/$target/checksum ] && [ "$(.build/hash $prefix)" = "$(cat .build/$target/checksum)" ] && return 0
    [ "$(.build/hash vendor)" = $vendor ] || { printf 'error: corrupted vendor/\n'; exit 1; }
    rm -rf .build/$target/build/fin $prefix; $install .build/$target/build $prefix

    _start=$(date +%s)
    set -- -Wno-dev -G Ninja \
        -DCMAKE_OSX_SYSROOT="" \
        -DCMAKE_BUILD_TYPE=Release \
        -DCMAKE_C_COMPILER_TARGET=$triple \
        -DCMAKE_AR="$(command -v llvm-ar)" \
        -DCMAKE_CXX_COMPILER_TARGET=$triple \
        -DCMAKE_C_COMPILER="$(command -v clang)" \
        -DCMAKE_C_FLAGS="$(printf '%s ' $flags)" \
        -DCMAKE_CXX_COMPILER="$(command -v clang++)" \
        -DCMAKE_CXX_FLAGS="$stdlib $(printf '%s ' $flags)" \
        -DCMAKE_OBJCOPY=false -DCMAKE_RANLIB=false -DCMAKE_NM=false

    buildzstd=.build/$target/build/zstd; $install $buildzstd; cmake -S vendor/zstd-*/build/cmake -B $buildzstd "$@" \
        -DZSTD_BUILD_SHARED=OFF \
        -DZSTD_BUILD_PROGRAMS=OFF \
        -DZSTD_LEGACY_SUPPORT=OFF \
        -DZSTD_MULTITHREAD_SUPPORT=ON \
        -DCMAKE_INSTALL_PREFIX=$prefix; echo

    ninja -C $buildzstd; ninja -C $buildzstd install >/dev/null; echo

    buildzlib=.build/$target/build/zlib; $install $buildzlib; cmake -S vendor/zlib-* -B $buildzlib "$@" \
        -DZLIB_COMPAT=ON \
        -DBUILD_TESTING=OFF \
        -DWITH_REDUCED_MEM=ON \
        -DBUILD_SHARED_LIBS=OFF \
        -DCMAKE_INSTALL_PREFIX=$prefix; echo

    ninja -C $buildzlib; ninja -C $buildzlib install >/dev/null; echo

    mv $prefix/lib64 $prefix/lib 2>/dev/null || true
    find $prefix/lib -name 'ZLIB' -exec mv {} $prefix/lib/libz.a \;
    find $prefix/lib -name 'zstd' -exec mv {} $prefix/lib/libzstd.a \;

    buildllvm=.build/$target/build/llvm; $install $buildllvm; cmake -S vendor/llvm-*/llvm -B $buildllvm "$@" \
        -DLLD_VENDOR="fin" \
        -DCLANG_VENDOR="fin " \
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

    components='clangFrontendTool lldCOFF lldCommon lldELF lldMachO lldWasm LLVMFrontendOpenMP LLVMOrcJIT Polly'
    ninja -C $buildllvm $components; echo; $install $prefix/lib $prefix/include/lld/Common
    {
        ninja -C $buildllvm $(printf 'install-%s-headers ' clang clang-resource lld llvm) >/dev/null
        rm -rf $prefix/../lib; $install $prefix/../lib; mv $prefix/lib/clang $prefix/../lib
        cd $prefix/include/lld; $install COFF ELF MachO wasm; cd ../../../../..
        for dir in COFF ELF MachO wasm; do ln $buildllvm/tools/lld/$dir/Options.inc $prefix/include/lld/$dir; done
        ln $buildllvm/tools/lld/include/lld/Common/Version.inc $prefix/include/lld/Common
    } &
    cd $buildllvm/lib && {
        echo 'create ../../../prefix/lib/libClangJIT.a'
        for lib in *.a *.lib; do [ -f $lib ] && echo "addlib $lib"; done
        printf 'save\nend\n'
    } | llvm-ar -M &
    wait; _elapsed=$(($(date +%s) - _start))

    .build/hash $prefix >.build/$target/checksum
    #find .build/$target/build \( -name '*.o' -o -name '*.a' -o -name '*.lib' \) -delete &
    _count=$(find $prefix/lib \( -name '*.a' -o -name '*.lib' \) -exec llvm-ar t {} \; | grep -c '\.o$')
    printf '%s\n    %d objects compiled for %s in %dm%ds\n\n' $bar $_count $target $((_elapsed / 60)) $((_elapsed % 60))
}

build() {
    set -m; root=$PWD out=$root/.build/$target
    $install $out/build/fin $out/bin; cd $out/build/fin
    cxx="clang++ -c $flags $stdlib -I$out/prefix/include"
    case $mode in safe) mode=-g0 ;; debug) mode=-g ;; esac
    
    c3c compile-only -O0 $mode --single-module=yes --no-obj --emit-llvm --llvm-out . \
        $(find $root/src -name '*.c3') && clang++ -c $flags -UNDEBUG fin.ll && rm fin.ll &
    for flavor in COFF ELF MachO wasm; do
        $cxx -I$out/prefix/include/lld/$flavor $root/vendor/llvm-*/lld/$flavor/Driver.cpp -o lld_$flavor.o &
    done
    for src in cc1_main cc1as_main; do $cxx $root/vendor/llvm-*/clang/tools/driver/$src.cpp & done
    for src in $(find $root/src -name '*.cc'); do $cxx $src & done

    set +m; wait; clang++ -fuse-ld=lld -Wl,$gc * $root/$prefix/lib/*.a -o $out/bin/fin
    #set +m; wait; clang++ -fuse-ld=lld -Wl,--lto-O0 * $root/$prefix/lib/*.a -o $out/bin/fin
}

settings "$@"; libs; build
