source_filename = "src/transpiler/include/types.ll"

%u8 = type i8  %u16 = type i16  %u32 = type i32  %u64 = type i64  %u128 = type i128

; There is no value in abstracting i8-i128 in LLVM IR.

%f16 = type half  %bf16 = type bfloat  %f32 = type float  %f64 = type double

#if __SIZEOF_POINTER__ == 8
    %uptr = type i64  %iptr = type i64
#elif __SIZEOF_POINTER__ == 4 || __SIZEOF_POINTER__ == 2
    %uptr = type i32  %iptr = type i32
#else
    #error "Fin only supports 64-, 32-, and 16-bit nominal pointer sizes."
#endif