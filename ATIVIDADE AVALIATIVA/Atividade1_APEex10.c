#include <stdio.h>

int main()
{
    int num, i, media;
    media = 0;

    for (i = 1; i <= 10; i++)
    {
        printf("Insira um numero: \n");
        scanf("%d", &num);
        media = num + media;
    }
    printf("\nA soma dos numeros informados e: %d", media);
    media = media / 10;
    printf("\nA media dos numeros informados e: %d", media);
}