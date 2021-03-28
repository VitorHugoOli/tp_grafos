// https://ozh.github.io/ascii-tables/

#include "matriz.h"



void menuMatriz() {
    int opcao, hasGrafo = 0;
    GrafoMatriz grafo;
    Paad paad;
    inicializaGrafoMatriz(&grafo);
#if DEBUG
    leituraArquivo(&grafo);
    hasGrafo = 1;
#endif

    limpatela
    print_grafos();

    do {
        printf("\033[1;34m");
        printf("\n\n═════════════════════ Menu ══════════════════════\n");
        if (hasGrafo) {
            printf("Arquivo carregado: \033[1;35m%s\033[1;34m", grafo.nomeArquivo);
        } else {
            printf("Arquivo carregado: -");
        }
        printf("\n"
               "╔═════════╦═════════════════════════════════════╗\n"
               "║ Valores ║ Descrição                           ║\n"
               "║    0    ║ Carregar arquivo                    ║\n"
               "║    1    ║ Ordem do grafo                      ║\n"
               "║    2    ║ Tamanho do grafo                    ║\n"
               "║    3    ║ Vizinhos de um vértice              ║\n"
               "║    4    ║ Grau de um vértice                  ║\n"
               "║    5    ║ Busca em profundidade               ║\n"
               "║    6    ║ Componente conexas                  ║\n"
               "║    7    ║ Verificar se vértice é articulação  ║\n"
               "║    8    ║ Verificar se aresta é ponte         ║\n"
               "║    9    ║ Leer arquivo matriz                 ║\n"
               "║   10    ║ Grafo para matriz                   ║\n"
               #if DEBUG
               "║   11    ║ Imprimir Matriz                     ║\n"
               #endif
               "║ e | 101 ║ Voltar                              ║\n"
               "╚═════════╩═════════════════════════════════════╝\n"

        );
        printf("\033[1;36mDigite a opção desejada: \033[0m");
        opcao = get_int();
        if ((opcao > 0 && opcao <= 11 && hasGrafo) || (opcao == 0 || opcao == 101 || opcao == 9)) {
            switch (opcao) {
                case 0:
                    if (leituraArquivo(&grafo)) hasGrafo = 1;
                    break;
                case 1:
                    case1(&grafo);
                    break;
                case 2:
                    case2(&grafo);
                    break;
                case 3:
                    case3(&grafo);
                    break;
                case 4:
                    case4(&grafo);
                    break;
                case 5:
                    case5(&grafo);
                    break;
                case 6:
                    case6(&grafo);
                    break;
                case 7:
                    case7(&grafo);
                    break;
                case 8:
                    case8(&grafo);
                    break;
                case 9:
                    hasGrafo = case9(&grafo, &paad);
                    break;
                case 10:
                    fflush(stdout);
                    matrizToPaad(&grafo, &paad);
                    paadWrite(&paad);
                    break;
                case 11:
                    imprime(grafo);
                    break;
                case 'e':
                    printf("\n\tPrograma finalizado com sucesso!\n");
                    return;
                default:
                    printf("Opcao invalida!\n");
                    break;
            }
            congela;
            limpatela;
        } else {
            printf("\033[1;32m\n\tVoce precisa primeiramente fazer a leitura de um arquivo!\033[0;0m\n\n");
            congela;
            limpatela;
        }
    } while (opcao != 101);
}


void case1(GrafoMatriz *grafo) {
    printf("\n\tOrdem do grafo: %d\n\n", grafo->numVertices);
}

void case2(GrafoMatriz *grafo) {
    printf("\n\tTamanho do grafo: %d\n\n", grafo->numArestas);
}

void case3(GrafoMatriz *grafo) {
    int vertice;
    printf("\nEntre com o vertice que deseja saber a vizinhanca: ");
    vertice = get_int();
    if (vertice <= 0 || vertice > grafo->numVertices) {
        printf("\n\tNumero de vertice invalido!\n\n");
        return;
    }
    vizinhos(*grafo, vertice);
}

void case4(GrafoMatriz *grafo) {
    int vertice;
    printf("\nEntre com o vertice que deseja saber o grau: ");
    vertice = get_int();
    if (vertice <= 0 || vertice > grafo->numVertices) {
        printf("\n\tNumero de vertice invalido!\n\n");
        return;
    }
    printf("\n\tO grau do vertice %d eh %d.\n\n", vertice, grau(*grafo, vertice));
}

void case7(GrafoMatriz *grafo) {
    int vertice;
    printf("\nEntre com o vertice que deseja: ");
    vertice = get_int();
    if (vertice <= 0 || vertice > grafo->numVertices) {
        printf("\n\tNumero de vertice invalido!\n\n");
        return;
    }
    grafoArticulacao(*grafo, vertice);
}

void case8(GrafoMatriz *grafo) {
    printf("\nEntre com 1º vertice que deseja: ");
    vertice1 = get_int();
    printf("Entre com 2º vertice que deseja: ");
    vertice2 = get_int();
    if (vertice1 <= 0 || vertice1 > grafo->numVertices) {
        printf("\n\tNumero de vertice invalido!\n\n");
        return;
    }
    if (vertice2 <= 0 || vertice2 > grafo->numVertices) {
        printf("\n\tNumero de vertice invalido!\n\n");
        return;
    }
    if (GRAPHbridges(*grafo) == 1)
        printf("\n\tAresta %d -> %d eh uma ponte\n\n", vertice1, vertice2);
    else
        printf("\n\tAresta %d -> %d nao eh uma ponte\n\n", vertice1, vertice2);
}

void case5(GrafoMatriz *grafo) {
    printf("\n\tPROFUNDIDADE\n\n");
    PrintDepth(*grafo);
}

int case9(GrafoMatriz *grafo, Paad *paad) {
    if (paadRead(paad)) {
        return paadToMatriz(grafo, paad);
    }
    return 0;

};


void case6(GrafoMatriz *grafo) {
    int *groupConexoVertice = (int *) malloc(grafo->numVertices * sizeof(int));
    int componentes = ECC(*grafo, groupConexoVertice);
    printf("\n\tO numero de componentes conexas é %d\n", componentes);
    int i, j;
    for (j = 0; j < componentes; j++) {
        printf("\n\tVertices do componente conexo: %d ->  ", j + 1);
        for (i = 0; i < grafo->numVertices; i++)
            if (groupConexoVertice[i] == j)
                printf("%d ", i + 1);
        printf("\n");
    }
    printf("\n");
    free(groupConexoVertice);
}



