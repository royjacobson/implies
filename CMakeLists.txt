cmake_minimum_required(VERSION 3.14)
project(my_project)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)

add_library(implies INTERFACE) 
target_include_directories(implies INTERFACE include/) 

enable_testing()
add_subdirectory(tests)
