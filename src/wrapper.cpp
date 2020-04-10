#include <jitcall/Wrapper.h>

using namespace llvm;

namespace jitcall {

Wrapper::Wrapper(Function *impl) : Impl(impl) {}

} // namespace jitcall
