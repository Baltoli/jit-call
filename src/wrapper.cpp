#include <jitcall/Wrapper.h>

using namespace llvm;

namespace jitcall {

Wrapper::Wrapper(Function *impl) : Impl(impl) {}

Module *Wrapper::module() { return Impl->getParent(); }

DataLayout Wrapper::getDataLayout() { return DataLayout(module()); }

LLVMContext &Wrapper::context() { return Impl->getContext(); }

} // namespace jitcall
