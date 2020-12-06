cmake_minimum_required(VERSION 3.17)
project(libOfBMP C)

set(CMAKE_C_STANDARD 99)

add_library(bmp bmpDrawing.h bmpDrawing.c)

add_executable(libOfBMP main.c)

target_link_libraries(libOfBMP bmp)