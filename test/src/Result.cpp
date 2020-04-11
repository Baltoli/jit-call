#include <jitcall/Result.h>

#include <vendor/Catch.h>

#include <iostream>

using namespace jitcall;
using namespace Catch::literals;

TEST_CASE("Can interpret Result data constructed by hand") {
  auto res = Result(4);

  res.rawData()[0] = 1;
  res.rawData()[1] = 2;
  res.rawData()[2] = 3;
  res.rawData()[3] = 4;

  auto int_val = res.as<int>();
  REQUIRE(int_val);
  REQUIRE(*int_val == 0x04030201);

  auto float_val = res.as<float>();
  REQUIRE(float_val);
  REQUIRE(*float_val == 1.54e-36_a);
}
