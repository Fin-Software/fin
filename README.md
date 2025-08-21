# Fin, A Friendly Systems Language

> Extension: .fn. Governing implementation license: Apache-2.0.

---

## Language Features

###### Primitive Types

* Conditions for automatic laziness in an otherwise eager syntax.
* Type specification is only necessary when unambigious type inference doesn't provide the wanted result
* Zig-like manual memory management, comptime, error handling, namespacing, and deferred-statement scoping
* Parametric polymorphism in the form of generics; ad hoc polymorphism in some form
* LET THERE BE POSITS via integer-based software emulation or native hardware instruction generation when available in LLVM

###### Keywords

`alias`       may alias pointer type modifer
`align`       suggest alignment, followed by a power-of-two between 2 and 4096 in a tuple
`and`         short-circuiting logical AND operator
`continue`    continue
`defer`       schedule an action at scope exit
`div`         function‑only modifier: this function may diverge (not return)
`else`        adds a fallback branch to an `if`
`emit`        inject lexemes at the call site
`elseif`      adds another branch to an `if`
`fall`        goto FALLTHROUGH, to the next `where` case
`for`         begins a for loop
`fin`         ends each block (function/closure, if, while, for, where, rescue, defer (rescue))
`goto`        jumps to a label statement
`if`          starts a conditional branch (expression/statement)
`inline`      suggest inlining (declaration or call)
`linkable`    function‑only modifier: symbol visible to linker
`linked`      function‑only modifier: external linkage
`mut`         this or these are mutable
`naked`       function‑only modifier: no prologue/epilogue
`namespace`   group declarations under a name
`noreturn`    statement: no further code in this path returns
`or`          short-circuiting logical OR operator
`orelse`      unwrap an optional or run fallback
`rescue`      inline error‑handling operator
`return`      exits a function with a value
`requires`
`static`      lives forever, don't it?
`struct`      define a data record (declaration or expression)
`syntax`      marks a syntax‑emitting macro result
`this`        refers to the current enclosing type (for method syntax)
`trait`       define an interface by required shape
`module`      tags file as belonging to a particular module
`unroll`      suggest loop unrolling
`unreachable`
`while`       begins a while loop
`where`       multi‑way branch (enhanced switch)


`and`         logical conjunction (boolean “and”)
`continue`    skip to next iteration of a loop
`defer`       schedule an expression to run when the surrounding scope exits
`demands`     specify required capabilities on a trait
`do`          begin a do‑block
`else`        alternative branch of an if or rescue
`emit`        emit an event (for backends or codegen)
`elseif`      “else if” branch of an if
`fall`        fall‑through in a switch‑like construct
`for`         begin a for‑loop
`fin`         end a block or function (Fin’s “end” marker)
`goto`        unconditional jump to a label
`if`          begin a conditional branch
`inline`      hint that a function should be inlined
`or`          logical disjunction (boolean “or”)
`orelse`      short‑circuit boolean “or else”
`rescue`      handle an error (Fin’s try/catch)
`return`      return from a function
`syntax`      begin a syntax extension or special form
`this`        implicit receiver in methods/traits
`trait`       begin a trait/interface definition
`unreachable` mark code as unreachable (compiler hint)
`unroll`      hint that a loop should be unrolled
`where`       constrain a generic or trait
`while`       begin a while‑loop

`alias`       alias‑type modifier
`align`       alignment modifier for storage
`dyn`         dynamic trait object modifier
`mut`         mutable binding modifier
`static`      static‑storage binding modifier

###### Operators

Infix unless otherwise specified.

`...`   postfix: variadic element ending a tuple type signature
`..`    exclusive range as used in slices, cases, and for expressions
`.type` postfix: access compile time type
`.len`  postfix: access length
`>>=`   right shift assign
`>>`    right shift
`>=`    greater-than or equal to comparison
`>`     greater-than comparison
`<<=`   left shift assign
`<<`    left shift
`<=`    less-than or equal to comparison
`<`     less-than comparison
`*%=`   wrapping multiply assign
`*%`    wrapping multiply
`*=`    multply assign
`*`     prefix: dereference, infix: multiply
`+%=`   wrapping add assign
`+%`    wrapping add
`+=`    add assign
`+`     add
`-%=`   wrapping subtract assign
`-%`    wrapping subtract
`-=`    subtract assign
`-`     prefix: negate, infix: subtract
`&=`    bitwise AND assign
`&`     prefix: access address of, infix: bitwise AND
`%=`    modulo assign
`%`     modulo
`^=`    bitwise XOR assign
`^`     bitwise XOR, prefix: bitwise NOT
`/=`    divide assign
`/`     divide
`|=`    bitwise OR assign
`|`     bitwise OR
`!=`    inequality comparison
`!`     prefix: logical NOT, postfix: sugar for `rescue |err| return err fin`
`==`    equality comparison
`:=`    declare value
`=`     assign or declare value or declare default
`?`     postfix: sugar for `orelse unreachable`
`#`     prefix: invoke call or declare function as macro
`$`     prefix: expand `[]lexeme` to syntax


###### Immutable By Default



###### Extended Operators and Builtins




    + all operators for macro construction or arbitrary bullshit

    @panic()
    # idk

    # CT things
    @ctError()
    @alignOf()
    @sizeOf()

    # Common platform-agnostic intrinsics
    @clz()
    @ctz()
    @fma()
    @popcnt()
    @reverseBytes()
    @reverseBits()



    @addrSpaceCast x
    @addWithOverflow
    @alignCast
    @as
    @atomicLoad
    @atomicRmw
    @atomicStore
    @bitCast
    @bitOffsetOf
    @bitSizeOf
    @branchHint
    @breakpoint

    @offsetOf
    @call
    @cDefine
    @cImport
    @cInclude
    @cmpxchgStrong
    @cmpxchgWeak
    @compileError
    @compileLog
    @constCast
    @cUndef
    @cVaArg
    @cVaCopy
    @cVaEnd
    @cVaStart
    @divExact
    @divFloor
    @divTrunc
    @embedFile
    @enumFromInt
    @errorFromInt
    @errorName
    @errorReturnTrace
    @errorCast
    @export
    @extern
    @field
    @fieldParentPtr
    @FieldType
    @floatCast
    @floatFromInt
    @frameAddress
    @hasDecl
    @hasField
    @import
    @inComptime
    @intCast
    @intFromBool
    @intFromEnum
    @intFromError
    @intFromFloat
    @intFromPtr
    @max
    @memcpy
    @memset
    @min
    @wasmMemorySize
    @wasmMemoryGrow
    @mod
    @mulWithOverflow
    @panic
    @popCount
    @prefetch
    @ptrCast
    @ptrFromInt
    @rem
    @returnAddress
    @select
    @setEvalBranchQuota
    @setFloatMode
    @setRuntimeSafety
    @shlExact
    @shlWithOverflow
    @shrExact
    @shuffle
    @sizeOf
    @splat
    @reduce
    @src
    @sqrt
    @sin
    @cos
    @tan
    @exp
    @exp2
    @log
    @log2
    @log10
    @abs
    @floor
    @ceil
    @trunc
    @round
    @subWithOverflow
    @tagName
    @This
    @trap
    @truncate
    @Type
    @typeInfo
    @typeName
    @TypeOf
    @unionInit
    @Vector
    @volatileCast
    @workGroupId
    @workGroupSize
    @workItemId


###### Implementation Consistency Guarantees

* Compilers must halt; interpreters are... permitted.
* Primitive integer operations must be constant-time.
* Type inference must follow the (currently un)specified, halting algorithm.
* Macro expansion (syntax) and folding (syntax and procedural) cannot be delayed until runtime.

## Governing Implementation Design Goals

##### Support Targets (unless I'm paid to work on this)

OSes: MacOS, Windows, Linux, and FreeBSD
ISAs: x86 (32 and 64), arm (16, 32, and 64), riscv (32 and 64)

---

## Compiler

|   Mode  |                               Potential Implementation                               |
| :------ | :----------------------------------------------------------------------------------- |
| `jit`   | `$reqd -O1 -DLAZY -DSAFETY`                                                          |
| `debug` | `$reqd -O0 $errors -DLAZY -DSAFETY -g`                                               |
| `safe`  | `$reqd -O3 $errors -mllvm -polly -mllvm -polly-vectorizer=stripmine -DLAZY -DSAFETY` |
| `fast`  | `$reqd -O3 $errors -mllvm -polly -mllvm -polly-vectorizer=stripmine -DLAZY`          |
| `tiny`  | `$reqd -Oz $errors`                                                                  |
|         | `errors = -Wall -Wextra -Wno-cast-function-type-mismatch`                            |
|         | `reqd = -fwrapv -nostdlib -nostartfiles`                                             |

* LLVM-based code generation
* JiT'd comptime code generation and execution followed by JiT'd or AoT'd runtime code generation (and possible execution)
* rustc-level informative errors for compiler-driven development (faster, due to less strict and less complex semantics)
* native and LLVM IR stdlib with comprehensive support only for SotA or appropriately longstanding or ubiquitous software
* struct and literal deduplication
* per-comptime backwards jump limit default, possibly 2^16
* per-file node limit default, possibly 2^32

---

## Standard Library

| source file sans extension |                          contents and priority =>                           |   |
| :------------------------- | :-------------------------------------------------------------------------- | - |
| `builtin/builtin`          | builtin intrinsics                                                          | 0 |
| `compressor/brotli`        | (E then D) Brotli compression format                                        |   |
| `compressor/bzip2`         | (D only)   Bzip2 compression format                                         |   |
| `compressor/flate`         | (E and D)  Deflate or Gzip or Zlib compression format                       |   |
| `compressor/lzma`          | (D only)   LZMA compression format                                          |   |
| `compressor/lzma2`         | (D only)   LZMA2 compression format                                         |   |
| `compressor/zstd`          | (E then D) Zstandard compression format                                     |   |
| `container/sevenz`         | (D only)   7-zip LZMA, LZMA2, or Deflate archive format                     |   |
| `container/tar`            | (E and D)  gnu, ustar, and pax tape archive format                          |   |
| `container/xz`             | (D only)   XZ LZMA or LZMA2 container format                                |   |
| `container/zip`            | (E and D)  Zip or Zip64 Deflate archive format                              |   |
| `cova/cova`                | commands, options, values, and arguments; a reprised cli library            |   |
| `encoding/base2`           | (E and D)  12.5% efficient binary ASCII                                     |   |
| `encoding/base8`           | (E and D)  ~33.3% efficient octal ASCII                                     |   |
| `encoding/base10`          | (E and D)  ~42% efficient decimal ASCII                                     |   |
| `encoding/base16`          | (E and D)  50% efficient uppercase or lowercase hexadecimal ASCII           |   |
| `encoding/base32`          | (E and D)  62.5% efficient uppercase or lowercase base32 ASCII              |   |
| `encoding/base64`          | (E and D)  75% efficient base64 ASCII                                       |   |
| `encoding/base85`          | (E and D)  80% efficient base85 or ascii85 or z85 ASCII                     |   |
| `encoding/base91`          | (E and D)  ~81-88% efficient basE91 or Base91 ASCII                         |   |
| `encoding/csv`             | (E and D)                                                                   |   |
| `encoding/cbor`            | (E and D)                                                                   |   |
| `encoding/json`            | (E and D)                                                                   |   |
| `encoding/pam`             | (E and D)  uncompressed binary or ASCII format geared towards image data    |   |
| `encoding/toml`            | (E and D)                                                                   |   |
| `encoding/utf-8`           | (E and D)  utf-8 unicode text encoding                                      |   |
| `encoding/wtf-16`          | (E and D)  wtf-16 unicode text encoding                                     |   |
| `fmt/fmt`                  | value formatting and writing                                                |   |
| `hw/cpu`                   | cpu and cpu feature detection                                               |   |
| `hw/gpu`                   | gpu and gpu feature detection                                               |   |
| `hw/disk`                  | disk and disk feature detection                                             |   |
| `io/io`                    | generic readers and writers                                                 |   |
| `io/reader`                | generic readers and writers                                                 |   |
| `io/writer`                | generic readers and writers                                                 |   |
| `math/math`                | higher-level mathematics library                                            |   |
| `math/big/big`             | arbitrary-precision arithmetic and bitwise operation library                |   |
| `math/big/int`             | arbitrary-precision integer arithmetic                                      |   |
| `math/big/posit`           | arbitrary-precision posit arithmetic                                        |   |
| `math/big/rational`        | arbitrary-precision rational arithmetic                                     |   |
| `mem/mem`                  | generic memory manipulation                                                 |   |
| `mem/heap`                 | generic memory allocation                                                   |   |
| `mem/heap/allocator`       | memory allocator mixin                                                      |   |
| `mem/heap/arenaalloc`      | allocator wrapper that disables all freeing until deinitialization          |   |
| `mem/heap/rpmalloc`        | reimplementation of https://github.com/mjansson/rpmalloc                    |   |
| `mem/heap/stackalloc`      | fixed-buffer allocator; may only free the most recent allocation            |   |
| `mem/heap/safealloc`       | allocator wrapper that safety checks and panics or warns                    |   |
| `mem/heap/failalloc`       | allocator wrapper that precisely, randomly, or catastrophically fails       |   |
| `mem/sort`                 | generic memory sorting                                                      |   |
| `mime/mime`                | filetype detection                                                          |   |
| `os/os`                    | higher-level operating system interaction                                   |   |
| `os/exec`                  | higher-level program execution                                              |   |
| `os/fs`                    | higher-level filesystem interaction                                         |   |
| `os/fs/path`               | filepath traversal and manipulation                                         |   |
| `os/posix`                 | low-level POSIX interaction                                                 | 1 |
| `os/syscall`               | low-level kernel interaction                                                | 0 |
| `regex/regex`              | custom regex engine                                                         | 4 |
| `runt/runt`                | fin's minimal runtime                                                       | 0 |
| `runt/tracy`               | execution tracing                                                           |   |
| `sync/atomic`              | low-level atomic primitives                                                 | 1 |
| `sync/sched`               | scheduler mixin and default schedulers                                      | 3 |
| `sync/chan`                | channel mixin and default channels                                          | 1 |
| `sync/coroutine`           | userspace threads                                                           | 3 |
| `sync/future`              | future mixin                                                                | 1 |
| `sync/mutex`               | (rw)mutexes and their mixins                                                | 1 |
| `sync/thread`              | thread mixin and posix threads                                              | 1 |
| `sync/waitgroup`           | waitgroups                                                                  | 1 |
| `time/time`                |                                                                             | 2 |
| `time/tz`                  |                                                                             | 2 |
| `unicode`                  | current unicode tables                                                      | 2 |

+ others I don't know or haven't written down



## Notes

- goto is limited to intra-routine jumps
- type-punning via aliasing pointer casting is limited to types of the same size in memory
- slicewise operators are vectorized where possible and must occur between identically-shaped integer or float slices
- overflow checks are opt-out at the operation level and are inlined; some compilation modes omit them
- lazy eval may occur on any runtime function that exhibits referential transparency

Runtime functions exhibit referential transparency if their lowered and monomorphized and constant folded code do not:
    - dereference any addresses passed via parameters directly or indirectly
    - directly reference any non-local values (CT constants are universally local)
    - call any functions that directly reference non-local values
    - have the potential to not return
