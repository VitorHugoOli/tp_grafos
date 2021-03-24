#include "../grafoMatriz.h"


#ifndef TP_C_DEPTH_H
#define TP_C_DEPTH_H


typedef struct {
    int conta;
    int *pre;
    int **retorno;
    int indexRetorno;
} TadDepth;


void initDepth(int m, TadDepth *depth);

void allocRetorno(TadDepth *depth);

void DepthR(GrafoMatriz G, int v, TadDepth *depth);

void Depth(GrafoMatriz G, TadDepth *depth);

void PrintDepth(GrafoMatriz G);

#endif //TP_C_DEPTH_H
