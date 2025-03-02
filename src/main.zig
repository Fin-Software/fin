// SPDX-License-Identifier: Apache-2.0
// Copyright © 2024 The Whixy Authors. All rights reserved.
// Contributors responsible for this file:
// @p7r0x7 <mattrbonnette@pm.me>

const io = @import("std").io;
const cli = @import("cli.zig");
const heap = @import("std").heap;

pub fn main() !void {
    const stderr = io.getStdErr();
    {
        // Run VPXL's CLI using an arena-wrapped stack allocator.
        var buf: [9 << 10]u8 = undefined; // Adjust as necessary.
        var fba = heap.FixedBufferAllocator.init(buf[0..]); // Not reused
        try cli.runWhixy(stderr, fba.allocator());
    }
}

test "passes" {
    const message =
        \\⊌
    ;
    const List = @import("std").ArrayList;
    const testing = @import("std").testing;
    const passes = @import("transpiler/src_passes.zig");

    var ta = testing.allocator_instance;
    //defer ta.deinit();

    var list = List(u8).init(ta.allocator());
    const lw = list.writer();
    var euw = passes.escapedUTF8Writer(lw);
    try euw.writer().writeAll(message);
    try io.getStdErr().writeAll(list.items);
}
