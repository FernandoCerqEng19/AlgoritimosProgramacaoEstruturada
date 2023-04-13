#include<stdio.h>


int main(){

    char nome[40];
    float totalVendas, salarioFixo, comissao, totalMes;

    printf("Digite seu nome completo: ");
    fgets(nome, 40, stdin);
    printf("\nInsira o seu salário fixo: ");
    scanf("%f", &salarioFixo);
    printf("\nInsira o total de vendas efetuadas no mês: ");
    scanf("%f", &totalVendas);
    
    comissao = 0.15 * totalVendas;
    totalMes = comissao + salarioFixo;

    printf("\nO seu salário final é: %.2fR$", totalMes);

    return 0;
    
}