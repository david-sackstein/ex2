cmake_minimum_required(VERSION 3.8)
project(ex2)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Enums.h Console.cpp Console.h UnicodeBuilder.cpp UnicodeBuilder.h Board.cpp Board.h)
add_executable(ex2 ${SOURCE_FILES})