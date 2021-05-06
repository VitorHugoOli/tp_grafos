//
// Created by vitor on 5/5/21.
//

#include "ListNodes.h"


void swapValues(ListNodes *listNodes, ListNodes *new_node);

void startListNodes(ListNodes *listNodes) {
    listNodes->node = 0;
    listNodes->cost = 0;
    listNodes->index = 0;
    listNodes->next = NULL;
}

ListNodes *initListNodes() {
    ListNodes *listNodes = (ListNodes *) malloc(sizeof(ListNodes));
    startListNodes(listNodes);
    return listNodes;
}

void add(ListNodes *listNodes, ListNodes *new_node) {
    ListNodes *aux = listNodes;

    if (listNodes->index == -1) { //Primeira adicao
        listNodes->node = new_node->node;
        listNodes->cost = new_node->cost;
        listNodes->next = new_node->next;
        listNodes->index = 0;
        return;
    }

    while (true) {
        if (aux->next == NULL) {
            aux->next = new_node;
            break;
        }
        aux = aux->next;
    }
}

int lenList(ListNodes *listNodes) {
    ListNodes *aux = listNodes;
    int count = 0;

    while (aux != NULL) {
        count++;
        aux = aux->next;
    }
    return count;
}

ListNodes *retrieveAt(ListNodes *listNodes, int index) {
    ListNodes *aux = listNodes;
    int count = 0;

    while (true) {
        if (count == index) {
            return aux;
        }
        if (aux == NULL)break;
        aux = aux->next;
        count++;
    }
}

ListNodes *retrieve(ListNodes *listNodes, int node) {
    ListNodes *aux = listNodes;
    int count = 0;

    while (aux != NULL) {
        if (aux->node == node) {
            aux->index = count;
            return aux;
        };
        aux = aux->next;
        count++;
    }
}

void swapValues(ListNodes *first, ListNodes *second) {
    float auxSwap;

    auxSwap = (float) first->node;
    first->node = second->node;
    second->node = (int) auxSwap;

    auxSwap = (float) first->index;
    first->index = second->index;
    second->index = (int) auxSwap;

    auxSwap = first->cost;
    first->cost = second->cost;
    second->cost = auxSwap;
}


void addAt(ListNodes *listNodes, ListNodes *new_node, int index) {
    ListNodes *aux = listNodes;
    ListNodes *prevAux = listNodes;
    int count = 0;


    while (true) {
        if (count == index) {
            if (count == 0) {
                swapValues(listNodes, new_node);
                new_node->next = aux->next;
                aux->next = new_node;
            } else if (aux == NULL) {
                prevAux->next = new_node;
            } else {
                prevAux->next = new_node;
                new_node->next = aux;
            }
            break;
        }
        if (aux == NULL) break;
        prevAux = aux;
        aux = aux->next;
        count++;
    }
}


void removeNode(ListNodes *listNodes, int node) {
    ListNodes *aux = listNodes;
    ListNodes *prevAux = listNodes;


    while (aux != NULL) {
        if (aux->node == node) {
            if (aux == listNodes) {
                if (aux->next != NULL) {
                    swapValues(listNodes, aux->next);
                    listNodes->next = aux->next->next;
                } else {
                    listNodes->node = 0;
                    listNodes->cost = 0;
                    listNodes->index = -1; //Sinaliza q a lista est'a vazia
                }
            } else if (aux == NULL) {
                prevAux->next = NULL;
            } else {
                prevAux->next = aux->next;
            }
            break;
        };
        prevAux = aux;
        aux = aux->next;
    }
}
