_ llvm = std.llvm # The keyword `std` is a universal reference to the standard library struct.

_ cache = (
    mut [6171]u8 tab
    for (&tab, 0..tab.len) |*v, i| (
        mut uptr t = i; v.* = 0
        while (t > 1) (v.* += 1)
            (t = if (t % 2 == 0) t / 2 else 3 * t + 1)
    ); tab
) # block expression returns comptime-generated tab

## Calculates the Collatz Conjecture stopping time of a.
uptr CollatzStoppingTime {uptr a}
(
    mut uptr steps = (llvm.ctz uptr a) as uptr
    mut uptr n = a >> (steps as u6)

    while (n > cache.len - 1) (
        n = 3 * n + 1
        uptr t = (llvm.ctz uptr n) as uptr
        n >>= t as u6
        steps += t + 1
    )
    return steps + (cache[n] as uptr)
)

# Main must always be declared as exported (PascalCase vs camelCase) and procedural ("$(" vs "(").
u8 Main {}
$(
    return (CollatzStoppingTime 7987987979) as u8
)

# For reference only; will compile if used 
_ Bitwise =
{
	inline a.type Not {a.type a} (return !a)
	inline a.type Or {a.type a b} (return a | b)
	inline a.type And {a.type a b} (return a & b)
	inline a.type Xor {a.type a b} (return a ^ b)
	inline a.type Shl {a.type a b} (return a << b)
	inline a.type Shr {a.type a b} (return a >> b)
	inline a.type Rotl {a.type a b} (return a <<% b)
	inline a.type Rotr {a.type a b} (return a >>% b)
}

_ Arithmetic = {}
