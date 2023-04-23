cmake_minimum_required(VERSION 3.10)
project(HW1)

set(CMAKE_CXX_STANDARD 17)

add_executable(hw1 hw1.cpp lex.yy.c tokens.hpp)