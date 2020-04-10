#pragma once

#include <llvm/ADT/APInt.h>
#include <llvm/ADT/None.h>

#include <vector>

namespace jitcall {

class Result {
public:
  explicit Result(size_t size);

  template <typename T> llvm::Optional<T> as() const;

  size_t size() const;

private:
  std::vector<uint8_t> Data;
};

template <typename T> llvm::Optional<T> Result::as() const {
  if (size() == sizeof(T)) {
    return T{};
  } else {
    return llvm::None;
  }
}

} // namespace jitcall
