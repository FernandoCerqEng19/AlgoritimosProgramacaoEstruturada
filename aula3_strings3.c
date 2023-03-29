#include<stdio.h> //biblioteca de entrada e saída de dados
#include<locale.h>
#include<string.h>//biblioteca para manipulação de strings

int main(){

    char nome[15], sobrenome[15];  //10 bytes alocados na memória (15 caracteres) #locação estática (endereços sequenciais)
    int a, b;

    printf("Insira o seu primeiro nome: ");
    gets(nome);
    fflush(stdin);
    printf("Insira o seu sobrenome: ");
    gets(sobrenome);

    a = strlen(nome);
    b = strlen(sobrenome);

    if (a == b)
    {
        printf("\nA quantidade de letras de seu nome e sobrenome é igual.");
    } 
    else if (a > b)
    {
        printf("\nO seu nome e maior que o seu sobrenome.");
    }
    else
    {
        printf("\nO seu sobrenome e maior que o seu nome.");
    }
    return 0;
    
    // strlen(nome); //função que retorna o tamanho da string armazenada, sem \0. o parâmetro é o nome da variável.
    

}