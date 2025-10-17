// SPDX-License-Identifier: Apache-2.0
// Copyright © 2025 The Fin Authors. All rights reserved.
// Contributors responsible for this file:
// @p7r0x7 <mattrbonnette@pm.me>

const fs = @import("std").fs;
const fmt = @import("std").fmt;
const db = @import("std").debug;
const Build = @import("std").Build;
const builtin = @import("std").builtin;
const Bandaid = @import("build_bandaid").Bandaid;

// Build methods are generally declarative and unsequenced.

pub fn build(b: *Build) void {
    b.exe_dir = ".build";
    const aid = Bandaid{ .b = b };
    const target, const optimize = aid.stdOptions(.{}, .{});

    const fin = aid.executable("fin", "src/main.zig", target, optimize, .{});
    const cova = b.dependency("cova", .{ .target = target, .optimize = optimize });
    const channels = b.dependency("channels", .{ .target = target, .optimize = optimize });

    // Enable `zig build hash-vendor`
    const hash_vendor = aid.executable("hash-vendor", "hash.zig", target, .ReleaseFast, .{}); // Fast
    const run_hash_vendor = aid.runArtifact(hash_vendor, &.{
        "vendor",
        "f6f4f3801cc3b6547b8496c8278ef0e20a5e330070ed6936727560eea5976d38", // CODE REVIEW POISON
    });
    hash_vendor.root_module.addImport("channels", channels.module("channels"));
    b.step("hash-vendor", "").dependOn(&run_hash_vendor.step);

    const libs = libs: {
        var buf: [64]u8 = undefined;
        const mcpu = target.result.cpu.model.llvm_name orelse "baseline";
        const safety = if (optimize == .ReleaseFast) "fast" else "safe";
        const triple = fmt.bufPrint(&buf, "{s}-{s}-{s}", .{
            @tagName(target.result.cpu.arch),
            @tagName(target.result.os.tag),
            @tagName(target.result.abi),
        }) catch unreachable;
        break :libs switch (b.graph.host.result.os.tag) {
            .windows => b.addSystemCommand(&.{ "cmd.exe", "scripts/libs.cmd", safety, triple, mcpu }),
            else => b.addSystemCommand(&.{ "sh", "scripts/libs.sh", safety, triple, mcpu }),
        };
    };
    libs.step.dependOn(&run_hash_vendor.step);
    fin.step.dependOn(&libs.step);

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
