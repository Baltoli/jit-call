#include <jitcall/Wrapper.h>

using namespace llvm;

namespace jitcall {

Wrapper::Wrapper(Function *impl) : Impl(impl) {
}

Module *Wrapper::module() const {
  return Impl->getParent();
}

DataLayout Wrapper::getDataLayout() const {
  return DataLayout(module());
}

LLVMContext &Wrapper::context() const {
  return Impl->getContext();
}

TypeSize Wrapper::getTypeSize(llvm::Type *ty) const {
  // TODO: handle other types that LLVM doesn't want to size but we need to for
  // regularity (e.g. void).
  return getDataLayout().getTypeStoreSize(ty);
}

} // namespace jitcall
