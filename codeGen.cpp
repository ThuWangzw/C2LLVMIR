#include <llvm/IR/Value.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/LegacyPassManager.h>
#include <llvm/IR/IRPrintingPasses.h>
#include <llvm/Support/raw_ostream.h>
#include <llvm/IR/Verifier.h>
#include <llvm/IR/GlobalVariable.h>
#include <iostream>
#include "context.h"
#include "AST.h"
#include "y.tab.hpp"

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

Value* CharExpAST::codeGen(Context* context){
    return ConstantInt::get(Type::getInt8Ty(context->llvmContext), this->value, true);
}

Value* StringLiteralExpAST::codeGen(Context* context){
    GlobalVariable* value = context->builder.CreateGlobalString(this->value, "string");
    std::vector<Value*> indices;
    indices.push_back(ConstantInt::get(Type::getInt32Ty(context->llvmContext),0,false));
    indices.push_back(ConstantInt::get(Type::getInt32Ty(context->llvmContext),0,false));
    auto ptr = context->builder.CreateInBoundsGEP(value,indices,"arrayPtr");
    return ptr;
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
        case BINARY_OPT_LOGAND:{
            //constant
            IntExpAST* zero = new IntExpAST(0);
            //else
            BlockAST *elseb = new BlockAST(string("left"));
            elseb->addAST(zero);
            //R
            BlockAST *rb = new BlockAST(string("right"));
            rb->addAST(this->RHS);
            IfExpAST *ifexp = new IfExpAST(this->LHS, rb, elseb);
            ifexp->setNeed(true);
            Value* addcon = context->builder.CreateICmpNE(ifexp->codeGen(context),ConstantInt::get(context->llvmContext, APInt(1,0)), "ifcond");
            return context->builder.CreateICmpNE(addcon,ConstantInt::get(context->llvmContext, APInt(1,0)), "ifcond");
        }
        case BINARY_OPT_LOGOR:{
            //constant
            IntExpAST* one = new IntExpAST(1);
            //else
            BlockAST *elseb = new BlockAST(string("left"));
            elseb->addAST(one);
            //R
            BlockAST *rb = new BlockAST(string("right"));
            rb->addAST(this->RHS);
            IfExpAST *ifexp = new IfExpAST(this->LHS, elseb, rb);
            ifexp->setNeed(true);
            Value* addcon = context->builder.CreateICmpNE(ifexp->codeGen(context),ConstantInt::get(context->llvmContext, APInt(1,0)), "ifcond");
            return context->builder.CreateICmpNE(addcon,ConstantInt::get(context->llvmContext, APInt(1,0)), "ifcond");
        }
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
    FunctionType *FT;
    if (this->isExtern) FT = FunctionType::get(rettype, argtypes, true);
    else FT = FunctionType::get(rettype, argtypes, false);
    Function* res =Function::Create(FT, Function::ExternalLinkage, this->name, context->theModule.get());
    int i = 0;
    for(auto &arg:res->args()){
        arg.setName(this->args[i].second);
        i++;
    }
    if(!res){
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
    this->body->origin_arg = this->getfuncArgvec();
    Value* retres = this->body->codeGen(context);
    return func;
    if(retres){
        IntExpAST* retval = new IntExpAST(0);
        ReturnExpAST* retexp = new ReturnExpAST(retval);
        retexp->codeGen(context);
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
    context->blockstack.push_back(this);
    if(this->blockName.empty()){
        this->blockName = "block";
    }
    if(!this->bbCreated){
        if(this->func != nullptr){
            this->bblock = BasicBlock::Create(context->llvmContext, this->blockName, this->func);
            context->builder.SetInsertPoint(this->bblock);

            int i = 0;
            Value* argAlloc;
            for(auto &ir_arg_it: this->func->args()){
                ir_arg_it.setName((*origin_arg)[i]->lhs->getName());
                argAlloc = (*origin_arg)[i]->codeGen(context);
                context->builder.CreateStore(&ir_arg_it, argAlloc, false);
                i++;
            }
        } else{
            //Function* tmp = context->builder.GetInsertBlock()->getParent();
            this->bblock = BasicBlock::Create(context->llvmContext, this->blockName, context->nowFunc);
            context->builder.SetInsertPoint(this->bblock);
        }
    } else{
        context->builder.SetInsertPoint(this->bblock);
    }

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
    // if (CalleeF->arg_size() != this->args.size())
        // return LogErrorV("Incorrect # arguments passed");
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
            CondV,ConstantInt::get(context->llvmContext, APInt(1,0)), "ifcond");
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
    //thenbb = context->builder.GetInsertBlock();

    // Emit else block.
    TheFunction->getBasicBlockList().push_back(elsebb);
    Value *ElseV = this->Else->codeGen(context);
    context->builder.CreateBr(mergebb);
    // Codegen of 'Else' can change the current block, update ElseBB for the PHI.
    //elsebb = context->builder.GetInsertBlock();

    // Emit merge block.
    TheFunction->getBasicBlockList().push_back(mergebb);
    context->builder.SetInsertPoint(mergebb);
    if(this->needres){
        PHINode *PN = context->builder.CreatePHI(Type::getInt1Ty(context->llvmContext), 2, "iftmp");

        PN->addIncoming(ThenV, thenbb);
        PN->addIncoming(ElseV, elsebb);
        return PN;
    }
    return Constant::getNullValue(getType(TYPE_INT, context));;
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


    BasicBlock *beforeLoop = BasicBlock::Create(context->llvmContext, "beforeloop", TheFunction);
    context->builder.CreateBr(beforeLoop);
    context->builder.SetInsertPoint(beforeLoop);
    //

    //create end
    BasicBlock *AfterBB = BasicBlock::Create(context->llvmContext, "afterloop");
    //add cond
    if(!this->cond){
        this->cond = new IntExpAST(1);
    }
    Value* CondV = this->cond->codeGen(context);

    BasicBlock* loop = this->block->BBCreate(context);
    CondV = context->builder.CreateICmpNE(
            CondV,ConstantInt::get(context->llvmContext, APInt(1,0)), "forcond");
    context->builder.CreateCondBr(CondV, loop, AfterBB);
    context->builder.SetInsertPoint(loop);
    //choose cond

    if(!this->block->codeGen(context)){
        return  LogErrorV("for block error");
    }

    //incre and continue
    this->incre->codeGen(context);
    context->builder.CreateBr(beforeLoop);
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


    BasicBlock *beforeLoop = BasicBlock::Create(context->llvmContext, "beforeloop", TheFunction);
    context->builder.CreateBr(beforeLoop);
    context->builder.SetInsertPoint(beforeLoop);
    //

    //create end
    BasicBlock *AfterBB = BasicBlock::Create(context->llvmContext, "afterloop");
    //add cond
    if(!this->cond){
        this->cond = new IntExpAST(1);
    }
    Value* CondV = this->cond->codeGen(context);

    BasicBlock* loop = this->block->BBCreate(context);
    CondV = context->builder.CreateICmpNE(
            CondV,ConstantInt::get(context->llvmContext, APInt(1,0)), "forcond");
    context->builder.CreateCondBr(CondV, loop, AfterBB);
    context->builder.SetInsertPoint(loop);

    //choose cond

    if(!this->block->codeGen(context)){
        return  LogErrorV("for block error");
    }
    context->builder.CreateBr(beforeLoop);
    //after loop
    TheFunction->getBasicBlockList().push_back(AfterBB);
    context->builder.SetInsertPoint(AfterBB);
    return Constant::getNullValue(getType(TYPE_INT, context));
}

llvm::Value* ReturnExpAST::codeGen(Context* context){
    Value* retval = this->retexp->codeGen(context);
    context->builder.CreateRet(retval);
    return retval;
}

llvm::Value* IdentifierExpAST::codeGen(Context *context){
    Value* t_value = context -> getSymbol( this -> name);
    if (!t_value){
        return LogErrorV("Undeclared Variables");
    }
    if (t_value->getType() -> isPointerTy()){
        auto arrayPtr = context->builder.CreateLoad(t_value,"arrayPtr");
        //array type
        if(arrayPtr->getType() -> isArrayTy()){
            std::vector<Value*> indices;
            indices.push_back(ConstantInt::get(Type::getInt32Ty(context->llvmContext),0,false));
            indices.push_back(ConstantInt::get(Type::getInt32Ty(context->llvmContext),0,false));
            auto ptr = context->builder.CreateInBoundsGEP(t_value,indices,"arrayPtr");
            return ptr;
        }
    }

    return context->builder.CreateLoad(t_value,false,"");
}

llvm::Value* VariableAssignAST::codeGen(Context *context){
    Value* l_value = context -> getSymbol( this->lhs->name );
    if (!l_value){
        return LogErrorV("Undeclared Variables");
    }
    Value* r_value = this -> rhs ->codeGen(context);

    context->builder.CreateStore(r_value,l_value);
    return l_value;
}

llvm::Value* VariableDecAST::codeGen(Context *context){
    Type * tp = getType(this->type,context);
    Value *inst = nullptr;
    if(this->lhs->isArray){
        if(this->lhs->arrayLength <= 0){
            return LogErrorV("Wrong Array Length");
        }
        Value* arraySizeValue  = IntExpAST(this->lhs->arrayLength).codeGen(context);
        auto arrayType = ArrayType::get(tp,this->lhs->arrayLength);
        inst = context->builder.CreateAlloca(arrayType,arraySizeValue,"arraytmp");
    }
    else{
        inst = context->builder.CreateAlloca(tp, nullptr, this->lhs->name);
    }
    context->addSymbol(this->lhs->name,inst);
    context->setSymbolType(this->lhs->name,this->type);

    if(this->rhs != nullptr){
        VariableAssignAST assign(this->lhs,this->rhs);
        assign.codeGen(context);
    }
    return inst;
}


llvm::Value* GlobalVariableDecAST::codeGen(Context* context){
    Type * tp = getType(this->type,context);
    GlobalVariable *inst = nullptr;
    if(this->lhs->isArray){
        if(this->lhs->arrayLength <= 0){
            return LogErrorV("Wrong Array Length");
        }
        auto arrayType = ArrayType::get(tp,this->lhs->arrayLength);
        inst = new GlobalVariable(*context->theModule,arrayType,false,llvm::GlobalValue::CommonLinkage,0,this->lhs->name);
        inst -> setAlignment(4);
        std::vector<Constant *> init_ref;
        for (int i = 0; i < this->lhs->arrayLength; i++)
            init_ref.push_back(ConstantInt::get(tp, 0, true));
        auto init_value = ConstantArray::get(arrayType,init_ref);
        inst -> setInitializer(init_value);
    }
    else{
        inst = new GlobalVariable(*context->theModule,tp,false,llvm::GlobalValue::CommonLinkage,0,this->lhs->name);
        auto init_value = ConstantInt::get(tp, 0, true);
        inst -> setAlignment(4);
        inst -> setInitializer(init_value);
    }
    context->addSymbol(this->lhs->name,inst);
    context->setSymbolType(this->lhs->name,this->type);

    if(this->rhs != nullptr){
        VariableAssignAST assign(this->lhs,this->rhs);
        assign.codeGen(context);
    }
    return inst;
}


llvm::Value* ArrayIndexAST::codeGen(Context *context){
    auto arrPtr = context->getSymbol(this->arrayName->name);
    auto arrType = getType(context->getSymbolType(this->arrayName->name),context);

    auto index = this->indexExp->codeGen(context);
    std::vector<Value*> indices;

    if(arrPtr->getType()->isPointerTy()){
        indices ={ConstantInt::get(Type::getInt64Ty(context->llvmContext),0),index };
    }
    else{
        return LogErrorV("The Variable is not array");
    }
    auto ptr = context->builder.CreateInBoundsGEP(arrPtr,indices,"elementPtr");
    return context->builder.CreateAlignedLoad(ptr,4);
}


llvm::Value* ArrayAssignAST::codeGen(Context *context){
    // cout << "Array Assign" << endl;
    auto arrValue = context->getSymbol(this->index->arrayName->name);
    if(arrValue == nullptr){
        cout << "symbol not found" << endl;
        return LogErrorV("Undeclared Variable");
    }

    auto arrPtr = context->builder.CreateLoad(arrValue,"arrayPtr");
    auto arrType = getType(context->getSymbolType(this->index->arrayName->name),context);
    
    if(!arrPtr->getType()->isArrayTy() && !arrPtr->getType()->isPointerTy()){
        return LogErrorV("Variable is not Array");
    }

    auto index = this->index->indexExp->codeGen(context);
    std::vector<Value*> indices= {ConstantInt::get(Type::getInt64Ty(context->llvmContext),0),index };
    auto ptr = context->builder.CreateInBoundsGEP(arrValue,indices,"elementPtr");
    return context->builder.CreateAlignedStore(this->r_value->codeGen(context),ptr,4);
}


llvm::Value* ArrayInitAST::codeGen(Context *context){
    auto arrPtr = this->arrayDec->codeGen(context);
    auto arrSize = this->arrayDec->lhs->arrayLength;

    for(unsigned long i = 0; i < this->list->size(); i++){
        IntExpAST* indexValue = new IntExpAST(i);
        ArrayIndexAST* id = new ArrayIndexAST(this->arrayDec->lhs,indexValue);
        ArrayAssignAST* asg = new ArrayAssignAST(id,this->list->at(i));
        asg->codeGen(context);
    }
    return nullptr;
}

