//
// Created by vitor on 2/28/21.
//
#include "../grafo_scaffold/tad.h"


#ifndef TP_C_PAAD_H
#define TP_C_PAAD_H


typedef struct {
    int from;
    int to;
    double weight;
} Edge;

typedef struct {
    int nodeLen;
    int edgesLen;
    Edge *edges;
    int *nodes;
    int isPonderado;
} Paad;


int paadRead(Paad *Paad);

int paadToGrafo(TipoGrafo *grafo, Paad *paad);

int grafoToPaad(TipoGrafo *grafo, Paad *paad);

int paadWrite(Paad *Paad);


#endif //TP_C_PAAD_H
