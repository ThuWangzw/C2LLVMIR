#include "context.h"
#include "AST.h"

using namespace std;
using namespace llvm;
int main(){
    Context *ctx = new Context();

    IntExpAST *intast3 = new IntExpAST(5);
    IntExpAST *intast4 = new IntExpAST(6);
    BinaryOptExpAST *bin1 = new BinaryOptExpAST(BINARY_OPT_MULTI,intast3, intast4);

    IntExpAST *intast7 = new IntExpAST(7);
    IntExpAST *intast8 = new IntExpAST(8);
    BinaryOptExpAST *bin2 = new BinaryOptExpAST(BINARY_OPT_MULTI,intast7, intast8);

    FunctionDecAST *func1 = new FunctionDecAST();
    func1->setName(std::string("test"));
    func1->setType(TYPE_INT);
    func1->addArg(TYPE_INT,std::string("arg1"));
    //func->addArg(TYPE_INT,std::string("arg2"));
    BlockAST *block1 = new BlockAST();
    block1->addAST(bin1);
    block1->addAST(bin2);

    FunctionDefAST *funcdef1 = new FunctionDefAST(func1, block1);

    FunctionCallAST* funccall = new FunctionCallAST("test");
    IntExpAST *intast5 = new IntExpAST(6);
    funccall->addArg(intast5);

    IntExpAST *intast = new IntExpAST(1);
    IntExpAST *intast2 = new IntExpAST(2);
    BinaryOptExpAST *bin = new BinaryOptExpAST(BINARY_OPT_MULTI,intast, intast2);

    FunctionDecAST *func = new FunctionDecAST();
    func->setName(std::string("main"));
    func->setType(TYPE_INT);
    func->addArg(TYPE_INT,std::string("arg1"));
    //func->addArg(TYPE_INT,std::string("arg2"));
    BlockAST *block = new BlockAST("en");
    block->addAST(funccall);
    block->addAST(bin);
//
    FunctionDefAST *funcdef = new FunctionDefAST(func, block);
//
    BlockAST *basic = new BlockAST();
    basic->addAST(funcdef1);
    basic->addAST(funcdef);

    Value* res = basic->codeGen(ctx);
    res->print(errs());

    cout<<endl;
    //ctx->theModule->print(errs(), nullptr);
    return 0;
}
