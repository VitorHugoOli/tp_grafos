//
// Created by vitor on 5/5/21.
//

#include "hamiltonianPath.h"

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

void printHalminton(HamiltonianPath *hp) {
    printf("\nCaminho pecorrido\n\n");
    printf("\033[1;32mTempo Gasto = %lfs\n", hp->duration);
    printf("Tempo da Cpu Gasta = %lfs\n", hp->clockDuration);
    printf("Custo do ciclo = %f\033[0;0m\n", hp->cost);
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