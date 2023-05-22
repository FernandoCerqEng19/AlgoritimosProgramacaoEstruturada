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

void incluirUsuario() {
    int id = gerarNumeroAleatorio(1000, 9999);
    ids[numUsuarios] = id;

    printf("Digite o nome completo: ");
    fgets(nomes[numUsuarios], MAX_STRING_LENGTH, stdin);
    nomes[numUsuarios][strcspn(nomes[numUsuarios], "\n")] = '\0'; // Remove o caractere de nova linha

    printf("Digite o email: ");
    fgets(emails[numUsuarios], MAX_STRING_LENGTH, stdin);
    emails[numUsuarios][strcspn(emails[numUsuarios], "\n")] = '\0';

    printf("Digite o sexo (Feminino, Masculino, Outro): ");
    fgets(sexos[numUsuarios], MAX_STRING_LENGTH, stdin);
    sexos[numUsuarios][strcspn(sexos[numUsuarios], "\n")] = '\0';

    printf("Digite o endereco: ");
    fgets(enderecos[numUsuarios], MAX_STRING_LENGTH, stdin);
    enderecos[numUsuarios][strcspn(enderecos[numUsuarios], "\n")] = '\0';

    printf("Digite a altura (entre 1 e 2 metros): ");
    scanf("%lf", &alturas[numUsuarios]);
    getchar();

    printf("Recebeu a vacina? (1 para sim, 0 para não): ");
    scanf("%d", &vacinas[numUsuarios]);
    getchar();

    numUsuarios++;

    printf("Usuario cadastrado com sucesso!\n\n");
}

