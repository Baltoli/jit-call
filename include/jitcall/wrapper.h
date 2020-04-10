#pragma once

#include <jitcall/Result.h>

#include <llvm/IR/Function.h>

namespace jitcall {

class Wrapper {
public:
  Wrapper(llvm::Function *func);

  template <typename... Ts>
  Result operator()(Ts...);

private:
  llvm::Function *Impl;
};

template <typename... Ts>
Result Wrapper::operator()(Ts... args) {
  return Result(0);
}

} // namespace jitcall
