cmake_minimum_required(VERSION 3.17)
project(TP_C C)

set(CMAKE_C_STANDARD 99)

add_executable(TP_C main.c paad/paad.c depth/depth.c utils/utils.c tad.c cjson/cJSON.c conexo/conexo.c conexo/conexo.h)
