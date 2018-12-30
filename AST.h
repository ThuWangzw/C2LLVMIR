#ifndef C2LLVMIR_AST_H
#define C2LLVMIR_AST_H

#include <llvm/IR/Value.h>
#include <iostream>
#include <map>
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
    virtual llvm::Value* codeGen(Context* context) {return nullptr;}
    virtual json generateJson(){
        json j;
        j["type"] = "Char";
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

//Indentifier
class IdentifierExpAST:public ExpAST{
private:
    std::string name;
public:
    IdentifierExpAST(std::string t_name):name(t_name){}
    std::string getName(){return name;};
    virtual llvm::Value* codeGen(Context* context) {return nullptr;}
    virtual json generateJson(){
        json j;
        j["type"] = "Identifier";
        j["name"] = name;
        return j;
    }
};

class BlockAST:public ExpAST{
private:
    std::string blockName;
    std::vector<AST*> stmsAndExps;//needed
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
public:
    IfExpAST(ExpAST* nCond, BlockAST* nThen, BlockAST* nElse):Cond(nCond), Then(nThen), Else(nElse){}
    ~IfExpAST(){}
    virtual llvm::Value* codeGen(Context* context);
};

class ForExpAST:public StmAST{
private:
    ExpAST* init, *cond, *incre;//needed, can be nullptr
    BlockAST* block;//needed
public:
    ForExpAST(ExpAST* ninit, ExpAST* ncond, ExpAST* nincre, BlockAST* nblock):init(ninit), cond(ncond), incre(nincre), block(nblock){}
    ~ForExpAST(){}
    virtual llvm::Value* codeGen(Context* context);
};

class WhileExpAST:public StmAST{
private:
    ExpAST* cond;//needed
    BlockAST* block;//needed
public:
    WhileExpAST(ExpAST* ncond, BlockAST* nblock):cond(ncond), block(nblock){}
    ~WhileExpAST(){}
    virtual llvm::Value* codeGen(Context* context);
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
#endif //C2LLVMIR_AST_H
