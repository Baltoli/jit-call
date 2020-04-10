#include <jitcall/Result.h>

namespace jitcall {

Result::Result(size_t size) : Data(size, 0) {}

size_t Result::size() const { return Data.size(); }

std::vector<uint8_t> const &Result::data() const { return Data; }

uint8_t *Result::rawData() { return Data.data(); }

} // namespace jitcall
