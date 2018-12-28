#include <llvm/IR/Value.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/LegacyPassManager.h>
#include <llvm/IR/IRPrintingPasses.h>
#include <llvm/Support/raw_ostream.h>
#include <iostream>
#include "context.h"
#include "AST.h"
using namespace std;
using namespace llvm;

int LogError(const char* errstr){
    cout<<errstr<<endl;
    return 0;
}
llvm::Value* LogErrorV(const char* errstr){
    LogError(errstr);
    return nullptr;
}
Value* IntExpAST::codeGen(Context* context) {
    return ConstantInt::get(Type::getInt32Ty(context->llvmContext), this->value, true);
}

Value* BinaryOptExpAST::codeGen(Context* context) {
    Value *L = this->LHS->codeGen(context);
    Value *R = this->RHS->codeGen(context);
    if (!L || !R)
        return nullptr;

    switch (this->value) {
        case BINARY_OPT_PLUS:
            return context->builder.CreateAdd(L, R, "addtmp");
        case BINARY_OPT_MINUS:
            return context->builder.CreateSub(L, R, "subtmp");
        case BINARY_OPT_MULTI:
            return context->builder.CreateMul(L, R, "multmp");
        case BINARY_OPT_DIV:
            return context->builder.CreateSDiv(L, R, "divtmp");
        case BINARY_OPT_AND:
            return context->builder.CreateAnd(L, R, "andtmp");
        case BINARY_OPT_OR:
            return context->builder.CreateOr(L, R, "ortmp");
        case BINARY_OPT_EQ:
            return context->builder.CreateICmpEQ(L, R, "cmptmp");
        case BINARY_OPT_NE:
            return context->builder.CreateICmpNE(L, R, "cmptmp");
        case BINARY_OPT_LT:
            return context->builder.CreateICmpSLT(L, R, "cmptmp");
        case BINARY_OPT_GT:
            return context->builder.CreateICmpSGT(L, R, "cmptmp");
        case BINARY_OPT_LE:
            return context->builder.CreateICmpSLE(L, R, "cmptmp");
        case BINARY_OPT_GE:
            return context->builder.CreateICmpSGE(L, R, "cmptmp");
        default:
            return LogErrorV("invalid binary operator");
    }
}

llvm::Function* FunctionDecAST::codeGen(Context* context){
    //args
    std::vector<Type *> argtypes;
    for(vector<std::pair<int,std::string>>::iterator iter = this->args.begin(); iter != this->args.end(); iter++){
        pair<int, string> one = (*iter);
        if(one.first == TYPE_INT){
            argtypes.push_back( Type::getInt32Ty(context->llvmContext));
        }
        else if(one.first == TYPE_CHAR){
            argtypes.push_back( Type::getInt8Ty(context->llvmContext));
        }
    }
    //ret type
    Type *rettype;
    if(ret == TYPE_INT){
        rettype = Type::getInt32Ty(context->llvmContext);
    }
    else if(ret == TYPE_CHAR){
        rettype = Type::getInt8Ty(context->llvmContext);
    }
    //create func
    FunctionType *FT = FunctionType::get(rettype, argtypes, false);
    return Function::Create(FT, Function::ExternalLinkage, this->name, context->theModule.get());
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

llvm::Value* FunctionDefAST::codeGen(Context* context){
    Function *TheFunction = context->theModule->getFunction(this->declare->name);
    if (!TheFunction)
        TheFunction = this->declare->codegen();
    if (!TheFunction)
    {
        LogErrorV("function declare codegen error!");
        return nullptr;
    }
    //add block
    this->body->setName("entry");
    this->body->setLocalVariable(this->declare->args);
    context->blockstack.push
    this->body->codeGen(context);
}