#include "util.h"

#include "vendor/catch.hpp"

#include <iostream>

using namespace jitcall::test;

TEST_CASE("Can load IR files into test cases") {
  auto mod = loadModule(INPUT_DIR "/empty.ll");
  REQUIRE(mod);
}
