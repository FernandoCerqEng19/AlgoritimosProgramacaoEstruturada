//Faça um algoritmo que leia um numero inteiro, dois números reais (um float, com 3
//casas depois da vírgua, e um double), um caracter (uma única letra), uma string
//(conjunto de caracteres) e um endereço de memória, em hexadecimal. Na
//sequência, imprima todos com a formatação abaixo.

#include<stdio.h>
#include<locale.h>


int main(){
    setlocale(LC_ALL,"Portuguese");

    //declaração de variáveis
    int numInteiro;
    float numFloat;
    double numDouble;
    char umaLetra;
    char umaString[100];

    printf("Insira um número inteiro: ");
    scanf("%d", &numInteiro);
    printf("\nInsira um número real: ");
    scanf("%f", &numFloat);
    printf("\nInsira um outro número real: ");
    scanf("%lf", &numDouble);
    fflush(stdin); //limpa o buffer do teclado
    printf("\nInsira uma letra: ");
    scanf("%c", &umaLetra);
    fflush(stdin);
    printf("\nInsira uma string: ");
    fgets(umaString, 100, stdin);

    printf("Inteiro: %3d\n", numInteiro);
    printf("Float: %.3f\n", numFloat);
    printf("Double: %.1lf\n", numDouble);
    printf("Char: %c\n", umaLetra);
    printf("String: %s\n", umaString);
    printf("Endereco do Inteiro: %x", &numInteiro);
}
