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

#define BINARY_OPT_PLUS PLUS
#define BINARY_OPT_MINUS MINUS
#define BINARY_OPT_MULTI MUL
#define BINARY_OPT_DIV DIV
#define BINARY_OPT_AND BIT_AND
#define BINARY_OPT_OR BIT_OR
#define BINARY_OPT_EQ COM_EQ
#define BINARY_OPT_NE COM_NE
#define BINARY_OPT_LT COM_L //<
#define BINARY_OPT_GT COM_G //>
#define BINARY_OPT_LE COM_LE //<=
#define BINARY_OPT_GE COM_GE //>=

#define TYPE_INT INT
#define TYPE_CHAR CHAR
#define TYPE_CHAR_PTR CHAR_PTR
#define TYPE_ERROR -1

int LogError(const char* errstr);
llvm::Value* LogErrorV(const char* errstr);

#endif //C2LLVMIR_UTILS_H
