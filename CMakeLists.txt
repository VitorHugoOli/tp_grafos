cmake_minimum_required(VERSION 3.17)
project(TP_C C)

set(CMAKE_C_STANDARD 99)

add_executable(TP_C main.c paad/paad.c grafo_scaffold/depth/depth.c utils/utils.c grafo_scaffold/tad.c cjson/cJSON.c grafo_scaffold/conexo/conexo.c grafo_scaffold/articulacao/articulacao.c)
