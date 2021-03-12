#include "tad.h"

void inicializaMatriz(TipoGrafo *m) {
    m->matriz = NULL;
    m->numArestas = 0;
    m->nomeArquivo = (char *) malloc((255) * sizeof(char));
    m->numVertices = 0;
}

float **alocaMatriz(int m) {
    int i, j;
    float **v;

    // aloca as linhas da matriz
    v = (float **) malloc((m) * sizeof(float *));
    if (v == NULL)
        return NULL;

    // aloca as colunas da matriz
    for (i = 0; i < m; i++) {
        v[i] = (float *) malloc((m) * sizeof(float));
        if (v[i] == NULL)
            return NULL;
    }

    // inicializa matriz com valor valorInicial pre definido
    for (i = 0; i < m; i++) {
        for (j = 0; j < m; j++)
            v[i][j] = valorInicial;

    }

    return (v);
}

void imprime(TipoGrafo grafo) {
    int i, j;
    for (i = 0; i < grafo.numVertices; i++) {
        for (j = 0; j < grafo.numVertices; j++) {
            printf("%.2f ", grafo.matriz[i][j]);
        }
        printf("\n");
    }
}

void vizinhos(TipoGrafo grafo, int vertice) {
    int i, j;
    printf("\n\tVizinhos de %d\n", vertice);
    for (i = 0; i < grafo.numVertices; i++) {
        if (grafo.matriz[vertice - 1][i] != valorInicial)
            printf("Vertice: %d\n", i + 1);
    }
    printf("\n\n");
}

int grau(TipoGrafo grafo, int vertice) {
    int i, j, grau = 0;
    for (i = 0; i < grafo.numVertices; i++) {
        if (grafo.matriz[vertice - 1][i] != valorInicial)
            grau++;
    }
    return grau;
}


//PONTE
int GRAPHbridges(TipoGrafo G) {
    int v;
    conta = 0;
    numpts = 0;
    for (v = 0; v < G.numVertices; v++)
        pre[v] = -1;
    for (v = 0; v < G.numVertices; v++)
        if (pre[v] == -1) {
            parent[v] = v;
            bridgeR(G, v);
        }
    return numpts;
}

void bridgeR(TipoGrafo G, int v) {
    int w;
    pre[v] = conta++;///a cada chamada ele tira um v?rtice do vetor de v?rtices marcados pre.
    low[v] = pre[v];
    for (w = 0; w < G.numVertices; w++) {
        if (G.matriz[v][w] != 0) {
            if (pre[w] == -1) {
                parent[w] = v;
                bridgeR(G, w);
                if (low[v] > low[w]) low[v] = low[w];
                //if(v==w) printf("eh ponte");
                if (low[w] == pre[w]) {
                    if ((vertice1 == v + 1 && vertice2 == w + 1) || (vertice1 == w + 1 && vertice2 == v + 1))
                        numpts++;
                }
            } else if (w != parent[v] && low[v] > pre[w])
                low[v] = pre[w];
        }
    }
}

//ARTICULA??O
void grafoArticulacao(TipoGrafo G, int vertice) {
    TipoGrafo grafo;
    grafo.numVertices = G.numVertices;
    grafo.matriz = alocaMatriz(G.numVertices);
    int i, j;
    for (i = 0; i < G.numVertices; i++) {
        for (j = 0; j < G.numVertices; j++) {
            grafo.matriz[i][j] = G.matriz[i][j];
        }
    }
    for (j = 0; j < G.numVertices; j++) {
        if (grafo.matriz[vertice - 1][j] != valorInicial) {
            grafo.matriz[vertice - 1][j] = valorInicial;
            grafo.matriz[j][vertice - 1] = valorInicial;
        }
    }
    if (GRAPHcc(grafo) > GRAPHcc(G) + 1)
        printf("\n\tVertice %d eh uma articulacao!\n\n", vertice);
    else
        printf("\n\tVertice %d nao eh uma articulacao!\n\n", vertice);
}


//COMPONENTE CONEXA
int GRAPHcc(TipoGrafo G) {
    int v, id, i;
    id = 0;
    for (v = 0; v < G.numVertices; v++)
        pre[v] = -1;
    for (v = 0; v < G.numVertices; v++)
        if (pre[v] == -1)
            dfsRcc(G, v, id++);
    return id;
}

void dfsRcc(TipoGrafo G, int v, int id) {
    int w;
    pre[v] = id;
    for (w = 0; w < G.numVertices; w++)
        if (G.matriz[v][w] != valorInicial && pre[w] == -1)
            dfsRcc(G, w, id);
}






