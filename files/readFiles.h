//
// Created by vitor on 2/28/21.
//
#include "../depth/depth.h"
#include "string.h"
#include "cjson/cJSON.h"


#ifndef TP_C_READFILES_H
#define TP_C_READFILES_H

typedef struct {
    int nodeLen;
    int **edges;
    float **nodeArr;
    int isPonderado;
} Paad;

int leituraArquivo(TipoGrafo *grafo);

int paadRead(TipoGrafo *grafo, Paad *Paad);

int paadWrite(TipoGrafo *grafo, Paad *Paad);

#endif //TP_C_READFILES_H
