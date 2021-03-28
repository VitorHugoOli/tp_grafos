//
// Created by vitor on 3/23/21.
//

#include "linkedlistmenu.h"

void menuLinked() {
    int opcao, hasGrafo = 0;
    GrafoLinked grafo;
    initGrafo(&grafo);
    Paad paad;

#if DEBUG
    hasGrafo = textToGrafo(&grafo);
    limpatela
#endif


    do {
        print_grafos();
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
               "║    5    ║ Busca em profundidade(Daniel)               ║\n"
               "║    6    ║ Componente conexas(Daniel)                  ║\n"
               "║    7    ║ Verificar se vértice é articulação(Daniel)  ║\n"
               "║    8    ║ Verificar se aresta é ponte(Igor & Pedro)         ║\n"
               "║    9    ║ Leer arquivo paad                   ║\n"
               "║   10    ║ Grafo para paad                     ║\n"
               #if DEBUG
               "║   11    ║ Imprimir Linked List                ║\n"
               #endif
               "║ e | 101 ║ Sair                                ║\n"
               "╚═════════╩═════════════════════════════════════╝\n"

        );
        printf("\033[1;36mDigite a opção desejada: \033[0m");
        opcao = get_int();
        if ((opcao > 0 && opcao <= 11 && hasGrafo) || (opcao == 0 || opcao == 101 || opcao == 9)) {
            switch (opcao) {
                case 0:
                    if (textToGrafo(&grafo)) hasGrafo = 1;
                    break;
                case 1:
                    caseLinked1(&grafo);
                    break;
                case 2:
                    caseLinked2(&grafo);
                    break;
                case 3:
                    caseLinked3(&grafo);
                    break;
                case 4:
                    caseLinked4(&grafo);
                    break;
                case 5:
                    caseLinked5(&grafo);
                    break;
                case 6:
                    caseLinked6(&grafo);
                    break;
                case 7:
                    caseLinked7(&grafo);
                    break;
                case 8:
                    caseLinked8(&grafo);
                    break;
                case 9:
                    hasGrafo = caseLinked9(&grafo, &paad);
                    break;
                case 10:
                    fflush(stdout);
                    linkedToPaad(&grafo, &paad);
                    paadWrite(&paad);
                    break;
                case 11:
                    fflush(stdin);
                    printGrafo(&grafo);
                    break;
                case 'e':
                    if (hasGrafo) free(grafo.list);
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


void caseLinked1(GrafoLinked *grafo) {
    printf("\n\tOrdem do grafo: %d\n\n", grafo->numVertices);
}

void caseLinked2(GrafoLinked *grafo) {
    printf("\n\tTamanho do grafo: %d\n\n", grafo->numArestas);
}

void caseLinked3(GrafoLinked *grafo) {
    vizinhosLinked(grafo);
}

void caseLinked4(GrafoLinked *grafo) {
    grauLinked(grafo);
}

void caseLinked7(GrafoLinked *grafo) {
//    int vertice;
//    printf("\nEntre com o vertice que deseja: ");
//    vertice = get_int();
//    if (vertice <= 0 || vertice > grafo->numVertices) {
//        printf("\n\tNumero de vertice invalido!\n\n");
//        return;
//    }
//    grafoArticulacao(*grafo, vertice);
}

void caseLinked8(GrafoLinked *grafo) {
//    printf("\nEntre com 1o vertice que deseja: ");
//    vertice1 = get_int();
//    printf("Entre com 2o vertice que deseja: ");
//    vertice2 = get_int();
//    if (vertice1 <= 0 || vertice1 > grafo->numVertices) {
//        printf("\n\tNumero de vertice invalido!\n\n");
//        return;
//    }
//    if (vertice2 <= 0 || vertice2 > grafo->numVertices) {
//        printf("\n\tNumero de vertice invalido!\n\n");
//        return;
//    }
//    if (GRAPHbridges(*grafo) == 1)
//        printf("\n\tAresta %d -> %d eh uma ponte\n\n", vertice1, vertice2);
//    else
//        printf("\n\tAresta %d -> %d nao eh uma ponte\n\n", vertice1, vertice2);
}

void caseLinked5(GrafoLinked *grafo) {
//    printf("\n\tPROFUNDIDADE\n\n");
//    PrintDepth(*grafo);
}

int caseLinked9(GrafoLinked *grafo, Paad *paad) {
    if (paadRead(paad)) {
        return PaadToLinked(grafo, paad);
    }
    return 0;

};


void caseLinked6(GrafoLinked *grafo) {
//    int *groupConexoVertice = (int *) malloc(grafo->numVertices * sizeof(int));
//    int componentes = ECC(*grafo, groupConexoVertice);
//    printf("\n\tO numero de componentes conexas é %d\n", componentes);
//    int i, j;
//    for (j = 0; j < componentes; j++) {
//        printf("\n\tVertices do componente conexo: %d ->  ", j + 1);
//        for (i = 0; i < grafo->numVertices; i++)
//            if (groupConexoVertice[i] == j)
//                printf("%d ", i + 1);
//        printf("\n");
//    }
//    printf("\n");
//    free(groupConexoVertice);
}



