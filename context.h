#ifndef C2LLVMIR_CONTEXT_H
#define C2LLVMIR_CONTEXT_H
#include <llvm/IR/Value.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/Module.h>
#include <llvm/Support/raw_ostream.h>
#include <memory>
#include <stack>
#include "AST.h"
#include <iostream>
#include <string>

class Context{
public:
    llvm::LLVMContext llvmContext;
    llvm::IRBuilder<> builder;
    llvm::Function* nowFunc;
    std::unique_ptr<llvm::Module> theModule;
    std::vector<BlockAST*> blockstack;
    //get Symbol
    llvm::Value* getSymbol(std::string& t_name){
        //return blockstack.top() -> getSymbol(t_name);
    }
    //add Symbol
    bool addSymbol(const std::string& t_name,const llvm::Value* t_value){
        //return blockstack.top() -> addSymbol(t_name,t_value);
    }
    Context():builder(llvmContext), nowFunc(nullptr){
        this->theModule = llvm::make_unique<llvm::Module>("c model", this->llvmContext);
    }
    ~Context(){}
};
#endif //C2LLVMIR_CONTEXT_H
