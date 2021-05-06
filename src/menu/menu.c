//
// Created by vitor on 3/23/21.
//

#include "menu.h"
#include "../algorithms/TCPLIB/tcplib.h"
#include "../algorithms/cheaperInsertion/cheaperInsertion.h"

void menuLinked() {
    int opcao, hasGrafo = 0, hasHP = 0;

    int vectorTeste[3] = {6, 2, 5};


    Paad paad;
    GrafoLinked grafo;
    HamiltonianPath hamiltonianPath;

    initGrafo(&grafo);
    initPaad(&paad);

#if DEBUG
    hasGrafo = textToGrafo(&grafo);
#endif
    limpatela


    do {
        print_grafos();
        printf("\033[1;34m");
        printf("\n\n═════════════════════ Menu ══════════════════════\n");
        if (hasGrafo) {
            printf("Arquivo carregado: \033[1;35m%s\033[1;34m", grafo.nomeArquivo);
        } else {
            printf("Arquivo carregado: -");
        }
        printf("\n");
        if (hasHP == 1) {
            printf("Custo do ciclo hamiltaniano: \033[1;35m%f\033[1;34m", hamiltonianPath.cost);
        } else {
            printf("Custo do ciclo hamiltaniano: -");
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
               "║    9    ║ Leer arquivo paad                   ║\n"
               "║   10    ║ Grafo para paad                     ║\n"
               "║════════════════ Parte 2 ══════════════════════║\n"
               "║   11    ║ Vizinho mais proximo                ║\n"
               "║   12    ║ Melhoria 2-opt                      ║\n"
               "║   13    ║ Ler TCP Euclidiano                  ║\n"
               "║   14    ║ Aresta mais barata                  ║\n"
               #if DEBUG
               "║   15    ║ Imprimir Linked List                ║\n"
               #endif
               "║ e | 101 ║ Sair                                ║\n"
               "╚═════════╩═════════════════════════════════════╝\n"

        );
        printf("\033[1;36mDigite a opção desejada: \033[0m");
        opcao = get_int();
        if ((opcao > 0 && opcao <= 15 && hasGrafo) || (opcao == 0 || opcao == 101 || opcao == 9)) {
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
                    hasGrafo = caseLinked9(&grafo, &paad, hasGrafo);
                    break;
                case 10:
                    fflush(stdout);
                    linkedToPaad(&grafo, &paad);
                    paadWrite(&paad);
                    break;
                case 15:
                    fflush(stdin);
                    printGrafo(&grafo);
                    break;
                case 11:
                    fflush(stdin);
                    hasHP = nearestNeighbor(&grafo, &hamiltonianPath, 1);
                    break;
                case 12:
                    fflush(stdin);
                    if (hasHP == 1) startKOpt(&hamiltonianPath, 2);
                    else printf("Hum, me parece que vc ainda não executou o hamilton ♒((⇀‸↼))♒");
                    printf("\n");
                    break;
                case 13:
                    fflush(stdin);
                    readTCPLIB(&grafo);
                    break;
                case 14:
                    fflush(stdin);
                    cheaperInsertionAlgorithm(&grafo, &hamiltonianPath, vectorTeste);
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
    articulationLinked(grafo);
}

void caseLinked8(GrafoLinked *grafo) {
    bridgeLinked(*grafo);
}

void caseLinked5(GrafoLinked *grafo) {
    printf("\n\tPROFUNDIDADE\n\n");
    BuscaProfundidade_grafo(grafo, 0);
}

int caseLinked9(GrafoLinked *grafo, Paad *paad, int isInitGraph) {
    if (paadRead(paad)) {
        return PaadToLinked(grafo, paad, isInitGraph);
    }
    return 0;
};

void caseLinked6(GrafoLinked *grafo) {
    ECCLinked(*grafo, 1);
}



