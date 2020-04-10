enable_testing()

find_program(
  CLANG_EXECUTABLE
  clang-10
  ${LLVM_TOOLS_BINARY_DIR})

if(NOT CLANG_EXECUTABLE)
  message(FATAL_ERROR "Couldn't find Clang 10 to build test inputs")
endif()

add_executable(jitcall-unit
  src/load_module.cpp
  src/util.cpp
  src/main.cpp)

target_include_directories(jitcall-unit
  PRIVATE include)

target_compile_definitions(jitcall-unit PRIVATE
  INPUT_DIR="${CMAKE_CURRENT_SOURCE_DIR}/test/inputs/")

target_link_libraries(jitcall-unit
  jitcall)

add_test(NAME jitcall-unit
         COMMAND $<TARGET_FILE:jitcall-unit>)
