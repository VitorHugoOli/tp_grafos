cmake_minimum_required(VERSION 3.17)
project(TP_C C)

set(CMAKE_C_STANDARD 99)

add_executable(TP_C main.c
        src/matriz/algorithms/matrizPaad/matrizPaad.c
        src/matriz/algorithms/depth/depth.c src/modules/utils/utils.c
        src/matriz/algorithms/conexo/conexo.c
        src/matriz/algorithms/articulacao/articulacao.c
        src/modules/linkedlist/linkedlist.c
        src/matriz/menus/matriz/matriz.c src/matriz/matriz/grafoMatriz.c
        src/menu/menu.c
        src/modules/paad/paad.c
        src/tads/LinkedGrafo/linkedGrafo.c
        src/algorithms/linkedPaad/linkedPaad.c
        src/algorithms/depth/depthLikedList.c
        src/algorithms/conexo/conexo.c
        src/algorithms/bridge/bridge.c
        src/algorithms/articulation/articulation.c
        src/algorithms/neighborhood/neighborhood.c
        src/algorithms/kOpt/kopt.c
        src/algorithms/TCPLIB/tcplib.c
        src/modules/cjson/cJson.o src/algorithms/cheaperInsertion/cheaperInsertion.c
        src/tads/HamiltonianPath/hamiltonianPath.c
        src/algorithms/cheaperInsertion/ListNodes/ListNodes.c
        src/modules/analytics/analytics.c src/modules/analytics/hashtable/hash.c src/modules/analytics/hashtable/hash.h)


target_link_libraries(TP_C m)
target_link_libraries(TP_C pthread)
