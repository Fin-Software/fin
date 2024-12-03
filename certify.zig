// SPDX-License-Identifier: Apache-2.0
// Copyright © 2024 The Unvendor Contributors. All rights reserved.
// Contributors responsible for this file:
// @p7r0x7 <mattrbonnette@pm.me>

const io = @import("std").io;
const fs = @import("std").fs;
const fmt = @import("std").fmt;
const mem = @import("std").mem;
const heap = @import("std").heap;
const proc = @import("std").process;
const List = @import("std").ArrayList;
const B3 = @import("std").crypto.hash.Blake3;

pub fn main() !void {
    const hash_bitlen, const read_buffer = .{ 256, 64 << 10 };

    var expected: [hash_bitlen / 8]u8 = undefined;
    const wd = blk: {
        var buf: [fs.max_path_bytes + hash_bitlen / 4]u8 = undefined;
        var fba = heap.FixedBufferAllocator.init(buf[0..]); // Not reused
        var arg_iter = proc.argsWithAllocator(fba.allocator()) catch return error.ArgsLargerThanExpected;
        defer arg_iter.deinit();

        _ = arg_iter.skip(); // Skip program name.
        var buf2: [fs.max_path_bytes]u8 = undefined;
        const wd_path = try fs.cwd().realpath(arg_iter.next() orelse return error.MissingWorkingDirectoryArg, buf2[0..]);
        {
            const hash_hex = arg_iter.next() orelse return error.MissingHashArg;
            _ = fmt.hexToBytes(expected[0..], hash_hex) catch return error.InvalidHash;
        }
        break :blk try fs.cwd().openDir(wd_path, .{});
    };

    if (blk: {
        const ally = heap.page_allocator;
        const window = try ally.alloc(u8, zstd_window);
        defer ally.free(window);

        var bfrd = io.bufferedReaderSize(read_buffer, tarball.reader());
        var unzstd = zstd.decompressor(bfrd.reader(), .{ .window_buffer = window });
        var hasher = compress.hashedReader(unzstd.reader(), B3.init(.{}));
        try tar.pipeToFileSystem(out_dir, hasher.reader(), .{});
        {
            var buf: [128]u8 = undefined;
            while (try hasher.reader().readAll(buf[0..]) == buf.len) {}
        }
        var actual: [hash_bitlen / 8]u8 = undefined;
        hasher.hasher.final(actual[0..]);
        break :blk !mem.eql(u8, expected[0..], actual[0..]);
    }) return error.HashMismatch;
}

const EntryCollector = struct {
    entries: List(Entry),

    const Entry = struct { path: []u8, is_dir: bool };

    inline fn init(ec: *@This(), ally: mem.Allocator) void {
        ec.entries = List(Entry).init(ally);
    }
    inline fn reset(ec: *@This()) void {
        ec.entries.clearRetainingCapacity();
    }
    fn collectUnhiddenEntries(ec: *@This(), path: []const u8, is_dir: bool, ally: mem.Allocator) !void {
        if (path[0] != '.')
            try ec.entries.append(Entry{ .path = try ally.dupe(u8, path), .is_dir = is_dir });
        if (is_dir) {
            const dir = try fs.cwd().openDir(path, .{});
            defer dir.close();
            var it = dir.iterate();
            while (try it.next()) |entry| {
                if ('.' == entry.path[0]) continue;
                const entry_path = try fs.path.join(ally, &.{ path, entry.path });
                defer ally.free(entry_path);
                try collectUnhiddenEntries(entry_path, entry.is_dir);
            }
        }
    }
};

pub fn hashDirectorySorted(dirPath: []const u8, ally: mem.Allocator) ![]u8 {
    defer entries.deinit();

    try collectUnhiddenEntries(dirPath, true);

    std.sort.heap(
        Entry,
        entries.items,
    );

    var b3 = B3.init(.{});

    // Process sorted entries
    for (entries.items) |entry| {
        // Update the hash with the entry's full path
        sha256.update(&ctx, entry.full_path);

        if (!entry.is_dir) {
            // Hash file contents if it's a file
            const file = try fs.cwd().openFile(entry.full_path, .{});
            defer file.close();

            var buffer: [4096]u8 = undefined;
            while (try file.read(buffer[0..])) |data| {
                sha256.update(&ctx, data);
            }
        }
    }

    // Finalize and return the hash
    return sha256.finalize(&ctx);
}

// Recursive function to collect entries
