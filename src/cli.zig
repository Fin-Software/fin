// SPDX-License-Identifier: Apache-2.0
// Copyright © 2024 The Whixy Authors. All rights reserved.
// Contributors responsible for this file:
// @p7r0x7 <mattrbonnette@pm.me>

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

/// Cova configuration type identity
const WhixyCmd = cmd: {
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

    break :cmd cova.Command.Custom(cmd_config);
};

/// Comptime-assembled Cova command definition for Whixy
const whixy_cmd: WhixyCmd = command("whixy",
    \\Build and execute Whixy programs.
, &.{
    command("cc",
        \\Invoke the internal LLVM Clang C compiler.
    , null, null, null),

    command("cxx",
        \\Invoke the internal LLVM Clang C++ compiler.
    , null, null, null),
}, null, &.{
    option(false, "version", null, value("", bool, false, parsing.parseBool, ""),
        \\Print version information string and exit.
    ),

    option(true, "help", &.{ "-help", "h" }, value("", bool, false, parsing.parseBool, ""),
        \\Print command help message and exit.
    ),
    option(true, "verbose", &.{"v"}, value("", bool, false, parsing.parseBool, ""),
        \\Increment command output verbosity.
    ),
    option(true, "quiet", &.{"q"}, value("", bool, false, parsing.parseBool, ""),
        \\Decrement command output verbosity.
    ),
    option(true, "ansi", null, value("", bool, true, parsing.parseBool, ""),
        \\Emit ANSI escape sequences with terminal output when available.
    ),
});

// Comptime-only structure assemblers
fn command(cmd: []const u8, desc: []const u8, cmds: ?[]const WhixyCmd, vals: ?[]const WhixyCmd.ValueT, opts: ?[]const WhixyCmd.OptionT) WhixyCmd {
    return .{ .name = cmd, .vals = vals, .sub_cmds = cmds, .description = replaceNewlines(desc), .hidden = desc.len == 0, .opts = opts, .allow_inheritable_opts = true };
}

fn option(inherit: bool, opt: []const u8, aliases: ?[]const []const u8, val: WhixyCmd.ValueT, desc: []const u8) WhixyCmd.OptionT {
    return .{ .val = val, .name = opt, .long_name = opt, .description = replaceNewlines(desc), .hidden = desc.len == 0, .alias_long_names = aliases, .inheritable = inherit };
}

fn value(val: []const u8, comptime ValT: type, default: ?ValT, parse: ?*const fn ([]const u8, mem.Allocator) anyerror!ValT, desc: []const u8) WhixyCmd.ValueT {
    return WhixyCmd.ValueT.ofType(ValT, .{ .name = val, .parse_fn = parse, .default_val = default, .description = replaceNewlines(desc) });
}

/// For readability, some literal strings in this file require comptime transformation before being manipulated at runtime.
inline fn replaceNewlines(comptime str: []const u8) []const u8 {
    comptime {
        @setEvalBranchQuota(3 << 10);
        var buf = str[0..].*;
        mem.replaceScalar(u8, &buf, nb, spaces[0]);
        const out = buf;
        return &out;
    }
}

pub inline fn print(wr: anytype, strs: anytype) !void {
    inline for (strs) |str| {
        switch (@typeInfo(@TypeOf(str))) {
            .array => try wr.writeAll(&str),
            .pointer => try wr.writeAll(str),
            .int, .comptime_int => try wr.writeByte(str),
            else => @compileError("Expected byte or string, got " ++ @typeName(@TypeOf(str))),
        }
    }
}

/// Printing callback functions for Cova commands and options
const printing = struct {
    const schemes = [_]ColorScheme{
        ColorScheme{ .one = "\x1b[40;1;38;5;230m", .two = "\x1b[38;5;111m" }, // discord: buttercream, blurple
        //ColorScheme{ .one = "\x1b[40;1;38;5;220m", .two = "\x1b[38;5;36m" }, // transit: schoolbus yellow, highway sign green
    };
    const ColorScheme = struct { one: []const u8, two: []const u8 };
    var active_scheme: ?ColorScheme = null; // Global runtime variable.

    fn NonCSIRuneCountingWriter(comptime Wrapped: type) type {
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
    inline fn nonCSIRuneCountingWriter(writer: anytype) NonCSIRuneCountingWriter(@TypeOf(writer)) {
        return .{ .inner = writer };
    }

    fn SplitPattern(comptime T: type) type {
        return struct { cut_offset: isize, pattern: T };
    }
    const CharacterGroupIterator = CustomSplitIterator(u8, &[_]SplitPattern(u8){
        .{ .cut_offset = 1, .pattern = '-' },
        .{ .cut_offset = 0, .pattern = spaces[0] },
    });
    fn CustomSplitIterator(comptime T: type, comptime patterns: []const SplitPattern(T)) type {
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
            dex: usize = 0,

            pub inline fn first(csit: *@This()) []const T {
                db.assert(csit.dex == 0);
                return csit.next().?;
            }
            pub fn next(csit: *@This()) ?[]const T {
                if (csit.dex == csit.buf.len) return null;
                if (mem.indexOfAnyPos(T, csit.buf, csit.dex + 1, items)) |pos| {
                    const offset = offsets[mem.indexOfScalar(T, items, csit.buf[pos]).?];
                    const end: usize = @intCast(@as(isize, @intCast(pos)) + offset);
                    defer csit.dex += end - csit.dex;
                    return csit.buf[csit.dex..end];
                } else {
                    defer csit.dex = csit.buf.len;
                    return csit.buf[csit.dex..];
                }
            }
        };
    }

    fn commandUsage(root: anytype, wr: anytype, _: ?mem.Allocator) !void {
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

    fn commandHelp(root: anytype, wr: anytype, _: ?mem.Allocator) !void {
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

    fn valueUsage(val: anytype, wr: anytype, _: ?mem.Allocator) !void {
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
        } else db.panic("{s}", .{"Unimplemented type."});
        try print(wr, .{ "  default: ", str });
    }

    fn valueHelp(val: anytype, wr: anytype, _: ?mem.Allocator) !void {
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

    fn optionUsage(opt: anytype, wr: anytype, _: ?mem.Allocator) !void {
        try print(wr, .{ @TypeOf(opt.*).long_prefix.?, opt.long_name.? });
        if (opt.alias_long_names) |alias_long_names| {
            for (alias_long_names) |alias_long_name| {
                try print(wr, .{ ", " ++ @TypeOf(opt.*).long_prefix.?, alias_long_name });
            }
        }
        try print(wr, .{spaces[0]});
        try opt.val.usage(wr);
    }

    fn optionHelp(opt: anytype, wr: anytype, _: ?mem.Allocator) !void {
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

    fn isCSISupported(pipe: fs.File, it: *cova.ArgIteratorGeneric, ally: mem.Allocator) !bool {
        const available = io.tty.detectConfig(pipe) == .escape_codes;
        if (available) {
            return flag: {
                defer it.reset();
                _ = it.next(); // Skip arg[0], the program name.
                while (it.next()) |arg| {
                    if (arg.len < 5) continue;
                    if (ascii.eqlIgnoreCase("-ansi", arg[0..5])) {
                        const seps = WhixyCmd.OptionT.opt_val_seps;
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
const margin = columns - (WhixyCmd.indent_fmt.len * 2);
const spaces = [_]u8{' '} ** 4; // Adjust as necessary.
const zero = "\x1b[0m";
const columns = 100;
const ns = "\n";
const nb = '\n';

/// runWhixy() is the entry point for the CLI.
pub fn runWhixy(pipe: fs.File, ally: mem.Allocator) !void {
    var bfwr = io.bufferedWriter(pipe.writer());
    defer bfwr.flush() catch db.panic("{s}", .{"Failed to flush buffered writer to pipe."});
    try print(bfwr.writer(), .{nb});
    defer print(pipe.writer(), .{nb}) catch db.panic("{s}", .{"Couldn't print final newline."});

    const whixy_cli = try whixy_cmd.init(ally, .{
        .help_config = .{
            .add_cmd_help_group = .DoNotAdd,
            .add_opt_help_group = .DoNotAdd,
            .add_help_cmds = false,
            .add_help_opts = false,
        },
    });
    defer whixy_cli.deinit();
    defer if (builtin.mode == .Debug) cova.utils.displayCmdInfo(WhixyCmd, whixy_cli, ally, bfwr.writer(), false) catch
        db.panic("{s}", .{"Failed to display Cova debug info."});
    {
        var arg_it = try cova.ArgIteratorGeneric.init(ally);
        printing.active_scheme = if (try printing.isCSISupported(pipe, &arg_it, ally)) printing.schemes[0] else null;
        try cova.parseArgs(&arg_it, WhixyCmd, whixy_cli, bfwr.writer(), .{
            .set_opt_termination_symbol = "--", // This is the most common terminator, even if long flags start with '-'.
            .auto_handle_usage_help = false,
            .enable_opt_termination = true,
            .err_reaction = .Help,
        });
        (&arg_it).deinit();
    }
    {
        const cmd = whixy_cli.sub_cmd orelse {
            try whixy_cli.help(bfwr.writer());
            try bfwr.flush();
            return;
        };
        var values = try cmd.getVals(.{});
        const input = values.get("input_path");
        if (cmd.checkOpts(&.{"help"}, .{}) or !input.?.generic.string.is_set) {
            try cmd.help(bfwr.writer());
            try bfwr.flush();
        }
    }
}

/// Parsing callback functions for possible CLI inputs
const parsing = struct {
    fn parseInt(comptime T: type, base: u8) fn ([]const u8, mem.Allocator) anyerror!T {
        return struct {
            fn parseInt(arg: []const u8, _: mem.Allocator) !T {
                return fmt.parseInt(T, arg, base);
            }
        }.parseInt;
    }

    fn parseOptimize(arg: []const u8, _: mem.Allocator) ![]const u8 {
        const deadlines = [_][]const u8{ "fast", "good", "best" };
        for (deadlines) |str| if (ascii.eqlIgnoreCase(str, arg)) return str;
        return error.OptimizeValueUnsupported;
    }

    fn parseBool(arg: []const u8, _: mem.Allocator) !bool {
        const T = [_][]const u8{ "1", "true", "t", "yes", "y" };
        const F = [_][]const u8{ "0", "false", "f", "no", "n" };
        for (T) |str| if (ascii.eqlIgnoreCase(str, arg)) return true;
        for (F) |str| if (ascii.eqlIgnoreCase(str, arg)) return false;
        return error.BooleanValueUnsupported;
    }
};
