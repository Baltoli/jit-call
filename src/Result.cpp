#include <jitcall/Result.h>

namespace jitcall {

Result::Result(size_t size) : Data(size, 0) {}

size_t Result::size() const { return Data.size(); }

} // namespace jitcall
