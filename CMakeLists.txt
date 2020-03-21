cmake_minimum_required(VERSION 3.2 FATAL_ERROR)

project(JITCall CXX)

# Use AppleClang to identify the default compiler on MacOS (rather than Clang)
cmake_policy(SET CMP0025 NEW)

set(CMAKE_CXX_STANDARD 17)
