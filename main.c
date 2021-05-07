// https://ozh.github.io/ascii-tables/

#include "src/menu/menu.h"
#include "src/matriz/menus/matriz/matriz.h"
#include "src/modules/analytics/analytics.h"

int main() {

    srand(time(NULL));
    limpatela
    int chose = 0;
    while (chose != 101) {
        print_grafos();
        printf("\033[1;34m");
        printf("\n"
               "╔═══════╦═══════════════════╗\n"
               "║ Opção ║ Descrição         ║\n"
               "║   0   ║ Matriz            ║\n"
               "║   1   ║ Linked List       ║\n"
               "║ e|101 ║ Finalizar Progama ║\n"
               "╚═══════╩═══════════════════╝\n"
               "\n");

        if ((chose < 0 || chose > 1) && chose != 101) {
            printf("\033[1;33mEntrada invalida! \033[0m \n");
        }

        printf("\033[1;36mDigite a opção desejada: \033[0m");
        chose = get_int();

        switch (chose) {
            case 0:
                limpatela
                menuMatriz();
                break;
            case 1:
                menuLinked();
                limpatela
                break;
            case 'e':
                printf("\nPrograma finalizado com sucesso!\n");
                exit(0);
            default:
                limpatela;
        }
    };
    return 0;

}


