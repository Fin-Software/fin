// SPDX-License-Identifier: Apache-2.0
// Copyright © 2024 The Whixy Authors. All rights reserved.
// Contributors responsible for this file:
// @p7r0x7 <mattrbonnette@pm.me>

const io = @import("std").io;
const fmt = @import("std").fmt;
const mem = @import("std").mem;
const uni = @import("std").unicode;
const print = @import("cli.zig").print;

//pub fn WhixyContextValidatingWriter(comptime Wrapped: type) type {
//    return struct {
//        inner: Wrapped,
//
//        pub const Inner = Wrapped;
//        pub const Error = Wrapped.Error || error{};
//
//        pub fn writer(euw: *@This()) io.Writer(*@This(), Error, write) {
//            return .{ .context = euw };
//        }
//        pub fn write(euw: *@This(), str: []const u8) !usize {
//            mem.indexOfAnyPos(u8, slice: []const T, start_index: usize, values: []const T)
//        }
//    };
//}
//inline fn whixyContextValidatingWriter(writer: anytype) EscapedUTF8Writer(@TypeOf(writer)) {
//    return .{ .inner = writer };
//}

pub fn EscapedUTF8Writer(comptime Wrapped: type) type {
    return struct {
        inner: Wrapped,
        prefix_len_m1: u2 = 3, // 3 signals to ignore prefix, since prefix_len won't ever be 0 or 4.
        rune_len: u2 = undefined,
        prefix: [4]u8 = undefined,

        pub const Inner = Wrapped;
        pub const Error = Wrapped.Error;

        pub fn writer(euw: *@This()) io.Writer(*@This(), Error, write) {
            return .{ .context = euw };
        }
        pub fn write(euw: *@This(), str: []const u8) !usize {
            const len = str.len;
            var i: usize = undefined;
            switch (euw.prefix_len_m1) {
                3 => i = 0,
                0 => {
                    try print(euw.inner, .{ "\\u", fmt.bytesToHex(euw.prefix[0..2], .upper) });
                },
                1 => {
                    try print(euw.inner, .{ "\\U", fmt.bytesToHex(euw.prefix[0..3], .upper) });
                },
                2 => {
                    try print(euw.inner, .{ "\\U", fmt.bytesToHex(euw.prefix[0..4], .upper) });
                },
            }

            while (i < len) {
                const start = i;
                while (i < len and str[i] < 0x80) i += 1;
                try euw.inner.writeAll(str[start..i]);

                if (i < len) {
                    const rune_len = switch (str[i]) {
                        0b1100_0000...0b1101_1111 => 2,
                        0b1110_0000...0b1110_1111 => 3,
                        0b1111_0000...0b1111_0111 => 4,
                        else => unreachable,
                    };
                    if (i + rune_len - 1 > len) {
                        euw.rune_len = rune_len;
                        euw.prefix_len_m1 = len - (rune_len + i - 1);
                        for (0.., str[i..euw.prefix_len_m1]) |ii, v| euw.prefix[ii] = v;
                        break;
                    }

                    switch (rune_len) {
                        2 => try print(euw.inner, .{ "\\u", fmt.bytesToHex(str[i .. i + 2], .upper) }),
                        3 => try print(euw.inner, .{ "\\U", fmt.bytesToHex(str[i .. i + 3], .upper) }),
                        4 => try print(euw.inner, .{ "\\U", fmt.bytesToHex(str[i .. i + 4], .upper) }),
                        else => unreachable,
                    }
                    i += rune_len;
                }
            }
            return len;
        }
    };
}
pub fn escapedUTF8Writer(writer: anytype) EscapedUTF8Writer(@TypeOf(writer)) {
    return .{ .inner = writer };
}
