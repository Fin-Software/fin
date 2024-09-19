#!/bin/sh

# SPDX-License-Identifier: Apache-2.0
# Copyright © 2024 The Whixy Authors. All rights reserved.
# Contributors responsible for this file:
# @p7r0x7 <mattrbonnette@pm.me>

# vendor/ must be kept current in VCS with this file that publicly defines its deterministic generation.
# And for security reasons, only @p7r0x7 may sign and push commits changing vendor.sh and vendor/.

gcc()
{
	start gcc 7fb9a7d5bf5b39faed2ac705aa60225480aefc06be9460a481c1243357db95e3

	semv=14.2.0; url="https://ftp.gnu.org/gnu/gcc/gcc-$semv"; base="gcc-$semv.tar.xz"
	dl ffee29313fd417420454d985b6740be3755e6465e14173c420c02e3719a51539
	7zz e -so "$srcs/$base" | tar -xf - -C "$pkg"
	(
		cd "$pkg/gcc-$semv"; rm -rf c++tools gotools INSTALL libada libcpp libffi/man libgfortran libgo libgrust libobjc \
			libstdc++-v3 maintainer-scripts zlib gcc/ada gcc/cp gcc/d gcc/fortran gcc/go gcc/rust gcc/objc gcc/objcp
		find . \( -type d -name examples -o -type d -name doc -o -type d -name docs -o -type d -name test \
			-o -type d -name tests -o -type d -name testsuite -o -type d -name testdata \) -exec rm -rf {} +
	)
	finish
}

llvm()
{
	start llvm 14d60e280426faf2ae09c9bbf68d14574740533c0db6d556762e80a15546b1b4

	semv=19.1.0 deps="clang cmake compiler-rt libunwind lld llvm polly runtimes"
	url="https://github.com/llvm/llvm-project/releases/download/llvmorg-$semv"; base="llvm-project-$semv.src.tar.xz"
	dl fbbbaeea01cc9b9f45adc8bd16f909d2a10b1496605f18f0a8db9a154d3924ce
	7zz e -so "$srcs/$base" | tar -xf - --strip-components=1 -C "$pkg" $(printf "llvm-project-$semv.src/%s\n" $deps)
	(
		cd "$pkg"; for dep in $deps; do mv "$dep" "$dep-$semv"; done
		rm -rf -- */benchmark* llvm-*/bindings polly-*/lib/External/isl/test_inputs
		find . \( -type d -name examples -o -type d -name doc -o -type d -name docs -o -type d -name test \
			-o -type d -name tests -o -type d -name unittests -o -type d -name www \) -exec rm -rf {} +
	)
	finish
}

common()
{
	start common 022b2ef2bac36d6da3120a3bd0350139fb95ef1552886f8ce0df19b7b1ba717a

	semv=4.13.2; base="antlr-$semv-complete.jar"; url=https://www.antlr.org/download
	{
		dl 3922e3a76a095b4d5b38573c28ea59dce5e7342a557f9fce0f5a6c58489aae7b
		7zz x "$srcs/$base" -o"$pkg/antlr-$semv" >/dev/null
	} &
	base="antlr4-cpp-runtime-$semv-source.zip"
	{
		dl 0fac612afb44eb1e188f4de50f00ffd4972022480084cc6afb4d9222244aef6c
		install "$pkg/antlr-cpp-runtime-$semv"; 7zz x "$srcs/$base" -o"$pkg/antlr-cpp-runtime-$semv" >/dev/null

		rm -rf "$pkg/antlr-cpp-runtime-$semv/demo"
	} &

	semv=1.5.6; base="zstd-$semv.tar.zst"; url="https://github.com/facebook/zstd/releases/download/v$semv"
	{
		dl eaec93bd5737d25a816d33f0cee57443230f0ecc980f0eb0573602239f3e484e
		install "$pkg/zstd-$semv"; zstd -cd "$srcs/$base" | tar -xf - --strip-components=1 -C "$pkg/zstd-$semv"

		cd "$pkg/zstd-$semv"; rm -rf contrib build/meson build/VS* doc lib/legacy programs tests zlibWrapper
		find . \( -type d -name example -o -type d -name examples \) -exec rm -rf {} +
	} &

	wait && finish
}

start()
{
	trap clean INT HUP TERM EXIT; . ../vendor.sh # Borrows $@
	name="$1" hash="$2"; pkg=/tmp/"$name" tar=/tmp/"$name".tar tzst=/tmp/"$name".tzst
	[ -f "$name".tzst ] && [ "$(zstd -cd "$name".tzst | b3sum)" = "$hash  -" ] \
		&& { zstd -lv "$name".tzst; exit 0; } || { rm -rf "$pkg"; install "$pkg"; }
}

dl()
{
	hash="$1"; [ -f "$srcs/$base" ] || curl "$url/$base" -o "$srcs/$base"
	actual="$(b3sum < "$srcs/$base")"; [ "$actual" = "$hash  -" ] \
		|| { printf '%s !=\n%s\n' "$hash" ${actual%  -}; rm -rf "$srcs/$base" & return 1; }
}

finish()
{
	find "$pkg" \( -name '.[!.]*' -o -empty -o -iname '*changelog*' -o -iname '*bazel*' \) -exec rm -rf {} +
	tar --pax-option=exthdr.name=%d/PaxHeaders/%f,delete=atime,delete=ctime --sort=name \
		--mtime="@0" --owner=0 --group=0 --numeric-owner -S --no-seek -cf "$tar" -C "$pkg" .
	b3sum "$tar"; zstd "$tar" -o "$tzst"; zstd -lv "$tzst"; mv "$tzst" .
}

set -eu; umask 0022; srcs=/tmp/srcs; command -v gtar >/dev/null && tar() { gtar "$@"; }
tar --version | awk '{exit ($4 >= 1.28) ? 0 : 1}' || { printf 'GNU tar too old.'; return 1; }
zstd() { zstdmt --ultra -22 --long=29 --no-check --no-progress "$@"; }
install() { command install -dm 0755 "$@"; }
clean() { rm -rf "$pkg"* >/dev/null & }
curl() { command curl -sL "$@"; }
[ $# = 0 ] || return 0 # Sourcing mode ends here.

install "$srcs" vendor; cd vendor
gcc & llvm & common & wait
