#ifndef C2LLVMIR_AST_H
#define C2LLVMIR_AST_H

#include <llvm/IR/Value.h>
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include "utils.h"
class Context;
class FunctionDefAST;
llvm::Type*  getType(int typeidt, Context* context);

class AST{
public:
    AST(){}
    ~AST(){}
    virtual llvm::Value* codeGen(Context* context){return nullptr;}
};

class ExpAST:public AST{
public:
    ExpAST(){}
    ~ExpAST(){}
    virtual llvm::Value* codeGen(Context* context){ return nullptr;}
};

class StmAST:public AST{
public:
    StmAST(){}
    ~StmAST(){}
    virtual llvm::Value* codeGen(Context* context){ return nullptr;}
};

//Type Node
//Int
class IntExpAST:public ExpAST{
private:
    int value;
public:
    IntExpAST(int t_value):value(t_value){}
    ~IntExpAST(){}
    virtual llvm::Value* codeGen(Context* context);
};

//Char
class CharExpAST:public ExpAST{
private:
    char value;
public:
    CharExpAST(char t_value):value(t_value){}
    ~CharExpAST(){}
    virtual llvm::Value* codeGen(Context* context);
};

class BinaryOptExpAST:public ExpAST{
private:
    int value;//see BINARY_OPT_XXX
    ExpAST* LHS;
    ExpAST* RHS;
public:
    BinaryOptExpAST(int t_value,ExpAST* lhs, ExpAST* rhs):value(t_value),LHS(lhs),RHS(rhs){}
    ~BinaryOptExpAST(){}
    virtual llvm::Value* codeGen(Context* context);
};

//Indentifier
class IdentifierExpAST:public ExpAST{
private:
    std::string name;
public:
    IdentifierExpAST(std::string t_name):name(t_name){}
    virtual llvm::Value* codeGen(Context* context);
};

class BlockAST:public ExpAST{
private:
    std::string blockName;
    std::vector<AST*> stmsAndExps;
    std::map<std::string,llvm::Value*> symboltable;
    llvm::Function* func;
    bool bbCreated;
    llvm::BasicBlock* bblock;
public:
    BlockAST():func(nullptr), bbCreated(false){}
    BlockAST(std::string str):blockName(str), func(nullptr), bbCreated(false){}
    ~BlockAST(){}
    bool addAST(AST* one);
    bool addSymbol(const std::string&,const llvm::Value*);
    llvm::Value *getSymbol(const std::string&);
    virtual llvm::Value* codeGen(Context* context);
    void setName(const std::string newname){blockName.assign(newname);};
    void setFunc(llvm::Function* parent);
    llvm::BasicBlock *BBCreate(Context* context);
};

class FunctionDecAST:public StmAST{
private:
    std::string name;
    int ret;//return value type
    std::vector<std::pair<int,std::string>> args;//first type, second name
    friend class FunctionDefAST;
public:
    FunctionDecAST(){}
    virtual llvm::Function *codeGen(Context* context);
    void setName(std::string tname);
    void setType(int tret);
    void addArg(int rettype, std::string name);
};

class FunctionDefAST:public ExpAST{
private:
    FunctionDecAST *declare;//needed
    BlockAST *body;//needed
public:
    FunctionDefAST(){}
    FunctionDefAST(FunctionDecAST* tdec, BlockAST* tblo):declare(tdec), body(tblo){}
    ~FunctionDefAST(){}
    virtual llvm::Function* codeGen(Context* context);
};

class FunctionCallAST:public ExpAST{
private:
    std::string name;//needed
    std::vector<ExpAST*> args;//needed
public:
    FunctionCallAST(std::string nname):name(nname){}
    ~FunctionCallAST(){}
    void addArg(ExpAST* arg);
    virtual llvm::Value* codeGen(Context* context);
};

class IfExpAST:public ExpAST{
private:
    ExpAST* Cond;//needed
    BlockAST* Then;//needed
    BlockAST* Else;//needed maybe nullptr
    BlockAST* Merge;
public:
    IfExpAST(ExpAST* nCond, BlockAST* nThen, BlockAST* nElse):Cond(nCond), Then(nThen), Else(nElse){}
    ~IfExpAST(){}
    virtual llvm::Value* codeGen(Context* context);
};

class ForExpAST:public ExpAST{
private:
    ExpAST* init, *cond, *incre;//needed, can be nullptr
    BlockAST* block;//needed
public:
    ForExpAST(ExpAST* ninit, ExpAST* ncond, ExpAST* nincre, BlockAST* nblock):init(ninit), cond(ncond), incre(nincre), block(nblock){}
    ~ForExpAST(){}
    virtual llvm::Value* codeGen(Context* context);
};

class WhileExpAST:public ExpAST{
private:
    ExpAST* cond;//needed
    BlockAST* block;//needed
public:
    WhileExpAST(ExpAST* ncond, BlockAST* nblock):cond(ncond), block(nblock){}
    ~WhileExpAST(){}
    virtual llvm::Value* codeGen(Context* context);
};
#endif //C2LLVMIR_AST_H
