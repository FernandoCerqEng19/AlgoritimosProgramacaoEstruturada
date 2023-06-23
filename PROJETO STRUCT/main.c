#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"

int main() {
    
    char opcao;
    
    do {
        printf("Selecione uma opcao:\n");
        printf("1. Cadastrar usuario\n");
        printf("2. Editar usuario\n");
        printf("3. Excluir usuario\n");
        printf("4. Buscar usuario por email\n");
        printf("5. Imprimir usuarios cadastrados\n");
        printf("6. Fazer backup dos usuarios cadastrados\n");
        printf("7. Fazer restauracao dos dados\n");
        printf("0. Sair\n");
        printf("\nOpcao: ");
        
        scanf("%c", &opcao);
        getchar();
        
        switch (opcao) {
            case '1':
                printf("\n....................\n\n");
                cadastrarUsuario();
                break;
            case '2':
                printf("\n....................\n\n");
                editarUsuario();
                break;
            case '3':
                printf("\n....................\n\n");
                excluirUsuario();
                break;
            case '4':
                printf("\n....................\n\n");
                buscarUsuarioPorEmail();
                break;
            case '5':
                printf("\n....................\n\n");
                imprimirUsuariosCadastrados();
                break;
            case '6':
                printf("\n....................\n\n");
                fazerBackup();
                break;
            case '7':
                printf("\n....................\n\n");
                fazerRestauracao();
                break;
            case '0':
                printf("\n....................\n\n");
                printf("Encerrando o programa...\n");
                break;
            default:
                printf("\n....................\n\n");
                printf("Opcao invalida. Tente novamente.\n");
                break;
        }
        
        printf("\n");
    } while (opcao != '0');
    
    return 0;
}
