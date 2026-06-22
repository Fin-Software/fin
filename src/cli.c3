// SPDX-License-Identifier: Apache-2.0
// Copyright © 2026 Maxine Bonnette. All rights reserved.
// Inspired by the https://github.com/00JCIV00/cova zig project.

module fin::cli;

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
alias ParsedCmd = int; // debug
alias ParsedOpt = int; // debug
alias ParsedVal = int; // debug


macro Cmd command(String $name, String $desc, CommandFn $cmd_fn, Cmd[] $subcmds = {}, Opt[] $opts = {})
{
    return {
        .name = $name,
        .description = $desc,
        .cmd_fn = $cmd_fn,
        .subcmds = $subcmds,
        .options = $opts
    };
}
macro Opt positional(bool $inherited, String $name, String $default_val, Val $val, String $desc = "", short $max = 1)
{
    return {
        .inherited = $inherited,
        .name = $name,
        .default_val = $default_val,
        .value = $val,
        .description = $desc,
        .max_arity = $max,
        .kind = POSITIONAL,
    };
}
macro Opt option(bool $inherited, String $name, String[] $aliases, String $default_val, Val $val, String $desc = "", short $max = 1)
{
    return {
        .inherited = $inherited,
        .name = $name,
        .aliases = $aliases,
        .default_val = $default_val,             // Empty default_vals are treated as non-existent.
        .value = $val,
        .description = $desc,
        .max_arity = $max,                       // Options with an arity of 1 may be overridden.
        .kind = $desc.len > 0 ? PLAIN : HIDDEN,  // Options with empty descriptions are hidden.
    };
}
macro Val value(String $name, ParseFn $parser) => { .name = $name, .parser = $parser };

faultdef UNSUPPORTED_BOOLEAN;

fn void? pass_through(void* dst, String s) { *(String*)dst = s; }

fn void? parse_float(void* dst, String s) { *(float*)dst = s.to_float()!; }

fn void? parse_double(void* dst, String s) { *(double*)dst = s.to_double()!; }

fn void? parse_int(void* dst, String s) <Type, BASE> { *(Type*)dst = s.to_integer{Type}(BASE)!; }

fn void? parse_bool(void* dst, String s)
{
    foreach (t : (String[]){"1", "true", "t", "yes", "y"})
        if (s.compare_to_ignore_case(t) == 0) { *(bool*)dst = true; return; }
    foreach (f : (String[]){"0", "false", "f", "no", "n"})
        if (s.compare_to_ignore_case(f) == 0) { *(bool*)dst = false; return; }
    return UNSUPPORTED_BOOLEAN~;
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
const CLPrintFns DEFAULT_CLI_PRINTERS = {
    .cmd_help = &default_cmd_help,
    .cmd_usage = &default_cmd_usage,
    .opt_help = &default_opt_help,
    .opt_usage = &default_opt_usage,
    .val_help = &default_val_help,
    .val_usage = &default_val_usage,
};

fn void? default_cmd_help(CLParser* parser, Cmd* cmd)
{

}
fn void? default_cmd_usage(CLParser* parser, Cmd* cmd)
{

}
fn void? default_opt_help(CLParser* parser, Opt* opt)
{

}
fn void? default_opt_usage(CLParser* parser, Opt* opt)
{

}
fn void? default_val_help(CLParser* parser, Val* val)
{

}
fn void? default_val_usage(CLParser* parser, Val* val)
{

}


struct CLParser
{
    Allocator alloc;
    String[] option_starters;
    String[] alias_starters;
    String[] option_value_seps;
    bool reverse_fill;  // Options are filled in reverse order, as in mv. Args are never reordered.
    short max_columns;
}
const CLParser DEFAULT_CLI_PARSER = {
    .alloc = &allocators::LIBC_ALLOCATOR,
    .option_starters = env::WIN32 ? { "/", "--" } : {"--"},
    .alias_starters = env::WIN32 ? { "/", "-" } : {"-"},
    .option_value_seps = { "=", ":" },
    .reverse_fill = false,
    .max_columns = 80,
};

fn void? CLParser.parse(&clp, Cmd* command, String[] args, CLPrintFns printers = DEFAULT_CLI_PRINTERS)
{
    
}


const Cmd FIN_CLI = command(
    "fin", "Just-in-Time or Ahead-of-Time compile and execute Fin programs.", &invoke_fin,
{
    command("cc", "Invoke the provided LLVM Clang driver in C mode.", &invoke_cc),
    command("cxx", "Invoke the provided LLVM Clang driver in C++ mode.", &invoke_cxx),
    command("cl", "Invoke the provided LLVM Clang driver in MSVC mode.", &invoke_cl),
    command("as", "Invoke the provided LLVM Clang driver in assembler mode.", &invoke_as),
    command("ld", "Invoke the provided LLVM linker.", &invoke_ld),
    command("lsp", "Invoke the language server or toggle its daemon.", &invoke_lsp),
    command("fmt", "Format Fin source files.", &invoke_fmt),
    command("env", "Print installation and environment variables.", &invoke_env),
}, {
    positional(false, "sources", "", value("", &pass_through),
        "Paths to Fin source files or directories recursively containing them.", 32767
    ),

    option(false, "version", {}, "false", value("", &parse_bool),
        "Print version information string and exit."
    ),

    option(true, "help", { "-help", "h" }, "false", value("", &parse_bool),
        "Print command help message and exit."
    ),
    option(true, "verbose", {"v"}, "false", value("", &parse_bool),
        "Increment command output verbosity.", 5
    ),
    option(true, "quiet", {"q"}, "false", value("", &parse_bool),
        "Decrement command output verbosity.", 5
    ),
    option(true, "ansi", {}, "true", value("", &parse_bool),
        "Emit ANSI escape sequences with terminal output when available."
    ),
});

fn int invoke_fin(ParsedCmd* pcmd)
{
    return 0;
}
fn int invoke_cc(ParsedCmd* pcmd)
{
    return 0;
}
fn int invoke_cxx(ParsedCmd* pcmd)
{
    return 0;
}
fn int invoke_cl(ParsedCmd* pcmd)
{
    return 0;
}
fn int invoke_as(ParsedCmd* pcmd)
{
    return 0;
}
fn int invoke_ld(ParsedCmd* pcmd)
{
    return 0;
}
fn int invoke_lsp(ParsedCmd* pcmd)
{
    return 0;
}
fn int invoke_fmt(ParsedCmd* pcmd)
{
    return 0;
}
fn int invoke_env(ParsedCmd* pcmd)
{
    return 0;
}
