// SPDX-License-Identifier: Apache-2.0
// Copyright © 2025 The Fin Authors. All rights reserved.
// Contributors responsible for this file:
// @p7r0x7 <mattrbonnette@pm.me>

const io = @import("std").io;
const cli = @import("cli.zig");
const heap = @import("std").heap;

pub fn main() !void {
    const stderr = io.getStdErr();

    // Run VPXL's CLI using an arena-wrapped stack allocator.
    var buf: [9 << 10]u8 = undefined; // Adjust as necessary.
    var fba = heap.FixedBufferAllocator.init(buf[0..]);
    try cli.runFin(stderr, fba.allocator());
}
