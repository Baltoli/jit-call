#pragma once

#include <llvm/IR/LLVMContext.h>

#include <memory>
#include <mutex>
#include <thread>
#include <unordered_map>

namespace jitcall {

class ThreadContext {
public:
  ThreadContext(const ThreadContext &) = delete;
  void operator=(const ThreadContext &) = delete;

  static llvm::LLVMContext &get();
  static llvm::LLVMContext &get(std::thread::id id);
  static llvm::LLVMContext &get(const std::thread &t);

private:
  ThreadContext();

  static ThreadContext &instance();

  std::unordered_map<std::thread::id, std::unique_ptr<llvm::LLVMContext>>
      Mapping;
  std::mutex MapMutex;
};

} // namespace jitcall
