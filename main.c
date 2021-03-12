// https://ozh.github.io/ascii-tables/
#include "files/readFiles.h"
#include "utils/utils.h"


void menu();


void case1(TipoGrafo *grafo);

void case2(TipoGrafo *grafo);

void case3(TipoGrafo *grafo);

void case4(TipoGrafo *grafo);


void case7(TipoGrafo *grafo);

void case8(TipoGrafo *grafo);

void case5(TipoGrafo *grafo);


void case6(TipoGrafo *grafo);


int main() {
    print_grafos();

    menu();
    return 0;
}

void menu() {
    int opcao, hasGrafo = 0;
    TipoGrafo grafo;
    inicializaMatriz(&grafo);
#if DEBUG
    leituraArquivo(&grafo);
    hasGrafo = 1;
    limpatela
#endif

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
               #if DEBUG
               "║    9    ║ Imprimir Matriz                     ║\n"
               #endif
               "║ e | 101 ║ Sair                                ║\n"
               "╚═════════╩═════════════════════════════════════╝\n"

        );
        printf("\033[1;36mDigite a opção desejada: \033[0m");
        opcao = get_int();
        if ((opcao > 0 && opcao <= 17 && hasGrafo) || (opcao == 0 || opcao == 101)) {
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


void case1(TipoGrafo *grafo) {
    printf("\n\tOrdem do grafo: %d\n\n", grafo->numVertices);
}

void case2(TipoGrafo *grafo) {
    printf("\n\tTamanho do grafo: %d\n\n", grafo->numArestas);
}

void case3(TipoGrafo *grafo) {
    int vertice;
    printf("\nEntre com o vertice que deseja saber a vizinhanca: ");
    vertice = get_int();
    if (vertice <= 0 || vertice > grafo->numVertices) {
        printf("\n\tNumero de vertice invalido!\n\n");
        return;
    }
    vizinhos(*grafo, vertice);
}

void case4(TipoGrafo *grafo) {
    int vertice;
    printf("\nEntre com o vertice que deseja saber o grau: ");
    vertice = get_int();
    if (vertice <= 0 || vertice > grafo->numVertices) {
        printf("\n\tNumero de vertice invalido!\n\n");
        return;
    }
    printf("\n\tO grau do vertice %d eh %d.\n\n", vertice, grau(*grafo, vertice));
}


void case7(TipoGrafo *grafo) {
    int vertice;
    printf("\nEntre com o vertice que deseja: ");
    vertice = get_int();
    if (vertice <= 0 || vertice > grafo->numVertices) {
        printf("\n\tNumero de vertice invalido!\n\n");
        return;
    }
    grafoArticulacao(*grafo, vertice);
}

void case8(TipoGrafo *grafo) {
    printf("\nEntre com 1o vertice que deseja: ");
    vertice1 = get_int();
    printf("Entre com 2o vertice que deseja: ");
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

void case5(TipoGrafo *grafo) {
    printf("\n\tPROFUNDIDADE\n\n");
    PrintDepth(*grafo);
}


void case6(TipoGrafo *grafo) {
    int componentes = GRAPHcc(*grafo);
    printf("\n\tO numero de componentes conexas eh %d\n\n", componentes);
    int i, j;
    for (j = 0; j < componentes; j++) {
        printf("\n\tVertices da componente %d\n", j + 1);
        for (i = 0; i < grafo->numVertices; i++)
            if (pre[i] == j)
                printf("%d ", i + 1);
        printf("\n");
    }
    printf("\n");
}


