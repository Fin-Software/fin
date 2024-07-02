# Language Specification Design Goals

* Name: Whixy, pronounced "WIK-see" or /wɪk.siː/; Source file extension: .wx; Governing implementation license: Apache-2.0

###### Features Conducive to Systems Programming

* Pure and impure codepaths are explicitly delineated in the syntax.
* Conditions for automatic laziness in an otherwise eager syntax.
* Value declarations are immutable by default, and passed routine parameters are always immutable.

###### Features Conducive to Scripting

* Type specification is only necessary when unambigious type inference doesn't provide the wanted result
* Zig-like manual memory management, comptime, error handling, namespacing, and deferred-statement scoping
* Parametric polymorphism in the form of generics; ad hoc polymorphism in some form
* Routines are first class objects and will be designed to be anonymous by default (instead of two routine syntaxes, named and unnamed, there will just be the unnamed syntax that is to be assigned an identifier for reuse... just like everything else)
* LET THERE BE POSITS via integer-based software emulation or native hardware instruction generation when available in LLVM

###### Implementation Consistency Guarantees

* Tail call optimization (such that valid code in one implementation doesn't produce a stack overflow in another)
* Constant-time basic integer operations (otherwise writing secure code could become impossible)
* All forms of polymorphism must be statically-dispatched (as to incur no runtime overhead)
* Comptime code execution cannot be delayed until runtime
* Automatic laziness follows a specified algorithm and cannot be skipped

# Governing Implementation Design Goals

#### Compiler

<table><thead>
	<tr>
		<th></th>
		<th></th>
		<th colspan="4">Release Modes</th>
	</tr></thead>
<tbody>
	<tr>
		<td></td>
		<td>JiT</td>
		<td>debug</td>
		<td>safe</td>
		<td>fast</td>
		<td>tiny</td>
	</tr>
	<tr>
		<td>Clang</td>
		<td>-O1</td>
		<td>-O0 -g</td>
		<td>-O3 -mllvm -polly -mllvm -polly-vectorizer=stripmine</td>
		<td>-O3 -mllvm -polly -mllvm -polly-vectorizer=stripmine</td>
		<td>-Oz</td>
	</tr>
	<tr>
		<td>GCC</td>
		<td>-O1</td>
		<td>-O0 -g</td>
		<td>-O3</td>
		<td>-O3</td>
		<td>-Oz</td>
	</tr>
	<tr>
		<td>safety</td>
		<td>✔️</td>
		<td>✔️</td>
		<td>✔️</td>
		<td>✖️</td>
		<td>✖️</td>
	</tr>
</tbody>
</table>

* ISO C23 backend
* GCC- and/or LLVM-based code generation (selectable when building the compiler)
* JiT'd comptime code generation and execution followed by JiT'd or AoT'd runtime code generation (and possible execution)
* rustc-level semantic linting and informative errors for compiler-driven development
* 100% native stdlib with comprehensive support only for modern or appropriately longstanding software technology many programmers need
* Literal deduplication techniques more advanced than anything I'm aware exists in current code generation tools

#### Standard Library

format/container
format/compressor
format/encoding

codec/wbe (whixy binary encoding, like the go binary encoding format; E+D)
codec/pam (arbitrary uncompressed format geared towards image data; E+D)
codec/base10 (~42% efficient decimal text encoding in standard ascii arabic numerals; E+D)
codec/base16 (50% efficient uppercase or lowercase hexadecimal text encoding; E+D)
codec/base32 (base32; 62.5% efficient; E+D)
codec/base64 (base64; 75% efficient; E+D)
codec/base85 (base85 or ascii85 or z85; 80% efficient; E+D)
codec/base91 (Base91 or basE91; ~81-88% efficient; E+D)
codec/flate (Deflate or Gzip or Zlib compression format; D*)
codec/lzma (LZMA compression format; D)
codec/lzma2 (LZMA2 LZMA container format; D)
codec/brotli (Brotli; D*)
codec/zstd (Zstandard; D*)
codec/xz

*encoding eventually

+ others I don't yet know the importance of in my limited experience as a programmer
