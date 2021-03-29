#include <locale.h>
#include "matrizPaad.h"


int paadToMatriz(GrafoMatriz *grafo, Paad *paad) {
    int to, from;
    grafo->numVertices = paad->nodeLen;
    grafo->numArestas = paad->edgesLen;

    if (grafo->matriz == NULL) {
        free(grafo->matriz);
    }

    grafo->matriz = alocaMatriz(paad->nodeLen);

    for (int i = 0; i < paad->edgesLen; ++i) {
        to = searchIndex(paad->edges[i].to, paad);
        from = searchIndex(paad->edges[i].from, paad);
        grafo->matriz[to][from] = (float) paad->edges[i].weight;
        grafo->matriz[from][to] = (float) paad->edges[i].weight;
    }


    printf("Parse Paad json para TadGrafo com sucesso! \\o/");
    return 1;


}

int matrizToPaad(GrafoMatriz *grafo, Paad *paad) {
    paad->nodeLen = grafo->numVertices;
    paad->edgesLen = grafo->numArestas;
    strcpy(grafo->nomeArquivo, paad->file);

    paad->nodes = (int *) malloc(paad->nodeLen * sizeof(int));
    paad->edges = (Edge *) malloc(paad->edgesLen * sizeof(Edge));

    int count = 0;
    for (int i = 0; i < paad->nodeLen; ++i) {
        for (int j = 0; j < paad->nodeLen; ++j) {
            if (i <= j && grafo->matriz[i][j] != valorInicial) {
                paad->edges[count].from = i;
                paad->edges[count].to = j;
                paad->edges[count].weight = (double) grafo->matriz[i][j];
                count++;
            }
        }
    }

    return 1;
}




