find_program(
  CLANG_EXECUTABLE
  clang-10
  ${LLVM_TOOLS_BINARY_DIR})

if(NOT CLANG_EXECUTABLE)
  message(FATAL_ERROR "Couldn't find Clang 10 to build bitcode")
endif()
