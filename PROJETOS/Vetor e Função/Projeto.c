#include <stdio.h> //entrada e saída de dados   
#include <stdlib.h> //manipulação de memória
#include <string.h> //manipulação de strings
#include "funcoes.h"

int main() {
    srand(time(NULL)); //função que inicia o gerador de números aleatórios, de maneira que ele não repita nenhum número

    char opcao;
    int ids_backup[MAX_USERS];
    char nomes_backup[MAX_USERS][MAX_STRING_LENGTH];
    char emails_backup[MAX_USERS][MAX_STRING_LENGTH];
    char sexos_backup[MAX_USERS][MAX_STRING_LENGTH];
    char enderecos_backup[MAX_USERS][MAX_STRING_LENGTH];
    double alturas_backup[MAX_USERS];
    int vacinas_backup[MAX_USERS];
    int numUsuarios_backup = 0;

    do {
        printf("Selecione uma opcao:\n");
        printf("1. Incluir usuario\n");
        printf("2. Editar usuario\n");
        printf("3. Excluir usuario\n");
        printf("4. Buscar usuario pelo email\n");
        printf("5. Imprimir todos os usuarios cadastrados\n");
        printf("6. Fazer backup dos usuarios cadastrados\n");
        printf("7. Restaurar dados\n");
        printf("0. Sair\n");
        printf("\nOpcao: ");
        scanf("%c", &opcao);
        getchar();  //limpar o buffer

        switch (opcao) {
            case '1':
                incluirUsuario();
                break;
            case '2':
                editarUsuario();
                break;
            case '3':
                excluirUsuario();
                break;
            case '4':
                buscarUsuario();
                break;
            case '5':
                imprimirUsuarios();
                break;
            case '6':
                fazerBackup(ids_backup, nomes_backup, emails_backup, sexos_backup, enderecos_backup, alturas_backup, vacinas_backup);
                numUsuarios_backup = numUsuarios;
                break;
            case '7':
                if (numUsuarios_backup > 0) {
                    restaurarDados(ids_backup, nomes_backup, emails_backup, sexos_backup, enderecos_backup, alturas_backup, vacinas_backup);
                    numUsuarios = numUsuarios_backup;
                } else {
                    printf("\nNao ha dados de backup disponiveis.\n\n");
                }
                break;
            case '0':
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opcao invalida. Por favor, tente novamente.\n");
                break;
        }
    } while (opcao != '0'); //se a resposta for 0 ele encerra o programa

    return 0;
}
