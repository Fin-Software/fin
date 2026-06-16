module fin::cli;

alias ParseFn = fn void? (any*, String);

struct Val { String name; any default_val; ParseFn parser; String description; }

struct Cmd { String name; String description; Cmd[] subcmds; Val[] values; Opt[] options; }

struct Opt { bool inherited; String name; String[] aliases; Val value; String description; }

macro Val value(String name, any default_val, ParseFn parser, String desc) {
    return { .name = name, .default_val = default_val, .parser = parser, .description = normalizeWS(desc) };
}
macro Cmd command(String name, String desc, Cmd[] subcmds = {}, Val[] vals = {}, Opt[] opts = {}) {
    return { .name = name, .description = normalizeWS(desc), .subcmds = subcmds, .values = vals, .options = opts };
}
macro Opt option(bool inherited, String name, String[] aliases, Val val, String desc) {
    return { .inherited = inherited, .name = name, .aliases = aliases, .value = val, .description = normalizeWS(desc) };
}

faultdef UNSUPPORTED_BOOLEAN;

fn void? passThrough(any* dst, String s) { *dst = s.ptr; }

fn void? parseFloat(any* dst, String s) { *dst = &&s.to_float()!; }

fn void? parseDouble(any* dst, String s) { *dst = &&s.to_double()!; }

fn void? parseInt(any* dst, String s) <Type, BASE> { *dst = &&s.to_integer{Type}(BASE)!; }

fn void? parseBool(any* dst, String s) {
    foreach (t : (String[]){"1", "true", "t", "yes", "y"})
        if (s.compare_to_ignore_case(t) == 0) { *dst = &&true; return; }
    foreach (f : (String[]){"0", "false", "f", "no", "n"})
        if (s.compare_to_ignore_case(f) == 0) { *dst = &&false; return; }
    return UNSUPPORTED_BOOLEAN~;
}