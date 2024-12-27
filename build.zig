// SPDX-License-Identifier: Apache-2.0
// Copyright © 2024 The Whixy Authors. All rights reserved.
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
    //const target = b.standardTargetOptions(.{});
    //const optimize: builtin.OptimizeMode = if (b.option(bool, "release",
    //    \\true: production (distributors and users), false: debugging (contributors)
    //) orelse true) .ReleaseFast else .ReleaseSafe;
    //def.universalSettings(target);

    const parser = def.staticLib("parser", null, target, optimize);
    parser.root_module.error_tracing = false;
    //parser.root_module.strip = optimize == .ReleaseFast;
    def.addCSources(parser, &sources.parser);
    if (optimize == .Debug) b.installArtifact(parser);
    parser.linkLibCpp();

    const whixy = def.executable("whixy", "src/main.zig", target, optimize);
    //whixy.root_module.strip = optimize == .ReleaseFast;
    whixy.linkLibrary(parser);
    b.installArtifact(whixy);
    whixy.linkLibCpp();

    // Compile external libraries for statically linking to.
    if (b.build_root.handle.openDir(".build", .{}) == error.FileNotFound) {
        const hash_vendor = def.executable("hash-vendor", "hash.zig", target, .ReleaseFast);
        const run_hash_vendor = def.runArtifact(hash_vendor, &.{
            "vendor",
            \\71e5a4da0eb3d7519d8f752ab04e75c282c8e81885a158c4944912f5cd7fda5d
        });
        b.step("hash-vendor", "").dependOn(&run_hash_vendor.step); // Enable `zig build hash-vendor`

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

        run_hash_vendor.step.dependOn(&whixy.step);
        libs_step.step.dependOn(&run_hash_vendor.step);
    }

    // Dependencies
    const cova = b.dependency("cova", .{ .target = target, .optimize = optimize });
    whixy.root_module.addImport("cova", cova.module("cova"));

    // Enable `zig build run`
    const run_cmd = b.addRunArtifact(whixy);
    run_cmd.step.dependOn(b.getInstallStep());
    if (b.args) |args| run_cmd.addArgs(args);
    b.step("run", "").dependOn(&run_cmd.step);

    // Enable `zig build test`
    const unit_tests = b.addTest(.{ .root_source_file = b.path("src/main.zig"), .optimize = optimize, .target = target });
    const run_unit_tests = b.addRunArtifact(unit_tests);
    b.step("test", "").dependOn(&run_unit_tests.step);
}

const sources = struct {
    const parser = [_]Builddef.CSources{
        .{
            .root = "src/antlr/",
            .flags = &.{"-std=c++17"},
            .header_paths = &.{"."},
            .c_sources = &.{
                "WhixyLexer.cpp",
                "WhixyParser.cpp",
                "WhixyParserBaseVisitor.cpp",
                "WhixyParserVisitor.cpp",
                //"../antlr.cpp",
            },
        },
        .{
            .root = "vendor/antlr-cpp-runtime-4.13.2/runtime/src",
            .flags = &.{"-std=c++17"},
            .header_paths = &.{ ".", "atn", "dfa", "internal", "misc", "support", "tree", "tree/pattern", "tree/xpath" },
            .c_sources = &.{
                "ANTLRErrorListener.cpp",
                "ANTLRErrorStrategy.cpp",
                "ANTLRFileStream.cpp",
                "ANTLRInputStream.cpp",
                "BailErrorStrategy.cpp",
                "BaseErrorListener.cpp",
                "BufferedTokenStream.cpp",
                "CharStream.cpp",
                "CommonToken.cpp",
                "CommonTokenFactory.cpp",
                "CommonTokenStream.cpp",
                "ConsoleErrorListener.cpp",
                "DefaultErrorStrategy.cpp",
                "DiagnosticErrorListener.cpp",
                "Exceptions.cpp",
                "FailedPredicateException.cpp",
                "InputMismatchException.cpp",
                "IntStream.cpp",
                "InterpreterRuleContext.cpp",
                "Lexer.cpp",
                "LexerInterpreter.cpp",
                "LexerNoViableAltException.cpp",
                "ListTokenSource.cpp",
                "NoViableAltException.cpp",
                "Parser.cpp",
                "ParserInterpreter.cpp",
                "ParserRuleContext.cpp",
                "ProxyErrorListener.cpp",
                "RecognitionException.cpp",
                "Recognizer.cpp",
                "RuleContext.cpp",
                "RuleContextWithAltNum.cpp",
                "RuntimeMetaData.cpp",
                "Token.cpp",
                "TokenSource.cpp",
                "TokenStream.cpp",
                "TokenStreamRewriter.cpp",
                "UnbufferedCharStream.cpp",
                "UnbufferedTokenStream.cpp",
                "Vocabulary.cpp",
                "WritableToken.cpp",
                "atn/ATN.cpp",
                "atn/ATNConfig.cpp",
                "atn/ATNConfigSet.cpp",
                "atn/ATNDeserializationOptions.cpp",
                "atn/ATNDeserializer.cpp",
                "atn/ATNSimulator.cpp",
                "atn/ATNState.cpp",
                "atn/ATNStateType.cpp",
                "atn/ActionTransition.cpp",
                "atn/AmbiguityInfo.cpp",
                "atn/ArrayPredictionContext.cpp",
                "atn/AtomTransition.cpp",
                "atn/ContextSensitivityInfo.cpp",
                "atn/DecisionEventInfo.cpp",
                "atn/DecisionInfo.cpp",
                "atn/DecisionState.cpp",
                "atn/EpsilonTransition.cpp",
                "atn/ErrorInfo.cpp",
                "atn/LL1Analyzer.cpp",
                "atn/LexerATNConfig.cpp",
                "atn/LexerATNSimulator.cpp",
                "atn/LexerAction.cpp",
                "atn/LexerActionExecutor.cpp",
                "atn/LexerChannelAction.cpp",
                "atn/LexerCustomAction.cpp",
                "atn/LexerIndexedCustomAction.cpp",
                "atn/LexerModeAction.cpp",
                "atn/LexerMoreAction.cpp",
                "atn/LexerPopModeAction.cpp",
                "atn/LexerPushModeAction.cpp",
                "atn/LexerSkipAction.cpp",
                "atn/LexerTypeAction.cpp",
                "atn/LookaheadEventInfo.cpp",
                "atn/NotSetTransition.cpp",
                "atn/OrderedATNConfigSet.cpp",
                "atn/ParseInfo.cpp",
                "atn/ParserATNSimulator.cpp",
                "atn/PrecedencePredicateTransition.cpp",
                "atn/PredicateEvalInfo.cpp",
                "atn/PredicateTransition.cpp",
                "atn/PredictionContext.cpp",
                "atn/PredictionContextCache.cpp",
                "atn/PredictionContextMergeCache.cpp",
                "atn/PredictionMode.cpp",
                "atn/ProfilingATNSimulator.cpp",
                "atn/RangeTransition.cpp",
                "atn/RuleTransition.cpp",
                "atn/SemanticContext.cpp",
                "atn/SetTransition.cpp",
                "atn/SingletonPredictionContext.cpp",
                "atn/StarLoopbackState.cpp",
                "atn/Transition.cpp",
                "atn/TransitionType.cpp",
                "atn/WildcardTransition.cpp",
                "dfa/DFA.cpp",
                "dfa/DFASerializer.cpp",
                "dfa/DFAState.cpp",
                "dfa/LexerDFASerializer.cpp",
                "internal/Synchronization.cpp",
                "misc/InterpreterDataReader.cpp",
                "misc/Interval.cpp",
                "misc/IntervalSet.cpp",
                "misc/MurmurHash.cpp",
                "misc/Predicate.cpp",
                "support/Any.cpp",
                "support/Arrays.cpp",
                "support/CPPUtils.cpp",
                "support/StringUtils.cpp",
                "support/Utf8.cpp",
                "tree/ErrorNodeImpl.cpp",
                "tree/IterativeParseTreeWalker.cpp",
                "tree/ParseTree.cpp",
                "tree/ParseTreeListener.cpp",
                "tree/ParseTreeVisitor.cpp",
                "tree/ParseTreeWalker.cpp",
                "tree/TerminalNodeImpl.cpp",
                "tree/Trees.cpp",
                "tree/pattern/Chunk.cpp",
                "tree/pattern/ParseTreeMatch.cpp",
                "tree/pattern/ParseTreePattern.cpp",
                "tree/pattern/ParseTreePatternMatcher.cpp",
                "tree/pattern/RuleTagToken.cpp",
                "tree/pattern/TagChunk.cpp",
                "tree/pattern/TextChunk.cpp",
                "tree/pattern/TokenTagToken.cpp",
                "tree/xpath/XPath.cpp",
                "tree/xpath/XPathElement.cpp",
                "tree/xpath/XPathLexer.cpp",
                "tree/xpath/XPathLexerErrorListener.cpp",
                "tree/xpath/XPathRuleAnywhereElement.cpp",
                "tree/xpath/XPathRuleElement.cpp",
                "tree/xpath/XPathTokenAnywhereElement.cpp",
                "tree/xpath/XPathTokenElement.cpp",
                "tree/xpath/XPathWildcardAnywhereElement.cpp",
                "tree/xpath/XPathWildcardElement.cpp",
            },
        },
    };
};
