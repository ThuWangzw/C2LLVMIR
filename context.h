#ifndef C2LLVMIR_CONTEXT_H
#define C2LLVMIR_CONTEXT_H
#include <llvm/IR/Value.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/Module.h>
#include <llvm/Support/raw_ostream.h>
#include <memory>
#include <vector>
#include <map>
#include "AST.h"
#include <iostream>
#include <string>

class BlockAST;

class Context{
public:
    llvm::LLVMContext llvmContext;
    llvm::IRBuilder<> builder;
    llvm::Function* nowFunc;
    std::unique_ptr<llvm::Module> theModule;

    std::vector<BlockAST*> blockstack;
    //get Symbol
    llvm::Value* getSymbol(std::string& t_name){
        for(auto it = blockstack.rbegin(); it != blockstack.rend(); it++ ){
            llvm::Value * t_value = (*it) -> getSymbol(t_name);
            if (t_value)
                return t_value;
        }
        return nullptr;
    }
    //add Symbol
    bool addSymbol(const std::string& t_name, llvm::Value* t_value){
         return blockstack.back() -> addSymbol(t_name,t_value);
    }
    int getSymbolType(std::string& t_name){
        for(auto it = blockstack.rbegin(); it != blockstack.rend(); it++ ){
            int tp = (*it) -> getSymbolType(t_name);
            if (tp != TYPE_ERROR)
                return tp;
        }
        return TYPE_ERROR;
    }
    bool setSymbolType(std::string& t_name,int t_type){
         return blockstack.back() -> setSymbolType(t_name,t_type);
    }
    Context():builder(llvmContext), nowFunc(nullptr){
        this->theModule = llvm::make_unique<llvm::Module>("c model", this->llvmContext);
    }
    ~Context(){}
};
#endif //C2LLVMIR_CONTEXT_H
