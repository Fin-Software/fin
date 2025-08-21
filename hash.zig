// SPDX-License-Identifier: Apache-2.0
// Copyright © 2025 The Fin Authors. All rights reserved.
// Contributors responsible for this file:
// @p7r0x7 <mattrbonnette@pm.me>

const fs = @import("std").fs;
const fmt = @import("std").fmt;
const mem = @import("std").mem;
const db = @import("std").debug;
const heap = @import("std").heap;
const proc = @import("std").process;
const mode = @import("builtin").mode;
const List = @import("std").ArrayList;
const B3 = @import("std").crypto.hash.Blake3;

pub const DirEntry = struct { base: ?[]const u8, name: []const u8, kind: fs.Dir.Entry.Kind };

pub const DirFrame = struct { base: ?[]const u8, entries: List(fs.Dir.Entry) = undefined, id: u32 = 0 };

pub const DirEntries = struct {
    root: fs.Dir,
    stack: List(DirFrame),
    alloc: mem.Allocator,
    comptime less_than: ?fn (_: void, a: fs.Dir.Entry, b: fs.Dir.Entry) bool = struct {
        fn lexicalLT(_: void, a: fs.Dir.Entry, b: fs.Dir.Entry) bool {
            return mem.lessThan(u8, a.name, b.name);
        }
    }.lexicalLT,

    pub fn init(root: fs.Dir, path: []const u8, ally: mem.Allocator) !DirEntries {
        var de =
            DirEntries{ .root = root, .alloc = ally, .stack = List(DirFrame).init(ally) };
        if (path.len == 0) try de.traverse(de.root, DirFrame{ .base = null }) else try de.pushDir(path);
        return de;
    }
    pub fn reinit(de: *@This(), root: fs.Dir, path: []const u8) !void {
        while (de.stack.pop()) |frame| de.freeFrame(frame);
        de.stack.clearRetainingCapacity();
        de.root = root;
        if (path.len == 0) try de.pushRoot() else try de.pushDir(path);
    }
    pub fn deinit(de: *@This()) void {
        while (de.stack.pop()) |frame| de.freeFrame(frame);
        de.stack.clearAndFree();
    }
    fn freeFrame(de: *@This(), frame: DirFrame) void {
        var copy = frame;
        while (copy.entries.pop()) |entry| de.alloc.free(entry.name);
        copy.entries.clearAndFree();
        if (copy.base) |base| de.alloc.free(base);
    }

    fn pushDir(de: *@This(), path: []const u8) !void {
        var dir = try de.root.openDir(path, .{ .iterate = true });
        defer dir.close();

        try de.traverse(dir, DirFrame{ .base = try de.alloc.dupe(u8, path) });
    }
    fn traverse(de: *@This(), dir: fs.Dir, frame: DirFrame) !void {
        var copy = DirFrame{ .base = frame.base, .entries = List(fs.Dir.Entry).init(de.alloc) };
        var it = dir.iterate();
        while (try it.next()) |entry| {
            const dup = try de.alloc.dupe(u8, entry.name);
            try copy.entries.append(fs.Dir.Entry{ .name = dup, .kind = entry.kind });
        }
        if (de.less_than) |lt|
            if (copy.entries.items.len > 1) mem.sortUnstable(fs.Dir.Entry, copy.entries.items, {}, lt);
        try de.stack.append(copy);
    }
    pub fn next(de: *@This()) !?DirEntry {
        while (de.stack.items.len > 0) {
            var top = &de.stack.items[de.stack.items.len - 1];
            if (top.id < top.entries.items.len) {
                const entry = top.entries.items[top.id];
                top.id += 1;

                const ret = DirEntry{ .base = top.base, .name = entry.name, .kind = entry.kind };
                if (entry.kind == .directory) {
                    if (top.base) |base| {
                        var buf: [fs.max_path_bytes]u8 = undefined;
                        const full = joinAPath(&buf, base, entry.name);
                        try de.pushDir(full);
                    } else try de.pushDir(entry.name);
                }
                return ret;
            } else {
                de.freeFrame(de.stack.pop().?);
                continue;
            }
        }
        return null;
    }
    pub inline fn joinAPath(dst: []u8, base: []const u8, name: []const u8) []u8 {
        const len = base.len + 1 + name.len;
        db.assert(dst.len >= len);
        @memcpy(dst[0..base.len], base);
        dst[base.len] = fs.path.sep;
        @memcpy(dst[base.len + 1 .. len], name);
        return dst[0..len];
    }
};

const HashDirOptions = struct { buffer_len: u32 = 16 << 10, hash_len: u32 };

fn hashEntries(out_hash: []u8, de: *DirEntries, comptime opts: HashDirOptions) !void {
    db.assert(opts.buffer_len >= fs.max_path_bytes);
    var buf: [opts.buffer_len]u8 = undefined;
    var b3 = B3.init(.{});

    while (try de.next()) |entry| {
        var path: []u8 = undefined;
        if (entry.base) |base| {
            path = DirEntries.joinAPath(&buf, base, entry.name);
            if (fs.path.sep != fs.path.sep_posix) mem.replaceScalar(u8, path, fs.path.sep, fs.path.sep_posix);
        } else {
            path = buf[0..entry.name.len];
            @memcpy(path, entry.name);
        }
        if (mode == .ReleaseSafe) db.print("{s}\n", .{path});
        b3.update(path);

        if (entry.kind == .file) {
            const file = try de.root.openFile(path, .{});
            defer file.close();

            while (true) {
                const len = try file.read(&buf);
                if (len == 0) break;
                b3.update(buf[0..len]);
            }
        }
    }
    b3.final(out_hash);
    if (mode == .ReleaseSafe) db.print("\n{s}\n", .{fmt.bytesToHex(out_hash[0..opts.hash_len], .lower)});
}

pub fn main() !void {
    const hash_len = 32; // 256-bit
    var real: [hash_len]u8 = undefined;
    var hash: [hash_len]u8 = undefined;
    var alloc = heap.stackFallback(16 << 10, heap.raw_c_allocator);
    const sfba = alloc.get();

    var args = proc.argsWithAllocator(sfba) catch unreachable;
    if (!args.skip()) return error.TooFewArgs;

    const dir_path = args.next() orelse return error.MissingWorkingDirectoryArg;
    var dir = try fs.cwd().openDir(dir_path, .{ .no_follow = true, .iterate = true });
    defer dir.close();

    const hash_hex = args.next() orelse return error.MissingHashArg;
    _ = fmt.hexToBytes(&hash, hash_hex) catch return error.InvalidHash;
    if (args.skip()) return error.TooManyArgs;
    args.deinit();

    var entries = try DirEntries.init(dir, "", sfba);
    defer entries.deinit();

    try hashEntries(&real, &entries, .{ .hash_len = hash_len });
    if (!mem.eql(u8, &hash, &real)) return error.HashMismatch;
}
