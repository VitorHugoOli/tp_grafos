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


    LinkedList *cpyList = copyList(grafo);


    int pre_conexo = ECCLinked(*grafo, 0);

    grafo->list = deleteNode(grafo, vertice);


    int after_conexo = ECCLinked(*grafo, 0);

    LinkedList *aux = grafo->list;
    grafo->numVertices++;
    grafo->list = cpyList;
    free(aux);


    if (pre_conexo != after_conexo) {
        printf("O vértice (%d) é uma articulação\n", vertice );
    } else {
        printf("O vértice (%d) não é uma articulação\n", vertice );
    }


}