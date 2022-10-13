cmake_minimum_required(VERSION 3.22)
project(os)

set(CMAKE_CXX_STANDARD 20)

add_executable(
        os
        main.cpp
        utils.h
        utils.cpp
        CMiles.h
        CMiles.cpp
        CMura.h
        CMura.cpp
)
