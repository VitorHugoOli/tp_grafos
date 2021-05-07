#include "depth.h"

void initDepth(int m, TadDepth *depth) {
    depth->conta = 1;
    depth->indexRetorno = 0;
    depth->pre = (int *) malloc(m * sizeof(int));

    depth->retorno = (int **) malloc(sizeof(int *));
    depth->retorno[0] = (int *) malloc(2 * sizeof(int));


    for (int i = 0; i < m; i++)
        depth->pre[i] = -1;

    for (int i = 0; i < 2; i++)
        depth->retorno[0][i] = -1;
}

void allocRetorno(TadDepth *depth) {
    depth->indexRetorno = depth->indexRetorno + 1;


    depth->retorno = (int **) realloc(depth->retorno, (depth->indexRetorno + 1) * sizeof(int *));

    depth->retorno[depth->indexRetorno] = (int *) malloc(2 * sizeof(int));

    for (int i = 0; i < 2; i++)
        depth->retorno[depth->indexRetorno][i] = -1;

}


void DepthR(GrafoMatriz G, int v, TadDepth *depth) {
    int w;
    int i, cont = 0;

    while (depth->retorno[cont][0] != -1)
        cont++;

    printf("%3d\n", v + 1);
    depth->pre[v] = depth->conta + 1;
    for (w = 0; w < G.numVertices; w++) {
        if (G.matriz[v][w] != 0 && depth->pre[w] == -1)
            DepthR(G, w, depth);
        if (G.matriz[v][w] != 0 && depth->pre[w] != -1) {
            depth->retorno[cont][0] = v + 1;
            depth->retorno[cont][1] = w + 1;
            cont++;
            allocRetorno(depth);
        }
    }

}

void Depth(GrafoMatriz G, TadDepth *depth) {
    int v, i;


    for (v = 0; v < G.numVertices; v++) {
        if (depth->pre[v] == -1)
            DepthR(G, v, depth);
    }

    int cont = 0;

    while (depth->retorno[cont][0] != -1) {
        printf("Retorno de %d para %d\n", depth->retorno[cont][1], depth->retorno[cont][0]);
        cont++;
    }
}

void PrintDepth(GrafoMatriz G) {
    TadDepth depth;
    initDepth(G.numVertices, &depth);
    Depth(G, &depth);
    free(depth.retorno);
    free(depth.pre);
}