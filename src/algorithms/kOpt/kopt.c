//
// Created by vitor on 4/23/21.
//

//#include

#include "kopt.h"

int initKOpt(K_opt *kOpt) {
    kOpt->reachTime = false;
    kOpt->improvements = 0;
    kOpt->end_cyclo = false;
    kOpt->block_monitor_clock = false;
    kOpt->time = 0;
}

int loader(K_opt *kOpt) {
    time_t t_start, t_end;
    time(&t_start);
    int brick = 0;
    time(&t_end);
    double duration = difftime(t_end, t_start);

    char load[totalBlocks] = {[0 ... totalBlocks - 1]=' '};
    load[0] = '[';
    load[totalBlocks - 2] = ']';
    load[totalBlocks - 1] = '\0';


    while (timeThreshold > duration) {
        if (kOpt->end_cyclo) break;
        time(&t_end);
        duration = difftime(t_end, t_start);

        brick = floor(((safeArea - 1) * duration / timeThreshold));
        load[brick + 1] = '=';

        if (kOpt->block_monitor_clock == false)
            if (!kOpt->silence_mode)
                printf("Tempo restante: %.1fs %s Improvments: %d/3  cost: %f",
                       (timeThreshold - duration), load,
                       kOpt->improvements, kOpt->hamiltonianPath.cost);
            else {
                printf("\033[%d;%dH\r\033[10CTempo restante: %.1fs %s Improvments: %d/3  cost: \033[K%f",
                       kOpt->curso_y, kOpt->curso_x,
                       (timeThreshold - duration), load,
                       kOpt->improvements, kOpt->hamiltonianPath.cost);
            }
    }

    if (timeThreshold <= duration) {
        kOpt->reachTime = true;
        kOpt->end_cyclo = true;
    }

    kOpt->time = duration;
}

void monitorHp(K_opt *kOpt) {
    if (kOpt->silence_mode) return;
    kOpt->block_monitor_clock = true;
    printf("%c[2K\r", 27);
    printf("(╯°□°）╯︵ ┻━┻ Melhora\n");
    printHalmintonSimple(&(kOpt->hamiltonianPath));
    printf("\n");
    kOpt->block_monitor_clock = false;
}

int monitorImprovements(K_opt *kOpt) {
    float hold_cost = kOpt->hamiltonianPath.cost;
    while (!kOpt->end_cyclo) {
        if (hold_cost != kOpt->hamiltonianPath.cost && !kOpt->end_cyclo) {
            monitorHp(kOpt);
            hold_cost = kOpt->hamiltonianPath.cost;
        }
        if (kOpt->improvements >= maxImproves) kOpt->end_cyclo = true;
    }
}

int *choseEdges(int len, int k_len, int shift) {
    int *nodes = (int *) malloc(k_len * sizeof(int));
    int val;
    for (int i = 0; i < k_len; i++) {
        do {
            val = (rand() % len)+shift;// A quantidade de aresta é -1 a quantidade de vertices
        } while (valueInArray(val, nodes, k_len) == 1);// Previne que haja valores repetidos
        nodes[i] = val;
    }
    return nodes;
}

int optSwap(K_opt *kOpt, const int *edges) {

    int from_node_1 = kOpt->test_hamiltonianPath.path[edges[0] + 1];
    int to_node_2 = kOpt->test_hamiltonianPath.path[edges[1]];

    for (int i = 0; i < kOpt->test_hamiltonianPath.pathLen; ++i) {
        if (kOpt->test_hamiltonianPath.path[i] == from_node_1) kOpt->test_hamiltonianPath.path[i] = to_node_2;
        else if (kOpt->test_hamiltonianPath.path[i] == to_node_2) kOpt->test_hamiltonianPath.path[i] = from_node_1;
    }

}

int kOptSwap(K_opt *kOpt) {

    int *edges;

    while (!kOpt->end_cyclo) {
        edges = choseEdges(kOpt->test_hamiltonianPath.pathLen - 1, 2, 0);
        optSwap(kOpt, edges);
        calcWeightPath(&(kOpt->test_hamiltonianPath));
        if (kOpt->test_hamiltonianPath.cost < kOpt->hamiltonianPath.cost) {
            hamiltonPathcpy(&(kOpt->hamiltonianPath), &(kOpt->test_hamiltonianPath), kOpt->test_hamiltonianPath.grafo);
            kOpt->improvements++;
        }
    }

}

void flowController(K_opt *kOpt) {
    pthread_t _loader, _kOpt, _improves;

    pthread_create(&_loader, NULL, (void *(*)(void *)) loader, kOpt);
    pthread_create(&_improves, NULL, (void *(*)(void *)) monitorImprovements, kOpt);
    pthread_create(&_kOpt, NULL, (void *(*)(void *)) kOptSwap, kOpt);


    pthread_join(_loader, NULL);
    pthread_join(_improves, NULL);
    pthread_join(_kOpt, NULL);

}

int startKOpt(HamiltonianPath *hamiltonianPath, int silence, int curso_x, int curso_y) {
    K_opt kOpt;
    initKOpt(&kOpt);
    kOpt.silence_mode = silence;
    kOpt.curso_y = curso_y;
    kOpt.curso_x = curso_x;


    if (!silence) {
        printf("Caminho atual: \n");
        printHalmintonSimple(hamiltonianPath);
        printf("\n\n");
    }

    hamiltonPathcpy(&(kOpt.test_hamiltonianPath), hamiltonianPath, hamiltonianPath->grafo);

    hamiltonPathcpy(&(kOpt.hamiltonianPath), hamiltonianPath, hamiltonianPath->grafo);

    flowController(&kOpt);

    if (kOpt.end_cyclo) {
        return printFinalResult(hamiltonianPath, &kOpt, silence);
    }
    return 0;//Houve algum error

}

int printFinalResult(HamiltonianPath *hamiltonianPath, K_opt *kOpt, int silence) {
    if (!silence) printf("\n\n\033[1;32m");
    if ((*kOpt).hamiltonianPath.cost == hamiltonianPath->cost) {
        if (!silence) {
            printf("Não houve melhoras (⌣_⌣”)\t");
            printf("\033[0;0m");
        }
        return -1;//Não Houve melhora
    } else {
        hamiltonPathcpy(hamiltonianPath, &((*kOpt).hamiltonianPath), hamiltonianPath->grafo);
        if (!silence) {
            printf("Resultado Final 2-opt:\n");
            printf("Duração: %lf  Melhoras: %d\n", (*kOpt).time, (*kOpt).improvements);
            printHalmintonSimple(&((*kOpt).hamiltonianPath));
            printf("\033[0;0m");
        }
        return 1;//Houve melhora
    }
}
