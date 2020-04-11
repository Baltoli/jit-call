#pragma once

#include <jitcall/Result.h>

#include <llvm/IR/Function.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Module.h>

namespace jitcall {

class Wrapper {
public:
  Wrapper(llvm::Function *func);

  template <typename... Ts>
  Result operator()(Ts...);

private:
  llvm::Module *module();
  llvm::LLVMContext &context();

  llvm::Function *Impl;
};

template <typename... Ts>
Result Wrapper::operator()(Ts... args) {
  return Result(0);
}

} // namespace jitcall
