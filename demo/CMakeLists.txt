cmake_minimum_required(VERSION 3.15)

# set the project name
project(Demo VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

# Use the project root to find includes
include_directories(${PROJECT_SOURCE_DIR})


# add the executable
add_executable(Demo generic.cpp)