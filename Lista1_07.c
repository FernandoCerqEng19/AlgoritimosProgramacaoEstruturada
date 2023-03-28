#include<stdio.h>

int main(){

    int valor1, valor2, prod;

    printf("Insira um valor: ");
    scanf("%d", &valor1);
    printf("\nInsira um outro valor: ");
    scanf("%d", &valor2);

    prod = (valor1 * valor2);
    printf("\nPROD = %d", prod);

    return 0;
}