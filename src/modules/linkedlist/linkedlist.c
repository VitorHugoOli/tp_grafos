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

int deleteAresta(LinkedList *list, int vertice) {
    LinkedList *node = list;

    LinkedList *next;
    LinkedList *nextPointer;
    LinkedList *prev = NULL;

    while (node != NULL) {

        if (vertice == node->vertice) {
            if (node->next != NULL) {
                next = node->next;
                nextPointer = node->next->next;

                node->vertice = next->vertice;
                node->peso = next->peso;
                node->next = nextPointer;
                free(next);
                return 1;
            } else {
                if (list == node) { //Significa que e o primeiro item da lista
                    node->vertice = 0;
                    node->peso = 0;
                    return 1;
                } else { //Ultimo item da lista
                    prev->next = NULL;
                    free(node);
                    return 1;
                }
            }
        }

        prev = node;
        node = node->next;

    }

}

LinkedList copyLinkedList(LinkedList *list) {
    LinkedList *cpy = (LinkedList *) malloc(sizeof(LinkedList));
    LinkedList *nodeCpy = cpy;
    LinkedList *node = list;

    while (node != NULL) {
        nodeCpy->vertice = node->vertice;
        nodeCpy->peso = node->peso;
        if (node->next != NULL) {
            nodeCpy->next = alocaNode(1);
            nodeCpy = nodeCpy->next;
        } else {
            nodeCpy->next = NULL;
        }
        node = node->next;
    }
    return *cpy;
}

int isNodeOfList(LinkedList *list, int vertice) {
    LinkedList *node = list;
    while (node != NULL) {
        if (vertice == node->vertice) {
            return 1;
        }
        node = node->next;
    }
    return 0;

}
