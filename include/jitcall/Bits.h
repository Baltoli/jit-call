#pragma once

#include <cstdint>
#include <cstring>

namespace jitcall {

template <typename T>
T makeFromBytes(uint8_t const *bytes) {
  auto ret = T{};
  std::memcpy(&ret, bytes, sizeof(T));
  return ret;
}

} // namespace jitcall
