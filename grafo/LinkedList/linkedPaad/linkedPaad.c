//
// Created by vitor on 3/27/21.
//

#include "linkedPaad.h"

int linkedToPaad(GrafoLinked *grafo, Paad *paad) {
    paad->nodeLen = grafo->numVertices;
    paad->edgesLen = grafo->numArestas;
    paad->nodes = (int *) malloc(paad->nodeLen * sizeof(int));
    paad->edges = (Edge *) malloc(paad->edgesLen * sizeof(Edge));


    int count = 0;
    for (int i = 0; i < paad->nodeLen; ++i) {
        LinkedList *node = &grafo->list[i];
        while (node != NULL) {
            if (node->vertice > i) {
                paad->edges[count].to = i;
                paad->edges[count].from = node->vertice - 1;
                paad->edges[count].weight = node->peso;
                count++;
            }
            node = node->next;
        }
    }

    return 1;
}


int PaadToLinked(GrafoLinked *grafo, Paad *paad, int isInitGraph) {
    int to, from;

    if (grafo->list != NULL && isInitGraph) {
        free(grafo->list);
    }


    grafo->numVertices = paad->nodeLen;
    grafo->numArestas = paad->edgesLen;


    grafo->list = createLinkedList(grafo->numVertices);

    grafo->numArestas = 0;
    for (int i = 0; i < paad->edgesLen; ++i) {
        to = searchIndex(paad->edges[i].to, paad);
        from = searchIndex(paad->edges[i].from, paad);
        addAresta(&grafo->list[to], from + 1, paad->edges[i].weight);
        addAresta(&grafo->list[from], to + 1, paad->edges[i].weight);
        grafo->numArestas++;
    }
    printf("Parse Paad json para Linked com sucesso! \\o/\n");
    fflush(stdin);
    fflush(stdout);
    return 1;


}