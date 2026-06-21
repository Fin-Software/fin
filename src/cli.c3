// SPDX-License-Identifier: Apache-2.0
// Copyright © 2026 Maxine Bonnette. All rights reserved.
// Inspired by https://github.com/00JCIV00/cova.

module fin::cli;

alias ParsedCmd = int; // debug
alias CommandFn = fn int (ParsedCmd*);
struct Cmd
{
    String name, description; Cmd[] subcmds; Opt[] options; CommandFn cmd_fn;
}
enum OptKind @private { POSITIONAL, HIDDEN, PLAIN }  // Positional options are required flagless arguments.
struct Opt @private
{
    String name, description, default_val; String[] aliases; Val value; short max_arity; bool inherited; OptKind kind;
}
alias ParseFn = fn void? (void*, String);
struct Val @private
{
    String name; ParseFn parser;
}

macro Cmd command(String $name, String $desc, CommandFn cmd_fn, Cmd[] $subcmds = {}, Opt[] $opts = {})
{
    return {
        .name = $name,
        .description = $desc,
        .cmd_fn = cmd_fn,
        .subcmds = $subcmds,
        .options = $opts
    };
}
macro Opt positional(bool $inherited, String $name, String[] $aliases, String default_val, Val $val, String $desc = "", short $max = 1)
{
    return {
        .inherited = $inherited,
        .name = $name,
        .aliases = $aliases,
        .default_val = default_val,
        .value = $val,
        .description = $desc,
        .max_arity = $max,
        .kind = POSITIONAL,
    };
}
macro Opt option(bool $inherited, String $name, String[] $aliases, String default_val, Val $val, String $desc = "", short $max = 1)
{
    return {
        .inherited = $inherited,
        .name = $name,
        .aliases = $aliases,
        .default_val = default_val,
        .value = $val,
        .description = $desc,
        .max_arity = $max,
        .kind = $desc.len > 0 ? PLAIN : HIDDEN,  // Options with empty descriptions are hidden.
    };
}
macro Val value(String $name, ParseFn $parser, String $desc) => { .name = $name, .parser = $parser };

struct CLParser
{
    Allocator alloc;
    String[] option_starters;
    String[] alias_starters;
    String[] option_value_seps;
    bool reverse_option_fill;  // Args are never reversed. Semantics of mv.
    short max_columns;
}
alias CmdPrintFn = fn void? (CLParser*, Cmd*);
alias OptPrintFn = fn void? (CLParser*, Opt*);
alias ValPrintFn = fn void? (CLParser*, Val*);
struct CLPrintFns
{
    CmdPrintFn cmd_help, cmd_usage;
    OptPrintFn opt_help, opt_usage;
    ValPrintFn val_help, val_usage;
}

const CLParser DEFAULT_CLI_PARSER = {
    .alloc = &allocators::LIBC_ALLOCATOR,
    .option_starters = env::WIN32 ? { "/", "--" } : {"--"},
    .alias_starters = env::WIN32 ? { "/", "-" } : {"-"},
    .option_value_seps = { "=", ":" },
    .reverse_option_fill = false,
    .max_columns = 80,
};
const CLPrintFns DEFAULT_CLI_PRINTERS = {
    .cmd_help = &default_cmd_help,
    .cmd_usage = &default_cmd_usage,
    .opt_help = &default_opt_help,
    .opt_usage = &default_opt_usage,
    .val_help = &default_val_help,
    .val_usage = &default_val_usage,
};


fn void? CLParser.parse(&clp, Cmd* command, String[] args, CLPrintFns printers = DEFAULT_CLI_PRINTERS) {
    
}

const Cmd FIN_CLI = command(
    "fin", "Just-in-Time or Ahead-of-Time compile and execute Fin programs.",
{
    command("cc", "Invoke the provided LLVM Clang driver in C mode."),
    command("cxx", "Invoke the provided LLVM Clang driver in C++ mode."),
    command("cl", "Invoke the provided LLVM Clang driver in MSVC mode."),
    command("as", "Invoke the provided LLVM Clang driver in assembler mode."),
    command("ld", "Invoke the provided LLVM linker."),
    command("lsp", "Invoke the language server or toggle its daemon."),
    command("fmt", "Format Fin source files."),
    command("env", "Print installation and environment variables."),
}, {
    positional(false, "sources", {}, "", value("", &pass_through),
        "Paths to Fin source files or directories recursively containing them.", short::max
    ),

    option(false, "version", {}, "false", value("", &parse_bool),
        "Print version information string and exit."
    ),

    option(true, "help", { "-help", "h" }, "false", value("", &parse_bool),
        "Print command help message and exit."
    ),
    option(true, "verbose", {"v"}, "false", value("" &parse_bool),
        "Increment command output verbosity.", 5
    ),
    option(true, "quiet", {"q"}, "false", value("", &parse_bool),
        "Decrement command output verbosity.", 5
    ),
    option(true, "ansi", {}, "true", value("", &parse_bool),
        "Emit ANSI escape sequences with terminal output when available."
    ),
});

faultdef UNSUPPORTED_BOOLEAN;

fn void? pass_through(void* dst, String s) { *(String*)dst = s; }

fn void? parse_float(void* dst, String s) { *(float*)dst = s.to_float()!; }

fn void? parse_fouble(void* dst, String s) { *(double*)dst = s.to_double()!; }

fn void? parse_int(void* dst, String s) <Type, BASE> { *(Type*)dst = s.to_integer{Type}(BASE)!; }

fn void? parse_bool(void* dst, String s) {
    foreach (t : (String[]){"1", "true", "t", "yes", "y"})
        if (s.compare_to_ignore_case(t) == 0) { *(bool*)dst = true; return; }
    foreach (f : (String[]){"0", "false", "f", "no", "n"})
        if (s.compare_to_ignore_case(f) == 0) { *(bool*)dst = false; return; }
    return UNSUPPORTED_BOOLEAN~;
}
