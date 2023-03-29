#include<stdio.h>

int main(){

    int num1, num2;

    printf("Insira um numero: ");
    scanf("%d", &num1);
    printf("\nInsira outro numero: ");
    scanf("%d", & num2);

    if (num1 == num2){
        printf("\nOs numeros informados sao iguais.");
    }
    else if (num2 > num1){
        printf("\nO segundo numero informado: %d, e maior que o primeiro numero informado: %d", num2, num1);
    }
    else{
        printf("\nO primeiro numero informado: %d, e maior que o segundo numero informado: %d", num1, num2);
    }
}