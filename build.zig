// SPDX-License-Identifier: Apache-2.0
// Copyright © 2024 The Whixy Authors. All rights reserved.
// Contributors responsible for this file:
// @p7r0x7 <mattrbonnette@pm.me>

const fs = @import("std").fs;
const fmt = @import("std").fmt;
const db = @import("std").debug;
const Build = @import("std").Build;
const builtin = @import("std").builtin;

pub fn build(b: *Build) !void {
    const target = b.standardTargetOptions(.{});
    const optimize: builtin.OptimizeMode =
        if (b.option(bool, "release", "true: production, false: debugging") orelse (b.release_mode != .off))
        .ReleaseFast // For distributors and users
    else
        .ReleaseSafe; // For contributors
    db.assert(optimize != .Debug and optimize != .ReleaseSmall);
    b.enable_wine = target.result.os.tag == .windows and target.result.cpu.arch == .x86_64;
    b.enable_rosetta = target.result.os.tag == .macos and target.result.cpu.arch == .x86_64;

    const whixy = executable(b, "whixy", "src/main.zig", target, optimize);
    whixy.addCSourceFile(.{ .file = b.path("src/jit.cpp") });
    b.installArtifact(whixy);
    whixy.linkLibCpp();

    // Compile external libraries for statically linking to.
    if (b.build_root.handle.openDir("deps", .{}) == error.FileNotFound) {
        // Certify the integrity of external dependency sources.
        const hash_vendor = b.addTest(.{ .root_source_file = b.path("hash.zig"), .optimize = .ReleaseFast, .target = target });
        const run_hash_vendor = b.addRunArtifact(hash_vendor);
        {
            var buf: [fs.max_path_bytes]u8 = undefined;
            const cwd_path = try b.build_root.handle.realpath("vendor", buf[0..]);
            run_hash_vendor.addArg(cwd_path);
            run_hash_vendor.addArg("bab0fa6ecb28a9ca41d88ebde566c26325e0115c42a1bd79c5bb30f6d741a265");
        }
        b.step("hash-vendor", "").dependOn(&run_hash_vendor.step); // Enable `zig build hash-vendor`

        const deps_step = deps_step: {
            var buf: [32]u8 = undefined; // Adjust as necessary.
            const safety = if (optimize == .ReleaseFast) "fast" else "safe";
            const mcpu = target.result.cpu.model.llvm_name orelse "baseline";
            const triple = try fmt.bufPrint(buf[0..], "{s}-{s}-{s}", .{
                @tagName(target.result.cpu.arch),
                @tagName(target.result.os.tag),
                @tagName(target.result.abi),
            });
            break :deps_step switch (target.result.os.tag) {
                .windows => b.addSystemCommand(&[_][]const u8{ "cmd.exe", "libs.cmd", safety, triple, mcpu }),
                else => b.addSystemCommand(&[_][]const u8{ "sh", "libs.sh", safety, triple, mcpu }),
            };
        };

        deps_step.step.dependOn(&run_hash_vendor.step);
        whixy.step.dependOn(&deps_step.step);
    }
    {
        // Dependencies
        const cova = b.dependency("cova", .{ .target = target, .optimize = optimize });
        whixy.root_module.addImport("cova", cova.module("cova"));
    }
    {
        // Enable `zig build run`
        const run_cmd = b.addRunArtifact(whixy);
        run_cmd.step.dependOn(b.getInstallStep());
        if (b.args) |args| run_cmd.addArgs(args);
        b.step("run", "").dependOn(&run_cmd.step);
    }

    // Enable `zig build test`
    const unit_tests = b.addTest(.{ .root_source_file = b.path("src/main.zig"), .optimize = optimize, .target = target });
    const run_unit_tests = b.addRunArtifact(unit_tests);
    b.step("test", "").dependOn(&run_unit_tests.step);
}

fn executable(b: *Build, name: []const u8, root_path: []const u8, target: Build.ResolvedTarget, optimize: builtin.OptimizeMode) *Build.Step.Compile {
    const exe = b.addExecutable(.{
        .error_tracing = optimize == .ReleaseSafe or optimize == .Debug,
        .strip = optimize == .ReleaseFast or optimize == .ReleaseSmall,
        .omit_frame_pointer = optimize != .Debug,
        .root_source_file = b.path(root_path),
        .unwind_tables = optimize == .Debug,
        .optimize = optimize,
        .target = target,
        .name = name,
        .pic = true,
    });
    exe.want_lto = !target.result.isDarwin(); // https://github.com/ziglang/zig/issues/8680
    exe.compress_debug_sections = .zstd;
    exe.link_function_sections = true;
    exe.link_gc_sections = true;
    return exe;
}
