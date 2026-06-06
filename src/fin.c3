module fin;
import std::io;

extern fn int fin_clang_main(char* prefix, int argc, char** argv);
extern fn int fin_lld_main(char* prefix, int argc, char** argv);
alias LLVMProgram = fn int (char*, int, char**);

fn int dispatch(LLVMProgram program, String[] prefix, String[][] args) {
    String pre = string::tjoin(prefix, " ");
    int len; foreach (group : args) len += group.len;
    char** argv = mem::new_array(char*, len);
    defer mem::free(argv);
    
    int i; foreach (group : args) foreach (arg : group) argv[i++] = arg.ptr;
    return program(pre.ptr, len, argv);
}

fn int main(String[] args) {
    if (args.len < 2) {
        io::printfn("usage: %s <cc|cxx|cl|as|ld|lsp|fmt|env> [args...]", args[0]);
        return 1;
    }
    switch (args[1]) {
    case "cc":
        dispatch(&fin_clang_main, args[..1], { {args[0]}, args[2..] });
    case "cxx":
        dispatch(&fin_clang_main, args[..1], { {args[0], "--driver-mode=g++"}, args[2..] });
    case "cl":
        dispatch(&fin_clang_main, args[..1], { {args[0], "--driver-mode=cl"}, args[2..] });
    case "as":
        dispatch(&fin_clang_main, args[..1], { {args[0], "-c", "-x", "assembler"}, args[2..] });
    case "ld":
        if (args.len < 3) {
            io::printfn("usage: %s ld <coff|elf|macho|wasm> [args...]", args[0]);
            return 1;
        }
        switch (args[2]) {
        case "coff":
            dispatch(&fin_lld_main, args[..2], { {args[0], "-flavor", "link"}, args[3..] });
        case "elf":
            dispatch(&fin_lld_main, args[..2], { {args[0], "-flavor", "gnu"}, args[3..] });
        case "macho":
            dispatch(&fin_lld_main, args[..2], { {args[0], "-flavor", "darwin"}, args[3..] });
        case "wasm":
            dispatch(&fin_lld_main, args[..2], { {args[0], "-flavor", args[2]}, args[3..] });
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
