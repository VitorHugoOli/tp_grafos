//
// Created by vitor on 4/28/21.
//

#include "tcplib.h"

int readTCPLIB(GrafoLinked *grafo) {
    FILE *arquivo;
    char reader[100];
    int index;
    double x;
    double y;
    int count;
    arquivo = readFiles(grafo);
    TcpEuc *tcp;

    if (arquivo == NULL) return 0;

    do fscanf(arquivo, "%s", reader);
    while (strcmp(reader, "DIMENSION:") != 0);

    fscanf(arquivo, "%d", &(grafo->numVertices));
    tcp = (TcpEuc *) malloc(grafo->numVertices * sizeof(TcpEuc));
    grafo->list = createLinkedList(grafo->numVertices);


    do fscanf(arquivo, "%s", reader);
    while (strcmp(reader, "NODE_COORD_SECTION") != 0);

    count = 0;
    while (fscanf(arquivo, "%d %lf %lf", &index, &x, &y) != 0) {
        tcp[count].node = index;
        tcp[count].x = x;
        tcp[count].y = y;
        count++;
    }


    for (int i = 0; i < grafo->numVertices; ++i)
        for (int j = i + 1; j < grafo->numVertices; ++j) {
            addAresta(&(grafo->list[i]), j+1, eucCalWeight(&tcp[i], &tcp[j]));
            addAresta(&(grafo->list[j]), i+1, eucCalWeight(&tcp[j], &tcp[i]));
        }
    return 1;
}


int nint(double x) {
    return (int) (x + 0.5);
}

float eucCalWeight(TcpEuc *to, TcpEuc *from) {
    double xd = to->x - from->x;
    double yd = to->y - from->y;
    return (float) nint(sqrt((pow(xd, 2.0) + pow(yd, 2))));
}

