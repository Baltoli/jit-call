#include "util.h"

#include <vendor/catch.h>

#include <iostream>

#define INPUT(fn) INPUT_DIR #fn ".bc"

using namespace jitcall::test;

TEST_CASE("Can load IR files into test cases") {
  SECTION("Empty IR file") {
    auto mod = loadModule(INPUT(empty));
    REQUIRE(mod);
  }

  SECTION("Non-empty bitcode file") {
    auto mod = loadModule(INPUT(yneg));
    REQUIRE(mod);
    REQUIRE(mod->getFunction("func"));
  }
}
