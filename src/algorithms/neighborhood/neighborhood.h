//
// Created by vitor on 4/13/21.
//


#ifndef TP_C_NEIGHBORHOOD_H
#define TP_C_NEIGHBORHOOD_H

#include "../../tads/LinkedGrafo/linkedGrafo.h"

typedef struct {
    int *path;
    float *costVector;
    int pathLen;
    float cost;
    double duration;

    GrafoLinked *grafo;
} HamiltonianPath;

int initHamiltonianPath(GrafoLinked *grafo, HamiltonianPath *hp);

void printHalminton(HamiltonianPath *hp);

void printHalmintonSimple(HamiltonianPath *hp);

int nearestNeighbor(GrafoLinked *grafo, HamiltonianPath *hp, int initNode);

void vizinhosR(int vertice, HamiltonianPath *hp, int count);

int findNearestNeighbor(LinkedList *list, HamiltonianPath *hp, int count);

int valueInArray(int val, const int *arr, int len);

int *pathcpy(const int *path, int pathLen);

int hamiltonPathcpy(HamiltonianPath *to, HamiltonianPath *from, GrafoLinked *to_grafoLinked);

int calcWeightPath(HamiltonianPath *hp);

#endif //TP_C_NEIGHBORHOOD_H
