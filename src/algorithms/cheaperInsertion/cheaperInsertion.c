//
// Created by vitor on 5/4/21.
//

#include "cheaperInsertion.h"


int cheaperInsertionAlgorithm(GrafoLinked *grafo, HamiltonianPath *hp, const int *initPath) {
    cheaperInsertion cp;
    initHamiltonianPath(grafo, hp);
    initCheaperInsertion(&cp, grafo->numVertices);

    startMeasure;
    cp = initVariableCheaperInsertion(hp, initPath, &cp);
    execCheaperInsertion(hp, &cp);
    endMeasure;


    translateCpToHp(hp, &cp);

    printHalminton(hp);
    return 1;
}

void translateCpToHp(HamiltonianPath *hp, cheaperInsertion *cp) {
    ListNodes *aux = &(cp->selectNodes);
    int count = 0;
    float sum = 0;
    while (aux != NULL) {
        hp->path[count] = aux->node;
        hp->costVector[count] = aux->cost;
        sum += aux->cost;
        count++;
        aux = aux->next;
    }
    hp->path[hp->pathLen - 1] = cp->selectNodes.node;
    hp->cost = sum;
}

/*
 * Funçoes interna
 */

void initCheaperInsertion(cheaperInsertion *cp, int numb_nodes) {
    startListNodes(&cp->selectNodes);
    startListNodes(&cp->notSelectNodes);
    cp->selectNodes.index = -1;
    cp->notSelectNodes.index = -1;

    cp->costs = (float *) malloc(numb_nodes * sizeof(float));
    for (int i = 0; i < numb_nodes; ++i) cp->costs[i] = -1;
}

cheaperInsertion initVariableCheaperInsertion(HamiltonianPath *hp, const int *initPath, cheaperInsertion *cp) {
    ListNodes *new;

    for (int v = 0; v < hp->grafo->numVertices; ++v) {
        new = initListNodes();
        new->node = v + 1;
        add(&(*cp).notSelectNodes, new);
    };

    for (int v = 0; v < 3; ++v) {
        new = initListNodes();
        new->node = initPath[v];
        new->cost = weightEdge(hp->grafo, initPath[v % 3], initPath[(v + 1) % 3]);
        add(&(*cp).selectNodes, new);
        removeNode(&(*cp).notSelectNodes, initPath[v]);
    }
    return (*cp);
}

CheaperResult *initCheaperResult() {
    CheaperResult *cr;
    cr = (CheaperResult *) malloc(sizeof(CheaperResult));
    cr->cost = -1;
    cr->k = 0;
    cr->j = 0;
    cr->i = 0;
    return cr;
}

void execCheaperInsertion(HamiltonianPath *hp, cheaperInsertion *cp) {
    while (lenList(&cp->selectNodes) != hp->grafo->numVertices) {
        CheaperResult *cheaperResult;
        cheaperResult = initCheaperResult();

        searchNextEdge(hp, cp, cheaperResult);
        reorderPath(hp, cp, cheaperResult);
    }
}

void searchNextEdge(HamiltonianPath *hp, cheaperInsertion *cp, CheaperResult *cheaperResult) {
    int i, k, j;
    float ik = 0, kj = 0, ij = 0;
    float result = 0;

    int selectNodesList_len = lenList(&(*cp).selectNodes);
    int notSelectNodesList_len = lenList(&(*cp).notSelectNodes);
    int total = (selectNodesList_len * notSelectNodesList_len);

    for (int v = 0; v < total; v++) {
        i = retrieveAt(&(*cp).selectNodes, (int) (v / notSelectNodesList_len))->node;
        k = retrieveAt(&(*cp).notSelectNodes, (v % notSelectNodesList_len))->node;
        j = retrieveAt(&(*cp).selectNodes,
                       (int) (((v + notSelectNodesList_len) % total) / (notSelectNodesList_len)))->node;

        ik = weightEdge(hp->grafo, i, k);
        kj = weightEdge(hp->grafo, k, j);
        ij = weightEdge(hp->grafo, i, j);

        result = (ik + kj - ij);

        if ((*cheaperResult).cost > result || (*cheaperResult).cost == -1) {
            (*cheaperResult).cost = result;
            (*cheaperResult).i = i;
            (*cheaperResult).j = j;
            (*cheaperResult).k = k;
        }
    }
}

void reorderPath(HamiltonianPath *hp, cheaperInsertion *cp, CheaperResult *cheaperResult) {
    ListNodes *new;
    new = initListNodes();

    ListNodes *i_element = retrieve(&(*cp).selectNodes, (*cheaperResult).i);
    i_element->cost = weightEdge(hp->grafo, (*cheaperResult).i, (*cheaperResult).k);

    new->node = (*cheaperResult).k;
    new->cost = weightEdge(hp->grafo, (*cheaperResult).k, (*cheaperResult).j);

    addAt(&(*cp).selectNodes, new, (i_element->index + 1));

    removeNode(&(*cp).notSelectNodes, (*cheaperResult).k);
}



