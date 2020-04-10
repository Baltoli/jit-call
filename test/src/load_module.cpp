#include "util.h"

#include <vendor/catch.h>

#include <iostream>

using namespace jitcall::test;

TEST_CASE("Can load IR files into test cases") {
  SECTION("Empty IR file") {
    auto mod = loadNamedInput("empty");
    REQUIRE(mod);
  }

  SECTION("Non-empty bitcode file") {
    auto mod = loadNamedInput("yneg");
    REQUIRE(mod);
    REQUIRE(mod->getFunction("func"));
  }
}
