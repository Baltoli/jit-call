#include "Util.h"

#include <jitcall/Wrapper.h>

#include <vendor/Catch.h>

#include <iostream>

#include <llvm/Support/raw_ostream.h>

using namespace jitcall;
using namespace jitcall::test;

TEST_CASE("Can construct a wrapper") {
  auto mod = loadNamedInput("add");
  REQUIRE(mod);

  auto func = mod->getFunction("add");
  REQUIRE(func);

  auto wrap = Wrapper(func);
}

TEST_CASE("Can call a simple function", "[!shouldfail]") {
  auto mod = loadNamedInput("add");
  REQUIRE(mod);

  auto func = mod->getFunction("add");
  REQUIRE(func);

  auto wrap = Wrapper(func);

  auto ret = wrap(4, 5).as<int32_t>();
  REQUIRE(ret);
  REQUIRE(*ret == 9);
}

TEST_CASE("Can call a long function", "[!shouldfail]") {
  auto mod = loadNamedInput("longadd");
  REQUIRE(mod);

  auto func = mod->getFunction("add");
  REQUIRE(func);

  auto wrap = Wrapper(func);

  auto iret = wrap(4L).as<int32_t>();
  REQUIRE(!iret);

  auto ret = wrap(5L).as<int64_t>();
  REQUIRE(ret);
  REQUIRE(*ret == 7L);
}
