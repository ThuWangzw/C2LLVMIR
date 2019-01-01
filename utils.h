#ifndef C2LLVMIR_UTILS_H
#define C2LLVMIR_UTILS_H
#include <llvm/IR/Value.h>
#include <llvm/IR/Value.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/LegacyPassManager.h>
#include <llvm/IR/IRPrintingPasses.h>
#include <llvm/Support/raw_ostream.h>
#include <llvm/IR/Verifier.h>

#define BINARY_OPT_PLUS 0
#define BINARY_OPT_MINUS 1
#define BINARY_OPT_MULTI 2
#define BINARY_OPT_DIV 3
#define BINARY_OPT_AND 4
#define BINARY_OPT_OR 5
#define BINARY_OPT_EQ 6
#define BINARY_OPT_NE 7
#define BINARY_OPT_LT 8 //<
#define BINARY_OPT_GT 9 //>
#define BINARY_OPT_LE 10 //<=
#define BINARY_OPT_GE 11 //>=

#define TYPE_ERROR -1
#define TYPE_INT 0
#define TYPE_CHAR 1

int LogError(const char* errstr);
llvm::Value* LogErrorV(const char* errstr);

#endif //C2LLVMIR_UTILS_H
