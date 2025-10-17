#!/bin/sh
set -eu; umask 0022; install='install -dm 0755'

buildzstd=.build/.build-zstd
srcszstd=vendor/zstd-*/build/cmake
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

$install $buildzstd; cmake -S $srcszstd -B $buildzstd "$@" \
    -DZSTD_MULTITHREAD_SUPPORT=ON \
    -DZSTD_LEGACY_SUPPORT=OFF \
    -DZSTD_BUILD_PROGRAMS=OFF

ninja -C $buildzstd libzstd.a
mv $buildzstd/lib/libzstd.a .build

buildllvm=.build/.build-llvm
prefixllvm=.build/.install-llvm
srcsllvm=vendor/llvm-*/llvm

$install $buildllvm; cmake -S $srcsllvm -B $buildllvm "$@" \
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
    -DLLVM_USE_STATIC_ZSTD=ON \
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
    -DLLVM_TARGETS_TO_BUILD="X86;AArch64;RISCV;WebAssembly;LoongArch" \
    -DCMAKE_INSTALL_PREFIX=$prefixllvm

rm -rf $prefixllvm; ninja -C $buildllvm \
    install-clangDriver install-lld-libraries install-LLVMOrcJIT install-Polly install-LLVMFrontendOpenMP

ninja -C $buildllvm install-llvm-headers install-clang-headers install-lld-headers >/dev/null

cd $prefixllvm/include/lld; $install COFF ELF MachO wasm; cd ../../../..
ln $buildllvm/tools/lld/include/lld/Common/Version.inc $prefixllvm/include/lld/Common
ln $buildllvm/tools/lld/COFF/Options.inc $prefixllvm/include/lld/COFF
ln $buildllvm/tools/lld/ELF/Options.inc $prefixllvm/include/lld/ELF
ln $buildllvm/tools/lld/MachO/Options.inc $prefixllvm/include/lld/MachO
ln $buildllvm/tools/lld/wasm/Options.inc $prefixllvm/include/lld/wasm
cd $prefixllvm/lib
for lib in *.a; do { dir="${lib%%.a}"; $install $dir; cd $dir; llvm-ar -x ../$lib; cd ..; rm $lib; } & done
wait
set -- */*.o
du -csh "$@"
printf -- '--------------------------------------------------------\n %s\tobjects archived\n' "$#"
rm -rf ../../include ../../libLLVM.a
llvm-ar rcs ../../libLLVM.a "$@"
mv ../include ../../
cd ../../..
rm -rf $prefixllvm
