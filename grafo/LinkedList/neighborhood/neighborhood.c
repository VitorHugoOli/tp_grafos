//
// Created by vitor on 4/13/21.
//

//1 Inicializar a rota com um vértice aleatório (número 1)
//2 Encontrar o vértice K fora da rota cuja aresta possua o menor custo
//3 Adicionar o vértice K no final da lista de vértices visitados
//4 Se todos os vértices foram adicionados parar, senão volta ao passo 2


#include "neighborhood.h"

void printResultes(const GrafoLinked *grafo, const int *path, float tempo) {
    printf("\nCaminho pecorrido\n\n");
    printf("Tempo Gasto = %lf\n",tempo);
    for (int i = 0; i < grafo->numVertices; ++i) {
        printf("(%d)", path[i] + 1);
        if (i < (grafo->numVertices - 1)){
            printf(" -> ");
        }
    }
    printf("\n");
}

void nearestNeighbor(GrafoLinked *grafo) {
    int *path = (int *)calloc(grafo->numVertices, sizeof(int)) ;

    for (int i = 0; i < grafo->numVertices; ++i) {
        path[i] = -1;
    }


    clock_t t;
    t = clock();

    vizinhosR(0, path, grafo, 0);

    double time_taken = ((double)t)/CLOCKS_PER_SEC;

    printResultes(grafo, path, time_taken);

    return;
}


int valueinarray(int val, int *arr, int len) {

    for (int i = 0; i < len; i++) {
        if (arr[i] == val)
            return 1;
    }
    return 0;
}

int findNearestNeighbor(LinkedList *list, int *path, int len) {
    int nearestNode = -1;
    float light;

    LinkedList *node = list;

    while (node != NULL) {
        if ((nearestNode == -1 || node->peso < light) && !valueinarray(node->vertice - 1, path, len)) {
            nearestNode = node->vertice;
            light = node->peso;
        }
        node = node->next;
    }

    return nearestNode - 1;
}

void vizinhosR(int vertice, int *path, GrafoLinked *grafo, int count) {
    if (count == grafo->numVertices) return;
    path[count] = vertice;
    int nearestNeighbor = findNearestNeighbor(&grafo->list[vertice], path, grafo->numVertices);
    vizinhosR(nearestNeighbor, path, grafo, ++count);
}