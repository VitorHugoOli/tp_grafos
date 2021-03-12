#include "readFiles.h"

//
// Created by vitor on 2/28/21.
//
int leituraArquivo(TipoGrafo *grafo) {
    FILE *arquivo;
    stCelulaMatriz celula;
    char nomeArquivo[255];
    do {
        fflush(stdin);
        printf("Entre com o nome do arquivo: ");
        scanf("%s", nomeArquivo);
        arquivo = fopen(nomeArquivo, "rw");


        if (arquivo == NULL) {
            printf("\n\tArquivo invalido tente novamente.\n\n");
            return 0;
        }


        strcpy(grafo->nomeArquivo, nomeArquivo);

        fscanf(arquivo, "%d", &grafo->numVertices);

        grafo->matriz = alocaMatriz(grafo->numVertices);
        grafo->matrizAux = alocaMatriz(grafo->numVertices);

        if (grafo->matriz == NULL) {
            printf("\n\tMemoria insuficiente.\n\n");
            return 1;
        }

        while (fscanf(arquivo, "%d %d %f", &celula.linha, &celula.coluna, &celula.peso) != EOF) {
            //INSERE DADOS NA MATRIZ
            int isEmpty = grafo->matriz[celula.linha - 1][celula.coluna - 1] == valorInicial &&
                          grafo->matriz[celula.coluna - 1][celula.linha - 1] == valorInicial;

            if (isEmpty) {
                grafo->matriz[celula.linha - 1][celula.coluna - 1] = celula.peso;
                grafo->matriz[celula.coluna - 1][celula.linha - 1] = celula.peso;
                grafo->matrizAux[celula.linha - 1][celula.coluna - 1] = celula.peso;
                grafo->matrizAux[celula.coluna - 1][celula.linha - 1] = celula.peso;
                grafo->numArestas++;
            } else {
                printf("--> A aresta (%d, %d) já possui o valor %f", celula.linha - 1, celula.coluna - 1,
                       grafo->matriz[celula.coluna - 1][celula.linha - 1]);
            }
        }
    } while (arquivo == NULL);
    printf("\n\tArquivo lido com sucesso! \\o/ \n\n");
    return 1;
}


