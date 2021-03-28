#include "depthLinkedList.h"
#include "../grafoLinkedList.h"

void initDepthLinkedList(int m, TadDepthLinkedList *depth) {
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

void allocRetornoLinkedList(TadDepthLinkedList *depth) {
    depth->indexRetorno = depth->indexRetorno + 1;


    depth->retorno = (int **) realloc(depth->retorno, (depth->indexRetorno + 1) * sizeof(int *));

    depth->retorno[depth->indexRetorno] = (int *) malloc(2 * sizeof(int));

    for (int i = 0; i < 2; i++)
        depth->retorno[depth->indexRetorno][i] = -1;

}

void DepthRLinkedList(GrafoLinked G, int v, TadDepthLinkedList *depth) {
    int w;
    int i, cont = 0;

    while (depth->retorno[cont][0] != -1)
        cont++;

    printf("%3d\n", v + 1);
    depth->pre[v] = depth->conta + 1;
//    for (w = 0; w < G.numVertices; w++) {
//        if (G.matriz[v][w] != 0 && depth->pre[w] == -1)
//            DepthR(G, w, depth);
//        if (G.matriz[v][w] != 0 && depth->pre[w] != -1) {
//            depth->retorno[cont][0] = v + 1;
//            depth->retorno[cont][1] = w + 1;
//            cont++;
//            allocRetorno(depth);
//        }
//    }
}

void DepthLinkedList(GrafoLinked G, TadDepthLinkedList *depth) {
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

void PrintDepthLinkedList(GrafoLinked G) {
    TadDepthLinkedList depth; //ok
    initDepthLinkedList(G.numVertices, &depth); //ok
    DepthLinkedList(G, &depth);
    free(depth.retorno);
    free(depth.pre);
}