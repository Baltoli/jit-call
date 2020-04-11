#include <jitcall/Wrapper.h>

using namespace llvm;

namespace jitcall {

Wrapper::Wrapper(Function *impl) : Impl(impl) {}

Module *Wrapper::module() const { return Impl->getParent(); }

DataLayout Wrapper::getDataLayout() const { return DataLayout(module()); }

LLVMContext &Wrapper::context() const { return Impl->getContext(); }

TypeSize Wrapper::getTypeSize(llvm::Type *ty) const {
  return getDataLayout().getTypeStoreSize(ty);
}

} // namespace jitcall
