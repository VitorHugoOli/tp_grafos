//
// Created by vitor on 3/23/21.
//
#include "../../utils/utils.h"
#include "../../grafo/LinkedList/grafoLinkedList.h"
#include "../../grafo/LinkedList/linkedPaad/linkedPaad.h"
#include "../../grafo/LinkedList/conexo/conexo.h"
#include "../../grafo/LinkedList/bridge/bridge.h"
#include "../../grafo/LinkedList/articulation/articulation.h"
#include "../../grafo/LinkedList/depth/depthLinkedList.h"
#include "../../grafo/LinkedList/neighborhood/neighborhood.h"


#ifndef TP_C_LINKEDLISTMENU_H
#define TP_C_LINKEDLISTMENU_H

void menuLinked();

void caseLinked1(GrafoLinked *grafo);

void caseLinked2(GrafoLinked *grafo);

void caseLinked3(GrafoLinked *grafo);

void caseLinked4(GrafoLinked *grafo);

void caseLinked7(GrafoLinked *grafo);

void caseLinked8(GrafoLinked *grafo);

int caseLinked9(GrafoLinked *grafo, Paad *paad, int isInitGraph);

void caseLinked5(GrafoLinked *grafo);

void caseLinked6(GrafoLinked *grafo);

//int caseLinked9(GrafoLinked *grafo, Paad *matrizPaad);

#endif //TP_C_LINKEDLISTMENU_H
