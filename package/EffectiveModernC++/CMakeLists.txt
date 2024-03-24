cmake_minimum_required(VERSION 3.17)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(CppTest VERSION 1.0)

# Use the project root to find includes
include_directories(${PROJECT_SOURCE_DIR})

add_executable(CppTest promise.cc)
