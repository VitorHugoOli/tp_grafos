//
// Created by vitor on 3/20/21.
//
#include "conexo.h"

//COMPONENTE CONEXA

void printEcc(int numGrupoConexo, int *groupConexoVertice, int numVertices) {
    printf("\n\tO numero de componentes conexas é %d\n", numGrupoConexo);
    int i, j;
    for (j = 0; j < numGrupoConexo; j++) {
        printf("\n\tVertices do componente conexo: %d ->  ", j + 1);
        for (i = 0; i < numVertices; i++)
            if (groupConexoVertice[i] == j)
                printf("%d ", i + 1);
        printf("\n");
    }
    printf("\n");

}

int ECCLinked(GrafoLinked grafo, int show_result) {
    int *groupConexoVertice = (int *) malloc(grafo.numVertices * sizeof(int));
    int numGrupoConexo = 0;

    for (int i = 0; i < grafo.numVertices; i++)
        groupConexoVertice[i] = -1;


    for (int vertice = 0; vertice < grafo.numVertices; vertice++)
        if (groupConexoVertice[vertice] == -1)
            PCCLinked(grafo, vertice, numGrupoConexo++, groupConexoVertice);

    if (show_result) {
        printEcc(numGrupoConexo, groupConexoVertice, grafo.numVertices);
        printf("\n");
    }
    free(groupConexoVertice);

    return numGrupoConexo;
}

void PCCLinked(GrafoLinked G, int verticeAnalise, int numGrupoConexo, int *groupConexoVertice) {
    if (groupConexoVertice[verticeAnalise] != -1) return;
    groupConexoVertice[verticeAnalise] = numGrupoConexo;
    LinkedList *node = &G.list[verticeAnalise];
    while (node != NULL) {
        PCCLinked(G, (node->vertice - 1), numGrupoConexo, groupConexoVertice);
        node = node->next;
    }
}