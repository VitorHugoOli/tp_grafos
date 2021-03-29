//
// Created by vitor on 3/28/21.
//

#include "articulation.h"


int articulationLinked(GrafoLinked *grafo) {
    int vertice;

    printf("\nEntre com o vertice que deseja verificar: ");
    vertice = get_int();
    if (vertice <= 0 || vertice > grafo->numVertices) {
        printf("\n\tNumero de vertice invalido!\n\n");
        return 0;
    }

    LinkedList *cpyList = copyList(grafo);

    int pre_conexo = ECCLinked(*grafo, 0);

    grafo->list = deleteVertice(grafo, vertice);

    int after_conexo = ECCLinked(*grafo, 0);

//    LinkedList *aux = grafo->list;
//    grafo->list = cpyList;
//    free(aux);

    if (pre_conexo != after_conexo) {
        printf("O vértice (%d) é uma articulação\n", vertice);
    } else {
        printf("O vértice (%d) não é uma articulação\n", vertice);
    }


}