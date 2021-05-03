//
// Created by vitor on 3/23/21.
//



#ifndef TP_C_LINKEDLISTMENU_H
#define TP_C_LINKEDLISTMENU_H

#include "../modules/utils/utils.h"

#include "../tads/LinkedGrafo/linkedGrafo.h"
#include "../modules/paad/paad.h"
#include "../algorithms/neighborhood/neighborhood.h"
#include "../algorithms/linkedPaad/linkedPaad.h"
#include "../algorithms/kOpt/kopt.h"
#include "../algorithms/articulation/articulation.h"
#include "../algorithms/bridge/bridge.h"
#include "../algorithms/depth/depthLinkedList.h"



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
