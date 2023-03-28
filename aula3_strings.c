#include<stdio.h> //biblioteca de entrada e saída de dados
#include<locale.h>
#include<string.h>//biblioteca de funções de strings

int main(){

    char sexo;      //1 byte alocado na memória (somente 1 caractere)
    char nome[15];  //10 bytes alocados na memória (10 caracteres) #locação estática (endereços sequenciais)

    printf("Insira o seu primeiro nome: ");
    gets(nome);
    fflush(stdin);
    printf("\nInsira sua sexualidade(F ou M): ");
    scanf("%c", &sexo);

    printf("\nNome: %s", nome);
    printf("\nSexualidade: %c", sexo);
    printf("\nQuantidade de caracteres: %i", strlen(nome));
    
    // strlen(nome); //função que retorna o tamanho da string armazenada, sem \0. o parâmetro é o nome da variável.
    

}