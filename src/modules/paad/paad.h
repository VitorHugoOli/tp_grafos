//
// Created by vitor on 2/28/21.
//

#include "../../defines.h"

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
    char *file;
} Paad;

char *readPaadFiles(Paad *paad);

int searchIndex(int value, Paad *paad);

int paadRead(Paad *Paad);

int paadWrite(Paad *Paad);

void initPaad(Paad *Paad);


#endif //TP_C_PAAD_H
