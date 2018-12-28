#include "context.h"
#include "AST.h"
using namespace std;
using namespace llvm;
int main(){
    Context *ctx = new Context();
    IntExpAST *intast = new IntExpAST(1);
    IntExpAST *intast2 = new IntExpAST(2);
    BinaryOptExpAST *bin = new BinaryOptExpAST(BINARY_OPT_MULTI,intast, intast2);
    llvm::Value* res = bin->codeGen(ctx);
    res->print(errs());
    cout<<endl;
    ctx->theModule->print(errs(), nullptr);
    return 0;
}