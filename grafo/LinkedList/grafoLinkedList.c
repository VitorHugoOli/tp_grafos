//
// Created by vitor on 3/23/21.
//

#include "grafoLinkedList.h"


void initGrafo(GrafoLinked *grafo) {
    grafo = (GrafoLinked *) malloc(sizeof(GrafoLinked));
    grafo->nomeArquivo = (char *) malloc(255 * sizeof(char));
    grafo->numVertices = 0;
    grafo->numArestas = 0;
    grafo->list = NULL;
}

void addAresta(LinkedList *to, int from, float weight) {
    if (to->vertice == 0) {
        to->vertice = from;
        to->peso = weight;
        return;
    }

    while (to->next != NULL) {
        to = to->next;
    }
    to->next = createNode(from, weight);
}

void printGrafo(GrafoLinked *grafo) {

    if (grafo == NULL || grafo->numVertices == 0) {
        fflush(stdin);
        printf("O grafo esta vazio vazia");
    }

    for (int i = 0; i < grafo->numVertices; ++i) {
        printf("%d | ", i + 1);
        printLinked(&grafo->list[i]);
        printf("\n");
    }

}

FILE *readFiles(GrafoLinked *grafo) {
    FILE *arquivo;
    char nomeArquivo[255];

#if DEBUG

    arquivo = fopen(debugFile, "rw");

    strcpy(grafo->nomeArquivo, debugFile);
#else
    fflush(stdin);
    printf("Entre com o nome do arquivo: ");
    scanf("%s", nomeArquivo);
    arquivo = fopen(nomeArquivo, "rw");

    strcpy(grafo->nomeArquivo, nomeArquivo);
#endif
    return arquivo;

}

int textToGrafo(GrafoLinked *grafo) {
    FILE *arquivo;
    fileStruct data;


    do {

        arquivo = readFiles(grafo);

        if (arquivo == NULL) {
            printf("\n\tArquivo invalido tente novamente.\n\n");
            return 0;
        }

        fscanf(arquivo, "%d", &grafo->numVertices);

        grafo->list = createLinkedList(grafo->numVertices);

        if (grafo->list == NULL) {
            fclose(arquivo);
            printf("\n\tMemoria insuficiente.\n\n");
            return 1;
        }
        grafo->numArestas = 0;
        while (fscanf(arquivo, "%d %d %f", &data.linha, &data.coluna, &data.peso) != EOF) {
            addAresta(&grafo->list[data.linha - 1], data.coluna, data.peso);
            addAresta(&grafo->list[data.coluna - 1], data.linha, data.peso);
            grafo->numArestas++;
        }

        fclose(arquivo);

    } while (arquivo == NULL);
    printf("\n\tArquivo lido com sucesso! \\o/ \n\n");
    return 1;
}

LinkedList *copyList(GrafoLinked *grafo) {
    LinkedList *list = createLinkedList(grafo->numVertices);
    for (int i = 0; i < grafo->numVertices; ++i) {
        list[i] = copyLinkedList(&grafo->list[i]);
    }
    return list;
}

LinkedList *deleteVertice(GrafoLinked *grafo, int vertice) {
    int oldNumVertices = grafo->numVertices;
    grafo->numVertices--;

    LinkedList *list = createLinkedList(grafo->numVertices);

    LinkedList *node = &grafo->list[vertice];

    while (node != NULL) {
        deleteAresta(&grafo->list[node->vertice - 1], vertice + 1);
        node = node->next;
    }


    int newIndex = 0;
    for (int i = 0; i < oldNumVertices; ++i) {
        if (vertice != oldNumVertices) {
            list[newIndex] = grafo->list[i];
            newIndex++;
        }
    }
    free(grafo->list);

    return list;
}


/*
 * Operacoes dos Choices
 * */

int secureChoice(GrafoLinked *grafo, int vertice) {
    if (vertice <= 0 || vertice > (grafo->numVertices)) {
        return 1;
    } else {
        return 0;
    }
}

void vizinhosLinked(GrafoLinked *grafo) {
    int vertice;
    printf("\nEntre com o vertice que deseja saber a vizinhanca: ");
    vertice = get_int();

    if (secureChoice(grafo, vertice)) {
        printf("Entrada invalida");
        return;
    }


    printf("\n\tVizinhos de %d\n", vertice);


    printf("(%d)\n", vertice);
    LinkedList *neighbor = &grafo->list[vertice - 1];
    while (neighbor != NULL) {
        printf(" |-- %d\n", neighbor->vertice);
        neighbor = neighbor->next;
    }
    printf("\n\n");
}

int grauLinked(GrafoLinked *grafo) {
    int vertice;
    printf("\nEntre com o vertice que deseja saber o grau: ");
    vertice = get_int();

    if (secureChoice(grafo, vertice)) {
        printf("Entrada invalida");
        return -1;
    }

    LinkedList *neighbor = &grafo->list[vertice - 1];
    int grau = 0;
    while (neighbor != NULL) {
        grau++;
        neighbor = neighbor->next;
    }

    printf("\n\tO grau do vertice (%d) é %d.\n\n", vertice, grau);
    return grau;
}

//int GRAPHbridgesLinked(GrafoLinked G) {
//    int *pre = (int*)malloc(G.numVertices*sizeof(int));
//    int *parent = (int*)malloc(G.numVertices*sizeof(int));
//    int v, conta = 0, numpts = 0;
//
//    for (v = 0; v < G.numVertices; v++)
//        pre[v] = -1;
//
//    for (v = 0; v < G.numVertices; v++)
//        if (pre[v] == -1) {
//            parent[v] = v;
//            bridgeR(G, v);
//        }
//    return numpts;
//}
//
//void bridgeR(GrafoLinked G, int v,int *pre, int *low) {
//    int w;
//    pre[v] = conta++;///a cada chamada ele tira um v?rtice do vetor de v?rtices marcados pre.
//    low[v] = pre[v];
//    for (w = 0; w < G.numVertices; w++) {
//        if (G.list[v] != 0) {
//            if (pre[w] == -1) {
//                parent[w] = v;
//                bridgeR(G, w);
//                if (low[v] > low[w]) low[v] = low[w];
//                //if(v==w) printf("eh ponte");
//                if (low[w] == pre[w]) {
//                    if ((vertice1 == v + 1 && vertice2 == w + 1) || (vertice1 == w + 1 && vertice2 == v + 1))
//                        numpts++;
//                }
//            } else if (w != parent[v] && low[v] > pre[w])
//                low[v] = pre[w];
//        }
//    }
//}
