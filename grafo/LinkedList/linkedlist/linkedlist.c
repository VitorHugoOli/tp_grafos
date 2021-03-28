//
// Created by vitor on 3/23/21.
//

#include "linkedlist.h"

LinkedList *alocaNode(int vertices) {
    return (LinkedList *) malloc(vertices * sizeof(LinkedList));
}


LinkedList *createNode(int vertice, float weight) {
    LinkedList *node = alocaNode(1);
    node->vertice = vertice;
    node->peso = weight;
    node->next = NULL;
    return node;
}


/*
 * Aqui estamos instanciando a lista de vertices no TAD GrafoLinked
 * */
LinkedList *createLinkedList(int numVertices) {
    LinkedList *list = alocaNode(numVertices);

    for (int i = 0; i < numVertices; ++i) {
        list[i].vertice = 0;
        list[i].next = NULL;
    }
    return list;
}


void printLinked(LinkedList *list) {
    if (list == NULL || list->vertice == 0) {
        printf("Lista vazia");
        return;
    }

    while (list != NULL) {
        printf(" (v:%d; p:%.2f) -> ", list->vertice, list->peso);
        list = list->next;
    }

    printf("NULL");
}
