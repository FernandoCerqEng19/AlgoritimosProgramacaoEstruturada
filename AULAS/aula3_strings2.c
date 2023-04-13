#include<stdio.h> //biblioteca de entrada e saída de dados
#include<locale.h>
#include<string.h>//biblioteca para manipulação de strings

int main(){

    char nome[15], sobrenome[15];  //10 bytes alocados na memória (15 caracteres) #locação estática (endereços sequenciais)
    int quantidadeCaracteres; //quantidade de caracteres

    printf("Insira o seu primeiro nome: ");
    gets(nome);
    fflush(stdin);
    printf("Insira o seu sobrenome: ");
    gets(sobrenome);

    quantidadeCaracteres = (strlen(nome) + strlen(sobrenome));
    printf("\nNome: %s %s", nome, sobrenome);
    printf("\nQuantidade de caracteres: %i", quantidadeCaracteres);
    
    // strlen(nome); //função que retorna o tamanho da string armazenada, sem \0. o parâmetro é o nome da variável.
    

}