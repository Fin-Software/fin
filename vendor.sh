#!/bin/sh

# SPDX-License-Identifier: Apache-2.0
# Copyright © 2024 The Whixy Authors. All rights reserved.
# Contributors responsible for this file:
# @p7r0x7 <mattrbonnette@pm.me>

# vendor.tzst must be altered in the VCS when this script (that publicly defines its deterministic generation) changes.
# And for security reasons, only @p7r0x7 may sign and push commits changing this script and vendor.tzst.
# Because this script is not needed for the standard build process, it was not translated for Windows.

cleanup()
{
	rm -rf "$vendor" "$tarball" "$zip" >/dev/null &
	exit 1
}

if [ ! "$(basename "$PWD")" = "whixy" ]; then printf "Please, run this file in the directory it came from." && exit 1; fi
set -e && trap cleanup INT HUP TERM EXIT
alias mkdir="mkdir -pm 0744" && alias curl="curl -sL"
readonly vendor=/tmp/vendor && readonly srcs=/tmp/srcs && readonly tarball=/tmp/vendor.tar && readonly zip=/tmp/vendor.zip
for dir in "$vendor" "$srcs"; do if [ ! -d "$dir" ]; then mkdir "$dir"; fi; done

{
	readonly llvm_semv=18.1.6
	readonly llvm_url="https://github.com/llvm/llvm-project/releases/download/llvmorg-$llvm_semv"
	readonly llvm_deps="cmake compiler-rt libunwind lld llvm mlir runtimes third-party"

	base="llvm-project-$llvm_semv.src.tar.xz"
	{
		if [ ! -f "$srcs/$base" ]; then curl "$llvm_url/$base" -o "$srcs/$base"; fi
		# missing check
		tar -xJf "$srcs/$base" -C "$vendor" --strip-components=1 \
			$(for dep in $llvm_deps; do printf "llvm-project-%s.src/%s\n" "$llvm_semv" "$dep"; done)

		for dep in $llvm_deps; do mv "$vendor/$dep" "$vendor/$dep-$llvm_semv"; done
		cd "$vendor" && rm -rf -- \
			*"-$llvm_semv/".[!.]* *"-$llvm_semv/docs" *"-$llvm_semv/examples" *"-$llvm_semv/benchmark"* *"-$llvm_semv/test" \
			"llvm-$llvm_semv/bindings" "compiler-rt-$llvm_semv/www"
	} &
}
{
	readonly antlr_semv=4.13.1
	readonly antlr_url=https://www.antlr.org/download

	base="antlr-$antlr_semv-complete.jar"
	{
		if [ ! -f "$srcs/$base" ]; then curl "$antlr_url/$base" -o "$srcs/$base"; fi
		# missing check
		cp "$srcs/$base" "$vendor/antlr-$antlr_semv.jar"

		jar -0 --update --file "$vendor/antlr-$antlr_semv.jar" --date 1980-01-01T00:00:02Z --main-class org.antlr.v4.Tool
	} &

	base="antlr4-cpp-runtime-$antlr_semv-source.zip"
	{
		if [ ! -f "$srcs/$base" ]; then curl "$antlr_url/$base" -o "$srcs/$base"; fi
		# missing check
		mkdir "$vendor/antlr-cpp-runtime-$antlr_semv"
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
		# missing check
		mkdir "$vendor/zstd-$zstd_semv"
		zstdmt -cd "$srcs/$base" | tar -xf - --strip-components=1 -C "$vendor/zstd-$zstd_semv"

		cd "$vendor/zstd-$zstd_semv" && rm -rf .[!.]* contrib doc examples programs zlibWrapper lib/legacy tests
	} &
}
wait

gtar --pax-option=exthdr.name=%d/PaxHeaders/%f,delete=atime,delete=ctime --sort=name \
	--mtime="@0" --owner=0 --group=0 --numeric-owner -cf "$tarball" -C "$vendor" .
#cd "$vendor" && deterministic-zip -Z store -q -r -- "$zip" * &
wait

b3sum "$tarball" #"$zip"
#brotli -q 11 --large_window=28 -n "$tarball" -o vendor.tbr &
zstdmt --ultra -22 --long=28 --no-check "$tarball" -o vendor.tzst
wait
#brotli -q 11 --large_window=28 -n "$zip" -o vendor.zip.br &
#zstdmt --ultra -22 --long=28 --no-check "$zip" -o vendor.zip.zst &
#wait
