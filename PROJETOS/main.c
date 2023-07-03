#include <stdio.h>  // biblioteca de entrada e saída de dados
#include <stdlib.h> // biblioteca que contém funções para alocação de memória
#include <string.h> // biblioteca de manipulação de strings
#include <time.h>   // biblioteca para trabalhar com srand (funções que mexem com tempo real)
#include "funcoes.h"

int main() {
    
    char opcao;
    int numUsuarios = 0;
    Usuario *usuarios = NULL;
    
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
        

        // é passado os endereços para que as alterações sejam feitas diretamente no endereço das variáveis 
        switch (opcao) {
            case '1':
                printf("\n....................\n\n");
                cadastrarUsuario(&usuarios, &numUsuarios);
                break;
            case '2':
                printf("\n....................\n\n");
                editarUsuario(&usuarios, &numUsuarios);
                break;
            case '3':
                printf("\n....................\n\n");
                excluirUsuario(usuarios, &numUsuarios);
                break;
            case '4':
                printf("\n....................\n\n");
                buscarUsuarioPorEmail(usuarios, numUsuarios);
                break;
            case '5':
                printf("\n....................\n\n");
                imprimirUsuariosCadastrados(usuarios, numUsuarios);
                break;
            case '6':
                printf("\n....................\n\n");
                fazerBackup(usuarios, numUsuarios);
                break;
            case '7':
                printf("\n....................\n\n");
                fazerRestauracao(usuarios, numUsuarios);
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
