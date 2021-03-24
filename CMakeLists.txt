cmake_minimum_required(VERSION 3.17)
project(TP_C C)

set(CMAKE_C_STANDARD 99)

add_executable(TP_C main.c grafo/matriz/paad/paad.c grafo/matriz/depth/depth.c utils/utils.c cjson/cJSON.c grafo/matriz/conexo/conexo.c grafo/matriz/articulacao/articulacao.c grafo/LinkedList/linkedlist/linkedlist.h grafo/LinkedList/linkedlist/linkedlist.c menus/matriz/matriz.c menus/matriz/matriz.h grafo/matriz/grafoMatriz.c grafo/matriz/grafoMatriz.h grafo/LinkedList/grafoLinkedList.c grafo/LinkedList/grafoLinkedList.h menus/linkedList/linkedlistmenu.c menus/linkedList/linkedlistmenu.h)
