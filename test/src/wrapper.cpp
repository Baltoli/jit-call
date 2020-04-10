#include "util.h"

#include <jitcall/wrapper.h>

#include <vendor/catch.h>

using namespace jitcall;
using namespace jitcall::test;

TEST_CASE("Can construct a wrapper for a function") {
  auto mod = loadNamedInput("add");
  REQUIRE(mod);

  auto func = mod->getFunction("add");
  REQUIRE(func);

  auto wrap = Wrapper(func);
}
