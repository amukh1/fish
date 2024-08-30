#include <string>
#include <vector>
#include <map>

#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/Verifier.h>
#include <llvm/IR/Instructions.h>
#include <llvm/Support/raw_ostream.h>

int main() {
    llvm::raw_ostream &output = llvm::outs();
    llvm::outs() << "fish\n";

    llvm::LLVMContext ctx;
    std::unique_ptr<llvm::Module> module = std::make_unique<llvm::Module>("fish", ctx);
    llvm::IRBuilder<> builder(ctx);

    llvm::FunctionType *funcType = llvm::FunctionType::get(llvm::Type::getVoidTy(ctx), false);
    llvm::Function *mainFunc = llvm::Function::Create(funcType, llvm::Function::ExternalLinkage, "main", module.get());
    llvm::BasicBlock *entry = llvm::BasicBlock::Create(ctx, "entry", mainFunc);
    builder.SetInsertPoint(entry);
    // return
    builder.CreateRetVoid();

    // define fileOutput
    std::error_code errorInfo;
    llvm::raw_fd_ostream fileOutput("out.ll", errorInfo);
    if (errorInfo) {
        llvm::errs() << "Error: " << errorInfo.message() << "\n";
        return 1;
    }

    // put IR in out.ll
    module->print(fileOutput, nullptr);

    return 0;

}