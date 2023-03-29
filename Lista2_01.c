#include<stdio.h>

int main(){

    int num1, num2;

    printf("Insira um numero: ");
    scanf("%d", &num1);
    printf("\nInsira outro numero: ");
    scanf("%d", & num2);

    if (num1 > num2){
        printf("\nO numero %d, e maior que o numero %d", num1, num2);
    }
    else {
        printf("\nO numero %d, e maior que o numero %d", num2, num1);
    }

    return 0;

}