#include "Util.h"

#include <jitcall/Wrapper.h>

#include <vendor/Catch.h>

using namespace jitcall;
using namespace jitcall::test;

namespace {

Wrapper addWrapper() {
  auto mod = loadNamedInput("add");
  REQUIRE(mod);

  auto func = mod->getFunction("add");
  REQUIRE(func);

  return Wrapper(func);
}

} // namespace

TEST_CASE("Can construct a wrapper") { auto wrap = addWrapper(); }

TEST_CASE("Can call a simple function", "[!shouldfail]") {
  auto wrap = addWrapper();
  auto ret = wrap(4, 5).as<int>();

  REQUIRE(ret);
  REQUIRE(*ret == 9);
}
