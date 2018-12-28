#include "context.h"
#include "AST.h"

using namespace std;
using namespace llvm;
int main(){
    Context *ctx = new Context();

    IntExpAST *intast = new IntExpAST(1);
    IntExpAST *intast2 = new IntExpAST(2);
    BinaryOptExpAST *bin = new BinaryOptExpAST(BINARY_OPT_MULTI,intast, intast2);

    FunctionDecAST *func = new FunctionDecAST();
    func->setName(std::string("main"));
    func->setType(TYPE_INT);
    //func->addArg(TYPE_INT,std::string("arg1"));
    //func->addArg(TYPE_INT,std::string("arg2"));
    BlockAST *block = new BlockAST();
    block->addAST(bin);

    FunctionDefAST *funcdef = new FunctionDefAST(func, block);
    Value* res = funcdef->codeGen(ctx);
    res->print(errs());

    cout<<endl;
    //ctx->theModule->print(errs(), nullptr);
    return 0;
}
