#include "context.h"
#include "AST.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/ADT/StringRef.h"

using namespace std;
using namespace llvm;
extern FILE * yyin;
extern BlockAST* programBlock;
extern int yyparse();

int main(int argc,char* argv[]){
    Context *ctx = new Context();


    yyin = fopen(argv[1],"r");
    yyparse();
    printf("\n=====\nParse Finished\n=====\n");
    // printf("program block: %d", programBlock);
    Value* res = programBlock->codeGen(ctx);
    cout<<endl;
    ctx->theModule->print(errs(), nullptr);
    return 0;
}
