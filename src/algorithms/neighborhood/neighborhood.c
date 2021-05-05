//
// Created by vitor on 4/13/21.
//

//1 Inicializar a rota com um vértice aleatório (número 1)
//2 Encontrar o vértice K fora da rota cuja aresta possua o menor custo
//3 Adicionar o vértice K no final da lista de vértices visitados
//4 Se todos os vértices foram adicionados parar, senão volta ao passo 2


#include "neighborhood.h"

int nearestNeighbor(GrafoLinked *grafo, HamiltonianPath *hp, int initNode) {
    initHamiltonianPath(grafo, hp);


    clock_t t;
    t = clock();

    vizinhosR(initNode, hp, 0);

    hp->duration = ((double) t) / CLOCKS_PER_SEC;

    printHalminton(hp);

    return 1;
}

int valueInArray(int val, const int *arr, int len) {
    for (int i = 0; i < len; i++) if (arr[i] == val) return 1;
    return 0;
}

int findNearestNeighbor(LinkedList *list, HamiltonianPath *hp, int count) {
    int nearestNode = -1;
    float light = 0;

    LinkedList *node = list;


    while (node != NULL) {
        if ((nearestNode == -1 || node->peso < light) && !valueInArray(node->vertice, hp->path, hp->pathLen)) {
            nearestNode = node->vertice;
            light = node->peso;
        }
        node = node->next;
    }

    hp->cost += light;
    hp->costVector[count] = light;
    return nearestNode;
}

void vizinhosR(int vertice, HamiltonianPath *hp, int count) {
    float weight;

    if (count == hp->pathLen - 1) {
        hp->path[count] = hp->path[0];
        weight = weightEdge(hp->grafo, hp->path[count - 1], hp->path[0]);
        hp->cost += weight;
        hp->costVector[count - 1] = weight;
        return;
    };

    hp->path[count] = vertice;
    int nearestNeighbor = findNearestNeighbor(&(hp->grafo)->list[vertice - 1], hp, count);
    vizinhosR(nearestNeighbor, hp, ++count);
}