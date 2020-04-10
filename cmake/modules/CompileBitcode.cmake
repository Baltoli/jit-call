find_program(
  CLANG_EXECUTABLE
  clang-10
  ${LLVM_TOOLS_BINARY_DIR})

if(NOT CLANG_EXECUTABLE)
  message(FATAL_ERROR "Couldn't find Clang 10 to build bitcode")
endif()

function(compile_bitcode)
    cmake_parse_arguments(
        ARGS # prefix of output variables
        "" # list of names of the boolean arguments (only defined ones will be true)
        "INPUT;OUTPUT" # list of names of mono-valued arguments
        "" # list of names of multi-valued arguments (output variables are lists)
        ${ARGN} # arguments of the function to parse, here we take the all original ones
    )

    add_custom_command(
      OUTPUT ${ARGS_OUTPUT}
      COMMAND ${CLANG_EXECUTABLE} -emit-llvm -c ${ARGS_INPUT} -o ${ARGS_OUTPUT}
      MAIN_DEPENDENCY ${ARGS_INPUT}
    )

  string(REPLACE "/" "_" BC_TARGET_NAME ${ARGS_INPUT})
  add_custom_target(bitcode_${BC_TARGET_NAME}
      ALL DEPENDS ${ARGS_OUTPUT})
endfunction()
