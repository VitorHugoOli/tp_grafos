//
// Created by vitor on 5/7/21.
//

#include "../../tads/LinkedGrafo/linkedGrafo.h"
#include "../../algorithms/TCPLIB/tcplib.h"
#include "../../algorithms/cheaperInsertion/cheaperInsertion.h"
#include "../../algorithms/neighborhood/neighborhood.h"
#include "../../algorithms/kOpt/kopt.h"


#define ITERATIONS 30

#ifndef TP_C_ANALYTICS_H
#define TP_C_ANALYTICS_H


typedef struct {
    float results[ITERATIONS];
    HamiltonianPath best;
    HamiltonianPath worst;
} Analytic;


typedef struct {
    char instancia[100];
    Analytic analytic_nearest;
    Analytic analytic_cheaper;
} TcpAnalytic;


typedef struct {
    GrafoLinked *grafo;
    Analytic *analytic;
    int index;
    int curso_x, curso_y;

} FuncParametersAlgorithms;

typedef struct {
    char file[100];
    TcpAnalytic tcp_analytic;
    pthread_t _nearest;
    pthread_t _cheaper;
    FuncParametersAlgorithms parametersNearest;
    FuncParametersAlgorithms parametersCheaper;
} FuncParametersTcp;

int analyticMode();

int nearestKopt(FuncParametersAlgorithms *parameters);

int cheaperKopt(FuncParametersAlgorithms *parameters);

void analysisOfResults(Analytic *analytic, int index, HamiltonianPath *hp);

void printInitAnalise();

void printResultAnalytic(const Analytic *analytic);

void printResultAnalyticFile(const Analytic *analytic, FILE *arq);

void resultToFile(FuncParametersTcp *parametersTcp);


#endif //TP_C_ANALYTICS_H
