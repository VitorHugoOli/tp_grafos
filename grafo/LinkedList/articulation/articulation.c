//
// Created by vitor on 3/28/21.
//

#include "articulation.h"

void testePrint(LinkedList *list, int num) {
    LinkedList *aux;
    for (int i = 0; i < num; ++i) {
        printf("%d | ", i + 1);
        aux = &list[i];
        while (aux != NULL) {
            printf("%d ", aux->vertice);
            aux = aux->next;
        }
        printf("\n");
    }

    printf("--\n");
}

int articulationLinked(GrafoLinked *grafo) {
    int vertice;

    printf("\nEntre com o vertice que deseja verificar: ");
    vertice = get_int();
    if (vertice <= 0 || vertice > grafo->numVertices) {
        printf("\n\tNumero de vertice invalido!\n\n");
        return 0;
    }
    vertice--; //Transformando o valor do vertice para o da lista

    printf("Init\n");
    testePrint(grafo->list, grafo->numVertices);

    LinkedList *cpyList = copyList(grafo);


    printf("Copy\n");
    testePrint(cpyList, grafo->numVertices);

    int pre_conexo = ECCLinked(*grafo, 0);

    grafo->list = deleteVertice(grafo, vertice);

    printf("Delete\n");
    testePrint(grafo->list, grafo->numVertices);

    int after_conexo = ECCLinked(*grafo, 0);

    LinkedList *aux = grafo->list;
    grafo->numVertices++;
    grafo->list = cpyList;
    free(aux);


    printf("Back copy\n");
    testePrint(grafo->list, grafo->numVertices);

    if (pre_conexo != after_conexo) {
        printf("O vértice (%d) é uma articulação\n", vertice + 1);
    } else {
        printf("O vértice (%d) não é uma articulação\n", vertice + 1);
    }


}