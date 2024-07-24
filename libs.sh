#!/bin/sh

# SPDX-License-Identifier: Apache-2.0
# Copyright © 2024 The Whixy Authors. All rights reserved.
# Contributors responsible for this file:
# @p7r0x7 <mattrbonnette@pm.me>

set_dep_paths()
{
	status=0
	for arg; do
		if [ -n "$arg" ]; then continue; fi
		eval "readonly $arg=$(command -v "$arg")"
		if eval "[ -z \$$arg ]"; then
			if [ "$status" -eq 0 ]; then printf "\n\tRequired commands not found in PATH:"; fi
			printf " %s" "$arg" && status=1
		fi
	done && if [ "$status" -eq 1 ]; then printf "\n\n" && exit 1; fi
}

build_static_zstd()
{
	set_dep_paths cmake ninja zig
}

build_static_antlr_runtime()
{
	set_dep_paths cmake jar java ninja zig
}

build_static_cross_llvm_libs()
{
	set_dep_paths cmake ninja python3 zig

	read -r options <<-EOF
		-B=llvm/llvm/build -S=llvm/llvm -DCMAKE_BUILD_TYPE=Release -DCMAKE_SYSTEM_NAME=$cmake_target
		-DCMAKE_C_COMPILER=$zig;cc;-fno-sanitize=all;-s;-target;$triple;-mcpu=$mcpu
		-DCMAKE_CXX_COMPILER=$zig;c++;-fno-sanitize=all;-s;-target;$triple;-mcpu=$mcpu
		-DCMAKE_ASM_COMPILER=$zig;cc;-fno-sanitize=all;-s;-target;$triple;-mcpu=$mcpu
		-DCMAKE_RANLIB=$zig;ranlib;-fno-sanitize=all;-s;-target;$triple;-mcpu=$mcpu
		-DCMAKE_AR=$zig;ar;-fno-sanitize=all;-s;-target;$triple;-mcpu=$mcpu
		-DLLVM_DEFAULT_TARGET_TRIPLE=$triple -DLLVM_ENABLE_LTO=Thin -DLLVM_ENABLE_LLD=ON
		-DLLVM_OPTIMIZED_TABLEGEN=ON -DLLVM_BUILD_STATIC=ON -DLLVM_UNREACHABLE_OPTIMIZE=ON
	EOF

	if [ "$cmake_target" = "Windows" ]; then
		options="$options -DCMAKE_RC_COMPILER=$zig;rc;-fno-sanitize=all;-s;-target;$triple;-mcpu=$mcpu"
	fi

	if [ "$safety" = safe ]; then safe=ON; elif [ "$safety" = fast ]; then safe=OFF; else printf "" && exit 1; fi
	readonly safe
	options="$options -DLLVM_ENABLE_EH=$safe -DLLVM_ENABLE_RTTI=$safe -DLLVM_ENABLE_UNWIND_TABLES=$safe -DLLVM_ENABLE_PEDANTIC=$safe"

	for arg in $llvm_projects; do
		if [ "$arg" = llvm ] || [ "$arg" = third-party ]; then continue; fi
		projects="$projects;$arg"
		upper="$(printf %s "$arg" | tr '[:lower:]' '[:upper:]')"
		options="$options -DLLVM_EXTERNAL_${upper}_SOURCE_DIR=$arg"
	done
	options="$options -DLLVM_EXTERNAL_PROJECTS=${projects#?}"

	for arg in $llvm_runtimes; do
		runtimes="$runtimes;$arg"
		upper="$(printf %s "$arg" | tr '[:lower:]' '[:upper:]')"
		options="$options -DLLVM_EXTERNAL_${upper}_SOURCE_DIR=$arg"
	done
	options="$options -DLLVM_EXTERNAL_RUNTIMES=${runtimes#?}"

	"$cmake" -G Ninja $options \
		-DLLVM_ENABLE_LIBCXX=ON -DLLVM_ENABLE_BACKTRACES=OFF \
		-DLLVM_ENABLE_BINDINGS=OFF -DLLVM_ENABLE_CRASH_OVERRIDES=OFF \
		-DLLVM_ENABLE_LIBEDIT=OFF -DLLVM_ENABLE_LIBPFM=OFF \
		-DLLVM_ENABLE_LIBXML2=OFF -DLLVM_ENABLE_OCAMLDOC=OFF \
		-DLLVM_ENABLE_PLUGINS=OFF -DLLVM_ENABLE_TERMINFO=OFF \
		-DLLVM_ENABLE_Z3_SOLVER=OFF -DLLVM_ENABLE_ZLIB=OFF \
		-DLLVM_ENABLE_ZSTD=OFF -DLLVM_USE_STATIC_ZSTD=OFF \
		-DLLVM_BUILD_UTILS=OFF -DLLVM_BUILD_TOOLS=OFF \
		-DLLVM_INCLUDE_UTILS=OFF \
		-DLLVM_INCLUDE_TESTS=OFF -DLLVM_INCLUDE_EXAMPLES=OFF \
		-DLLVM_INCLUDE_BENCHMARKS=OFF -DLLVM_INCLUDE_DOCS=OFF
	"$ninja" -C llvm/llvm/build
}

cleanup()
{
	rm -rf llvm >/dev/null &
	exit 1
}

if [ ! -d llvm ]; then
	set -ex
	trap cleanup INT HUP TERM

	readonly llvm_runtimes="compiler-rt libunwind" # to be used unquoted
	readonly llvm_projects="clang lld llvm polly"  # to be used unquoted

	readonly safety="$1"       # safe or fast
	readonly triple="$2"       # Example: riscv64-linux-gnu
	readonly mcpu="$3"         # Example: native, rv64imafdc
	cmake_target=${triple#*-}  # Example: linux-gnu
	case ${cmake_target%-*} in # Example: linux
		macos) cmake_target="Darwin" ;;
		freebsd) cmake_target="FreeBSD" ;;
		windows) cmake_target="Windows" ;;
		linux) cmake_target="Linux" ;;
		native) cmake_target="" ;;
	esac && readonly cmake_target

	build_static_zstd            # for linking
	build_static_antlr_runtime   # for linking
	build_static_cross_llvm_libs # for linking
fi
