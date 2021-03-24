#include "linkedlist/linkedlist.h"
#include "../../utils/utils.h"

#ifndef TP_C_GRAFOLINKEDLIST_H
#define TP_C_GRAFOLINKEDLIST_H

typedef struct {
    int numVertices;
    int numArestas;
    char *nomeArquivo;
    LinkedList *list;
} GrafoLinked;


void initGrafo(GrafoLinked *grafo);

int textToGrafo();

void addAresta(LinkedList *to, int from, float weight);

FILE *readFiles(GrafoLinked *grafo);

void printGrafo(GrafoLinked *grafo);


#endif //TP_C_GRAFOLINKEDLIST_H
