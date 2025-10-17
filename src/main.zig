// SPDX-License-Identifier: Apache-2.0
// Copyright © 2025 The Fin Authors. All rights reserved.
// Contributors responsible for this file:
// @p7r0x7 <mattrbonnette@pm.me>

const cova = @import("cova");
const io = @import("std").io;
const os = @import("std").os;
const fs = @import("std").fs;
const fmt = @import("std").fmt;
const mem = @import("std").mem;
const db = @import("std").debug;
const heap = @import("std").heap;
const builtin = @import("builtin");
const utf8 = @import("std").unicode;

const cli = @import("cli.zig");
const printing = cli.printing;
const parsing = cli.parsing;
const command = cli.command;
const option = cli.option;
const value = cli.option;
const print = cli.print;

const nb = cli.nb;

const schemes = [_]cli.ColorScheme{
    cli.ColorScheme{ .one = "\x1b[48;5;0;38;5;230;1m", .two = "\x1b[38;5;111m" }, // discord: buttercream, blurple
    //cli.ColorScheme{ .one = "\x1b[48;5;0;38;5;220;1m", .two = "\x1b[38;5;36m" }, // transit: schoolbus yellow, highway sign green
};

/// Comptime-assembled Cova command definition for Fin
const fin_cmd: cli.CmdT = command("fin",
    \\Just-in-Time or Ahead-of-Time compile and execute Fin programs.
, &.{
    command("cc",
        \\Invoke fin's provided LLVM Clang driver in C mode.
    , null, null, null),

    command("cxx",
        \\Invoke fin's provided LLVM Clang driver in C++ mode.
    , null, null, null),

    command("cl",
        \\Invoke fin's provided LLVM Clang driver in MSVC mode.
    , null, null, null),

    command("as",
        \\Invoke the provided LLVM assembler.
    , null, null, null),

    command("ld",
        \\Invoke the provided LLVM linker.
    , null, null, null),

    command("lsp",
        \\Invoke the language server or toggle its daemon.
    , null, null, null),

    command("fmt",
        \\Format Fin source files.
    , null, null, null),

    command("env",
        \\Print installation and environment variables.
    , null, null, null),
}, &.{
    value(false, "path", null, parsing.passThrough,
        \\Path to the
    ),
}, &.{
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

/// runFin() is the entry point for the CLI.
fn runFin(pipe: fs.File, ally: mem.Allocator) !void {
    var buf: [4 << 10]u8 = undefined;
    var writer = pipe.writer(&buf);
    const bfwr = &writer.interface;

    try print(bfwr, .{nb});
    defer bfwr.flush() catch db.panic("{s}", .{"Failed to flush buffered writer to pipe."});
    defer print(bfwr, .{nb}) catch db.panic("{s}", .{"Failed to print final newline."});

    const fin_cli = try fin_cmd.init(ally, .{ .help_config = .{
        .add_cmd_help_group = .DoNotAdd,
        .add_opt_help_group = .DoNotAdd,
        .add_help_cmds = false,
        .add_help_opts = false,
    } });
    defer fin_cli.deinit();
    defer if (builtin.mode == .Debug) cova.utils.displayCmdInfo(cli.CmdT, fin_cli, ally, bfwr, false) catch
        db.panic("{s}", .{"Failed to display Cova debug info."});

    var arg_it = try cova.ArgIteratorGeneric.init(ally);
    printing.active_scheme = if (try printing.isCSISupported(pipe, &arg_it, ally)) printing.schemes[0] else null;
    try cova.parseArgs(&arg_it, cli.CmdT, fin_cli, bfwr, .{
        .set_opt_termination_symbol = "--", // This is the most common terminator, even if long flags start with '-'.
        .auto_handle_usage_help = false,
        .enable_opt_termination = true,
        .err_reaction = .Help,
    });
    (&arg_it).deinit();

    const cmd = fin_cli.sub_cmd orelse {
        try fin_cli.help(bfwr);
        try bfwr.flush();
        return;
    };
    var values = try cmd.getVals(.{});
    const input = values.get("input_path");
    if (cmd.checkOpts(&.{"help"}, .{}) or input == null) {
        try cmd.help(bfwr);
        try bfwr.flush();
    }
}

pub fn main() !void {
    const stderr = fs.File.stderr();

    // Run VPXL's CLI using an arena-wrapped stack allocator.
    var buf: [9 << 10]u8 = undefined; // Adjust as necessary.
    var fba = heap.FixedBufferAllocator.init(buf[0..]);
    try runFin(stderr, fba.allocator());
}
