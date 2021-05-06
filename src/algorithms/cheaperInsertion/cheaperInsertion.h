//
// Created by vitor on 5/4/21.
//

#include "../../tads/HamiltonianPath/hamiltonianPath.h"
#include "ListNodes/ListNodes.h"


#ifndef TP_C_CHEAPERINSERTION_H
#define TP_C_CHEAPERINSERTION_H


typedef struct {
    float *costs;

    ListNodes selectNodes;
    ListNodes notSelectNodes;
} cheaperInsertion;


typedef struct {
    int i, k, j;
    float cost;
} CheaperResult;

void initCheaperInsertion(cheaperInsertion *cp, int numb_nodes);

CheaperResult *initCheaperResult();

int cheaperInsertionAlgorithm(GrafoLinked *grafo, HamiltonianPath *hp, const int *initPath);

cheaperInsertion
initVariableCheaperInsertion(HamiltonianPath *hp, const int *initPath, cheaperInsertion *cp);

void execCheaperInsertion(HamiltonianPath *hp, cheaperInsertion *cp);

void translateCpToHp(HamiltonianPath *hp, cheaperInsertion *cp);

#endif //TP_C_CHEAPERINSERTION_H
