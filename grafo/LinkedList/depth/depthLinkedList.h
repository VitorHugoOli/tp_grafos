
#include "../grafoLinkedList.h"


typedef struct {
    int conta;
    int *pre;
    int **retorno;
    int indexRetorno;
} TadDepthLinkedList;


void initDepthLinkedList(int m, TadDepthLinkedList *depth);

void allocRetornoLinkedList(TadDepthLinkedList *depth);

void DepthRLinkedList(GrafoLinked G, int v, TadDepthLinkedList *depth);

void DepthLinkedList(GrafoLinked G, TadDepthLinkedList *depth);

void PrintDepthLinkedList(GrafoLinked G);

