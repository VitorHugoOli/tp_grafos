//
// Created by vitor on 3/23/21.
//

#include "linkedGrafo.h"


void initGrafo(GrafoLinked *grafo) {
    grafo->nomeArquivo = NULL;
    grafo->numVertices = 0;
    grafo->numArestas = 0;
    grafo->list = NULL;
}

LinkedList *copyList(GrafoLinked *grafo) {
    LinkedList *list = createLinkedList(grafo->numVertices);
    for (int i = 0; i < grafo->numVertices; ++i) {
        list[i] = copyLinkedList(&grafo->list[i]);
    }
    return list;
}

int graphcpy(GrafoLinked *to, GrafoLinked *from) {
    to->nomeArquivo = (char *) malloc(255 * sizeof(char));
    strcpy(to->nomeArquivo, from->nomeArquivo); //todo: potencial a erro
    to->numVertices = from->numVertices;
    to->numArestas = from->numArestas;
    to->list = copyList(from);
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
        printf("O matriz esta vazio vazia");
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
    strcpy(nomeArquivo, debugFile);
    grafo->nomeArquivo = (char *) malloc(sizeof(debugFile) / sizeof(char) * sizeof(char));
    strcpy(grafo->nomeArquivo, nomeArquivo);
#else
    fflush(stdin);
    printf("Entre com o nome do arquivo: ");
    scanf("%s", nomeArquivo);
    arquivo = fopen(nomeArquivo, "rw");
    grafo->nomeArquivo = (char *) malloc(sizeof(nomeArquivo)/sizeof (char)* sizeof(char));

    strcpy(grafo->nomeArquivo, nomeArquivo);
#endif
    if (arquivo == NULL) {
        return NULL;
    }

    return arquivo;
}

FILE *readFilesDirect(GrafoLinked *grafo, char *file) {
    FILE *arquivo;
    char nomeArquivo[255];


    arquivo = fopen(file, "rw");
    strcpy(nomeArquivo, file);
    grafo->nomeArquivo = (char *) malloc(255 * sizeof(char));
    strcpy(grafo->nomeArquivo, nomeArquivo);

    if (arquivo == NULL) {
        return NULL;
    }

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

        if (grafo->numVertices == 0) return -1;

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

LinkedList *deleteNode(GrafoLinked *grafo, int vertice) {
    int oldNumVertices = grafo->numVertices;
    grafo->numVertices--;

    LinkedList *list = createLinkedList(grafo->numVertices);

    LinkedList *node = &grafo->list[vertice - 1];

    while (node != NULL) {
        deleteAresta(&grafo->list[node->vertice - 1], vertice);
        node = node->next;
    }


    int newIndex = 0;
    LinkedList *aux;
    for (int i = 0; i < oldNumVertices; ++i) {
        if (i != (vertice - 1)) {
            list[newIndex] = grafo->list[i];
            aux = &list[newIndex];
            while (aux != NULL) {
                if (aux->vertice > vertice) {
                    aux->vertice--;
                }
                aux = aux->next;
            }

            newIndex++;
        }
    }
    free(grafo->list);

    return list;
}

int deleteEdge(GrafoLinked *grafo, int to, int from) {

    deleteAresta(&(grafo->list[to - 1]), from);
    deleteAresta(&(grafo->list[from - 1]), to);

    return 1;
}

float weightEdge(GrafoLinked *grafo, int to, int from) {
    LinkedList *node = &(grafo->list[to - 1]);
    while (node != NULL) {
        if (from == node->vertice) return node->peso;
        node = node->next;
    }
    return -1;
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
