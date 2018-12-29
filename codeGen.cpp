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

llvm::Type*  getType(int typeidt, Context* context){
    if(typeidt == TYPE_INT){
        return Type::getInt32Ty(context->llvmContext);
    }
    if(typeidt == TYPE_CHAR){
        return Type::getInt8Ty(context->llvmContext);
    }
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
        argtypes.push_back( getType(one.first,context));
    }
    //ret type
    Type *rettype;
    rettype = getType(this->ret,context);
    //create func
    FunctionType *FT = FunctionType::get(rettype, argtypes, false);
    Function* res =Function::Create(FT, Function::ExternalLinkage, this->name, context->theModule.get());
    int i = 0;
    for(auto &arg:res->args()){
        arg.setName(this->args[i].second);
        i++;
    }
    if(res== nullptr){
        LogErrorV("declare error!!!");
        return nullptr;
    }
    return res;
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

llvm::Function* FunctionDefAST::codeGen(Context* context){
    //handle declare
    Function *func = context->theModule->getFunction(this->declare->name);
    if(!func){
        func = this->declare->codeGen(context);
    }
    if(func == nullptr)
    {
        cout<<func;
        LogErrorV("function declaration error");
        cout<<func;
        return nullptr;
    }
    //add block
    this->body->setName("entry");
    this->body->setFunc(func);
    Value* retres = this->body->codeGen(context);
    if(retres){
        context->builder.CreateRet(retres);
        llvm::verifyFunction(*func);
        return func;
    } else{
        func->eraseFromParent();
        return nullptr;
    }
}

llvm::Value* BlockAST::codeGen(Context* context){
    //set var name and value
    Value* retval = nullptr;
    if(!this->bbCreated){
        if(this->func != nullptr){
            for (auto &Arg : this->func->args()){
                this->symboltable[Arg.getName().data()] = &Arg;
            }
            BasicBlock *BB = BasicBlock::Create(context->llvmContext, this->blockName, this->func);
            context->builder.SetInsertPoint(BB);
        } else{
            BasicBlock *BB = BasicBlock::Create(context->llvmContext, this->blockName);
            context->builder.SetInsertPoint(BB);
        }
    } else{
        context->builder.SetInsertPoint(this->bblock);
    }
    context->blockstack.push_back(this);
    for(vector<AST*>::iterator iter = this->stmsAndExps.begin(); iter != this->stmsAndExps.end(); iter++){
        AST* now = *iter;
        retval = now->codeGen(context);
    }
    context->blockstack.pop_back();
    return retval;
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

llvm::Value* FunctionCallAST::codeGen(Context* context){
    // Look up the name in the global module table.
    Function *CalleeF = context->theModule->getFunction(name);
    if (!CalleeF)
        return LogErrorV("Unknown function referenced");
    // If argument mismatch error.
    if (CalleeF->arg_size() != this->args.size())
        return LogErrorV("Incorrect # arguments passed");
    std::vector<Value *> ArgsV;
    for (unsigned i = 0, e = this->args.size(); i != e; ++i) {
        ArgsV.push_back(this->args[i]->codeGen(context));
        if (!ArgsV.back())
            return nullptr;
    }
    return context->builder.CreateCall(CalleeF, ArgsV, "call");
}

llvm::Value* IfExpAST::codeGen(Context* context){
    Value *CondV = this->Cond->codeGen(context);
    if (!CondV)
    {
        LogErrorV("if condition exp error!");
        return nullptr;
    }
    //if cond
    CondV = context->builder.CreateICmpNE(
            CondV,Constant::getIntegerValue(getType(TYPE_INT, context),APInt(32,0,true)), "ifcond");
    Function *TheFunction = context->builder.GetInsertBlock()->getParent();
    // Create blocks for the then and else cases.  Insert the 'then' block at the
    // end of the function.
    this->Then->setFunc(TheFunction);
    this->Then->setName("then");
    BasicBlock* thenbb = this->Then->BBCreate(context);
    this->Else->setName("else");
    BasicBlock* elsebb = this->Else->BBCreate(context);
    this->Merge = new BlockAST();
    this->Merge->setName("ifcont");
    BasicBlock* mergebb = this->Merge->BBCreate(context);
    context->builder.CreateCondBr(CondV, thenbb, elsebb);
    // Emit then value.
    Value* ThenV = this->Then->codeGen(context);
    if (!ThenV){
        LogErrorV("then error");
        return nullptr;

    }
    context->builder.CreateBr(mergebb);
    // Codegen of 'Then' can change the current block, update ThenBB for the PHI.
    thenbb = context->builder.GetInsertBlock();

    // Emit else block.
    TheFunction->getBasicBlockList().push_back(elsebb);
    Value *ElseV = this->Else->codeGen(context);
    if (!ElseV)
    {
        LogErrorV("else error");
        return nullptr;

    }

    context->builder.CreateBr(mergebb);
    // Codegen of 'Else' can change the current block, update ElseBB for the PHI.
    elsebb = context->builder.GetInsertBlock();

    // Emit merge block.
    TheFunction->getBasicBlockList().push_back(mergebb);
    context->builder.SetInsertPoint(mergebb);
    PHINode *PN = context->builder.CreatePHI(getType(TYPE_INT, context), 2, "iftmp");

    PN->addIncoming(ThenV, thenbb);
    PN->addIncoming(ElseV, elsebb);
    return PN;
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