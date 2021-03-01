#include <stdio.h>
#include <stdlib.h>

#define FIN_CICLO -1
#define false 0
#define true 1

#define limpatela system("cls");
#define congela system("pause");
#define valorInicial 0
#define qtd 10000
#define INF 2147483647
#define DEBUG 0 /* 1 for print the matrixes,0 to hide */

typedef struct {
    int linha;
    int coluna;
    float peso;
} stCelulaMatriz;

typedef struct {
    int numVertices;
    int numArestas;
    float **matriz;
    float **matrizAux;
} TipoGrafo;

//VARI?VEIS GLOBAIS
//PROFUNDIDADE
int conta;
int pre[qtd];
int retorno[qtd][2];

//LARGURA
typedef int Item;
Item *q;
int inicio, fim;
int low[qtd];

//BIPARTIDO
int color[qtd];
typedef struct node *link;
struct node {
    int w;
    link next;
};

typedef struct item {
    int grau;
    int index;
    int marca;
} Titem;

//CAMINHO MINIMO
int *rot;
float *distancia;
int *vet;

//ARVORE GERADORA MINIMA
int parent[qtd];

//PONTE
int numpts;
int lbl[qtd];
int vertice1, vertice2;

void inicializaMatriz(TipoGrafo *matriz);

void imprime(TipoGrafo grafo);

float **alocaMatriz(int m);

int grau(TipoGrafo grafo, int vertice);

void vizinhos(TipoGrafo grafo, int vertice);

int verificarGrafoEhEuleriano(TipoGrafo *grafo);

//BUSCA PROFUNDIDADE
void BuscaProfunR(TipoGrafo G, int v);

void BuscaProfun(TipoGrafo G);

void ImprimeProf(TipoGrafo G);

//BUSCA LARGURA
void fazFila(int maxN);

int filavazia();

void enfileira(Item item);

Item desenfileira();

void freeFila();

void buscaEmLargura(TipoGrafo G, int s);

//BIPARTIDO
int GRAPHtwocolor(TipoGrafo G);

int dfsRcolor(TipoGrafo G, int v, int c);

//CAMINHO MINIMO
void dijkstra(TipoGrafo G, int s);

void iniciaVars(TipoGrafo G, int s);

//ARVORE GERADORA MINIMA
void mst(TipoGrafo G, int parent[]);

//COMPONENTE CONEXA
int GRAPHcc(TipoGrafo G);

void dfsRcc(TipoGrafo G, int v, int id);

//PONTE
int GRAPHbridges(TipoGrafo G);

void bridgeR(TipoGrafo G, int v);

//ARTICULA��O
void grafoArticulacao(TipoGrafo G, int vertice);

//CIRCUITO NEGATIVO
float FindMinDistance(float **matrix, float matrixSize, float pt1, float pt2);

float minPonto(float x, float y);

void PrintMatrix(float **matrix, float matrixSize);

void Floyd(TipoGrafo G);

void greedy(TipoGrafo G);

void ordena(Titem *A, int n);

int chamaEuler(TipoGrafo G);

void pegarCiclos(int *ciclo, int *subciclo, int posicion);

void pegarCiclos(int *ciclo, int *subciclo, int posicion);

int tieneAristas(TipoGrafo G, int n);

void eliminarAristas(TipoGrafo G, int *ciclo);

int *encontrarCiclo(TipoGrafo G, int vertice, int n);

void mostrarCiclo(int *ciclo);

int dentroDeCiclo(int *ciclo, int vertice);

void destruirMatrizAdyacencia(int n);

