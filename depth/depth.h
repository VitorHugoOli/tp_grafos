#include "../tad.h"


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