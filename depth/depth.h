#include "../conexo/conexo.h"


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

void DepthR(TipoGrafo G, int v, TadDepth *depth);

void Depth(TipoGrafo G, TadDepth *depth);

void PrintDepth(TipoGrafo G);

#endif //TP_C_DEPTH_H
