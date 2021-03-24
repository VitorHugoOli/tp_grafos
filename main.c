// https://ozh.github.io/ascii-tables/
#include "utils/utils.h"
#include "menus/matriz/matriz.h"
#include "menus/linkedList/linkedlistmenu.h"

int main() {
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


