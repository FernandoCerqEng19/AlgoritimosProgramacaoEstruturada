#include<stdio.h>
#include<locale.h>

int main(){

    int a,b,c,d;
    int diferenca;

    printf("\nInsira o valor de A (deve ser inteiro): ");
    scanf("%d", &a);
    printf("\nInsira o valor de B (deve ser inteiro): ");
    scanf("%d", &b);
    printf("\nInsira o valor de C (deve ser inteiro): ");
    scanf("%d", &c);
    printf("\nInsira o valor de D (deve ser inteiro): ");
    scanf("%d", &d);

    diferenca = ((a * b) - (c * d));
    
    printf("\nDiferenca de: %d x %d - %d x %d",a,b,c,d);
    printf("\nDiferenca = %d", diferenca);
}