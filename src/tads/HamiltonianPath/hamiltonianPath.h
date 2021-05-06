//
// Created by vitor on 5/5/21.
//

#include "../../tads/LinkedGrafo/linkedGrafo.h"

#define startMeasure time_t t_start, t_end;clock_t c_start = clock();time(&t_start);
#define endMeasure time(&t_end); hp->duration = difftime(t_end, t_start); hp->clockDuration = ((double) (clock() - c_start)) / CLOCKS_PER_SEC;



#ifndef TP_C_HAMILTONIANPATH_H
#define TP_C_HAMILTONIANPATH_H

typedef struct {
    int *path;
    float *costVector;
    int pathLen;
    float cost;
    double duration;
    double clockDuration;

    GrafoLinked *grafo;
} HamiltonianPath;


int initHamiltonianPath(GrafoLinked *grafo, HamiltonianPath *hp);

void printHalminton(HamiltonianPath *hp);

void printHalmintonSimple(HamiltonianPath *hp);

int *pathcpy(const int *path, int pathLen);

float *costVectorcpy(const float *path, int pathLen);

int hamiltonPathcpy(HamiltonianPath *to, HamiltonianPath *from, GrafoLinked *to_grafoLinked);

int calcWeightPath(HamiltonianPath *hp);


#endif //TP_C_HAMILTONIANPATH_H
