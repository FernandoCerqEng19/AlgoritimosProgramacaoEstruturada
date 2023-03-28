//Faça um algoritmo que imprima o poema abaixo, com a mesma formatação:

#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL,"Portuguese");

    printf("Caderno de poesias é um belo lugar.");
    printf("\nTantas coisas lindas que eu gostaria de falar.");
    printf("\nEu falo em forma de versos para todos poderem escutar.");
    printf("\nAgora você já sabe por que os poetas passam os dias escrevendo em seus");
    printf("\ncadernos de poesias.");
}