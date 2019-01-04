#include <llvm/IR/Value.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/LegacyPassManager.h>
#include <llvm/IR/IRPrintingPasses.h>
#include <llvm/Support/raw_ostream.h>
#include <llvm/IR/Verifier.h>
#include <iostream>
#include "context.h"
#include "AST.h"
#include "y.tab.hpp"
using namespace llvm;
using namespace std;

llvm::Type*  getType(int typeidt, Context* context){
    if(typeidt == TYPE_INT){
        return Type::getInt32Ty(context->llvmContext);
    }
    if(typeidt == TYPE_CHAR){
        return Type::getInt8Ty(context->llvmContext);
    }
    if(typeidt == TYPE_CHAR_PTR){
        return Type::getInt8PtrTy(context->llvmContext);
    }
    return nullptr;
}

void FunctionDecAST::setType(int tret){
    this->ret = tret;
    return;
}

void FunctionDecAST::addArg(int rettype, std::string name){
    this->args.push_back(make_pair(rettype,name));
    return;
}

void FunctionDecAST::setName(std::string tname){
    this->name.assign(tname);
    return;
}

void BlockAST::setFunc(llvm::Function* parent){
    this->func = parent;
}

bool BlockAST::addAST(AST* one){
    this->stmsAndExps.push_back(one);
    return true;
}

void FunctionCallAST::addArg(ExpAST *arg){
    this->args.push_back(arg);
}

llvm::BasicBlock* BlockAST::BBCreate(Context* context){
    if(this->blockName.empty()){
        if(this->func== nullptr){
            this->bblock = BasicBlock::Create(context->llvmContext);
            this->bbCreated = true;
        } else{
            this->bblock = BasicBlock::Create(context->llvmContext,"",this->func);
            this->bbCreated = true;
        }
    } else{
        if(this->func== nullptr){
            this->bblock = BasicBlock::Create(context->llvmContext,this->blockName);
            this->bbCreated = true;
        } else{
            this->bblock = BasicBlock::Create(context->llvmContext,this->blockName,this->func);
            this->bbCreated = true;
        }
    }
    return this->bblock;
}

void ReturnExpAST::setExp(ExpAST* n_retexp){
    this->retexp = n_retexp;
}

bool BlockAST::addSymbol(const std::string& name, llvm::Value* t_value){
    auto it = this -> symboltable.find(name);
    if( it == this->symboltable.end()){
        this->symboltable[name] = t_value;
        return true;
    }
    return false;
}
    
    
llvm::Value * BlockAST::getSymbol(const std::string& name){
    auto it = this -> symboltable.find(name);
    if( it == this->symboltable.end()){
        return nullptr;
    }
    return this->symboltable[name];
}

bool BlockAST::setSymbolType(const std::string& name, int tp){
    auto it = this -> symboltype.find(name);
    if( it != this->symboltype.end()){
        this->symboltype[name] = tp;
        return true;
    }
    return false;
}

int BlockAST::getSymbolType(const std::string& name){
    auto it = this -> symboltype.find(name);
    if( it == this->symboltype.end()){
        return TYPE_ERROR;
    }
    return this->symboltype[name];

}