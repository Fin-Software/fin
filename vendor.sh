#!/bin/sh

# SPDX-License-Identifier: Apache-2.0
# Copyright © 2024 The Whixy Authors. All rights reserved.
# Contributors responsible for this file:
# @p7r0x7 <mattrbonnette@pm.me>

# vendor.tzst must be altered in the VCS when this script (that publicly defines its deterministic generation) changes.
# And for security reasons, only @p7r0x7 may sign and push commits changing this script and vendor.tzst.
# Because this script is not needed for the standard build process, it was not translated for Windows.

teardown()
{
	rm -rf "$vendor" "$srcs" "$tball" >/dev/null &
	exit
}

startup()
{
	set -eu && trap teardown INT HUP TERM EXIT && readonly vendor=/tmp/vendor srcs=/tmp/srcs tball=/tmp/vendor.tar tzst=vendor.tzst

	readonly hash=5a78ce85329e9a937ca94a5e921b15c9ef2b4cf3677bb6dadbf757413b576516
	[ "$(basename "$PWD")" = "whixy" ] || { printf "Please, execute %s from the Whixy monorepo.\n" "$(basename "$0")" && exit 1; }
	[ -f "$tzst" ] && [ "$(zstdmt -cd "$tzst" --long=29 | b3sum)" = "$hash  -" ] && zstdmt -lv "$tzst" && exit 0

	command -v gtar >/dev/null && tar() { command gtar "$@"; }
	install() { command install -dm 0744 "$@"; } && curl() { command curl -sL "$@"; }
	tar --version | awk '{exit ($4 >= 1.28) ? 0 : 1}' || { printf "GNU tar too old." && exit 1; }

	rm -rf "$vendor" "$srcs" "$tball" "$tzst" >/dev/null
	install "$vendor" "$srcs"
}

finish()
{
	find "$vendor" -name '.[!.]*' -exec rm -rf {} +
	tar --pax-option=exthdr.name=%d/PaxHeaders/%f,delete=atime,delete=ctime --sort=name \
		--mtime="@0" --owner=0 --group=0 --numeric-owner -S --no-seek -cf "$tball" -C "$vendor" .

	b3sum "$tball"
	#brotli -q 11 --large_window=28 -n "$tball" -o vendor.tbr
	#7zz a -txz -mx9 -md=256m -mfb=273 -mpb=1 -mlp=0 -mlc=4 vendor.txz "$tball"
	zstdmt --ultra -22 --long=29 --no-check "$tball" -o "$tzst"
	zstdmt -lv "$tzst"
}

startup
#{
#	readonly gcc_semv=14.1.0
#	readonly gcc_url="https://ftp.gnu.org/gnu/gcc/gcc-$gcc_semv"
#
#	base="gcc-$gcc_semv.tar.xz"
#	{
#		[ -f "$srcs/$base" ] || curl "$gcc_url/$base" -o "$srcs/$base"
#		# TODO(@p7r0x7): Check the source's integrity and decompress with 7zz if available.
#		tar -xJf "$srcs/$base" -C "$vendor" --strip-components=1
#	}
#}
{
	readonly llvm_semv=18.1.8
	readonly llvm_url="https://github.com/llvm/llvm-project/releases/download/llvmorg-$llvm_semv"
	readonly llvm_deps="clang cmake compiler-rt libunwind lld llvm polly runtimes third-party"

	base="llvm-project-$llvm_semv.src.tar.xz"
	{
		[ -f "$srcs/$base" ] || curl "$llvm_url/$base" -o "$srcs/$base"
		# TODO(@p7r0x7): Check the source's integrity and decompress with 7zz if available.
		tar -xJf "$srcs/$base" -C "$vendor" --strip-components=1 \
			$(for dep in $llvm_deps; do printf "llvm-project-%s.src/%s\n" "$llvm_semv" "$dep"; done)

		for dep in $llvm_deps; do mv "$vendor/$dep" "$vendor/$dep-$llvm_semv"; done
		cd "$vendor" && rm -rf -- \
			*"-$llvm_semv/docs" *"-$llvm_semv/examples" *"-$llvm_semv/benchmark"* *"-$llvm_semv/test" \
			"llvm-$llvm_semv/bindings" "compiler-rt-$llvm_semv/www"
	} &
}
{
	readonly antlr_semv=4.13.1 antlr_url=https://www.antlr.org/download

	base="antlr-$antlr_semv-complete.jar"
	{
		[ -f "$srcs/$base" ] || curl "$antlr_url/$base" -o "$srcs/$base"
		# TODO(@p7r0x7): Check the source's integrity.
		unzip -q "$srcs/$base" -d "$vendor/antlr-$antlr_semv"
	} &

	base="antlr4-cpp-runtime-$antlr_semv-source.zip"
	{
		[ -f "$srcs/$base" ] || curl "$antlr_url/$base" -o "$srcs/$base"
		# TODO(@p7r0x7): Check the source's integrity.
		install "$vendor/antlr-cpp-runtime-$antlr_semv"
		unzip -q "$srcs/$base" -d "$vendor/antlr-cpp-runtime-$antlr_semv"

		rm -rf "$vendor/antlr-cpp-runtime-$antlr_semv/demo"
	} &
}
{
	readonly zstd_semv=1.5.6
	readonly zstd_url="https://github.com/facebook/zstd/releases/download/v$zstd_semv"

	base="zstd-$zstd_semv.tar.zst"
	{
		[ -f "$srcs/$base" ] || curl "$zstd_url/$base" -o "$srcs/$base"
		# TODO(@p7r0x7): Check the source's integrity.
		install "$vendor/zstd-$zstd_semv"
		zstdmt -cd "$srcs/$base" | tar -xf - --strip-components=1 -C "$vendor/zstd-$zstd_semv"

		cd "$vendor/zstd-$zstd_semv" && rm -rf contrib doc examples programs zlibWrapper lib/legacy tests
	} &
}
wait

finish
