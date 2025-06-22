const std = @import("std");
const c = @cImport({
    @cInclude("llvm-c/Analysis.h");
    @cInclude("llvm-c/Core.h");
    @cInclude("llvm-c/ExecutionEngine.h");
    @cInclude("llvm-c/Target.h");
    @cInclude("llvm-c/Transforms/Scalar.h");
});

const OperationType = enum(c_uint) { ADD, SUB, MUL, DIV };

fn buildArithmeticOperation(
    builder: c.LLVMBuilderRef,
    lhs: c.LLVMValueRef,
    rhs: c.LLVMValueRef,
    opType: OperationType,
) c.LLVMValueRef {
    return switch (opType) {
        .ADD => c.LLVMBuildAdd(builder, lhs, rhs, "addtmp"),
        .SUB => c.LLVMBuildSub(builder, lhs, rhs, "subtmp"),
        .MUL => c.LLVMBuildMul(builder, lhs, rhs, "multmp"),
        .DIV => c.LLVMBuildSDiv(builder, lhs, rhs, "divtmp"),
    };
}

fn generateArithmeticFunction(
    module: c.LLVMModuleRef,
    builder: c.LLVMBuilderRef,
    name: [*:0]const u8,
    opType: OperationType,
) void {
    const returnType = c.LLVMInt32Type();
    const paramTypes = [_]c.LLVMTypeRef{
        c.LLVMInt32Type(),
        c.LLVMInt32Type(),
    };
    const funcType = c.LLVMFunctionType(returnType, &paramTypes, paramTypes.len, 0);
    const function = c.LLVMAddFunction(module, name, funcType);

    const entry = c.LLVMAppendBasicBlock(function, "entry");
    c.LLVMPositionBuilderAtEnd(builder, entry);
    const x = c.LLVMGetParam(function, 0);
    const y = c.LLVMGetParam(function, 1);
    const result = buildArithmeticOperation(builder, x, y, opType);
    _ = c.LLVMBuildRet(builder, result);
}

pub fn main() !void {
    _ = c.LLVMInitializeNativeTarget();
    _ = c.LLVMInitializeNativeAsmPrinter();
    _ = c.LLVMInitializeNativeAsmParser();

    const context = c.LLVMGetGlobalContext();
    const module = c.LLVMModuleCreateWithNameInContext("arithmetic_module", context);
    const builder = c.LLVMCreateBuilder();

    generateArithmeticFunction(module, builder, "add", .ADD);
    generateArithmeticFunction(module, builder, "sub", .SUB);
    generateArithmeticFunction(module, builder, "mul", .MUL);
    generateArithmeticFunction(module, builder, "div", .DIV);

    var engine: c.LLVMExecutionEngineRef = undefined;
    var err: [*:0]u8 = undefined;
    if (c.LLVMCreateExecutionEngineForModule(&engine, module, &err) != 0) {
        std.debug.print("Error creating execution engine: {s}\n", .{err});
        c.LLVMDisposeMessage(err);
        return error.LLVM;
    }

    const AddFunc = *const fn (c_int, c_int) callconv(.C) c_int;
    const add_func: AddFunc = @ptrCast(@alignCast(c.LLVMGetFunctionAddress(engine, "add")));
    const sub_func: AddFunc = @ptrCast(@alignCast(c.LLVMGetFunctionAddress(engine, "sub")));
    const mul_func: AddFunc = @ptrCast(@alignCast(c.LLVMGetFunctionAddress(engine, "mul")));
    const div_func: AddFunc = @ptrCast(@alignCast(c.LLVMGetFunctionAddress(engine, "div")));

    if (add_func != null and sub_func != null and mul_func != null and div_func != null) {
        std.debug.print("add(10, 5) = {d}\n", .{add_func(10, 5)});
        std.debug.print("sub(10, 5) = {d}\n", .{sub_func(10, 5)});
        std.debug.print("mul(10, 5) = {d}\n", .{mul_func(10, 5)});
        std.debug.print("div(10, 5) = {d}\n", .{div_func(10, 5)});
    } else {
        std.debug.print("Failed to retrieve one or more functions.\n", .{});
    }

    c.LLVMDisposeExecutionEngine(engine);
    c.LLVMDisposeBuilder(builder);
    c.LLVMDisposeModule(module);
}
