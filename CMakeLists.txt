cmake_minimum_required(VERSION 3.17)
project(TP_C C)

set(CMAKE_C_STANDARD 99)

add_executable(TP_C main.c tad.c tad.h files/readFiles.c files/readFiles.h utils/utils.h)
