#!/bin/sh

# SPDX-License-Identifier: Apache-2.0
# Copyright © 2024 The Whixy Authors. All rights reserved.
# Contributors responsible for this file:
# @p7r0x7 <mattrbonnette@pm.me>

# vendor/ must be kept current in VCS with this file that publicly defines its deterministic generation.
# And for security reasons, only @p7r0x7 may sign and push commits changing vendor.sh and vendor/.

gcc()
{
	start gcc 001992d33a97297575e26bc6dfd40933c1e9794bd8eb427b9a21662031a9d435

	semv=14.2.0; url="https://ftp.gnu.org/gnu/gcc/gcc-$semv"; base="gcc-$semv.tar.xz"
	dl ffee29313fd417420454d985b6740be3755e6465e14173c420c02e3719a51539
	7zz e -so "$srcs/$base" | tar -xf - -C "$pkg"
	(
		cd "$pkg/gcc-$semv"
		rm -rf c++tools gotools libada libcpp libgfortran libgo libgrust libobjc libstdc++-v3 zlib \
			gcc/ada gcc/cp gcc/d gcc/fortran gcc/go gcc/rust gcc/objc gcc/objcp
		find . \( -type d -name 'tests*' -o -type d -name doc -o -name '*ChangeLog*' \) -exec rm -rf {} +
	)
	finish
}

llvm()
{
	start llvm 0b2d32cf902882e080aa292ccd30b81b5814494d0042dce1ba89ca7703a05ba8

	semv=18.1.8 deps="clang cmake compiler-rt libunwind lld llvm polly runtimes third-party"
	url="https://github.com/llvm/llvm-project/releases/download/llvmorg-$semv"; base="llvm-project-$semv.src.tar.xz"
	dl 450adbb7590dda12a622cb3d74a51cb101ac7eb58177b9e25b93b2abdfc5dcdc
	7zz e -so "$srcs/$base" | tar -xf - --strip-components=1 -C "$pkg" $(printf "llvm-project-$semv.src/%s\n" $deps)
	(
		cd "$pkg"
		for dep in $deps; do mv "$dep" "$dep-$semv"; done
		rm -rf -- */docs */examples */benchmark* */test "llvm-$semv/bindings" "compiler-rt-$semv/www"
	)
	finish
}

common()
{
	start common 37579a5ceee6bd3fc1a6ad89174948bdc5dccdc2f1d7ef49d1c820ee8a11a5a6

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

		cd "$pkg/zstd-$semv"; rm -rf contrib doc programs zlibWrapper lib/legacy tests
		find . -type d -name examples -exec rm -rf {} +
	} &

	wait && finish
}

start()
{
	trap clean INT HUP TERM EXIT; . ../vendor.sh # Borrows $@
	name="$1" hash="$2"; pkg=/tmp/"$name" tar=/tmp/"$name".tar tzst=/tmp/"$name".tzst
	[ -f "$name".tzst ] && [ "$(zstd -cd "$name".tzst | b3sum)" = "$hash  -" ] \
		&& { zstd -lv "$name".tzst; exit 0; } || install "$pkg"
}

dl()
{
	hash="$1"; [ -f "$srcs/$base" ] || curl "$url/$base" -o "$srcs/$base"
	[ "$(b3sum < "$srcs/$base")" = "$hash  -" ] \
		|| { printf 'Resource %s could not be validated against hash\n%s' "$base" "$hash"; return 1; }
}

finish()
{
	find "$pkg" \( -name '.[!.]*' -o -empty \) -exec rm -rf {} +
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

for dir in "$srcs" vendor; do [ -d "$dir" ] || install "$dir"; done; cd vendor
gcc & llvm & common & wait
