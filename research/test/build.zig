const std = @import("std");
const Builddef = @import("builddef").Builddef;

pub fn build(b: *std.Build) void {
    var def = Builddef.init(b);
    const target, const optimize = def.

    const exe = b.addExecutable(.{
        .name = "llvm_zig",
        .root_source_file = b.path("src/test.zig"),
        .target = target,
        .optimize = optimize,
    });

    exe.linkLibC();
    exe.linkSystemLibrary("LLVM-20");
    exe.addIncludePath(.{.cwd_relative = "/opt/homebrew/Cellar/llvm/20.1.1/include"});
    exe.addLibraryPath(.{.cwd_relative = "/opt/homebrew/Cellar/llvm/20.1.1/lib"});

    b.installArtifact(exe);
}
