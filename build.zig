// SPDX-License-Identifier: Apache-2.0
// Copyright © 2025 The Fin Authors. All rights reserved.
// Contributors responsible for this file:
// @p7r0x7 <mattrbonnette@pm.me>

const fs = @import("std").fs;
const fmt = @import("std").fmt;
const db = @import("std").debug;
const Build = @import("std").Build;
const builtin = @import("std").builtin;
const Builddef = @import("builddef").Builddef;

pub fn build(b: *Build) void {
    // Environment defaults
    var def = Builddef.init(b);
    const target, const optimize = def.stdOptions(.{}, .{});

    // Static executable
    const fin = def.executable("fin", "src/main.zig", target, optimize);
    b.installArtifact(fin);

    // Compile external libraries for statically linking to.
    const hash_vendor = def.executable("hash-vendor", "hash.zig", target, .ReleaseFast); // Fast
    const run_hash_vendor = def.runArtifact(hash_vendor, &.{
        "vendor",
        "e44f77f7d357ae6b8f1bfa6e77ab0aeaa2625b5d9f7737ab726ed2883cd070f1", // CODE REVIEW POISON
    });
    b.step("hash-vendor", "").dependOn(&run_hash_vendor.step); // Enable `zig build hash-vendor`
    run_hash_vendor.step.dependOn(&fin.step);

    const libs_step = libs_step: {
        var buf: [11 + 1 + 12 + 1 + 12]u8 = undefined; // Adjust as necessary.
        const safety = if (optimize == .ReleaseFast) "fast" else "safe";
        const mcpu = target.result.cpu.model.llvm_name orelse "baseline";
        const triple = fmt.bufPrint(&buf, "{s}-{s}-{s}", .{
            @tagName(target.result.cpu.arch),
            @tagName(target.result.os.tag),
            @tagName(target.result.abi),
        }) catch unreachable;
        break :libs_step switch (target.result.os.tag) {
            .windows => b.addSystemCommand(&.{ "cmd.exe", "scripts/libs.cmd", safety, triple, mcpu }),
            else => b.addSystemCommand(&.{ "sh", "scripts/libs.sh", safety, triple, mcpu }),
        };
    };
    libs_step.step.dependOn(&run_hash_vendor.step);
    b.getInstallStep().dependOn(&libs_step.step);

    // Dependencies
    const cova = b.dependency("cova", .{ .target = target, .optimize = optimize });
    fin.root_module.addImport("cova", cova.module("cova"));

    const channels = b.dependency("channels", .{ .target = target, .optimize = optimize });
    fin.root_module.addImport("channels", channels.module("channels"));

    // Enable `zig build run`
    const run_cmd = def.runArtifact(fin, b.args);
    b.step("run", "").dependOn(&run_cmd.step);

    // Enable `zig build test`
    const unit_tests = def.@"test"("src/main.zig", target, optimize);
    const run_unit_tests = def.runArtifact(unit_tests, null);
    b.step("test", "").dependOn(&run_unit_tests.step);
}
