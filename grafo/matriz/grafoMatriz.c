//
// Created by vitor on 3/23/21.
//

#include "grafoMatriz.h"


void inicializaGrafoMatriz(GrafoMatriz *m) {
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

#if DEBUG
    printf("\n\tMatriz semi alocada. Agora será inicializada.\n\n");
#endif

    // aloca as colunas da matriz
    for (i = 0; i < m; i++) {
        v[i] = (float *) malloc((m) * sizeof(float));
        // inicializa matriz com valor valorInicial pre definido
        memset(v[i], valorInicial, (m) * sizeof(float));
        if (v[i] == NULL)
            return NULL;
    }


//    float (*teste) [100000] = malloc(sizeof(float[11][11]));
//    for (int k = 0; k < 11; ++k) {
//        for (int l = 0; l < 11; ++l) {
//            teste[k][l] = 1.0F;
//        }
//        memset(&teste[k], valorInicial, (100000) * sizeof(float));
//    }
//    printf("%f", teste[0][0]);

//    int *arr = malloc((100000 * 100000) * (sizeof(int *)));
//    memset(arr, 0, (100000 * 100000) * (sizeof(int)));
//    printf("%d", (&arr[1000000])[1000000]);

//    int **teste;
//    teste = (int **) malloc((100000) * sizeof(*teste));
//    for (int k = 0; k < 100000; ++k) {
//        teste[i] = (&arr[1]);
//    }
//    printf("%d", teste[0][0]);

    return (v);
}

int leituraArquivo(GrafoMatriz *grafo) {
    FILE *arquivo;
    fileStruct celula;
    char nomeArquivo[255];
    do {
        fflush(stdin);
#if DEBUG
        arquivo = fopen(debugFile, "rw");
        strcpy(grafo->nomeArquivo, debugFile);
#else
        printf("Entre com o nome do arquivo: ");
        scanf("%s", nomeArquivo);
        arquivo = fopen(nomeArquivo, "rw");
        strcpy(grafo->nomeArquivo, nomeArquivo);
#endif


        if (arquivo == NULL) {
            printf("\n\tArquivo invalido tente novamente.\n\n");
            return 0;
        }


        fscanf(arquivo, "%d", &grafo->numVertices);

#if DEBUG
        printf("\n\tEntrando do aloca matriz.\n\n");
#endif

        grafo->matriz = alocaMatriz(grafo->numVertices);

#if DEBUG
        printf("\n\tSaiu do aloca matriz.\n\n");
#endif

        if (grafo->matriz == NULL) {
            fclose(arquivo);
            printf("\n\tMemoria insuficiente.\n\n");
            return 1;
        }

        while (fscanf(arquivo, "%d %d %f", &celula.linha, &celula.coluna, &celula.peso) != EOF) {
            //INSERE DADOS NA MATRIZ
            int isEmpty = grafo->matriz[celula.linha - 1][celula.coluna - 1] == valorInicial &&
                          grafo->matriz[celula.coluna - 1][celula.linha - 1] == valorInicial;

            if (isEmpty) {
                grafo->matriz[celula.linha - 1][celula.coluna - 1] = celula.peso;
                grafo->matriz[celula.coluna - 1][celula.linha - 1] = celula.peso;
                grafo->numArestas++;
            } else {
                printf("--> A aresta (%d, %d) já possui o valor %f", celula.linha - 1, celula.coluna - 1,
                       grafo->matriz[celula.coluna - 1][celula.linha - 1]);
            }
        }
        fclose(arquivo);
    } while (arquivo == NULL);
    printf("\n\tArquivo lido com sucesso! \\o/ \n\n");
    return 1;
}

void imprime(GrafoMatriz grafo) {
    int i, j;
    for (i = 0; i < grafo.numVertices; i++) {
        for (j = 0; j < grafo.numVertices; j++) {
            printf("%.2f ", grafo.matriz[i][j]);
        }
        printf("\n");
    }
}

void vizinhos(GrafoMatriz grafo, int vertice) {
    int i, j;
    printf("\n\tVizinhos de %d\n", vertice);
    for (i = 0; i < grafo.numVertices; i++) {
        if (grafo.matriz[vertice - 1][i] != valorInicial)
            printf("Vertice: %d\n", i + 1);
    }
    printf("\n\n");
}

int grau(GrafoMatriz grafo, int vertice) {
    int i, j, grau = 0;
    for (i = 0; i < grafo.numVertices; i++) {
        if (grafo.matriz[vertice - 1][i] != valorInicial)
            grau++;
    }
    return grau;
}


//PONTE
int GRAPHbridges(GrafoMatriz G) {
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

void bridgeR(GrafoMatriz G, int v) {
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
