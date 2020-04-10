#include <jitcall/context.h>

using namespace llvm;

namespace jitcall {

ThreadContext::ThreadContext() : Mapping{} {}

LLVMContext &ThreadContext::get() { return get(std::this_thread::get_id()); }

LLVMContext &ThreadContext::get(std::thread::id id) {
  std::lock_guard<std::mutex> l{instance().MapMutex};

  auto &m = instance().Mapping;
  if (m.find(id) == std::end(m)) {
    m[id] = std::make_unique<LLVMContext>();
  }

  return *m[id];
}

LLVMContext &ThreadContext::get(const std::thread &t) {
  return get(t.get_id());
}

ThreadContext &ThreadContext::instance() {
  static ThreadContext instance;
  return instance;
}

} // namespace jitcall
