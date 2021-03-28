cmake_minimum_required(VERSION 3.17)
project(TP_C C)

set(CMAKE_C_STANDARD 99)

add_executable(TP_C main.c grafo/matriz/matrizPaad/matrizPaad.c grafo/matriz/depth/depth.c utils/utils.c cjson/cJSON.c grafo/matriz/conexo/conexo.c grafo/matriz/articulacao/articulacao.c grafo/LinkedList/linkedlist/linkedlist.c menus/matriz/matriz.c grafo/matriz/grafoMatriz.c menus/linkedList/linkedlistmenu.c paad/paad.c grafo/LinkedList/grafoLinkedList.c grafo/LinkedList/linkedPaad/linkedPaad.c grafo/LinkedList/linkedPaad/linkedPaad.h)
