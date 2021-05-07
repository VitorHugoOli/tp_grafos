#include "depthLinkedList.h"


listaAresta *initListaAresta(int len) {
    listaAresta *list = (listaAresta *) malloc(sizeof(listaAresta));
    list->size = 0;
    list->vetor = (int *) malloc(len * sizeof(int));
    return list;
}


void addList(listaAresta *list, int value) {
    list->vetor[list->size] = value;
    list->size++;
}

void printsArestas(listaAresta *explorado, listaAresta *retorno) {
    printf("\n\n");

    printf("Arestas explorada: \n");
    for (int j = 0; j < explorado->size; j = j + 2) {
        printf("[%d - %d] ", explorado->vetor[j], explorado->vetor[j + 1]);
    }

    printf("\nArestas de retorno: \n");
    for (int j = 0; j < retorno->size; j = j + 2) {
        printf("[%d - %d] ", retorno->vetor[j], retorno->vetor[j + 1]);
    }
    printf("\n");
}


void BuscaProfundidade_grafo(GrafoLinked *grafo, int ini) {
    int *visitado = (int *) malloc(grafo->numVertices * sizeof(int));

    listaAresta *explorado = initListaAresta(grafo->numArestas);
    listaAresta *retorno = initListaAresta(grafo->numArestas);
    int i, cont = 1;

    for (i = 0; i < grafo->numVertices; i++) visitado[i] = 0;


    printf("Ordem de visita: ");
    BuscaProfundidade(grafo, ini, visitado, cont, explorado, retorno);

    printsArestas(explorado, retorno);

    free(visitado);
    free(explorado->vetor);
    free(explorado);
}


void BuscaProfundidade(GrafoLinked *grafo,
                       int ini,
                       int *visitado,
                       int cont,
                       listaAresta *explorado,
                       listaAresta *retorno) {
    printf("(%d) ", ini + 1);
    visitado[ini] = cont;
    LinkedList *node = &grafo->list[ini];
    while (node != NULL) {
        if (!visitado[node->vertice - 1]) {
            addList(explorado, (ini + 1));
            addList(explorado, node->vertice);
            BuscaProfundidade(grafo, (node->vertice - 1), visitado, cont + 1, explorado, retorno);
        } else {
            if (node->vertice > (ini + 1)) {
                addList(retorno, (ini + 1));
                addList(retorno, node->vertice);
            }
        }
        node = node->next;
    }
}


