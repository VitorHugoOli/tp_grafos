//
// Created by vitor on 4/23/21.
//
#include "../neighborhood/neighborhood.h"

#define timeThreshold 180
#define safeArea 30
#define totalBlocks (safeArea+3)
#define maxImproves 3


#ifndef TP_C_KOPT_H
#define TP_C_KOPT_H


typedef struct {
    int improvements;
    int reachTime;
    double time;
    int block_monitor_clock;

    int end_cyclo;

    int silence_mode;
    int curso_x,curso_y;

    HamiltonianPath hamiltonianPath;
    HamiltonianPath test_hamiltonianPath;
} K_opt;

int startKOpt(HamiltonianPath *hamiltonianPath, int silence, int curso_x, int curso_y);

void flowController(K_opt *kOpt);

int loader(K_opt *kOpt);

int kOptSwap(K_opt *kOpt);

int initKOpt(K_opt *kOpt);

void monitorHp(K_opt *kOpt);

int *choseEdges(int len, int k_len, int shift);

int printFinalResult(HamiltonianPath *hamiltonianPath, K_opt *kOpt, int silence);


#endif //TP_C_KOPT_H
