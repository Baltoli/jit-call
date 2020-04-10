#include "util.h"

#include <jitcall/context.h>

#include <llvm/IRReader/IRReader.h>
#include <llvm/Support/MemoryBuffer.h>
#include <llvm/Support/SourceMgr.h>

using namespace llvm;

namespace jitcall {
namespace test {

std::unique_ptr<Module> loadModule(std::string const &path) {
  auto &ctx = ThreadContext::get();
  auto err = SMDiagnostic{};

  return parseIRFile(path, err, ctx);
}

std::unique_ptr<Module> loadNamedInput(std::string const &name) {
  return loadModule(INPUT_DIR + name + ".bc");
}

} // namespace test
} // namespace jitcall
