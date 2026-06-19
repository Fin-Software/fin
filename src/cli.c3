module fin::cli;

alias ParseFn = fn void? (void*, String);
alias CmdPrintFn = fn void? (CLParser*, Cmd*);
alias OptPrintFn = fn void? (CLParser*, Opt*);
alias ValPrintFn = fn void? (CLParser*, Val*);

struct Cmd { String name; String description; Cmd[] subcmds; Val[] values; Opt[] options; }

struct Opt { String name; String description; String[] aliases; Val value; bool inherited; }

struct Val { String name; String description; String default_val; ParseFn parser; short max; }

macro Cmd command(String name, String desc, Cmd[] subcmds = {}, Val[] vals = {}, Opt[] opts = {}) {
    return { .name = name, .description = desc, .subcmds = subcmds, .values = vals, .options = opts };
}
macro Opt option(bool inherited, String name, String[] aliases, Val val, String desc) {
    return { .inherited = inherited, .name = name, .aliases = aliases, .value = val, .description = desc };
}
macro Val value(String name, String default_val, ParseFn parser, String desc, short max = 1) {
    return { .name = name, .default_val = default_val, .parser = parser, .description = desc, .max = max };
}

struct CLParser {
    Allocator alloc;
    String[] option_starters;
    String[] alias_starters;
    String[] option_value_seps;
    bool reverse_value_fill;  // Args are never reversed. Semantics of mv.
    short max_columns;
}
struct CLPrintFns {
    CmdPrintFn cmd_help, cmd_usage;
    OptPrintFn opt_help, opt_usage;
    ValPrintFn val_help, val_usage;
}

const CLParser DEFAULT_CLI_PARSER = {
    .alloc = mem,
    .option_starters = env::WIN32 ??? { "/", "--" } : {"--"},
    .alias_starters = env::WIN32 ??? { "/", "-" } : {"-"},
    .option_value_seps = { "=", ":" },
    .reverse_value_fill = false,
    .max_columns = 80,
};
const CLPrintFns DEFAULT_CLI_PRINTERS = {
    .cmd_help = default_cmd_help,
    .cmd_usage = default_cmd_usage,
    .opt_help = default_opt_help,
    .opt_usage = default_opt_usage,
    .val_help = default_val_help,
    .val_usage = default_val_usage,
};

fn void? CLParser.parse(&clp, Cmd* command, String[] args, CLPrintFns printers = DEFAULT_CLI_PRINTERS) {
    
}

Cmd fin_cli = command("fin", "Just-in-Time or Ahead-of-Time compile and execute Fin programs.",
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
    value("sources", "Paths to Fin source files or directories recursively containing them.", &passThrough, "", short::max),
}, {
    option(false, "version", {}, value("", "false", &parseBool, ""),
        "Print version information string and exit."
    ),

    option(true, "help", { "-help", "h" }, value("", "false", &parseBool, ""),
        "Print command help message and exit."
    ),
    option(true, "verbose", {"v"}, value("", "false", &parseBool, ""),
        "Increment command output verbosity."
    ),
    option(true, "quiet", {"q"}, value("", "false", &parseBool, ""),
        "Decrement command output verbosity."
    ),
    option(true, "ansi", {}, value("", "true", &parseBool, ""),
        "Emit ANSI escape sequences with terminal output when available."
    ),
});

faultdef UNSUPPORTED_BOOLEAN;

fn void? passThrough(void* dst, String s) { *(String*)dst = s; }

fn void? parseFloat(void* dst, String s) { *(float*)dst = s.to_float()!; }

fn void? parseDouble(void* dst, String s) { *(double*)dst = s.to_double()!; }

fn void? parseInt(void* dst, String s) <Type, BASE> { *(Type*)dst = s.to_integer{Type}(BASE)!; }

fn void? parseBool(void* dst, String s) {
    foreach (t : (String[]){"1", "true", "t", "yes", "y"})
        if (s.compare_to_ignore_case(t) == 0) { *(bool*)dst = true; return; }
    foreach (f : (String[]){"0", "false", "f", "no", "n"})
        if (s.compare_to_ignore_case(f) == 0) { *(bool*)dst = false; return; }
    return UNSUPPORTED_BOOLEAN~;
}
