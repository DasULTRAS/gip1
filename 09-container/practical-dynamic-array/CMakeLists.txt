cmake_minimum_required(VERSION 3.21)
project(practical_dynamic_array C)

set(CMAKE_C_STANDARD 11)

add_executable(main
        dynamic_array/dynamic_array.c
        dynamic_array/dynamic_array.h
        main.c)