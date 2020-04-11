#pragma once

#include <jitcall/Result.h>

#include <llvm/IR/DataLayout.h>
#include <llvm/IR/Function.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Module.h>
#include <llvm/Support/TypeSize.h>

namespace jitcall {

class Wrapper {
public:
  Wrapper(llvm::Function *func);

  template <typename... Ts>
  Result operator()(Ts...);

private:
  llvm::Module *module() const;
  llvm::DataLayout getDataLayout() const;
  llvm::LLVMContext &context() const;

  llvm::TypeSize getTypeSize(llvm::Type *) const;

  llvm::Function *Impl;
};

template <typename... Ts>
Result Wrapper::operator()(Ts... args) {
  return Result(0);
}

} // namespace jitcall
