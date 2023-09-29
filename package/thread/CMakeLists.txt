cmake_minimum_required(VERSION 3.17)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(Test VERSION 1.0)

# find_package(spdlog REQUIRED)
# add_compile_definitions(SPDLOG_FMT_EXTERNAL)

# Use the project root to find includes
include_directories(${PROJECT_SOURCE_DIR})

add_executable(Test mutex.cc)

# target_link_libraries(Advanced PRIVATE spdlog::spdlog)