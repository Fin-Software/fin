module fin;
import std::io;

extern fn int fin_clang_main(char* real_exe, int argc, char** argv);
extern fn int fin_lld_main(char* real_exe, int argc, char** argv);
alias LLVMProgram = fn int (char*, int, char**);

fn int dispatch(LLVMProgram program, String[][3] args) {
    String argv0 = string::tjoin(args[0], " ");
    int len = 1 + args[1].len + args[2].len;
    char** argv = mem::new_array(char*, len);
    defer mem::free(argv);

    argv[0] = argv0.ptr; int i = 1;
    foreach (arg : args[1]) argv[i++] = arg.ptr;
    foreach (arg : args[2]) argv[i++] = arg.ptr;
    return program(args[0][0].ptr, len, argv);
}

fn int main(String[] args) {
    if (args.len < 2) {
        io::printfn("usage: %s <cc|cxx|cl|as|ld|lsp|fmt|env> [args...]", args[0]);
        return 1;
    }
    switch (args[1]) {
    case "cc":
        dispatch(&fin_clang_main, { args[0:2], {}, args[2..] });
    case "cxx":
        dispatch(&fin_clang_main, { args[0:2], {"-x", "c++"}, args[2..] });
    case "cl":
        dispatch(&fin_clang_main, { args[0:2], {"--driver-mode=cl"}, args[2..] });
    case "as":
        dispatch(&fin_clang_main, { args[0:2], {"-cc1as"}, args[2..] });
    case "ld":
        if (args.len < 3) {
            io::printfn("usage: %s ld <coff|elf|macho|wasm> [args...]", args[0]);
            return 1;
        }
        switch (args[2]) {
        case "coff":
        case "elf":
        case "macho":
        case "wasm":
            dispatch(&fin_lld_main, { args[0:3], {"--flavor", args[2]}, args[3..] });
        default:
            io::printfn("%s ld: error: flavor %s unavailable,"
                " expected coff, elf, macho, or wasm.", args[0], args[2]);
            return 1;
        }
    case "lsp":
        io::printfn("%s lsp: error: subcommand unimplemented.", args[0]);
    case "fmt":
        io::printfn("%s fmt: error: subcommand unimplemented.", args[0]);
    case "env":
        io::printfn("%s env: error: subcommand unimplemented.", args[0]);
    default:
        io::printfn("%s: error: subcommand %s unavailable.", args[0], args[1]);
        return 1;
    }
    return 0;
}
