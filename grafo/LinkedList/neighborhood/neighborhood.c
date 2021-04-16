//
// Created by vitor on 4/13/21.
//

//1 Inicializar a rota com um vértice aleatório (número 1)
//2 Encontrar o vértice K fora da rota cuja aresta possua o menor custo
//3 Adicionar o vértice K no final da lista de vértices visitados
//4 Se todos os vértices foram adicionados parar, senão volta ao passo 2


#include "neighborhood.h"


HamiltonianPath *initHamiltonianPath(GrafoLinked *grafo) {
    HamiltonianPath *hamiltonianPath = (HamiltonianPath *) malloc(sizeof(HamiltonianPath));
    hamiltonianPath->path = malloc(grafo->numVertices * sizeof(int));
    hamiltonianPath->pathLen = grafo->numVertices;
    hamiltonianPath->cost = 0;
    hamiltonianPath->duration = 0.0;
    hamiltonianPath->grafo = grafo;

    for (int i = 0; i < grafo->numVertices; ++i) hamiltonianPath->path[i] = -1;

    return hamiltonianPath;

}


void printResultes(HamiltonianPath *hp) {
    printf("\nCaminho pecorrido\n\n");
    printf("Tempo Gasto = %lf\n", hp->duration);
    printf("Custo do ciclo = %f\n", hp->cost);
    for (int i = 0; i < hp->pathLen; ++i) {

        printf("(%d)", hp->path[i] + 1);

        if (i < (hp->pathLen - 1)) printf(" -> ");

    }
    printf("\n");
}

int nearestNeighbor(GrafoLinked *grafo, HamiltonianPath *hamiltonianPath) {
    *hamiltonianPath = *initHamiltonianPath(grafo);

    clock_t t;
    t = clock();

    vizinhosR(0, hamiltonianPath, 0);

    hamiltonianPath->duration = ((double) t) / CLOCKS_PER_SEC;

    printResultes(hamiltonianPath);

    return 1;
}


int valueInArray(int val, const int *arr, int len) {
    for (int i = 0; i < len; i++) if (arr[i] == val) return 1;
    return 0;
}

int findNearestNeighbor(LinkedList *list, HamiltonianPath *hp) {
    int nearestNode = -1;
    float light;

    LinkedList *node = list;

    while (node != NULL) {
        if ((nearestNode == -1 || node->peso < light) && !valueInArray(node->vertice - 1, hp->path, hp->pathLen)) {
            nearestNode = node->vertice;
            light = node->peso;
        }
        node = node->next;
    }

    hp->cost += light;
    return nearestNode - 1;
}

void vizinhosR(int vertice, HamiltonianPath *hp, int count) {
    if (count == hp->pathLen) return;
    hp->path[count] = vertice;
    int nearestNeighbor = findNearestNeighbor(&(hp->grafo)->list[vertice], hp);
    vizinhosR(nearestNeighbor, hp, ++count);
}