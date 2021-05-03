//
// Created by vitor on 4/13/21.
//

//1 Inicializar a rota com um vértice aleatório (número 1)
//2 Encontrar o vértice K fora da rota cuja aresta possua o menor custo
//3 Adicionar o vértice K no final da lista de vértices visitados
//4 Se todos os vértices foram adicionados parar, senão volta ao passo 2


#include "neighborhood.h"


int initHamiltonianPath(GrafoLinked *grafo, HamiltonianPath *hp) {
    hp->path = malloc((grafo->numVertices + 1) * sizeof(int));
    hp->costVector = malloc((grafo->numVertices) * sizeof(int));
    hp->pathLen = grafo->numVertices + 1;//O cliclo será a quantidade de vertice mais 1;
    hp->cost = 0;
    hp->duration = 0.0;
    hp->grafo = grafo;

    for (int i = 0; i < hp->pathLen; ++i) hp->path[i] = -1;

    return 1;
}


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

/*
 * Auxiliares
 * */

void printHalminton(HamiltonianPath *hp) {
    printf("\nCaminho pecorrido\n\n");
    printf("Tempo Gasto = %lf\n", hp->duration);
    printf("Custo do ciclo = %f\n", hp->cost);
    for (int i = 0; i < hp->pathLen; ++i) {

        printf("(%d)", hp->path[i]);

        if (i < (hp->pathLen - 1)) printf(" - %.1f - ", hp->costVector[i]);

    }
    printf("\n");
}

void printHalmintonSimple(HamiltonianPath *hp) {

    for (int i = 0; i < hp->pathLen; ++i) {
        printf("(%d)", hp->path[i]);
        if (i < (hp->pathLen - 1)) printf(" - %.1f - ", hp->costVector[i]);
    }

    printf("\033[1;32m  Custo = %f\033[0;0m\n", hp->cost);
}

int *pathcpy(const int *path, int pathLen) {
    int *cpyPath = (int *) malloc(pathLen * sizeof(int));
    for (int i = 0; i < pathLen; ++i) cpyPath[i] = path[i];
    return cpyPath;
}

float *costVectorcpy(const float *path, int pathLen) {
    float *cpyPath = (float *) malloc(pathLen * sizeof(float));
    for (int i = 0; i < pathLen; ++i) cpyPath[i] = path[i];
    return cpyPath;
}

int hamiltonPathcpy(HamiltonianPath *to, HamiltonianPath *from, GrafoLinked *to_grafoLinked) {
    to->path = pathcpy(from->path, from->pathLen + 1);
    to->costVector = costVectorcpy(from->costVector, from->pathLen);
    to->pathLen = from->pathLen;
    to->duration = from->duration;
    to->cost = from->cost;
    to->grafo = to_grafoLinked;

    return 1;
}

int calcWeightPath(HamiltonianPath *hp) {
    float sum = 0;
    float weight = 0;

    for (int i = 0; i < hp->pathLen - 1; ++i) {
        weight = weightEdge(hp->grafo, hp->path[i], hp->path[i + 1]);
        if (weight == -1) {
            printf("Algo deu errado ao calcular os pesos");
            return -1;
        }
        hp->costVector[i] = weight;
        sum += weight;
    }

    hp->cost = sum;
    return 1;


}