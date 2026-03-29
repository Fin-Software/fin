#include <llvm-c/Analysis.h>
#include <llvm-c/Core.h>
#include <llvm-c/ExecutionEngine.h>
#include <llvm-c/Target.h>
#include <llvm-c/Transforms/Scalar.h>
#include <stdio.h>

typedef enum { ADD, SUB, MUL, DIV } OperationType;

LLVMValueRef buildArithmeticOperation(LLVMBuilderRef builder, LLVMValueRef lhs, LLVMValueRef rhs, OperationType opType) {
    switch (opType) {
    case ADD: return LLVMBuildAdd(builder, lhs, rhs, "addtmp");
    case SUB: return LLVMBuildSub(builder, lhs, rhs, "subtmp");
    case MUL: return LLVMBuildMul(builder, lhs, rhs, "multmp");
    case DIV: return LLVMBuildSDiv(builder, lhs, rhs, "divtmp");
    default: return NULL;
    }
}

void generateArithmeticFunction(LLVMModuleRef module, LLVMBuilderRef builder, const char* name, OperationType opType) {
    LLVMTypeRef returnType = LLVMInt32Type();
    LLVMTypeRef paramTypes[] = {LLVMInt32Type(), LLVMInt32Type()};
    LLVMTypeRef funcType = LLVMFunctionType(returnType, paramTypes, 2, 0);
    LLVMValueRef function = LLVMAddFunction(module, name, funcType);

    LLVMBasicBlockRef entry = LLVMAppendBasicBlock(function, "entry");
    LLVMPositionBuilderAtEnd(builder, entry);
    LLVMValueRef x = LLVMGetParam(function, 0);
    LLVMValueRef y = LLVMGetParam(function, 1);
    LLVMValueRef result = buildArithmeticOperation(builder, x, y, opType);
    LLVMBuildRet(builder, result);
}

int main() {
    LLVMInitializeNativeTarget();
    LLVMInitializeNativeAsmPrinter();
    LLVMInitializeNativeAsmParser();

    LLVMContextRef context = LLVMGetGlobalContext();
    LLVMModuleRef module = LLVMModuleCreateWithNameInContext("arithmetic_module", context);
    LLVMBuilderRef builder = LLVMCreateBuilder();

    generateArithmeticFunction(module, builder, "add", ADD);
    generateArithmeticFunction(module, builder, "sub", SUB);
    generateArithmeticFunction(module, builder, "mul", MUL);
    generateArithmeticFunction(module, builder, "div", DIV);

    char* error = NULL;
    LLVMExecutionEngineRef engine;
    if (LLVMCreateExecutionEngineForModule(&engine, module, &error)) {
        fprintf(stderr, "Error creating execution engine: %s\n", error);
        LLVMDisposeMessage(error);
        return 1;
    }

    typedef int (*ArithmeticFunction)(int, int);
    ArithmeticFunction addFunc = (ArithmeticFunction)LLVMGetFunctionAddress(engine, "add");
    ArithmeticFunction subFunc = (ArithmeticFunction)LLVMGetFunctionAddress(engine, "sub");
    ArithmeticFunction mulFunc = (ArithmeticFunction)LLVMGetFunctionAddress(engine, "mul");
    ArithmeticFunction divFunc = (ArithmeticFunction)LLVMGetFunctionAddress(engine, "div");

    if (addFunc && subFunc && mulFunc && divFunc) {
        printf("add(10, 5) = %d\n", addFunc(10, 5));
        printf("sub(10, 5) = %d\n", subFunc(10, 5));
        printf("mul(10, 5) = %d\n", mulFunc(10, 5));
        printf("div(10, 5) = %d\n", divFunc(10, 5));
    } else {
        fprintf(stderr, "Failed to retrieve one or more functions.\n");
    }

    LLVMDisposeExecutionEngine(engine);
    LLVMDisposeBuilder(builder);
    LLVMDisposeModule(module);
    return 0;
}
