const cova = @import("cova");
const io = @import("std").io;
const os = @import("std").os;
const fs = @import("std").fs;
const fmt = @import("std").fmt;
const mem = @import("std").mem;
const db = @import("std").debug;
const ascii = @import("std").ascii;
const builtin = @import("builtin");
const utf8 = @import("std").unicode;

pub const margin = columns - (CmdT.indent_fmt.len * 2);
pub const spaces = [_]u8{' '} ** 4; // Adjust as necessary.
pub const zero = "\x1b[0m";
pub const columns = 100;
pub const ns = "\n";
pub const nb = '\n';

pub const ColorScheme = struct { one: []const u8, two: []const u8 };
pub var active_scheme: ?ColorScheme = null; // Global variable.

/// Cova configuration type identity
pub const CmdT = cmd: {
    var cmd_config = cova.Command.Config.optimized(.{ .no_formats = true, .remove_features = true });

    cmd_config.opt_config.global_usage_fn = printing.optionUsage;
    cmd_config.opt_config.global_help_fn = printing.optionHelp;
    cmd_config.opt_config.allow_abbreviated_long_opts = false;
    cmd_config.opt_config.allow_opt_val_no_space = true;
    cmd_config.opt_config.indent_fmt = spaces[0..4];
    cmd_config.opt_config.opt_val_seps = "=:";
    cmd_config.opt_config.short_prefix = null;
    cmd_config.opt_config.long_prefix = "-";

    cmd_config.val_config.global_usage_fn = printing.valueUsage;
    cmd_config.val_config.global_help_fn = printing.valueHelp;
    cmd_config.val_config.use_custom_bit_width_range = false;
    cmd_config.val_config.global_set_behavior = .Last;
    cmd_config.val_config.indent_fmt = spaces[0..4];
    cmd_config.val_config.add_base_floats = false;
    cmd_config.val_config.add_base_ints = false;
    cmd_config.val_config.custom_types = &.{u8};
    cmd_config.val_config.use_slim_base = true;
    cmd_config.val_config.max_children = 1;

    cmd_config.global_usage_fn = printing.commandUsage;
    cmd_config.global_help_fn = printing.commandHelp;
    cmd_config.global_allow_inheritable_opts = true;
    cmd_config.global_sub_cmds_mandatory = false;
    cmd_config.global_case_sensitive = false;
    cmd_config.global_vals_mandatory = false;
    cmd_config.indent_fmt = spaces[0..4];
    cmd_config.global_help_prefix = "";
    cmd_config.auto_flush = false;

    break :cmd cova.Command.Custom(cmd_config);
};

pub const printing = struct {
    pub fn NonCSIRuneCountingWriter(comptime Wrapped: type) type {
        return struct {
            inner: Wrapped,
            rune_count: usize = 0,

            pub const Inner = Wrapped;
            pub const Error = Wrapped.Error || error{
                MalformedControlSequence,
                Utf8ExpectedContinuation,
                Utf8EncodesSurrogateHalf,
                Utf8CodepointTooLarge,
                Utf8InvalidStartByte,
                Utf8OverlongEncoding,
                TruncatedInput,
            };

            pub fn writer(rcw: *@This()) io.Writer(*@This(), Error, write) {
                return .{ .context = rcw };
            }
            fn write(rcw: *@This(), str: []const u8) !usize {
                const runes = try countVisibleRunes(str);
                defer rcw.rune_count += runes;
                try rcw.inner.writeAll(str);
                return str.len;
            }
            fn countVisibleRunes(str: []const u8) !usize {
                // https://www.wikiwand.com/en/ANSI_escape_code#CSI_(Control_Sequence_Introducer)_sequences
                const csi = "\x1b[";
                var runes: usize = 0;
                var index: usize = 0;
                while (mem.indexOfPos(u8, str, index, csi)) |start| {
                    const end = for (str[start + csi.len ..], start + csi.len..) |c, i| {
                        if (c >= '@' and c <= '~') break i;
                    } else return error.MalformedControlSequence;
                    if (start != 0) runes += try utf8.utf8CountCodepoints(str[index .. start - 1]);
                    index = end + 1;
                } else runes += try utf8.utf8CountCodepoints(str[index..]);
                return runes;
            }
        };
    }
    pub inline fn nonCSIRuneCountingWriter(writer: anytype) NonCSIRuneCountingWriter(@TypeOf(writer)) {
        return .{ .inner = writer };
    }

    pub fn SplitPattern(comptime T: type) type {
        return struct { cut_offset: isize, pattern: T };
    }
    pub const CharacterGroupIterator = CustomSplitIterator(u8, &[_]SplitPattern(u8){
        .{ .cut_offset = 1, .pattern = '-' },
        .{ .cut_offset = 0, .pattern = spaces[0] },
    });
    pub fn CustomSplitIterator(comptime T: type, comptime patterns: []const SplitPattern(T)) type {
        const items, const offsets = splitPattern: {
            var items_arr: [patterns.len]T, var offsets_arr: [patterns.len]isize = .{ undefined, undefined };
            for (&items_arr, &offsets_arr, patterns) |*i, *o, v| {
                i.* = v.pattern;
                o.* = v.cut_offset;
            }
            const items_out, const offsets_out = .{ items_arr, offsets_arr };
            break :splitPattern .{ items_out[0..], offsets_out[0..] };
        };
        return struct {
            buf: []const T,
            i: usize = 0,

            pub inline fn first(csit: *@This()) []const T {
                db.assert(csit.i == 0);
                return csit.next().?;
            }
            pub fn next(csit: *@This()) ?[]const T {
                if (csit.i == csit.buf.len) return null;
                if (mem.indexOfAnyPos(T, csit.buf, csit.i + 1, items)) |pos| {
                    const offset = offsets[mem.indexOfScalar(T, items, csit.buf[pos]).?];
                    const end: usize = @intCast(@as(isize, @intCast(pos)) + offset);
                    defer csit.i += end - csit.i;
                    return csit.buf[csit.i..end];
                } else {
                    defer csit.i = csit.buf.len;
                    return csit.buf[csit.i..];
                }
            }
        };
    }

    pub fn commandUsage(root: anytype, wr: anytype, _: ?mem.Allocator) !void {
        try print(wr, .{ "USAGE   ", root.name, spaces[0] });
        if (root.sub_cmds != null) try print(wr, " [command]");
        if (root.vals) |vals| for (vals) |val| try print(wr, .{ " <", val.name(), '>' });
        if (root.opts != null) try print(wr, .{" [option ...]"});

        const indent = @TypeOf(root.*).indent_fmt;
        try print(wr, .{ns ++ ns ++ indent ++ indent});
        if (active_scheme) |v| try print(wr, .{v.one});

        var rcw = nonCSIRuneCountingWriter(wr);
        var it = CharacterGroupIterator{ .buf = root.description };
        var next: ?[]const u8 = it.first();
        while (next != null) : (next = it.next()) {
            if (rcw.rune_count + next.?.len <= margin) {
                try print(rcw.writer(), .{next.?});
            } else {
                rcw.rune_count = 0;
                if (active_scheme) |_| try print(wr, .{zero});
                try print(wr, .{ns ++ indent ++ indent});
                if (active_scheme) |v| try print(wr, .{v.one});
                try print(rcw.writer(), .{if (next.?[0] == spaces[0]) next.?[1..] else next.?});
            }
        }
        if (active_scheme) |_| try print(wr, .{zero});
        try print(wr, .{ns ++ ns});
    }

    pub fn commandHelp(root: anytype, wr: anytype, _: ?mem.Allocator) !void {
        try root.usage(wr);
        if (root.sub_cmds) |cmds| {
            const indent = @TypeOf(root.*).indent_fmt;
            for (cmds) |cmd| {
                if (cmd.hidden) continue;
                var rcw = nonCSIRuneCountingWriter(wr);
                try print(rcw.writer(), .{ indent ++ indent, root.name, spaces[0], cmd.name, ":  " });
                if (active_scheme) |v| try print(wr, .{v.one});
                var it = CharacterGroupIterator{ .buf = cmd.description };
                var next: ?[]const u8 = it.first();
                while (next != null) : (next = it.next()) {
                    if (rcw.rune_count + next.?.len <= margin) {
                        try print(rcw.writer(), .{next.?});
                    } else {
                        rcw.rune_count = 0;
                        if (active_scheme) |_| try print(wr, .{zero});
                        try print(wr, .{ns ++ indent ++ indent});
                        if (active_scheme) |v| try print(wr, .{v.one});
                        try print(rcw.writer(), .{if (next.?[0] == spaces[0]) next.?[1..] else next.?});
                    }
                }
                if (active_scheme) |_| try print(wr, .{zero});
                try print(wr, .{ns});
            }
            try print(wr, .{nb});
        }
        if (root.vals) |vals| {
            try print(wr, .{(spaces[0..1] ** 89) ++ "values:" ++ ns ++ ns});
            for (vals) |val| {
                try val.help(wr);
                try print(wr, .{nb});
            }
        }
        if (root.opts) |opts| {
            var done = false;
            for (opts) |opt| {
                if (opt.hidden) continue;
                if (opt.inheritable) continue;
                if (!done) {
                    try print(wr, .{(spaces[0..1] ** 88) ++ "options:" ++ ns ++ ns});
                    done = true;
                }
                try opt.help(wr);
                try print(wr, .{nb});
            }
        }
        var done, var tmp: ?@TypeOf(root) = .{ false, root };
        while (tmp) |cmd| : (tmp = cmd.parent_cmd) {
            if (cmd.opts) |opts| {
                for (opts) |opt| {
                    if (opt.hidden) continue;
                    if (!opt.inheritable) continue;
                    if (!done) {
                        try print(wr, .{ns ++ "GLOBAL" ++ (spaces[0..1] ** 82) ++ "options:" ++ ns ++ ns});
                        done = true;
                    }
                    try opt.help(wr);
                    try print(wr, .{nb});
                }
            }
        }
    }

    pub fn valueUsage(val: anytype, wr: anytype, _: ?mem.Allocator) !void {
        if (active_scheme) |v| try print(wr, .{v.one});
        try print(wr, .{'"'});
        const val_name = val.name();
        if (val_name.len > 0) try print(wr, .{ val_name, spaces[0] });
        try print(wr, .{'('});
        const child_type = val.childType();
        if (mem.eql(u8, child_type[0..1], "u")) {
            try print(wr, .{"uint"});
        } else if (mem.eql(u8, child_type[0..1], "i")) {
            try print(wr, .{"int"});
        } else if (mem.eql(u8, child_type, "[]const u8")) {
            try print(wr, .{"string"});
        } else try print(wr, .{child_type});
        try print(wr, .{")\""});
        if (active_scheme) |_| try print(wr, .{zero});

        var str: []const u8 = undefined;
        if (mem.eql(u8, child_type, "[]const u8")) {
            str = val.generic.string.default_val orelse return;
        } else if (mem.eql(u8, child_type, "bool")) {
            str = if (val.generic.bool.default_val orelse return) "true" else "false";
        } else if (mem.eql(u8, child_type, "u8")) {
            var buf: [3]u8 = undefined;
            str = try fmt.bufPrint(buf[0..], "{d}", .{val.generic.u8.default_val orelse return});
        } else error.UnimplementedType;
        try print(wr, .{ "  default: ", str });
    }

    pub fn valueHelp(val: anytype, wr: anytype, _: ?mem.Allocator) !void {
        const indent = @TypeOf(val.*).indent_fmt;
        try print(wr, indent);
        var rcw = nonCSIRuneCountingWriter(wr);
        try val.usage(rcw.writer());
        try print(rcw.writer(), .{spaces[0..2]});
        if (active_scheme) |v| try print(wr, .{v.two});
        var it = CharacterGroupIterator{ .buf = val.description() };
        var next: ?[]const u8 = it.first();
        while (next != null) : (next = it.next()) {
            if (rcw.rune_count + next.?.len <= margin) {
                try print(rcw.writer(), .{next.?});
            } else {
                rcw.rune_count = 0;
                if (active_scheme) |_| try print(wr, .{zero});
                try print(wr, .{ns ++ indent});
                if (active_scheme) |v| try print(wr, .{v.two});
                try print(rcw.writer(), .{if (next.?[0] == spaces[0]) next.?[1..] else next.?});
            }
        }
        if (active_scheme) |_| try print(wr, .{zero});
        try print(wr, .{ns});
    }

    pub fn optionUsage(opt: anytype, wr: anytype, _: ?mem.Allocator) !void {
        try print(wr, .{ @TypeOf(opt.*).long_prefix.?, opt.long_name.? });
        if (opt.alias_long_names) |alias_long_names| {
            for (alias_long_names) |alias_long_name| {
                try print(wr, .{ ", " ++ @TypeOf(opt.*).long_prefix.?, alias_long_name });
            }
        }
        try print(wr, .{spaces[0]});
        try opt.val.usage(wr);
    }

    pub fn optionHelp(opt: anytype, wr: anytype, _: ?mem.Allocator) !void {
        try print(wr, .{@TypeOf(opt.*).indent_fmt.?});
        var rcw = nonCSIRuneCountingWriter(wr);
        try opt.usage(rcw.writer());

        try print(rcw.writer(), .{spaces[0..2]});
        if (active_scheme) |v| try print(wr, .{v.two});
        var it = CharacterGroupIterator{ .buf = opt.description };
        var next: ?[]const u8 = it.first();
        while (next != null) : (next = it.next()) {
            if (rcw.rune_count + next.?.len <= margin) {
                try print(rcw.writer(), .{next.?});
            } else {
                rcw.rune_count = 0;
                if (active_scheme) |_| try print(wr, .{zero});
                try print(wr, .{ns ++ @TypeOf(opt.*).indent_fmt.?});
                if (active_scheme) |v| try print(wr, .{v.two});
                try print(rcw.writer(), .{if (next.?[0] == spaces[0]) next.?[1..] else next.?});
            }
        }
        if (active_scheme) |_| try print(wr, .{zero});
        try print(wr, .{ns});
    }

    pub fn isCSISupported(pipe: fs.File, it: *cova.ArgIteratorGeneric, ally: mem.Allocator) !bool {
        const available = io.tty.detectConfig(pipe) == .escape_codes;
        if (available) {
            return flag: {
                defer it.reset();
                _ = it.next(); // Skip arg[0], the program name.
                while (it.next()) |arg| {
                    if (arg.len < 5) continue;
                    if (ascii.eqlIgnoreCase("-ansi", arg[0..5])) {
                        const seps = CmdT.OptionT.opt_val_seps;
                        const val = switch (arg[5]) {
                            seps[0], seps[1], spaces[0] => arg[6..],
                            else => arg[5..],
                        };
                        break :flag parsing.parseBool(val, ally);
                    }
                }
                break :flag true;
            };
        } else return false;
    }
};

/// Parsing callback functions for possible CLI inputs
pub const parsing = struct {
    pub fn passThrough(arg: []const u8, _: mem.Allocator) ![]const u8 {
        return arg;
    }
    pub fn parseInt(comptime T: type, base: u8) fn ([]const u8, mem.Allocator) anyerror!T {
        return struct {
            fn parseInt(arg: []const u8, _: mem.Allocator) !T {
                return fmt.parseInt(T, arg, base);
            }
        }.parseInt;
    }
    pub fn parseBool(arg: []const u8, _: mem.Allocator) !bool {
        const T = [_][]const u8{ "1", "true", "t", "yes", "y" };
        const F = [_][]const u8{ "0", "false", "f", "no", "n" };
        for (T) |str| if (ascii.eqlIgnoreCase(str, arg)) return true;
        for (F) |str| if (ascii.eqlIgnoreCase(str, arg)) return false;
        return error.BooleanValueUnsupported;
    }
};

//
//    Folded
//

// zig fmt: off
pub fn command(cmd: []const u8, desc: []const u8, cmds: ?[]const CmdT, vals: ?[]const CmdT.ValueT, opts: ?[]const CmdT.OptionT) CmdT {
    return .{ .name = cmd, .vals = vals, .sub_cmds = cmds, .description = normalizeWS(desc), .hidden = desc.len == 0, .opts = opts, .allow_inheritable_opts = true };
}
pub fn option(inherit: bool, opt: []const u8, aliases: ?[]const []const u8, val: CmdT.ValueT, desc: []const u8) CmdT.OptionT {
    return .{ .val = val, .name = opt, .long_name = opt, .description = normalizeWS(desc), .hidden = desc.len == 0, .alias_long_names = aliases, .inheritable = inherit };
}
pub fn value(val: []const u8, comptime ValT: type, default: ?ValT, parse: ?*const fn ([]const u8, mem.Allocator) anyerror!ValT, desc: []const u8) CmdT.ValueT {
    return CmdT.ValueT.ofType(ValT, .{ .name = val, .parse_fn = parse, .default_val = default, .description = normalizeWS(desc) });
}
// zig fmt: on

pub fn normalizeWS(comptime str: []const u8) []const u8 {
    var out: [str.len]u8 = undefined;
    var len: u16 = 0;
    var i: u16 = 0;

    @setEvalBranchQuota(64 << 10);
    while (i < str.len) {
        const start = mem.indexOfNonePos(u8, str, i, " \t\n\r") orelse break;
        const end = mem.indexOfAnyPos(u8, str, start, " \t\n\r") orelse str.len;

        if (len > 0) {
            out[len] = ' ';
            len += 1;
        }
        mem.copyForwards(u8, out[len..], str[start..end]);
        len += end - start;
        i = end;
    }
    return out[0..len];
}

pub inline fn print(wr: *io.Writer, strs: anytype) !void {
    inline for (strs) |str| {
        switch (@typeInfo(@TypeOf(str))) {
            .array => try wr.writeAll(&str),
            .pointer => try wr.writeAll(str),
            .int, .comptime_int => try wr.writeByte(str),
            else => error.UnimplementedType,
        }
    }
}
