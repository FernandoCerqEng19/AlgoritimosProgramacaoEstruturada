#include <stdio.h>

void exibirMenu() 
{
    printf("=== MENU DE FRUTAS ===\n");
    printf("1 => ABACAXI - R$5,00 a unidade\n");
    printf("2 => MACA - R$1,00 a unidade\n");
    printf("3 => PERA - R$4,00 a unidade\n");
    printf("0 => RETORNA AO MENU\n");
    printf("NUMERO NEGATIVO - SAIR\n");
    
}
float calcularTotal(int opcao, int quantidade) 
{
    float valorTotal = 0.0;

    switch (opcao) 
    {
        case 1:
            valorTotal = quantidade * 5.0;
            break;
        case 2:
            valorTotal = quantidade * 1.0;
            break;
        case 3:
            valorTotal = quantidade * 4.0;
            break;
        default:
            printf("Opcao invalida. Tente novamente.\n");
            break;
    }

    return valorTotal;
}

int main() 
{
    int opcao, quantidade;
    float total = 0.0;

    exibirMenu();

    while (1) 
    {
        printf("\nDigite a opcao desejada: ");
        scanf("%d", &opcao);

        if (opcao < 0) 
        {
            printf("Compra finalizada.\n");
            break;
        }
        else if (opcao == 0)
        {
            exibirMenu();
            printf("\nDigite a opcao desejada: ");
            scanf("%d", &opcao);
            continue;
        }
        else 
        {
            printf("Digite a quantidade desejada: ");
            scanf("%d", &quantidade);
            float valorTotal = calcularTotal(opcao, quantidade);
            if (valorTotal > 0) 
            {
                printf("Valor da compra: R$%.2f\n", valorTotal);
                total += valorTotal;
            }
        }
    }

    printf("Valor total da compra: R$%.2f\n", total);

    return 0;
}
