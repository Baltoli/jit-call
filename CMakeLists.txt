cmake_minimum_required(VERSION 3.2 FATAL_ERROR)

project(JITCall CXX)

# Use AppleClang to identify the default compiler on MacOS (rather than Clang)
cmake_policy(SET CMP0025 NEW)

set(CMAKE_CXX_STANDARD 17)

if(JITCALL_TEST)
  enable_testing()

  add_executable(jitcall-unit
    test/main.cpp)

  add_test(NAME jitcall-unit
           COMMAND $<TARGET_FILE:jitcall-unit>)
endif()
