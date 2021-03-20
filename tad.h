#include "utils/defines.h"

#ifndef TP_C_TAD_H_
#define TP_C_TAD_H_


typedef struct {
    int linha;
    int coluna;
    float peso;
} stCelulaMatriz;

typedef struct {
    int numVertices;
    char *nomeArquivo;
    int numArestas;
    float **matriz;
} TipoGrafo;

//VARI?VEIS GLOBAIS
//PROFUNDIDADE
int conta;
int pre[qtd];

int low[qtd];


//ARVORE GERADORA MINIMA
int parent[qtd];

//PONTE
int numpts;
int vertice1, vertice2;

void inicializaMatriz(TipoGrafo *matriz);

void imprime(TipoGrafo grafo);

float **alocaMatriz(int m);

int grau(TipoGrafo grafo, int vertice);

void vizinhos(TipoGrafo grafo, int vertice);




//PONTE
int GRAPHbridges(TipoGrafo G);

void bridgeR(TipoGrafo G, int v);

//ARTICULA��O
void grafoArticulacao(TipoGrafo G, int vertice);


#endif //TP_C_UTILS_H
