cmake_minimum_required(VERSION 3.17)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(CppTest VERSION 1.0)

find_package(spdlog REQUIRED)
add_compile_definitions(SPDLOG_FMT_EXTERNAL)

# Use the project root to find includes
include_directories(${PROJECT_SOURCE_DIR})

add_executable(CppTest thread_test.cc)

target_link_libraries(CppTest PRIVATE spdlog::spdlog)

# target_compile_options(CppTest PRIVATE -fno-exceptions)