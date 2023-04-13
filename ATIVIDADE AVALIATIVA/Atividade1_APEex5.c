#include <stdio.h>

int main()
{

    int num, div, i;
    i = 1;

    printf("Insira um numero inteiro: ");
    scanf("%d", &num);

    while (i <= num)
    {
        if (num % i == 0)
        {
            printf("\nO numero %d e divisivel por: %d", num, i);
        }
        i = i + 1;
    }
}