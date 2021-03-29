//
// Created by vitor on 3/28/21.
//

#include "bridge.h"

int bridgeLinked(GrafoLinked grafo) {
    printf("\nEntre com 1º vertice que deseja: ");
    int v_one = get_int();
    if (v_one <= 0 || v_one > grafo.numVertices) {
        printf("\n\tNumero de vertice invalido!\n\n");
        return 0;
    }

    printf("Entre com 2º vertice que deseja: ");
    int v_two = get_int();
    if (v_two <= 0 || v_two > grafo.numVertices) {
        printf("\n\tNumero de vertice invalido!\n\n");
        return 0;
    }

    if (!isAresta(&grafo.list[v_one - 1], v_two)) {
        printf("Os vertices (%d)-(%d) não formam uma aresta\n", v_one, v_two);
        return 0;
    }

    int pre_conexo = ECCLinked(grafo, 0);

    LinkedList ori[2] = {grafo.list[v_one - 1], grafo.list[v_two - 1]};

    grafo.list[v_one - 1] = copyLinkedList(&grafo.list[v_one - 1]);
    grafo.list[v_two - 1] = copyLinkedList(&grafo.list[v_two - 1]);

    deleteAresta(&grafo.list[v_one - 1], v_two);
    deleteAresta(&grafo.list[v_two - 1], v_one);

    int after_conexo = ECCLinked(grafo, 0);

    grafo.list[v_one - 1] = ori[0];
    grafo.list[v_two - 1] = ori[1];

    if (pre_conexo != after_conexo) {
        printf("A aresta (%d)-(%d) é uma ponte\n", v_one, v_two);
    } else {
        printf("A aresta (%d)-(%d) não é uma ponte\n", v_one, v_two);
    }

}