cmake_minimum_required(VERSION 3.27)
project(BigInt36)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(BigInt36
        big_int_general.h
        main.cpp
        tests.h)
