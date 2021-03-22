//
// Created by vitor on 3/14/21.
//

#include "utils.h"

void print_grafos() {
    printf("\033[1;35m"
           "      ___           ___           ___           ___           ___           ___     \n"
           "     /\\__\\         /\\  \\         /\\  \\         /\\__\\         /\\  \\         /\\__\\    \n"
           "    /:/ _/_       /::\\  \\       /::\\  \\       /:/ _/_       /::\\  \\       /:/ _/_   \n"
           "   /:/ /\\  \\     /:/\\:\\__\\     /:/\\:\\  \\     /:/ /\\__\\     /:/\\:\\  \\     /:/ /\\  \\  \n"
           "  /:/ /::\\  \\   /:/ /:/  /    /:/ /::\\  \\   /:/ /:/  /    /:/  \\:\\  \\   /:/ /::\\  \\ \n"
           " /:/__\\/\\:\\__\\ /:/_/:/__/___ /:/_/:/\\:\\__\\ /:/_/:/  /    /:/__/ \\:\\__\\ /:/_/:/\\:\\__\\\n"
           " \\:\\  \\ /:/  / \\:\\/:::::/  / \\:\\/:/  \\/__/ \\:\\/:/  /     \\:\\  \\ /:/  / \\:\\/:/ /:/  /\n"
           "  \\:\\  /:/  /   \\::/~~/~~~~   \\::/__/       \\::/__/       \\:\\  /:/  /   \\::/ /:/  / \n"
           "   \\:\\/:/  /     \\:\\~~\\        \\:\\  \\        \\:\\  \\        \\:\\/:/  /     \\/_/:/  /  \n"
           "    \\::/  /       \\:\\__\\        \\:\\__\\        \\:\\__\\        \\::/  /        /:/  /   \n"
           "     \\/__/         \\/__/         \\/__/         \\/__/         \\/__/         \\/__/"
           "\033[0m");
}

int get_int() {
    char str[255];
    scanf("%s", str);
    if (str[0] == 101) {
        return 101;
    }
    return (int) strtol(str, NULL, 10);
}



int leituraArquivo(TipoGrafo *grafo) {
    FILE *arquivo;
    stCelulaMatriz celula;
    char nomeArquivo[255];
    do {
        fflush(stdin);
#if DEBUG
        arquivo = fopen(debugFile, "rw");
        strcpy(grafo->nomeArquivo, debugFile);
#else
        printf("Entre com o nome do arquivo: ");
        scanf("%s", nomeArquivo);
        arquivo = fopen(nomeArquivo, "rw");
        strcpy(grafo->nomeArquivo, nomeArquivo);
#endif


        if (arquivo == NULL) {
            printf("\n\tArquivo invalido tente novamente.\n\n");
            return 0;
        }


        fscanf(arquivo, "%d", &grafo->numVertices);

#if DEBUG
        printf("\n\tEntrando do aloca matriz.\n\n");
#endif

        grafo->matriz = alocaMatriz(grafo->numVertices);

#if DEBUG
        printf("\n\tSaiu do aloca matriz.\n\n");
#endif

        if (grafo->matriz == NULL) {
            fclose(arquivo);
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
                grafo->numArestas++;
            } else {
                printf("--> A aresta (%d, %d) já possui o valor %f", celula.linha - 1, celula.coluna - 1,
                       grafo->matriz[celula.coluna - 1][celula.linha - 1]);
            }
        }
        fclose(arquivo);
    } while (arquivo == NULL);
    printf("\n\tArquivo lido com sucesso! \\o/ \n\n");
    return 1;
}
