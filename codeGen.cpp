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
    context->nowFunc = func;
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
            this->bblock = BasicBlock::Create(context->llvmContext, this->blockName, this->func);
            context->builder.SetInsertPoint(this->bblock);
            //cout<< this->blockName <<"func not null"<<endl;
        } else{
            //Function* tmp = context->builder.GetInsertBlock()->getParent();
            this->bblock = BasicBlock::Create(context->llvmContext, this->blockName, context->nowFunc);
            context->builder.SetInsertPoint(this->bblock);
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
    if(this->Else== nullptr){
        this->Else = new BlockAST();
        IntExpAST *tmp = new IntExpAST(-1);
        this->Else->addAST(tmp);
    }
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

llvm::Value* ForExpAST::codeGen(Context *context){
    //init
    if(this->init){
        this->init->codeGen(context);
    }
    //create block
    Function *TheFunction = context->builder.GetInsertBlock()->getParent();
    BasicBlock *PreheaderBB = context->builder.GetInsertBlock();
    this->block->setName("loop");
    this->block->setFunc(TheFunction);
    BasicBlock* loop = this->block->BBCreate(context);
    context->builder.CreateBr(loop);
    context->builder.SetInsertPoint(loop);

    //create end
    BasicBlock *AfterBB = BasicBlock::Create(context->llvmContext, "afterloop");
    //add cond
    if(!this->cond){
        this->cond = new IntExpAST(1);
    }
    Value* CondV = this->cond->codeGen(context);
    CondV = context->builder.CreateICmpNE(
            CondV,Constant::getIntegerValue(getType(TYPE_INT, context),APInt(32,0,true)), "forcond");
    //choose cond
    context->builder.CreateCondBr(CondV, loop, AfterBB);
    if(!this->block->codeGen(context)){
        return  LogErrorV("for block error");
    }

    //incre and continue
    this->incre->codeGen(context);
    context->builder.CreateBr(loop);
    //after loop

    TheFunction->getBasicBlockList().push_back(AfterBB);
    context->builder.SetInsertPoint(AfterBB);
    return Constant::getNullValue(getType(TYPE_INT, context));
}

llvm::Value* WhileExpAST::codeGen(Context* context){
    Function *TheFunction = context->builder.GetInsertBlock()->getParent();
    BasicBlock *PreheaderBB = context->builder.GetInsertBlock();
    this->block->setName("loop");
    this->block->setFunc(TheFunction);
    BasicBlock* loop = this->block->BBCreate(context);
    context->builder.CreateBr(loop);
    context->builder.SetInsertPoint(loop);
    //create end
    BasicBlock *AfterBB = BasicBlock::Create(context->llvmContext, "afterloop");
    //add cond
    if(!this->cond){
        this->cond = new IntExpAST(1);
    }
    Value* CondV = this->cond->codeGen(context);
    CondV = context->builder.CreateICmpNE(
            CondV,Constant::getIntegerValue(getType(TYPE_INT, context),APInt(32,0,true)), "forcond");
    //choose cond
    context->builder.CreateCondBr(CondV, loop, AfterBB);
    if(!this->block->codeGen(context)){
        return  LogErrorV("while block error");
    }
    //continue
    context->builder.CreateBr(loop);
    //after loop
    TheFunction->getBasicBlockList().push_back(AfterBB);
    context->builder.SetInsertPoint(AfterBB);
    return Constant::getNullValue(getType(TYPE_INT, context));
}