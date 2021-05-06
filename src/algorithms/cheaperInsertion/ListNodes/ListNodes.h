//
// Created by vitor on 5/5/21.
//

#include "../../../modules/utils/utils.h"


#ifndef TP_C_LISTNODES_H
#define TP_C_LISTNODES_H


typedef struct listNodes {
    int node;
    float cost;
    struct listNodes *next;

    int index; //Variavel auxiliar
} ListNodes;


void startListNodes(ListNodes *listNodes);
ListNodes * initListNodes();

void add(ListNodes *listNodes, ListNodes *new_node);

int lenList(ListNodes *listNodes);

ListNodes *retrieveAt(ListNodes *listNodes, int index);

ListNodes *retrieve(ListNodes *listNodes, int node);

void addAt(ListNodes *listNodes, ListNodes *new_node, int index);

void removeAt(ListNodes *listNodes, int index);

void removeNode(ListNodes *listNodes, int node);



#endif //TP_C_LISTNODES_H
