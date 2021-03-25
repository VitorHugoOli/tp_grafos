#include "linkedlist/linkedlist.h"
#include "../../utils/utils.h"

#ifndef TP_C_GRAFOLINKEDLIST_H
#define TP_C_GRAFOLINKEDLIST_H

typedef struct {
    int numVertices;
    int numArestas;
    char *nomeArquivo;
    //Lista de linked lists
    LinkedList *list;
} GrafoLinked;


void initGrafo(GrafoLinked *grafo);

int textToGrafo(GrafoLinked *grafo);

void addAresta(LinkedList *to, int from, float weight);

FILE *readFiles(GrafoLinked *grafo);

void printGrafo(GrafoLinked *grafo);

int secureChoice(GrafoLinked *grafo, int vertice);

void vizinhosLinked(GrafoLinked *grafo);

int grauLinked(GrafoLinked *grafo);


#endif //TP_C_GRAFOLINKEDLIST_H
