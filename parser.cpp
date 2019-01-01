#include "context.h"
#include "AST.h"
#include "json.hpp"

using json = nlohmann::json;
using namespace std;
using namespace llvm;
extern FILE * yyin;
extern BlockAST* programBlock;
extern int yyparse();

int main(int argc,char* argv[]){

    yyin = fopen(argv[1],"r");
    yyparse();
    if (programBlock != nullptr) {
        printf("\n=====\nGraph here:\n");
        json j(programBlock->generateJson());
        std::cout << j.dump(2) << std::endl;
    }
    return 0;
}
