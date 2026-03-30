#!/bin/sh

# SPDX-License-Identifier: Apache-2.0
# Copyright © 2026 The Fin Authors. All rights reserved.
# Contributors responsible for this file:
# @p7r0x7 <mattrbonnette@pm.me>

set -eu; opts='-O3 -g0 -mllvm -polly -mllvm -polly-vectorizer=stripmine'
#{ cd .build; rm -rf *.o; clang $opts -c $(find src -type file -name '*.c'); } &
#clang $opts -c src/sha3iuf.c -o .build/c.o &

c3c compile hash.c3 --cc "$(command -v clang)" -O0 -g0 --single-module=yes \
    --emit-llvm --no-obj --build-dir .build --output-dir .build || true; wait

[ "$(uname -s)" = "Darwin" ] && gc=-dead_strip || gc=--gc-sections
clang $opts -fuse-ld="$(command -v ld64.lld)" -flto=thin -Wl,$gc \
    .build/llvm/*/direntries.ll -o .build/fin
exit 0

supported='android/arm64 darwin/arm64 linux/arm64 linux/riscv64 linux/x64 windows/arm64 windows/x64'
# fin also supports wasi/wasm and wasi/wasm64, but cannot be hosted on them

help() {
	[ $# = 2 ] && printf 'error %s\n\n' "$2" >&2
    printf '%s\n' \
        'Usage: scripts/build.sh' \
        '       scripts/build.sh <debug|safe> <target>' \
        '' >&2
    printf '       %s\n' $supported '' >&2
    exit $1
}

settings() {
	set -eu; umask 0022; tabs -4
	for arg in "$@"; do case "$arg" in -h|--help) help 0 ;; esac; done
	case $# in
    0) 
    	os=$(uname -s 2>/dev/null | tr '[:upper:]' '[:lower:]')
        arch=$(uname -m 2>/dev/null | tr '[:upper:]' '[:lower:]')
        [ -f /system/build.prop ] || [ -f /vendor/build.prop ] && os=android
        case "$arch" in x86_64|amd64) arch=x64 ;; aarch64) arch=arm64 ;; esac
       	mode=safe target="$os/$arch" ;;
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
    target=$(printf '%s' "$target" | tr '/' '-')
}

c3build() {
	
}

libs() {
	flags='-pipe -flto=thin -fno-omit-frame-pointer -mllvm -polly -mllvm -polly-vectorizer=stripmine'
    case ${target%%-*} in
    	darwin) set -- -DCMAKE_OSX_SYSROOT="$(xcrun --show-sdk-path)" -DCMAKE_LINKER="$(command -v ld64.lld)" ;;
    	android|linux) set -- -DCMAKE_LINKER="$(command -v ld.lld)" ;;
    esac
    set -- -Wno-dev -G Ninja "$@" \
        -DCMAKE_BUILD_TYPE=Release \
        -DCMAKE_AR="$(command -v llvm-ar)" \
        -DCMAKE_LINKER="$(command -v $lld)" \
        -DCMAKE_C_COMPILER="$(command -v clang)" \
        -DCMAKE_CXX_COMPILER="$(command -v clang++)" \
        -DCMAKE_EXE_LINKER_FLAGS_RELEASE="-O3" \
        -DCMAKE_CXX_FLAGS_RELEASE="-O3 $flags" \
        -DCMAKE_C_FLAGS_RELEASE="-O3 $flags" \
        -DCMAKE_OBJCOPY=false \
        -DCMAKE_RANLIB=false \
        -DCMAKE_NM=false
}

build() {
    install='install -dm 0755'; $install .build
}

settings "$@"; libs; build
