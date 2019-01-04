#ifndef C2LLVMIR_AST_H
#define C2LLVMIR_AST_H

#include <llvm/IR/Value.h>
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <utility>
#include "utils.h"
#include "json.hpp"
using json = nlohmann::json;

class Context;
class FunctionDefAST;
llvm::Type*  getType(int typeidt, Context* context);

class AST{
public:
    AST(){}
    ~AST(){}
    virtual llvm::Value* codeGen(Context* context){return nullptr;}
    virtual json generateJson(){return json();}
};

class ExpAST:public AST{
public:
    ExpAST(){}
    ~ExpAST(){}
    virtual llvm::Value* codeGen(Context* context){ return nullptr;}
    virtual json generateJson(){return json();}
};

class StmAST:public AST{
public:
    StmAST(){}
    ~StmAST(){}
    virtual llvm::Value* codeGen(Context* context){ return nullptr;}
    virtual json generateJson(){return json();}
};

//Type Node
//Int
class IntExpAST:public ExpAST{
private:
    int value;
public:
    IntExpAST(int t_value):value(t_value){}
    ~IntExpAST(){}
    int get_value(){return value;}
    virtual llvm::Value* codeGen(Context* context);
    virtual json generateJson(){
        json j;
        j["type"] = "Int";
        j["value"] = value;
        return j;
    }
};

//Char
class CharExpAST:public ExpAST{
private:
    char value;
public:
    CharExpAST(char t_value):value(t_value){}
    ~CharExpAST(){}
    virtual llvm::Value* codeGen(Context* context);
    virtual json generateJson(){
        json j;
        j["type"] = "Char";
        j["value"] = value;
        return j;
    }
};

//StringLiteral
class StringLiteralExpAST:public ExpAST{
private:
    std::string value;
public:
    StringLiteralExpAST(std::string t_value):value(t_value){}
    ~StringLiteralExpAST(){}
    virtual llvm::Value* codeGen(Context* context);
    virtual json generateJson(){
        json j;
        j["type"] = "StringLiteral";
        j["value"] = value;
        return j;
    }
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
    virtual json generateJson(){
        json j;
        j["type"] = "BinaryOptExp";
        j["operator"] = value;
        j["left"] = LHS->generateJson();
        j["right"] = RHS->generateJson();
        return j;
    }
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
    virtual json generateJson(){
        json j;
        j["type"] = "Block";
        j["body"] = {};
        for (auto p = stmsAndExps.begin(); p != stmsAndExps.end(); p++) {
            j["body"].push_back((*p)->generateJson());
        }
        return j;
    }
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
    virtual json generateJson(){
        json j;
        j["type"] = "FuncDec";
        j["name"] = name;
        j["ret_type"] = ret;
        j["args"] = {};
        for (auto p = args.begin(); p != args.end(); p++) {
            j["args"].push_back(json({
                {"type", p->first},
                {"name", p->second}
            }));
	    }
        return j;
    }
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

    virtual json generateJson(){
        json j;
        j["type"] = "FuncDef";
        j["dec"] = declare->generateJson();
        j["body"] = body->generateJson();
        return j;
    }
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

    virtual json generateJson(){
        json j;
        j["type"] = "FunCall";
        j["name"] = name;
        j["args"] = {};
        for (auto p = args.begin(); p != args.end(); p++) {
            j["args"].push_back((*p)->generateJson());
	    }
        return j;
    }
};

class IfExpAST:public StmAST{
private:
    ExpAST* Cond;//needed
    BlockAST* Then;//needed
    BlockAST* Else;//needed maybe nullptr
    BlockAST* Merge;
    int needres;
public:
    IfExpAST(ExpAST* nCond, BlockAST* nThen, BlockAST* nElse):Cond(nCond), Then(nThen), Else(nElse), needres(false){}
    ~IfExpAST(){}
    void setNeed(int newneed){needres = newneed;}
    virtual llvm::Value* codeGen(Context* context);
    virtual json generateJson(){
        json j;
        j["type"] = "IfExp";
        j["cond"] = Cond->generateJson();
        j["then"] = Then->generateJson();
        if (Else != nullptr) j["else"] = Else->generateJson();
        return j;
    }
};

class ForExpAST:public StmAST{
private:
    ExpAST* init, *cond, *incre;//needed, can be nullptr
    BlockAST* block;//needed
public:
    ForExpAST(ExpAST* ninit, ExpAST* ncond, ExpAST* nincre, BlockAST* nblock):init(ninit), cond(ncond), incre(nincre), block(nblock){}
    ~ForExpAST(){}
    virtual llvm::Value* codeGen(Context* context);
    virtual json generateJson(){
        json j;
        j["type"] = "ForExp";
        if (init != nullptr) j["init"] = init->generateJson();
        if (cond != nullptr) j["cond"] = cond->generateJson();
        if (incre != nullptr) j["increase"] = incre->generateJson();
        j["block"] = block->generateJson();
        return j;
    }
};

class WhileExpAST:public StmAST{
private:
    ExpAST* cond;//needed
    BlockAST* block;//needed
public:
    WhileExpAST(ExpAST* ncond, BlockAST* nblock):cond(ncond), block(nblock){}
    ~WhileExpAST(){}
    virtual llvm::Value* codeGen(Context* context);
    virtual json generateJson(){
        json j;
        j["type"] = "while";
        j["cond"] = cond->generateJson();
        j["block"] = block->generateJson();
        return j;
    }
};

class ReturnExpAST:public StmAST{
private:
    ExpAST* retexp;
public:
    ReturnExpAST():retexp(nullptr){}
    ReturnExpAST(ExpAST* n_retexp):retexp(n_retexp){}
    ~ReturnExpAST(){}
    void setExp(ExpAST* n_retexp);
    virtual llvm::Value* codeGen(Context* context);
    virtual json generateJson(){
        json j;
        j["type"] = "ReturnExp";
        if (retexp != nullptr){
            j["exp"] = retexp->generateJson();
        }
        return j;
    }
};

typedef std::vector<ExpAST*> ExpressionList;

//Indentifier
class IdentifierExpAST:public ExpAST{
public:
    std::string name;
    bool isArray;
    uint64_t arrayLength;
    std::string getName(){return name;}
    IdentifierExpAST(std::string t_name,int t_isArray = false,uint64_t t_arrayLength = 0):
        name(t_name),isArray(t_isArray),arrayLength(t_arrayLength){}
    void setToArray(unsigned long long size){ isArray = true; arrayLength = size; }
    virtual llvm::Value* codeGen(Context* context);
    virtual json generateJson(){
        json j;
        j["type"] = "Identifier";
        j["name"] = name;
        j["isArray"] = isArray;
        j["arrayLength"] = arrayLength;
        return j;
    }
};

//Variable
class VariableAssignAST:public ExpAST{
public:
    IdentifierExpAST* lhs;
    ExpAST* rhs;
    VariableAssignAST(IdentifierExpAST* t_lhs, ExpAST* t_rhs):
        lhs(t_lhs),rhs(t_rhs){}
    virtual llvm::Value* codeGen(Context * context);
    virtual json generateJson(){
        json j;
        j["type"] = "Assign";
        j["ident"] = lhs->generateJson();
        j["expr"] = rhs->generateJson();
        return j;
    }
};


class VariableDecAST:public StmAST{
public:
    IdentifierExpAST* lhs;
    ExpAST* rhs;
    int type;
    VariableDecAST(int t_type, IdentifierExpAST* t_lhs,ExpAST* t_rhs = nullptr):
        lhs(t_lhs),rhs(t_rhs),type(t_type){}
    virtual llvm::Value* codeGen(Context* context);
    virtual json generateJson(){
        json j;
        j["type"] = "VarDec";
        j["ident"] = lhs->generateJson();
        if (rhs != nullptr) j["expr"] = rhs->generateJson();
        return j;
    }
};


//Array
class ArrayIndexAST:public ExpAST{
public:
    IdentifierExpAST * arrayName;
    ExpAST * indexExp;
    ArrayIndexAST(IdentifierExpAST* t_arrayName,ExpAST* t_indexExp):
        arrayName(t_arrayName),indexExp(t_indexExp){}
    virtual llvm::Value* codeGen(Context* context);
    virtual json generateJson(){
        json j;
        j["type"] = "ArrayIndex";
        j["name"] = arrayName->generateJson();
        j["index"] = indexExp->generateJson();
        return j;
    }
};


class ArrayAssignAST:public ExpAST{
public:
    ArrayIndexAST *index;
    ExpAST* r_value;
    ArrayAssignAST(ArrayIndexAST *idx,ExpAST* vl):
        index(idx),r_value(vl){}
    virtual llvm::Value* codeGen(Context* context);
    virtual json generateJson(){
        json j;
        j["type"] = "ArrayAssign";
        j["arrayIndex"] = index->generateJson();
        j["expr"] = r_value->generateJson();
        return j;
    }
};


class ArrayInitAST:public ExpAST{
public:
    VariableDecAST* arrayDec;
    ExpressionList* list;
    ArrayInitAST(VariableDecAST* dec,ExpressionList* lt):
        arrayDec(dec),list(lt){}
    virtual llvm::Value* codeGen(Context* context);
    virtual json generateJson(){
        json j;
        j["type"] = "ArrayInit";
        j["arrayDec"] = arrayDec->generateJson();
        j["exprs"] = {};
        for (auto p = list->begin(); p != list->end(); p++)
            j["exprs"].push_back((*p)->generateJson());
        return j;
    }
};





#endif //C2LLVMIR_AST_H

