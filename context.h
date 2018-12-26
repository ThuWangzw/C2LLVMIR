#ifndef C2LLVMIR_CONTEXT_H
#define C2LLVMIR_CONTEXT_H
#include <llvm/IR/Value.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/Module.h>
#include <llvm/Support/raw_ostream.h>
#include <memory>
class Context{
public:
    llvm::LLVMContext llvmContext;
    llvm::IRBuilder<> builder;
    std::unique_ptr<llvm::Module> theModule;
    Context():builder(llvmContext){
        this->theModule = llvm::make_unique<llvm::Module>("c model", this->llvmContext);
    }
    ~Context(){}
};
#endif //C2LLVMIR_CONTEXT_H
