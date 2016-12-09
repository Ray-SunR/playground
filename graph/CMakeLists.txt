cmake_minimum_required(VERSION 3.1)
project(graph CXX)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

file(GLOB SOURCE_FILES *.cpp)
message(${SOURCE_FILES})
add_executable(graph ${SOURCE_FILES})
