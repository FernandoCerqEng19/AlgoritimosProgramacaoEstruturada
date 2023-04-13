#include <stdio.h>

int main()
{
    int a, b, c, d;
    int diferenca;


    printf("Insira o valor de A, B, C e D respectivamente: \n");
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);
    scanf("%d", &d);
    diferenca = ((a * b) - (c * d));
    printf("\nDiferenca = %d * %d - %d * %d", a, b, c, d);
    printf("\nDiferenca = %d", diferenca);
}