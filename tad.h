#include <stdio.h>
#include <stdlib.h>
#include <curses.h>

#define FIN_CICLO -1
#define false 0
#define true 1


#ifdef _WIN32
#define limpatela vsystem("cls");
#elif defined(unix) || defined(__unix__) || defined(__unix) || (defined(__APPLE__) && defined(__MACH__))
#define limpatela system("clear");
#endif

#ifdef _WIN32
#define congela system("pause");
#elif defined(unix) || defined(__unix__) || defined(__unix) || (defined(__APPLE__) && defined(__MACH__))
#define congela system("read -p \"Pressione enter para sair\" saindo");
#endif


#define valorInicial 0
#define qtd 10000
#define DEBUG 0 /* 1 for print the matrixes,0 to hide */
#define file "pilot.txt"


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
    float **matrizAux;
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


//COMPONENTE CONEXA
int GRAPHcc(TipoGrafo G);

void dfsRcc(TipoGrafo G, int v, int id);

//PONTE
int GRAPHbridges(TipoGrafo G);

void bridgeR(TipoGrafo G, int v);

//ARTICULA��O
void grafoArticulacao(TipoGrafo G, int vertice);


