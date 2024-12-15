// SPDX-License-Identifier: Apache-2.0
// Copyright © 2024 The Whixy Authors. All rights reserved.
// Contributors responsible for this file:
// @p7r0x7 <mattrbonnette@pm.me>

const math = @import("std").math;

pub const bitwise = struct {
    pub inline fn shl(comptime T: type, a: T, b: T) T {
        return a << b;
    }
    pub inline fn shr(comptime T: type, a: T, b: T) T {
        return a >> b;
    }
    pub inline fn @"and"(comptime T: type, a: T, b: T) T {
        return a & b;
    }
    pub inline fn @"or"(comptime T: type, a: T, b: T) T {
        return a | b;
    }
    pub inline fn xor(comptime T: type, a: T, b: T) T {
        return a ^ b;
    }
    pub inline fn not(comptime T: type, a: T) T {
        return ~a;
    }
};

pub const arithmetic = struct {
    pub const overflow_behavior = enum { wrapOnOverflow, panicOnOverflow };

    pub inline fn add(comptime T: type, a: T, b: T, comptime of: overflow_behavior) T {
        return switch (of) {
            .wrapOnOverflow => a +% b,
            .panicOnOverflow => a + b,
        };
    }
    pub inline fn sub(comptime T: type, a: T, b: T, comptime of: overflow_behavior) T {
        return switch (of) {
            .wrapOnOverflow => a -% b,
            .panicOnOverflow => a - b,
        };
    }
    pub inline fn mul(comptime T: type, a: T, b: T, comptime of: overflow_behavior) T {
        return switch (of) {
            .wrapOnOverflow => a *% b,
            .panicOnOverflow => a * b,
        };
    }

    pub inline fn div(comptime T: type, a: T, b: T) T {
        return a / b;
    }
    pub inline fn mod(comptime T: type, a: T, b: T) T {
        return a % b;
    }
    pub inline fn neg(comptime T: type, a: T) T {
        return -a;
    }
};
