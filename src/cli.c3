module fin::cli;

alias ParseFn = fn void? (void*, String);

struct Val { String name; String description; String default_val; ParseFn parser; }

struct Opt { String name; String description; String[] aliases; Val value; bool inherited; }

struct Cmd { String name; String description; Cmd[] subcmds; Val[] values; Opt[] options; }

macro Val value(String name, String default_val, ParseFn parser, String desc) {
    return { .name = name, .default_val = default_val, .parser = parser, .description = normalizeWS(desc) };
}
macro Opt option(bool inherited, String name, String[] aliases, Val val, String desc) {
    return { .inherited = inherited, .name = name, .aliases = aliases, .value = val, .description = normalizeWS(desc) };
}
macro Cmd command(String name, String desc, Cmd[] subcmds = {}, Val[] vals = {}, Opt[] opts = {}) {
    return { .name = name, .description = normalizeWS(desc), .subcmds = subcmds, .values = vals, .options = opts };
}

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
