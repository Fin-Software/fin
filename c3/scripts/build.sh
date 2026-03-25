#!/bin/sh

supported='
    android/arm64
    darwin/arm64
    wasi/wasm
    wasi/wasm64
    freebsd/arm64
    freebsd/riscv64
    freebsd/x64
    linux/arm64
    linux/loong64
    linux/riscv64
    linux/x64
    windows/arm64
    windows/x64'

help() {
    printf '%s\n' \
        'Usage: scripts/build.sh' \
        '       scripts/build.sh <debug|safe> <target>'
    printf '    %s\n' $supported
    exit $1
}
build() {
    set -eu; install='install -dm 0755'; $install .build
    case "$target" in
        android/arm64)        target=android-aarch64 ;;
        darwin/arm64)         target=macos-aarch64 ;;
        freestanding/arm64)   target=elf-aarch64 ;;
        freestanding/loong64) exit 11 ;;
        freestanding/riscv64) target=elf-riscv64 ;;
        freestanding/x64)     target=elf-x64 ;;
        freestanding/wasm)    target=wasm32 ;;
        freestanding/wasm64)  target=wasm64 ;;
        freebsd/arm64)        exit 12 ;;
        freebsd/riscv64)      exit 13 ;;
        freebsd/x64)          target=freebsd-x64 ;;
        linux/arm64)          target=linux-aarch64 ;;
        linux/loong64)        exit 14 ;;
        linux/riscv64)        target=linux-riscv64 ;;
        linux/x64)            target=linux-x64 ;;
        windows/arm64)        target=windows-aarch64 ;;
        windows/x64)          target=windows-x64 ;;
    esac

    [ -n "${target-}" ] || target=
}

case "$#" in
    0) {
        mode=safe target=


    } ;;
    2) {
        mode="$1" target="$2"


    } ;;
    *) help 1 ;;
esac


opts='-O3 -g0 -mllvm -polly -mllvm -polly-vectorizer=stripmine
    -fomit-frame-pointer -ffunction-sections -fdata-sections'

#{ cd .build; rm -rf *.o; clang $opts -c $(find ../src -type file -name '*.c'); } &
#clang $opts -c src/sha3iuf.c -o .build/c.o &

c3c compile src --cc "$(command -v clang)" -O0 -g0 --single-module=yes \
    --emit-llvm --no-obj --build-dir .build --output-dir .build; wait

[ "$(uname -s)" = "Darwin" ] && gc=-dead_strip || gc=--gc-sections
clang $opts -fuse-ld="$(command -v ld64.lld)" -flto=thin -Wl,$gc \
    .build/llvm/*/*.ll -o .build/fin