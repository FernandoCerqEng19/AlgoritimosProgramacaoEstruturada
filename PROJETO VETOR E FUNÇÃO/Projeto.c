#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 1000
#define MAX_STRING_LENGTH 100

int ids[MAX_USERS];
char nomes[MAX_USERS][MAX_STRING_LENGTH];
char emails[MAX_USERS][MAX_STRING_LENGTH];
char sexos[MAX_USERS][MAX_STRING_LENGTH];
char enderecos[MAX_USERS][MAX_STRING_LENGTH];
double alturas[MAX_USERS];
int vacinas[MAX_USERS];

int numUsuarios = 0;

int gerarNumeroAleatorio(int min, int max) {
    return min + rand() % (max - min + 1);
}

void imprimirUsuario(int index) {
    printf("ID: %d\n", ids[index]);
    printf("Nome: %s\n", nomes[index]);
    printf("Email: %s\n", emails[index]);
    printf("Sexo: %s\n", sexos[index]);
    printf("Endereco: %s\n", enderecos[index]);
    printf("Altura: %.2f\n", alturas[index]);
    printf("Vacina: %s\n\n", (vacinas[index] == 1) ? "Sim" : "Não");
}

