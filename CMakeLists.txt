cmake_minimum_required(VERSION 3.21)
project(CppLearn)
project(ch02_initializer_list_learn)
project(ch02_tuple_learn)
project(ch02_return_with_auto)

set(CMAKE_CXX_STANDARD 14)

add_executable(CppLearn main.cpp)
add_executable(ch02_initializer_list_learn chapter02/initializer_list_learn.cpp)
add_executable(ch02_tuple_learn chapter02/tuple_learn.cpp)
add_executable(ch02_return_with_auto chapter02/return_with_auto.cpp)
