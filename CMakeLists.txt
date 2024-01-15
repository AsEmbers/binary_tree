cmake_minimum_required(VERSION 3.19)
project(binary_tree)

set(CMAKE_CXX_STANDARD 14)

add_executable(binary_tree main.cpp binary_tree.h binary_tree.cpp linked_queue.h linked_queue.cpp)