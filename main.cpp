#include "context.h"
#include "AST.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/ADT/StringRef.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

using namespace std;
using namespace llvm;
extern FILE * yyin;
extern BlockAST* programBlock;
extern int yyparse();

int main(int argc,char* argv[]){
    Context *ctx = new Context();
    int fd = open("output.ll",O_WRONLY || O_CREAT);
    if(fd<0)cout<<"errorfile";
    raw_fd_ostream ofs(fd, false);
    yyin = fopen(argv[1],"r");
    yyparse();
    printf("\n=====\nParse Finished\n=====\n");
    // printf("program block: %d", programBlock);
    Value* res = programBlock->codeGen(ctx);
    cout<<endl;
    ctx->theModule->print(ofs, nullptr);
    return 0;
}
