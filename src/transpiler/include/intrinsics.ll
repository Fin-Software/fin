attributes #0 = { alwaysinline }

#define OP(TYPE, INTRINSIC, NAME)                                                                   \
    define TYPE @NAME##_##INTRINSIC(TYPE %a, TYPE %b) #0 { %r = INTRINSIC TYPE %a, %b ret TYPE %r }

#define UNSIGNED_OP(INTRINSIC) \
  OP(%u8,   INTRINSIC, u8)     \
  OP(%u16,  INTRINSIC, u16)    \
  OP(%u32,  INTRINSIC, u32)    \
  OP(%u64,  INTRINSIC, u64)    \
  OP(%u128, INTRINSIC, u128)

#define SIGNED_OP(INTRINSIC) \
  OP(i8,   INTRINSIC, i8)    \
  OP(i16,  INTRINSIC, i16)   \
  OP(i32,  INTRINSIC, i32)   \
  OP(i64,  INTRINSIC, i64)   \
  OP(i128, INTRINSIC, i128)