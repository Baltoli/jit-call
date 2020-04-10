#pragma once

#include <llvm/IR/Module.h>

#include <memory>

namespace jitcall {
namespace test {

std::unique_ptr<llvm::Module> LoadModule(std::string const &path);

} // namespace test
} // namespace jitcall
