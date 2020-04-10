#pragma once

#include <cstdint>

namespace jitcall {

template <typename T>
T makeFromBytes(uint8_t const *bytes) {
  auto ret = T{};
  return ret;
}

} // namespace jitcall
