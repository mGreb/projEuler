# cmake_minimum_required(VERSION <specify CMake version here>)
project(15)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")

set(SOURCE_FILES 15.cpp)
add_executable(15 ${SOURCE_FILES})