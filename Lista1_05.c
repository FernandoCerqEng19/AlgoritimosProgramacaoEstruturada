//Faça o mesmo exercício só que realizando o calculo dentro do printf

#include<stdio.h>
#include<locale.h>

int main(){
    setlocale(LC_ALL,"Portuguese");

    int a, b, x;

    printf("Insira o valor de A: ");
    scanf("%i", &a);
    printf("\nInsira o valor de B: ");
    scanf("%i", &b);
    x= a+b;
    printf("%i + %i = %i",a,b,x);

    return 0;
}