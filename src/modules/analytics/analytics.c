//
// Created by vitor on 5/7/21.
//

#include "analytics.h"


char *matchNames(char *name) {
    if (strcmp(name, d198) == 0) return "d198";
    else if (strcmp(name, ch130) == 0) return "ch130";
    else if (strcmp(name, berlin52) == 0) return "berlin52";
    else return "404";
}

void bodyAnalytics(FuncParametersTcp *parametersTcp);


void analysisOfResults(Analytic *analytic, int index, HamiltonianPath *hp) {
    analytic->results[index] = hp->cost;
    if (hp->cost < analytic->best.cost || analytic->best.cost == 0) {
        free(analytic->best.path);
        free(analytic->best.costVector);
        hamiltonPathcpy(&(analytic->best), hp, hp->grafo);
    }
    if (hp->cost > analytic->worst.cost || analytic->worst.cost == 0) {
        free(analytic->worst.path);
        free(analytic->worst.costVector);
        hamiltonPathcpy(&(analytic->worst), hp, hp->grafo);
    }
}


int analyticMode() {
    limpatela;
    printInitAnalise();
    char files[3][100] = {berlin52, ch130, d198};
    pthread_t _berlin, _ch, _d;

    FuncParametersTcp berlin, ch, d;

    strcpy(berlin.file, berlin52);
    berlin.parametersCheaper.curso_x = 1;
    berlin.parametersCheaper.curso_y = 17;

    berlin.parametersNearest.curso_x = 1;
    berlin.parametersNearest.curso_y = 17 + 1;
    strcpy(ch.file, ch130);
    ch.parametersCheaper.curso_x = 1;
    ch.parametersCheaper.curso_y = 23;

    ch.parametersNearest.curso_x = 1;
    ch.parametersNearest.curso_y = 23 + 1;
    strcpy(d.file, d198);
    d.parametersCheaper.curso_x = 1;
    d.parametersCheaper.curso_y = 30;

    d.parametersNearest.curso_x = 1;
    d.parametersNearest.curso_y = 30 + 1;


    pthread_create(&_berlin, NULL, (void *(*)(void *)) bodyAnalytics, &berlin);
    pthread_create(&_ch, NULL, (void *(*)(void *)) bodyAnalytics, &ch);
    pthread_create(&_d, NULL, (void *(*)(void *)) bodyAnalytics, &d);


    pthread_join(_berlin, NULL);
    pthread_join(_ch, NULL);
    pthread_join(_d, NULL);


    resultToFile(&berlin);
    resultToFile(&ch);
    resultToFile(&d);

}

void resultToFile(FuncParametersTcp *parametersTcp) {
    FILE *arquivo;
    char nomeDest[255] = {'\0'};
    strcat(nomeDest, matchNames(parametersTcp->file));
    strcat(nomeDest, ".txt");

    printf("\n%s\n", nomeDest);
    arquivo = fopen(nomeDest, "w");

    if (arquivo == NULL) {
        printf("\n\tArquivo invalido tente novamente.\n\n");
    }

    fprintf(arquivo, "RESULTADOS %s:\n\n", matchNames(parametersTcp->file));
    fprintf(arquivo, "%s", "Resultados Cheaper: \n");
    printResultAnalyticFile(&(parametersTcp->tcp_analytic.analytic_cheaper), arquivo);
    fprintf(arquivo, "\n");

    fprintf(arquivo, "%s", "Resultados Nearest: \n");
    printResultAnalyticFile(&(parametersTcp->tcp_analytic.analytic_nearest), arquivo);
    fprintf(arquivo, "\n");
    fclose(arquivo);
}


void bodyAnalytics(FuncParametersTcp *parametersTcp) {
    GrafoLinked *grafo = (GrafoLinked *) malloc(sizeof(GrafoLinked));
    initGrafo(grafo);
    if (readTCPLIB(grafo, parametersTcp->file, 0))
        printf("\033[%d;%dH\033[1;34m• Leituara do %s realizada com sucesso\033[0;0m\n\n",
               parametersTcp->parametersCheaper.curso_y - 2, 1, matchNames(parametersTcp->file));


    strcpy(parametersTcp->tcp_analytic.instancia, matchNames(parametersTcp->file));
    initHamiltonianPath(grafo, &(parametersTcp->tcp_analytic.analytic_nearest.best));
    initHamiltonianPath(grafo, &(parametersTcp->tcp_analytic.analytic_nearest.worst));
    initHamiltonianPath(grafo, &(parametersTcp->tcp_analytic.analytic_cheaper.best));
    initHamiltonianPath(grafo, &(parametersTcp->tcp_analytic.analytic_cheaper.worst));


    parametersTcp->parametersNearest.grafo = grafo;
    parametersTcp->parametersNearest.analytic = &(parametersTcp->tcp_analytic.analytic_nearest);
    parametersTcp->parametersNearest.index = 0;

    parametersTcp->parametersCheaper.grafo = grafo;
    parametersTcp->parametersCheaper.analytic = &(parametersTcp->tcp_analytic.analytic_cheaper);
    parametersTcp->parametersCheaper.index = 0;


    for (int j = 0; j < ITERATIONS; ++j) {
        parametersTcp->parametersNearest.index = j;
        parametersTcp->parametersCheaper.index = j;

        printf("\033[%d;%dH\r\033[1;35m %d / %d\033[0;0m ", parametersTcp->parametersCheaper.curso_y - 1, 1, j + 1,ITERATIONS);
        pthread_create(&(parametersTcp->_nearest), NULL, (void *(*)(void *)) nearestKopt,
                       &(parametersTcp->parametersNearest));
        pthread_create(&(parametersTcp->_cheaper), NULL, (void *(*)(void *)) cheaperKopt,
                       &(parametersTcp->parametersCheaper));

        pthread_join(parametersTcp->_nearest, NULL);
        pthread_join(parametersTcp->_cheaper, NULL);
    }
}

void printResultAnalytic(const Analytic *analytic) {
    printf("Melhor custo : %f\n", analytic->best.cost);
    printf("Pior custo : %f\n", analytic->worst.cost);
    float sumMedia = 0;
    for (int j = 0; j < ITERATIONS; ++j) {
        sumMedia += analytic->results[j];
    }
    float media = sumMedia / ITERATIONS;
    printf("Media: %f\n", media);

    double desvio;
    for (int j = 0; j < ITERATIONS; ++j) {
        desvio += pow((analytic->results[j] - media), 2);
    }
    printf("Desvio: %lf\n", sqrt((desvio / ITERATIONS)));
}

void printResultAnalyticFile(const Analytic *analytic, FILE *arq) {
    fprintf(arq, "Melhor custo : %f\n", analytic->best.cost);
    fprintf(arq, "Pior custo : %f\n", analytic->worst.cost);
    float sumMedia = 0;
    for (int j = 0; j < ITERATIONS; ++j) {
        sumMedia += analytic->results[j];
    }
    float media = sumMedia / ITERATIONS;
    fprintf(arq, "Media: %f\n", media);

    double desvio;
    for (int j = 0; j < ITERATIONS; ++j) {
        desvio += pow((analytic->results[j] - media), 2);
    }
    fprintf(arq, "Desvio: %lf\n", sqrt((desvio / ITERATIONS)));
}

void printInitAnalise() {
    printf("\n\n"
           "                     __              ______                    ___                          \n"
           " /'\\_/`\\            /\\ \\            /\\  _  \\                  /\\_ \\    __                   \n"
           "/\\      \\    ___    \\_\\ \\    ___    \\ \\ \\L\\ \\    ___      __  \\//\\ \\  /\\_\\    ____     __   \n"
           "\\ \\ \\__\\ \\  / __`\\  /'_` \\  / __`\\   \\ \\  __ \\ /' _ `\\  /'__`\\  \\ \\ \\ \\/\\ \\  /',__\\  /'__`\\ \n"
           " \\ \\ \\_/\\ \\/\\ \\L\\ \\/\\ \\L\\ \\/\\ \\L\\ \\   \\ \\ \\/\\ \\/\\ \\/\\ \\/\\ \\L\\.\\_ \\_\\ \\_\\ \\ \\/\\__, `\\/\\  __/ \n"
           "  \\ \\_\\\\ \\_\\ \\____/\\ \\___,_\\ \\____/    \\ \\_\\ \\_\\ \\_\\ \\_\\ \\__/.\\_\\/\\____\\\\ \\_\\/\\____/\\ \\____\\\n"
           "   \\/_/ \\/_/\\/___/  \\/__,_ /\\/___/      \\/_/\\/_/\\/_/\\/_/\\/__/\\/_/\\/____/ \\/_/\\/___/  \\/____/"
           "\n\n");
    printf("\nPrepare-se para 9hrs de execução!\n\n");

}

int cheaperKopt(FuncParametersAlgorithms *parameters) {
    HamiltonianPath *hp = (HamiltonianPath *) malloc(sizeof(HamiltonianPath));
    cheaperInsertionAlgorithm(parameters->grafo, hp, choseEdges(parameters->grafo->numVertices, 3,1), 1);
    startKOpt(hp, 1, parameters->curso_x, parameters->curso_y);

    analysisOfResults(parameters->analytic, parameters->index, hp);

    return 1;
}


int nearestKopt(FuncParametersAlgorithms *parameters) {

    HamiltonianPath *hp = (HamiltonianPath *) malloc(sizeof(HamiltonianPath));
    nearestNeighbor(parameters->grafo, hp, choseEdges(parameters->grafo->numVertices,2, 1)[0], 1);
    startKOpt(hp, 1, parameters->curso_x, parameters->curso_y);

    analysisOfResults(parameters->analytic, parameters->index, hp);

    return 1;
}
