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
    func1->setName(std::string("testfunc"));
    func1->setType(TYPE_INT);
    func1->addArg(TYPE_INT,std::string("arg1"));
    //func->addArg(TYPE_INT,std::string("arg2"));
    BlockAST *block1 = new BlockAST();
    block1->addAST(bin1);
    block1->addAST(bin2);

    FunctionDefAST *funcdef1 = new FunctionDefAST(func1, block1);

    FunctionCallAST* funccall1 = new FunctionCallAST("testfunc");
    IntExpAST *intast51 = new IntExpAST(3);
    funccall1->addArg(intast51);

    FunctionCallAST* funccall2 = new FunctionCallAST("testfunc");
    IntExpAST *intast52 = new IntExpAST(4);
    funccall2->addArg(intast52);

//if
    BlockAST* thenblock = new BlockAST();
    thenblock->addAST(funccall1);
    IdentifierExpAST* val1 = new IdentifierExpAST("my_val1");
    IntExpAST *val_tmp1 = new IntExpAST(1);
    IntExpAST *val_tmp2 = new IntExpAST(2);
    BinaryOptExpAST *val_tmp3 = new BinaryOptExpAST(BINARY_OPT_MULTI,val_tmp1, val_tmp2);
    VariableDecAST* dec1 = new VariableDecAST(TYPE_INT,val1,val_tmp3);
    thenblock->addAST(dec1);
    

    BlockAST* elseblock = new BlockAST();
    elseblock->addAST(funccall2);

    IntExpAST *intast71 = new IntExpAST(1);
    IntExpAST *intast81 = new IntExpAST(2);
    BinaryOptExpAST *bin3 = new BinaryOptExpAST(BINARY_OPT_MULTI,intast71, intast81);

    IfExpAST* ifexp = new IfExpAST(bin3, thenblock, elseblock);
//end if

//for
    IntExpAST *forinit = new IntExpAST(1);
    IntExpAST *forcond = new IntExpAST(1);
    IntExpAST *forincre = new IntExpAST(1);
    IntExpAST *forint1 = new IntExpAST(1);
    IntExpAST *forint2 = new IntExpAST(2);
    BinaryOptExpAST *forins = new BinaryOptExpAST(BINARY_OPT_MULTI, forint1, forint2);
    BlockAST* forblock = new BlockAST();
    forblock->addAST(forins);
    ForExpAST* forexp = new ForExpAST(forinit, forcond, forincre, forblock);
//end for
//while
    IntExpAST *whilecond = new IntExpAST(1);
    IntExpAST *whileint1 = new IntExpAST(1);
    IntExpAST *whileint2 = new IntExpAST(2);
    BinaryOptExpAST *whileins = new BinaryOptExpAST(BINARY_OPT_MULTI, whileint1, whileint2);
    BlockAST* whileblock = new BlockAST();
    whileblock->addAST(whileins);
    WhileExpAST* whileexp = new WhileExpAST(whilecond, whileblock);
//end while

//return
    IntExpAST *retast = new IntExpAST(99);
    ReturnExpAST * retexp = new ReturnExpAST(retast);
//end return
    IntExpAST *intast = new IntExpAST(1);
    IntExpAST *intast2 = new IntExpAST(2);
    BinaryOptExpAST *bin = new BinaryOptExpAST(BINARY_OPT_MULTI,intast, intast2);

    FunctionDecAST *func = new FunctionDecAST();
    func->setName(std::string("main"));
    func->setType(TYPE_INT);
   // func->addArg(TYPE_INT,std::string("arg1"));
    BlockAST* block2 = new BlockAST("okok");
    block2->addAST(ifexp);
    //func->addArg(TYPE_INT,std::string("arg2"));
    BlockAST *block = new BlockAST();
    block->addAST(block2);
    block->addAST(retexp);
    //block->addAST(block2);
    //block->addAST(bin);
//
    FunctionDefAST *funcdef = new FunctionDefAST(func, block);
//
    BlockAST *basic = new BlockAST();
    basic->addAST(funcdef1);
    basic->addAST(funcdef);

    Value* res = basic->codeGen(ctx);
    cout<<endl;
    ctx->theModule->print(errs(), nullptr);
    return 0;
}
