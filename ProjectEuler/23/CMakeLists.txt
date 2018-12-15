cmake_minimum_required(VERSION 3.6)
project(23)

set(CMAKE_VERBOSE_MAKEFILE ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -fopenmp")

set(SOURCE_FILES main.cpp)
add_executable(23 ${SOURCE_FILES})
