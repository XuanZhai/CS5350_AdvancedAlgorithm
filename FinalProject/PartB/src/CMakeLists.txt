cmake_minimum_required(VERSION 3.21)
project(src)

set(CMAKE_CXX_STANDARD 17)

add_executable(src main.cpp DLLNode.cpp DLLNode.h DLList.cpp DLList.h)
