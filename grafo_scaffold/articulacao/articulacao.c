#include "articulacao.h"

//ARTICULAÇÃO
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
    int *groupConexoVertice = (int *) malloc(G.numVertices * sizeof(int));
    if (ECC(grafo, groupConexoVertice) > ECC(G, groupConexoVertice) + 1)
        printf("\n\tVertice %d eh uma articulacao!\n\n", vertice);
    else
        printf("\n\tVertice %d nao eh uma articulacao!\n\n", vertice);
}