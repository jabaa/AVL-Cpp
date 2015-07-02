cmake_minimum_required(VERSION 3.2)
project(AVL)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(AVL ${SOURCE_FILES} AVL.cpp AVL.h)