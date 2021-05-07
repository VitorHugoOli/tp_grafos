//
// Created by vitor on 4/13/21.
//


#ifndef TP_C_NEIGHBORHOOD_H
#define TP_C_NEIGHBORHOOD_H

#include "../../tads/LinkedGrafo/linkedGrafo.h"
#include "../../tads/HamiltonianPath/hamiltonianPath.h"

int nearestNeighbor(GrafoLinked *grafo, HamiltonianPath *hp, int initNode, int silence);

void vizinhosR(int vertice, HamiltonianPath *hp, int count);

int findNearestNeighbor(LinkedList *list, HamiltonianPath *hp, int count);

int valueInArray(int val, const int *arr, int len);


#endif //TP_C_NEIGHBORHOOD_H
