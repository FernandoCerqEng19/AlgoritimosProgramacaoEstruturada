//Leia 2 valores inteiros e armazene-os nas variáveis A e B. Efetue a soma
//de A e B atribuindo o seu resultado na variável X. Imprima o resultado da seguinte
//forma “valor de A” + “valor de B” = “valor de X”.

#include<stdio.h>
#include<locale.h>

int main(){
    setlocale(LC_ALL,"Portuguese");

    int a, b, x;

    printf("Insira o valor de A: ");
    scanf("%i", &a);
    printf("\nInsira o valor de B: ");
    scanf("%i", &b);

    x = a + b;
    printf("\n\nO valor de A + B = %i", x);
}