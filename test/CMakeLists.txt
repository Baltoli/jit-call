include(CompileBitcode)

add_executable(jitcall-unit
  src/Result.cpp
  src/Wrapper.cpp
  src/LoadModule.cpp
  src/Util.cpp
  src/main.cpp)

target_include_directories(jitcall-unit
  PRIVATE include)

target_compile_definitions(jitcall-unit PRIVATE
  INPUT_DIR="${CMAKE_CURRENT_BINARY_DIR}/")

target_link_libraries(jitcall-unit
  jitcall)

function(add_test_example name)
  compile_bitcode(
    INPUT  "${CMAKE_CURRENT_SOURCE_DIR}/inputs/${name}.c"
    OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/${name}.bc")
endfunction()

add_test_example(add)
add_test_example(empty)
add_test_example(yneg)

add_test(NAME jitcall-unit
         COMMAND $<TARGET_FILE:jitcall-unit>)
