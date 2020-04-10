#pragma once

#include <jitcall/Result.h>

#include <llvm/IR/Function.h>

namespace jitcall {

class Wrapper {
public:
  Wrapper(llvm::Function *func);

private:
  llvm::Function *Impl;
};

} // namespace jitcall
