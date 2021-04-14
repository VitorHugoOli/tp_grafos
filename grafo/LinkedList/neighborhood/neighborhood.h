//
// Created by vitor on 4/13/21.
//

#include "../grafoLinkedList.h"
#include "time.h"

#ifndef TP_C_NEIGHBORHOOD_H
#define TP_C_NEIGHBORHOOD_H

void nearestNeighbor(GrafoLinked *grafo);
void vizinhosR(int vertice, int *path, GrafoLinked *grafo, int count);
int findNearestNeighbor(LinkedList *list, int *path, int len);


#endif //TP_C_NEIGHBORHOOD_H
