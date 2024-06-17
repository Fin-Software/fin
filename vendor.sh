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
	rm -rf "$vendor" "$srcs" "$tarball" >/dev/null &
	exit
}

startup()
{
	set -e && trap teardown INT HUP TERM EXIT
	install() { command install -dm 0744 "$@"; } && curl() { command curl -sL "$@"; }
	readonly vendor=/tmp/vendor && readonly srcs=/tmp/srcs && readonly tarball=/tmp/vendor.tar && readonly tzst=vendor.tzst

	readonly hash=94ac4302b729532255dd5798fa457e4e4234fa640f2a6f91894aafd12b76a0e5
	if [ ! "$(basename "$PWD")" = "whixy" ]; then printf "Please, execute %s from the Whixy monorepo.\n" "$(basename "$0")" && exit 1; fi
	if [ -f "$tzst" ] && [ "$(zstdmt -cd "$tzst" --long=28 | b3sum)" = "$hash  -" ]; then zstdmt -lv "$tzst" && exit 0; fi

	# TODO(@p7r0x7): This could be improved, but it's probably fine...
	case "$(uname)" in
		Darwin | FreeBSD | OpenBSD | NetBSD | Dragonfly) tar() { command gtar "$@"; } ;;
	esac
	tar --version | awk '{exit ($4 >= 1.28) ? 0 : 1}' && if [ $? -eq 1 ]; then printf "GNU tar too old." && exit 1; fi

	rm -rf "$vendor" "$srcs" "$tarball" "$tzst" >/dev/null
	install "$vendor" "$srcs"
}

finish()
{
	find "$vendor" -name '.[!.]*' -exec rm -rf {} +
	tar --pax-option=exthdr.name=%d/PaxHeaders/%f,delete=atime,delete=ctime --sort=name \
		--mtime="@0" --owner=0 --group=0 --numeric-owner -S --no-seek -cf "$tarball" -C "$vendor" .

	b3sum "$tarball"
	#brotli -q 11 --large_window=28 -n "$tarball" -o vendor.tbr
	#7zz a -txz -mx9 -md=256m -mfb=273 -mpb=1 -mlp=0 -mlc=4 vendor.txz "$tarball"
	zstdmt --ultra -22 --long=28 --no-check "$tarball" -o "$tzst"
	zstdmt -lv "$tzst"
}

startup
{
	readonly llvm_semv=18.1.7
	readonly llvm_url="https://github.com/llvm/llvm-project/releases/download/llvmorg-$llvm_semv"
	readonly llvm_deps="cmake compiler-rt libunwind lld llvm mlir runtimes third-party"

	base="llvm-project-$llvm_semv.src.tar.xz"
	{
		if [ ! -f "$srcs/$base" ]; then curl "$llvm_url/$base" -o "$srcs/$base"; fi
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
	readonly antlr_semv=4.13.1
	readonly antlr_url=https://www.antlr.org/download

	base="antlr-$antlr_semv-complete.jar"
	{
		if [ ! -f "$srcs/$base" ]; then curl "$antlr_url/$base" -o "$srcs/$base"; fi
		# TODO(@p7r0x7): Check the source's integrity.
		unzip -q "$srcs/$base" -d "$vendor/antlr-$antlr_semv"
		jar --no-compress --date 1980-01-01T00:00:02Z --main-class org.antlr.v4.Tool \
			--create --file "$vendor/antlr-$antlr_semv.jar" -C "$vendor/antlr-$antlr_semv" .

		rm -rf "$vendor/antlr-$antlr_semv"
	} &

	base="antlr4-cpp-runtime-$antlr_semv-source.zip"
	{
		if [ ! -f "$srcs/$base" ]; then curl "$antlr_url/$base" -o "$srcs/$base"; fi
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
		if [ ! -f "$srcs/$base" ]; then curl "$zstd_url/$base" -o "$srcs/$base"; fi
		# TODO(@p7r0x7): Check the source's integrity.
		install "$vendor/zstd-$zstd_semv"
		zstdmt -cd "$srcs/$base" | tar -xf - --strip-components=1 -C "$vendor/zstd-$zstd_semv"

		cd "$vendor/zstd-$zstd_semv" && rm -rf contrib doc examples programs zlibWrapper lib/legacy tests
	} &
}
wait

finish
