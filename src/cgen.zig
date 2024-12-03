const phrase = enum { unsequenced, alignas, thread_local, @"volatile" };

const c = union(phrase) {
    unsequenced: "[[unsequenced]]",
    alignas: "alignas",
    thread_local: "thread_local",
    @"volatile": "volatile",
};
