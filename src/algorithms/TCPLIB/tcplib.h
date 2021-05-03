//
// Created by vitor on 4/28/21.
//

#include "../../tads/LinkedGrafo/linkedGrafo.h"


#ifndef TP_C_TCPLIB_H
#define TP_C_TCPLIB_H

typedef struct {
    int node;
    double x;
    double y;
} TcpEuc;


int readTCPLIB(GrafoLinked *grafo);
float eucCalWeight(TcpEuc *to, TcpEuc *from);

#endif //TP_C_TCPLIB_H
