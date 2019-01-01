#ifndef C2LLVMIR_AST_H
#define C2LLVMIR_AST_H

#include <llvm/IR/Value.h>
#include <iostream>
#include <map>
#include <vector>
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


class BlockAST:public ExpAST{
private:
    std::string blockName;
    std::vector<AST*> stmsAndExps;//needed
    std::map<std::string,llvm::Value*> symboltable;
    std::map<std::string,int> symboltype;
    llvm::Function* func;
    bool bbCreated;
    llvm::BasicBlock* bblock;
public:
    BlockAST():func(nullptr), bbCreated(false){}
    BlockAST(std::string str):blockName(str), func(nullptr), bbCreated(false){}
    ~BlockAST(){}
    bool addAST(AST* one);
    bool addSymbol(const std::string&, llvm::Value*);
    bool setSymbolType(const std::string&, int);
    int getSymbolType(const std::string&);
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

class ReturnExpAST:public ExpAST{
private:
    ExpAST* retexp;
public:
    ReturnExpAST():retexp(nullptr){}
    ReturnExpAST(ExpAST* n_retexp):retexp(n_retexp){}
    ~ReturnExpAST(){}
    void setExp(ExpAST* n_retexp);
    virtual llvm::Value* codeGen(Context* context);
};

typedef std::vector<ExpAST*> ExpressionList;

//Indentifier
class IdentifierExpAST:public ExpAST{
public:
    std::string name;
    bool isArray;
    uint64_t arrayLength;
    IdentifierExpAST(std::string t_name,int t_isArray = false,uint64_t t_arrayLength = 0):
        name(t_name),isArray(t_isArray),arrayLength(t_arrayLength){}
    virtual llvm::Value* codeGen(Context* context);
};

//Variable
class VariableAssignAST:public ExpAST{
public:
    IdentifierExpAST* lhs;
    ExpAST* rhs;
    VariableAssignAST(IdentifierExpAST* t_lhs, ExpAST* t_rhs):
        lhs(t_lhs),rhs(t_rhs){}
    virtual llvm::Value* codeGen(Context * context);
};


class VariableDecAST:public StmAST{
public:
    IdentifierExpAST* lhs;
    ExpAST* rhs;
    int type;
    VariableDecAST(int t_type, IdentifierExpAST* t_lhs,ExpAST* t_rhs = nullptr):
        lhs(t_lhs),rhs(t_rhs),type(t_type){}
    virtual llvm::Value* codeGen(Context* context);
};


//Array
class ArrayIndexAST:public ExpAST{
public:
    IdentifierExpAST * arrayName;
    ExpAST * indexExp;
    ArrayIndexAST(IdentifierExpAST* t_arrayName,ExpAST* t_indexExp):
        arrayName(t_arrayName),indexExp(t_indexExp){}
    virtual llvm::Value* codeGen(Context* context);
};


class ArrayAssignAST:public ExpAST{
public:
    ArrayIndexAST *index;
    ExpAST* r_value;
    ArrayAssignAST(ArrayIndexAST *idx,ExpAST* vl):
        index(idx),r_value(vl){}
    virtual llvm::Value* codeGen(Context* context);
};


class ArrayInitAST:public ExpAST{
public:
    VariableDecAST* arrayDec;
    ExpressionList* list;
    ArrayInitAST(VariableDecAST* dec,ExpressionList* lt):
        arrayDec(dec),list(lt){}
    virtual llvm::Value* codeGen(Context* context);
};





#endif //C2LLVMIR_AST_H

