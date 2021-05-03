//
// Created by vitor on 4/23/21.
//
#include "../neighborhood/neighborhood.h"


#ifndef TP_C_KOPT_H
#define TP_C_KOPT_H


typedef struct {
    int improvements;
    int reachTime;
    double time;
    int block_monitor_clock;
    int k_len;

    int end_cyclo;

    HamiltonianPath hamiltonianPath;
    HamiltonianPath test_hamiltonianPath;
} K_opt;

int startKOpt(HamiltonianPath *hamiltonianPath, int k_len);

void flowController(K_opt *kOpt);

int loader(K_opt *kOpt);

int kOptSwap(K_opt *kOpt);

int initKOpt(K_opt *kOpt);

void monitorHp(K_opt *kOpt);


#endif //TP_C_KOPT_H
