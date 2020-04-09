cmake_minimum_required(VERSION 3.2 FATAL_ERROR)

project(JITCall CXX)

# Use AppleClang to identify the default compiler on MacOS (rather than Clang)
cmake_policy(SET CMP0025 NEW)

set(CMAKE_CXX_STANDARD 17)

find_package(LLVM 10 REQUIRED CONFIG)
add_definitions(${LLVM_DEFINITIONS})

llvm_map_components_to_libnames(llvm_libs
  passes mcjit executionengine option irreader
  asmparser x86asmparser x86codegen asmprinter
  codegen target transformutils
  bitwriter x86desc bitreader
  core x86utils x86info support)

add_library(jitcall
  src/wrapper.cpp)

target_include_directories(jitcall
  SYSTEM PUBLIC ${LLVM_INCLUDE_DIRS})

target_link_libraries(jitcall
  ${llvm_libs})

include(GNUInstallDirs)

target_include_directories(jitcall PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
    PRIVATE src)

install(TARGETS jitcall EXPORT JITCallConfig
    ARCHIVE  DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY  DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME  DESTINATION ${CMAKE_INSTALL_BINDIR})  # This is for Windows
install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

install(EXPORT JITCallConfig DESTINATION share/JITCall/cmake)

if(JITCALL_TEST)
  enable_testing()

  add_executable(jitcall-unit
    test/load_module.cpp
    test/util.cpp
    test/main.cpp)

  target_compile_definitions(jitcall-unit PRIVATE
    INPUT_DIR="${CMAKE_CURRENT_SOURCE_DIR}/test/inputs")

  target_link_libraries(jitcall-unit
    jitcall)

  add_test(NAME jitcall-unit
           COMMAND $<TARGET_FILE:jitcall-unit>)
endif()
