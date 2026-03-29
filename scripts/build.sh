#!/bin/sh

# SPDX-License-Identifier: Apache-2.0
# Copyright © 2026 The Fin Authors. All rights reserved.
# Contributors responsible for this file:
# @p7r0x7 <mattrbonnette@pm.me>

set -eu
opts='-O3 -g0 -mllvm -polly -mllvm -polly-vectorizer=stripmine
    -fomit-frame-pointer -ffunction-sections -fdata-sections'

#{ cd .build; rm -rf *.o; clang $opts -c $(find ../src -type file -name '*.c'); } &
#clang $opts -c src/sha3iuf.c -o .build/c.o &

c3c compile hash.c3 --cc "$(command -v clang)" -O0 -g0 --single-module=yes \
    --emit-llvm --no-obj --build-dir .build --output-dir .build || true; wait

[ "$(uname -s)" = "Darwin" ] && gc=-dead_strip || gc=--gc-sections
clang $opts -fuse-ld="$(command -v ld64.lld)" -flto=thin -Wl,$gc \
    .build/llvm/*/direntries.ll -o .build/fin
exit 0


supported='
    android/arm64
    darwin/arm64
    linux/arm64
    linux/riscv64
    linux/x64
    windows/arm64
    windows/x64'

# fin also supports wasi/wasm and wasi/wasm64, but cannot be hosted on them

help() {
    printf '%s\n' \
        'Usage: scripts/build.sh' \
        '       scripts/build.sh <debug|safe> <target>' \
        ''
    printf '       %s\n' $supported ''
    exit $1
}
build() {
    set -eu; install='install -dm 0755'; $install .build
    case "$target" in
        android/arm64) target=android-aarch64 ;;
        darwin/arm64)  target=macos-aarch64 ;;
        linux/arm64)   target=linux-aarch64 ;;
        linux/riscv64) target=linux-riscv64 ;;
        linux/x64)     target=linux-x64 ;;
        windows/arm64) target=windows-aarch64 ;;
        windows/x64)   target=windows-x64 ;;
        *) printf ''
    esac

    [ -n "${target-}" ] || target=
}

settings() {
	case "$#" in
    0) mode=safe target= ;;
    2) mode="$1" target="$2" ;;
    *) help 1 ;;
esac
	case "$mode" in
		safe|debug) ;;
		*) help 1 ;;
	esac
	case "$target" in
		'') {

os=$(uname -s 2>/dev/null | tr '[:upper:]' '[:lower:]')
arch=$(uname -m 2>/dev/null | tr '[:upper:]' '[:lower:]')

# Detect Android specifically
if [ -f /system/build.prop ] || [ -f /vendor/build.prop ]; then
    os=android
fi

# Normalize architecture names
case "$arch" in
    x86_64|amd64) arch=x64 ;;
    aarch64|arm64) arch=arm64 ;;
    riscv64)       arch=riscv64 ;;
esac

# Map to your target strings
case "$os/$arch" in
    android/arm64) target=android-aarch64 ;;
    darwin/arm64)  target=macos-aarch64 ;;
    linux/arm64)   target=linux-aarch64 ;;
    linux/riscv64) target=linux-riscv64 ;;
    linux/x64)     target=linux-x64 ;;
    *)             target=unknown ;;
esac

		} ;;
        android/arm64) target=android-aarch64 ;;
        darwin/arm64)  target=macos-aarch64 ;;
        linux/arm64)   target=linux-aarch64 ;;
        linux/riscv64) target=linux-riscv64 ;;
        linux/x64)     target=linux-x64 ;;
        windows/arm64) target=windows-aarch64 ;;
        windows/x64)   target=windows-x64 ;;
        *) printf ''
    esac
}

set -eu; settings "$@"; build
