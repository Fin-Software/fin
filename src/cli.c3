module fin::cli;

alias ParseFn = fn any? (String);

struct Val { String name; any default; ParseFn parser; String description; }

struct Cmd { String name; String description; Cmd[] subcmds; Val[] values; Opt[] options; }

struct Opt { bool inherited; String name; String[] aliases; Val value; String description; }

macro Value value(String name, any default, ParseFn parser, String desc) {
    return { .name = name, .default = default, .parser = parser, .description = normalizeWS(desc) };
}
macro Cmd command(String name, String desc, Cmd[] subcmds = {}, Value[] vals = {}, Opt[] opts = {}) {
    return { .name = name, .description = normalizeWS(desc), .subcmds = subcmds, .values = vals, .options = opts };
}
macro Opt option(bool inherited, String name, String[] aliases, Value val, String desc) {
    return { .inherited = inherited, .name = name, .aliases = aliases, .value = val, .description = normalizeWS(desc) };
}

faultdef UNSUPPORTED_BOOLEAN;

fn any? passThrough(String s) => s;

fn any? parseFloat(String s) => s.to_float()?;

fn any? parseDouble(String s) => s.to_double()?;

fn any? parseInt(String s) <Type, BASE> => s.to_integer{Type}(BASE)?;

fn any? parseBool(String s) {
    foreach (t : {"1", "true", "t", "yes", "y"}) if (s.compare_to_ignore_case(t) == 0) return true;
    foreach (f : {"0", "false", "f", "no", "n"}) if (s.compare_to_ignore_case(f) == 0) return false;
    return UNSUPPORTED_BOOLEAN~;
}
