#ifndef C2LLVMIR_AST_H
#define C2LLVMIR_AST_H

#define BINARY_OPT_PLUS 0
#define BINARY_OPT_MINUS 1
#define BINARY_OPT_MULTI 2
#define BINARY_OPT_DIV 3
#define BINARY_OPT_AND 4
#define BINARY_OPT_OR 5
#define BINARY_OPT_EQ 6
#define BINARY_OPT_NE 7
#define BINARY_OPT_LT 8 //<
#define BINARY_OPT_GT 9 //>
#define BINARY_OPT_LE 10 //<=
#define BINARY_OPT_GE 11 //>=

#define TYPE_INT 0
#define TYPE_CHAR 1
#include <llvm/IR/Value.h>
#include <iostream>
#include <map>
#include <string>
#include <utility>
class Context;
class FunctionDefAST;
int LogError(const char* errstr);
llvm::Value* LogErrorV(const char* errstr);

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
    virtual llvm::Value* codeGen(Context* context){return nullptr;}
};

class IntExpAST:public ExpAST{
private:
    int value;
public:
    IntExpAST(int t_value):value(t_value){}
    ~IntExpAST(){}
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
    std::stack<AST*> stmsAndExps;
    std::map<std::string,llvm::Value*> symboltable;
public:
    BlockAST(){}
    ~BlockAST(){}
    bool addAST(AST*);
    bool addSymbol(const std::string&,const llvm::Value*);
    llvm::Value *getSymbol(const std::string&);
    virtual llvm::Value* codeGen(Context* context){return nullptr;}
    void addSymbol();
    llvm::Value* getSymbol(std::string);
    void setName(const std::string newname);
    void setLocalVariable(const std::vector<std::pair<int,std::string>>& args);
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
    FunctionDecAST *declare;
    BlockAST *body;
public:
    FunctionDecAST(){}
    FunctionDecAST(FunctionDecAST* tdec, BlockAST* tblo):declare(tdec), body(tblo){}
    ~FunctionDecAST(){}
    virtual llvm::Value* codeGen(Context* context);
};
#endif //C2LLVMIR_AST_H
