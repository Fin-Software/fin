// SPDX-License-Identifier: Apache-2.0
// Copyright © 2024 The Whixy Authors. All rights reserved.
// Contributors responsible for this file:
// @p7r0x7 <mattrbonnette@pm.me>

const fs = @import("std").fs;
const fmt = @import("std").fmt;
const mem = @import("std").mem;
const db = @import("std").debug;
const sort = @import("std").sort;
const heap = @import("std").heap;
const proc = @import("std").process;
const mode = @import("builtin").mode;
const List = @import("std").ArrayList;
const B3 = @import("std").crypto.hash.Blake3;

const EntryCollector = struct {
    root: fs.Dir,
    entries: List(fs.Dir.Entry),
    allocator: mem.Allocator,

    fn initAndRun(root: []const u8, ally: mem.Allocator) !EntryCollector {
        var ec = EntryCollector{
            .root = try fs.cwd().openDir(root, .{ .no_follow = true }),
            .entries = List(fs.Dir.Entry).init(ally),
            .allocator = ally,
        };
        try ec.collectUnhiddenEntries(".");
        return ec;
    }
    fn renewAndRun(ec: *@This(), root: []const u8) !void {
        ec.root = root;
        ec.entries.clearRetainingCapacity();
        try ec.collectUnhiddenEntries(".");
    }
    inline fn deinit(ec: *@This()) void {
        ec.entries.clearAndFree();
    }
    fn collectUnhiddenEntries(ec: *@This(), dirName: []const u8) !void {
        var dir = try ec.root.openDir(dirName, .{ .no_follow = true });
        defer dir.close();

        var it = dir.iterate();
        while (try it.next()) |entry| {
            if ('.' == entry.name[0]) continue;
            const entry_name = try fs.path.join(ec.allocator, &.{ dirName, entry.name });
            defer ec.allocator.free(entry_name);

            try ec.entries.append(fs.Dir.Entry{ .name = try ec.allocator.dupe(u8, entry_name), .kind = entry.kind });
            if (entry.kind == .directory) try ec.collectUnhiddenEntries(entry_name);
        }
    }
};

fn lessThan(_: void, a: fs.Dir.Entry, b: fs.Dir.Entry) bool {
    return mem.lessThan(u8, a.name, b.name);
}

const HashDirOptions = struct {
    less_than: fn (_: void, a: fs.Dir.Entry, b: fs.Dir.Entry) bool = lessThan,
    read_buffer_len: usize = 64 << 10,
    hash_bitlen: usize,
};

fn hashDirSorted(dir: []const u8, out_hash: []u8, ally: mem.Allocator, comptime opts: HashDirOptions) !void {
    var ec = try EntryCollector.initAndRun(dir, ally);
    defer ec.deinit();

    sort.heap(fs.Dir.Entry, ec.entries.items, {}, opts.less_than);

    var b3 = B3.init(.{});
    var buf: [opts.read_buffer_len]u8 = undefined;
    for (ec.entries.items) |entry| {
        b3.update(entry.name);
        if (entry.kind == .file) {
            const file = try ec.root.openFile(entry.name, .{});
            defer file.close();

            while (true) {
                const len = try file.readAll(&buf);
                b3.update(buf[0..len]);
                if (len != opts.read_buffer_len) break;
            }
        }
        if (mode == .ReleaseSafe) db.print("{s}\n", .{entry.name});
    }
    b3.final(out_hash);
    if (mode == .ReleaseSafe) db.print("{s}\n", .{fmt.bytesToHex(out_hash[0 .. opts.hash_bitlen / 8], .lower)});
}

pub fn main() !void {
    const hash_bitlen = 256;
    var buf: [fs.max_name_bytes + hash_bitlen / 4]u8 = undefined;
    var fba = heap.FixedBufferAllocator.init(&buf);
    var arg_iter = proc.argsWithAllocator(fba.allocator()) catch return error.ArgsLargerThanExpected;
    defer arg_iter.deinit();

    _ = arg_iter.skip(); // Skip program name.
    const wd_name = arg_iter.next() orelse return error.MissingWorkingDirectoryArg;
    const hash_hex = arg_iter.next() orelse return error.MissingHashArg;
    var expected: [hash_bitlen / 8]u8 = undefined;
    _ = fmt.hexToBytes(&expected, hash_hex) catch return error.InvalidHash;

    var aa = heap.ArenaAllocator.init(heap.page_allocator);
    defer aa.deinit();

    var actual: [hash_bitlen / 8]u8 = undefined;
    try hashDirSorted(wd_name, &actual, aa.allocator(), .{ .hash_bitlen = hash_bitlen });
    if (!mem.eql(u8, &expected, &actual)) return error.HashMismatch;
}
