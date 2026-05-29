#!/bin/sh
set -eu; umask 0022; tabs -4; install='install -dm 0755'; $install .build
polly="-mllvm -polly -mllvm -polly-vectorizer=stripmine"
flags="-pipe -flto=thin"

set -- -Wno-dev -G Ninja \
    -DCMAKE_BUILD_TYPE=Release \
    -DCMAKE_AR="$(command -v llvm-ar)" \
    -DCMAKE_LINKER="$(command -v ld64.lld)" \
    -DCMAKE_C_COMPILER="$(command -v clang)" \
    -DCMAKE_CXX_COMPILER="$(command -v clang++)" \
    -DCMAKE_OSX_SYSROOT="$(xcrun --show-sdk-path)" \
    -DCMAKE_CXX_FLAGS_RELEASE="-O3 $polly $flags" \
    -DCMAKE_C_FLAGS_RELEASE="-O3 $polly $flags" \
    -DCMAKE_EXE_LINKER_FLAGS_RELEASE="-O3" \
    -DCMAKE_CXX_FLAGS_MINSIZEREL="-Oz $flags" \
    -DCMAKE_C_FLAGS_MINSIZEREL="-Oz $flags" \
    -DCMAKE_EXE_LINKER_FLAGS_MINSIZEREL="-O3" \
    -DCMAKE_OBJCOPY=false \
    -DCMAKE_RANLIB=false \
    -DCMAKE_NM=false

buildzstd=.build/.build-zstd
prefixzstd=.build/.install-zstd

$install $buildzstd; cmake -S vendor/zstd-*/build/cmake -B $buildzstd "$@" \
    -DZSTD_MULTITHREAD_SUPPORT=ON \
    -DZSTD_LEGACY_SUPPORT=OFF \
    -DZSTD_BUILD_PROGRAMS=OFF \
    -DZSTD_BUILD_SHARED=OFF \
    -DCMAKE_INSTALL_PREFIX=$prefixzstd; echo

rm -rf $prefixzstd; ninja -C $buildzstd libzstd.a
ninja -C $buildzstd install >/dev/null; echo

buildllvm=.build/.build-llvm
prefixllvm=.build/.install-llvm

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
    -DLLVM_ENABLE_ZLIB=OFF \
    -DLLVM_ENABLE_ZSTD=ON \
    -DLLVM_INCLUDE_DOCS=OFF \
    -DLLVM_INCLUDE_TESTS=OFF \
    -DLLVM_INCLUDE_EXAMPLES=OFF \
    -DLLVM_INCLUDE_BENCHMARKS=OFF \
    -DCOMPILER_RT_BUILD_XRAY=OFF \
    -DCOMPILER_RT_BUILD_PROFILE=OFF \
    -DCOMPILER_RT_BUILD_BUILTINS=ON \
    -DCOMPILER_RT_BUILD_SANITIZERS=ON \
    -DLLVM_ENABLE_PROJECTS="clang;lld;polly" \
    -DLLVM_ENABLE_RUNTIMES="compiler-rt;openmp" \
    -DLLVM_TARGETS_TO_BUILD="X86;AArch64;ARM;RISCV;WebAssembly;LoongArch" \
    -DCMAKE_PREFIX_PATH=$prefixzstd \
    -DCMAKE_INSTALL_PREFIX=$prefixllvm; echo

rm -rf $prefixllvm; ninja -C $buildllvm \
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

{
    cd $prefixllvm/include/lld; $install COFF ELF MachO wasm; cd ../../../..
    for dir in COFF ELF MachO wasm; do ln $buildllvm/tools/lld/$dir/Options.inc $prefixllvm/include/lld/$dir; done
    ln $buildllvm/tools/lld/include/lld/Common/Version.inc $prefixllvm/include/lld/Common
    rm -rf .build/include .build/libzstd.a; mv $prefixllvm/include .build/include; mv $prefixzstd/include .build/include/zstd
    mv $prefixzstd/lib/libzstd.a .build; rm -rf $prefixzstd &
} &
{
    cd $prefixllvm/lib
    for lib in *.a; do { dir=${lib%%.a}; $install $dir; cd $dir; llvm-ar -x ../$lib; } & done; wait; rm -- *.a
    for dir in $(echo * | LC_ALL=C sort); do { du -csh $(echo $dir/* | LC_ALL=C sort); echo; } done
    set -- $(echo */* | LC_ALL=C sort); [ -e ../../libLLVM.a ] && rm ../../libLLVM.a
    llvm-ar rcs ../../libLLVM.a "$@"; rm -rf ../../.install-llvm &
    printf -- '--------------------------------------------------------\n %s    objects archived   %s    total bytes\n' \
        "$#" "$(wc -c < ../../libLLVM.a)"
} &
wait
