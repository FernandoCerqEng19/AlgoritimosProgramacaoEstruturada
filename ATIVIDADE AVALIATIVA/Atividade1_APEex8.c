#include <stdio.h>

int main()
{
    int num, maiorNumero, menorNumero;
    num = 0;
    
    printf("Insira um numero:\n");
    scanf("%d", &num);
    maiorNumero = num;
    menorNumero = num;
    
    while (num >= 0)
    {
        printf("Insira um numero:\n");
        scanf("%d", &num);
        
        if (num > maiorNumero)
        {
            maiorNumero = num;
        }
        else if ((num < menorNumero) & (num > 0))
        {
            menorNumero = num;
        }
    }

    printf("O maior numero informado e: %d\n", maiorNumero);
    printf("O menor numero informado e: %d\n", menorNumero);

}

