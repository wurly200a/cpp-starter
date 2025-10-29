cmake_minimum_required(VERSION 3.16)

project(cpp-starter
  VERSION 0.1.0
  DESCRIPTION "Minimal C++ starter on Linux"
  LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release CACHE STRING "Build type" FORCE)
endif()

if(CMAKE_CXX_COMPILER_ID MATCHES "Clang|GNU")
  add_compile_options(-Wall -Wextra -Wpedantic -Wconversion -Wshadow -Wformat=2)
endif()

option(ENABLE_ASAN "Enable AddressSanitizer (for Debug)" OFF)
if(ENABLE_ASAN AND CMAKE_CXX_COMPILER_ID MATCHES "Clang|GNU")
  add_link_options(-fsanitize=address)
  add_compile_options(-fsanitize=address -fno-omit-frame-pointer)
endif()

add_executable(cpp-starter src/main.cpp)

include(GNUInstallDirs)
install(TARGETS cpp-starter RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
