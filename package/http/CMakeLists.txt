cmake_minimum_required(VERSION 3.15)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

project(Http VERSION 1.0)

find_package(Boost REQUIRED COMPONENTS filesystem iostreams program_options regex system)

find_package(Drogon CONFIG REQUIRED)


add_executable(Http server.cc TestCtrl.cc)

target_link_libraries(Http PRIVATE Drogon::Drogon)
