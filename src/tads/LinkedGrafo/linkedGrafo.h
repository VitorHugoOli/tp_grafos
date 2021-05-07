#include "../../modules/utils/utils.h"
#include "../../modules/linkedlist/linkedlist.h"

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

FILE *readFilesDirect(GrafoLinked *grafo, char *file);

void printGrafo(GrafoLinked *grafo);

int secureChoice(GrafoLinked *grafo, int vertice);

void vizinhosLinked(GrafoLinked *grafo);

int grauLinked(GrafoLinked *grafo);

LinkedList *copyList(GrafoLinked *grafo);

LinkedList *deleteNode(GrafoLinked *grafo, int vertice);

float weightEdge(GrafoLinked *grafo, int to, int from);

int deleteEdge(GrafoLinked *grafo, int to, int from);

int graphcpy(GrafoLinked *to, GrafoLinked *from);


#endif //TP_C_GRAFOLINKEDLIST_H
