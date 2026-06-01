module fin;
import std::io;

extern fn int clang_main_c(int argc, char** argv);

fn int main(String[] args) {
    switch (args[1]) {
    case "cc":
        return clang_main_c(0, (char**)&args);
    case "cxx":
        io::printn("cxx unimplemented.");
    case "cl":
        io::printn("cl unimplemented.");
    case "as":
        io::printn("as unimplemented.");
    case "ld":
        io::printn("ld unimplemented.");
    case "lsp":
        io::printn("lsp unimplemented.");
    case "fmt":
        io::printn("fmt unimplemented.");
    case "env":
        io::printn("env unimplemented.");
    }
    return 0;
}
