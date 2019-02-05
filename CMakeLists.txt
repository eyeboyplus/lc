cmake_minimum_required(VERSION 3.10)
project(lc)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(array)
add_subdirectory(greedy)

add_executable(lc main.cpp)