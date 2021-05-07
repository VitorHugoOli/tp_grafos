//
// Created by vitor on 3/23/21.
//

#include "../../../modules/paad/paad.h"

#include "../../matriz/grafoMatriz.h"

#include "../../algorithms/matrizPaad/matrizPaad.h"
#include "../../algorithms/articulacao/articulacao.h"
#include "../../algorithms/depth/depth.h"

#ifndef TP_C_MATRIZ_H
#define TP_C_MATRIZ_H


void menuMatriz();

void case1(GrafoMatriz *grafo);

void case2(GrafoMatriz *grafo);

void case3(GrafoMatriz *grafo);

void case4(GrafoMatriz *grafo);

void case7(GrafoMatriz *grafo);

void case8(GrafoMatriz *grafo);

void case5(GrafoMatriz *grafo);

void case6(GrafoMatriz *grafo);

int case9(GrafoMatriz *grafo, Paad *paad);


#endif //TP_C_MATRIZ_H
