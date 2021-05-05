//
// Created by vitor on 5/5/21.
//

#ifndef TP_C_HAMILTONIANPATH_H
#define TP_C_HAMILTONIANPATH_H

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

int *pathcpy(const int *path, int pathLen);

float *costVectorcpy(const float *path, int pathLen);

int hamiltonPathcpy(HamiltonianPath *to, HamiltonianPath *from, GrafoLinked *to_grafoLinked);

int calcWeightPath(HamiltonianPath *hp);


#endif //TP_C_HAMILTONIANPATH_H
