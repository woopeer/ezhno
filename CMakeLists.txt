cmake_minimum_required(VERSION 3.4.3)
project(ezhno)

find_package(LLVM REQUIRED CONFIG
  PATHS "/home/woop/workSpace/ego/build/llvm/lib/cmake/llvm" NO_DEFAULT_PATH)
message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")

add_definitions(${LLVM_DEFINITIONS})

find_package(Clang REQUIRED CONFIG
  PATHS "/home/woop/workSpace/ego/build/llvm/lib/cmake/clang" NO_DEFAULT_PATH)
message(STATUS "Found Clang ${CLANG_CMAKE_DIR}")

include_directories(BEFORE ${LLVM_INCLUDE_DIRS})
include_directories(BEFORE ${CLANG_INCLUDE_DIRS})
include_directories(BEFORE include)

SET(CMAKE_C_COMPILER /home/woop/workSpace/ego/build/llvm/bin/clang)
SET(CMAKE_CXX_COMPILER /home/woop/workSpace/ego/build/llvm/bin/clang++)
SET(CMAKE_CXX_FLAGS -std=c++17 ${CMAKE_CXX_FLAGS})

set(EXECUTABLE_OUTPUT_PATH "${CMAKE_CURRENT_BINARY_DIR}/bin")
set(LIBRARY_OUTPUT_PATH "${CMAKE_CURRENT_BINARY_DIR}/lib")
link_directories("${CMAKE_CURRENT_BINARY_DIR}/lib")

add_subdirectory(lib)
add_subdirectory(tools)
