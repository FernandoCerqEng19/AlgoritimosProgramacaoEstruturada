//Calculadora que soma os números naturais multiplos de 3 e 5 até o valor de 1000

#include <stdio.h>

int main()
{
    int num, soma;
    soma = 0;
    num = 1;

    while (num <= 1000)
    {
        if (num % 3 == 0)
        {
            soma = num + soma;
            printf("%d\n", soma);
        }
        else if (num % 5 == 0)
        {
            soma = num + soma;
            printf("%d\n", soma);
        }
        num = num + 1;
    }

}