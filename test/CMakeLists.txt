enable_testing()

include(CompileBitcode)

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

function(add_test_example name)
  compile_bitcode(
    INPUT  "${CMAKE_CURRENT_SOURCE_DIR}/inputs/${name}.c"
    OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/${name}.bc")
endfunction()

add_test_example(basic)

add_test(NAME jitcall-unit
         COMMAND $<TARGET_FILE:jitcall-unit>)
