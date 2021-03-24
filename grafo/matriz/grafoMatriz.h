#ifndef TP_C_GRAFOMATRIZ_H
#define TP_C_GRAFOMATRIZ_H

#include "../../utils/utils.h"

typedef struct {
    int numVertices;
    char *nomeArquivo;
    int numArestas;
    float **matriz;
} GrafoMatriz;

//VARIAVEIS GLOBAIS
//PROFUNDIDADE
int conta;
int pre[qtd];
int low[qtd];


//ARVORE GERADORA MINIMA
int parent[qtd];

//PONTE
int numpts;
int vertice1, vertice2;

void inicializaGrafoMatriz(GrafoMatriz *m);

void imprime(GrafoMatriz grafo);

float **alocaMatriz(int m);

int leituraArquivo(GrafoMatriz *grafo);

int grau(GrafoMatriz grafo, int vertice);

void vizinhos(GrafoMatriz grafo, int vertice);

//PONTE
int GRAPHbridges(GrafoMatriz G);

void bridgeR(GrafoMatriz G, int v);


#endif //TP_C_GRAFOMATRIZ_H
