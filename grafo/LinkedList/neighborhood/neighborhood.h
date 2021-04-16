//
// Created by vitor on 4/13/21.
//

#include "../grafoLinkedList.h"
#include "time.h"

#ifndef TP_C_NEIGHBORHOOD_H
#define TP_C_NEIGHBORHOOD_H

typedef struct {
    int *path;
    int pathLen;
    float cost;
    double duration;
    GrafoLinked *grafo;
} HamiltonianPath;

HamiltonianPath *initHamiltonianPath(GrafoLinked *grafo);

int nearestNeighbor(GrafoLinked *grafo, HamiltonianPath *hamiltonianPath);

void vizinhosR(int vertice, HamiltonianPath *hp, int count);

int findNearestNeighbor(LinkedList *list, HamiltonianPath *hp);


#endif //TP_C_NEIGHBORHOOD_H
