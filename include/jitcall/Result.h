#pragma once

#include <jitcall/Bits.h>

#include <llvm/ADT/None.h>
#include <llvm/ADT/Optional.h>

#include <vector>

namespace jitcall {

class Result {
public:
  explicit Result(size_t size);

  template <typename T>
  llvm::Optional<T> as() const;

  size_t size() const;

  std::vector<uint8_t> const &data() const;
  uint8_t *rawData();

private:
  std::vector<uint8_t> Data;
};

template <typename T>
llvm::Optional<T> Result::as() const {
  if (size() == sizeof(T)) {
    return makeFromBytes<T>(Data.data());
  } else {
    return llvm::None;
  }
}

} // namespace jitcall
