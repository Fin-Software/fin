// SPDX-License-Identifier: Apache-2.0
// Copyright © 2025 The Fin Authors. All rights reserved.
// Contributors responsible for this file:
// @p7r0x7 <mattrbonnette@pm.me>

const std = @import("std");
const fs = @import("std").fs;
const fmt = @import("std").fmt;
const mem = @import("std").mem;
const db = @import("std").debug;
const Build = @import("std").Build;
const builtin = @import("std").builtin;
const Bandaid = @import("build_bandaid").Bandaid;

// Build methods are generally declarative and unsequenced.

var mcpu_str: ?[]const u8 = undefined;
var triple_str: []const u8 = undefined;
var double_str: ?[]const u8 = undefined;

fn options(b: *Build) !?struct { Build.ResolvedTarget, builtin.OptimizeMode } {
    const optimize = b.standardOptimizeOption(.{});
    double_str = b.option([]const u8, "target",
        \\Target in OS/arch format (required)
        \\                                 Supported Values:
        \\                                   android/arm64
        \\                                   darwin/arm64
        \\                                   freestanding/arm64
        \\                                   freestanding/loong64
        \\                                   freestanding/riscv64
        \\                                   freestanding/x64
        \\                                   freestanding/wasm
        \\                                   freestanding/wasm64
        \\                                   freebsd/arm64
        \\                                   freebsd/riscv64
        \\                                   freebsd/x64
        \\                                   linux/arm64
        \\                                   linux/loong64
        \\                                   linux/riscv64
        \\                                   linux/x64
        \\                                   windows/arm64
        \\                                   windows/x64
    );
    mcpu_str = b.option([]const u8, "cpu", "CPU features to add or subtract");
    const target = resolved: {
        if (double_str) |str| {
            break :resolved try parseTarget(b, str);
        } else {
            const stdout = fs.File.stdout();
            const result = try std.process.Child.run(.{
                .argv = &[_][]const u8{ "zig", "build", "-h", "-Dtarget=linux/x64" },
                .allocator = b.allocator,
                .expand_arg0 = .expand,
            });
            try stdout.writeAll("error: Missing required option -Dtarget.\n");
            try stdout.writeAll(result.stdout);
            return null;
        }
    };
    return .{ target, optimize };
}

fn parseTarget(b: *Build, target: []const u8) !Build.ResolvedTarget {
    var parts = mem.splitScalar(u8, target, '/');
    const os_name = parts.first();
    const arch_name = parts.next() orelse return error.TargetFormatTooShort;
    if (parts.next()) |_| return error.TargetFormatTooLong;

    // zig fmt: off
    const os_tag: std.Target.Os.Tag = if (mem.eql(u8, os_name, "linux")) .linux
        else if (mem.eql(u8, os_name, "freestanding")) .freestanding
        else if (mem.eql(u8, os_name, "windows")) .windows
        else if (mem.eql(u8, os_name, "android")) .linux
        else if (mem.eql(u8, os_name, "freebsd")) .freebsd
        else if (mem.eql(u8, os_name, "darwin")) .macos
        else return error.UnsupportedOS;

    const cpu_arch: std.Target.Cpu.Arch = if (mem.eql(u8, arch_name, "x64")) .x86_64
        else if (mem.eql(u8, arch_name, "loong64")) .loongarch64
        else if (mem.eql(u8, arch_name, "riscv64")) .riscv64
        else if (mem.eql(u8, arch_name, "arm64")) .aarch64
        else if (mem.eql(u8, arch_name, "wasm64")) .wasm64
        else if (mem.eql(u8, arch_name, "wasm")) .wasm32
        else return error.UnsupportedArch;
    // zig fmt: on

    mcpu_str = if (mcpu_str) |feat| feat else if (cpu_arch == .x86_64) "x86_64_v3" else "generic";
    triple_str = str: {
        const arch = switch (cpu_arch) {
            .x86_64 => "x86_64",
            .wasm32 => "wasm32",
            .wasm64 => "wasm64",
            .aarch64 => "aarch64",
            .riscv64 => "riscv64",
            .loongarch64 => "loongarch64",
            else => unreachable,
        };
        const os_abi = switch (os_tag) {
            .macos => "macos",
            .freebsd => "freebsd",
            .windows => "windows-msvc",
            .freestanding => "freestanding",
            .linux => if (mem.eql(u8, os_name, "android")) "linux-android" else "linux-gnu",
            else => unreachable,
        };
        break :str try fmt.allocPrint(b.allocator, "{s}-{s}", .{ arch, os_abi });
    };
    return b.resolveTargetQuery(try Build.parseTargetQuery(
        std.Target.Query.ParseOptions{ .arch_os_abi = triple_str, .cpu_features = mcpu_str },
    ));
}

pub fn build(b: *Build) !void {
    const target, const optimize = try options(b) orelse return;
    const aid = Bandaid{ .b = b };
    aid.universalSettings(target);

    const fin = aid.executable("fin", "src/main.zig", target, optimize, .{});
    const cova = b.dependency("cova", .{ .target = target, .optimize = optimize });
    const channels = b.dependency("channels", .{ .target = target, .optimize = optimize });

    const lld_macho = aid.library("lldMachO", null, target, optimize, .{});
    aid.addCSources(lld_macho, Bandaid.CSources{
        .header_paths = &.{ ".build/include", ".build/include/lld/MachO" },
        .c_sources = &.{"vendor/llvm-21.1.3/lld/MachO/Driver.cpp"},
    });
    lld_macho.root_module.error_tracing = false;
    lld_macho.linkLibCpp();

    const lld_coff = aid.library("lldCOFF", null, target, optimize, .{});
    aid.addCSources(lld_coff, Bandaid.CSources{
        .header_paths = &.{ ".build/include", ".build/include/lld/COFF" },
        .c_sources = &.{"vendor/llvm-21.1.3/lld/COFF/Driver.cpp"},
    });
    lld_coff.root_module.error_tracing = false;
    lld_coff.linkLibCpp();

    const lld_wasm = aid.library("lldwasm", null, target, optimize, .{});
    aid.addCSources(lld_wasm, Bandaid.CSources{
        .header_paths = &.{ ".build/include", ".build/include/lld/wasm" },
        .c_sources = &.{"vendor/llvm-21.1.3/lld/wasm/Driver.cpp"},
    });
    lld_wasm.root_module.error_tracing = false;
    lld_wasm.linkLibCpp();

    const lld_elf = aid.library("lldELF", null, target, optimize, .{});
    aid.addCSources(lld_elf, Bandaid.CSources{
        .header_paths = &.{ ".build/include", ".build/include/lld/ELF" },
        .c_sources = &.{"vendor/llvm-21.1.3/lld/ELF/Driver.cpp"},
    });
    lld_elf.root_module.error_tracing = false;
    lld_elf.linkLibCpp();

    // Enable `zig build hash-vendor`
    const hash_vendor = aid.executable("hash-vendor", "hash.zig", target, .ReleaseFast, .{}); // Fast
    const run_hash_vendor = aid.runArtifact(hash_vendor, &.{
        "vendor",
        "f6f4f3801cc3b6547b8496c8278ef0e20a5e330070ed6936727560eea5976d38", // CODE REVIEW POISON
    });
    hash_vendor.root_module.addImport("channels", channels.module("channels"));
    b.step("hash-vendor", "").dependOn(&run_hash_vendor.step);

    const libs = switch (b.graph.host.result.os.tag) {
        .windows => b.addSystemCommand(&.{ "cmd.exe", "scripts/libs.cmd", double_str.?, triple_str, mcpu_str.? }),
        else => b.addSystemCommand(&.{ "sh", "scripts/libs.sh", double_str.?, triple_str, mcpu_str.? }),
    };
    libs.step.dependOn(&run_hash_vendor.step);
    lld_macho.step.dependOn(&libs.step);
    lld_coff.step.dependOn(&libs.step);
    lld_wasm.step.dependOn(&libs.step);
    lld_elf.step.dependOn(&libs.step);
    fin.step.dependOn(&libs.step);

    aid.addCSources(fin, Bandaid.CSources{
        .header_paths = &.{".build/include"},
        .c_sources = &.{
            "vendor/llvm-21.1.3/clang/tools/driver/cc1as_main.cpp",
            "vendor/llvm-21.1.3/clang/tools/driver/cc1_main.cpp",
        },
    });
    fin.root_module.addImport("channels", channels.module("channels"));
    fin.root_module.addObjectFile(b.path(".build/libLLVM.a"));
    fin.root_module.addImport("cova", cova.module("cova"));
    fin.root_module.linkLibrary(lld_macho);
    fin.root_module.linkLibrary(lld_coff);
    fin.root_module.linkLibrary(lld_wasm);
    fin.root_module.linkLibrary(lld_elf);
    b.installArtifact(fin);
    fin.linkLibCpp();

    // Enable `zig build run`
    const run_cmd = aid.runArtifact(fin, b.args);
    b.step("run", "").dependOn(&run_cmd.step);

    // Enable `zig build test`
    const unit_tests = aid.@"test"("src/main.zig", target, optimize, .{});
    const run_unit_tests = aid.runArtifact(unit_tests, null);
    b.step("test", "").dependOn(&run_unit_tests.step);
}
