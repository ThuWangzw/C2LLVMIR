#include "context.h"
#include "AST.h"
#include "json.hpp"
#include <fstream>

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
        json j(programBlock->generateJson());
        printf("\nParse Complete! See the result in output.json.\n");
        ofstream outfile("output.json");
        outfile << j.dump(2) << std::endl;
    }
    return 0;
}
