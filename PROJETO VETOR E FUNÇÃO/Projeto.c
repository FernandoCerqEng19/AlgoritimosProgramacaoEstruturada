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

void editarUsuario() {
    int id;
    printf("Digite o ID do usuario que deseja editar: ");
    scanf("%d", &id);
    getchar();

    int i;
    for (i = 0; i < numUsuarios; i++) {
        if (ids[i] == id) {
            printf("Digite o novo nome completo: ");
            fgets(nomes[i], MAX_STRING_LENGTH, stdin);
            nomes[i][strcspn(nomes[i], "\n")] = '\0';

            printf("Digite o novo email: ");
            fgets(emails[i], MAX_STRING_LENGTH, stdin);
            emails[i][strcspn(emails[i], "\n")] = '\0';

            printf("Digite o novo sexo (Feminino, Masculino, Outro): ");
            fgets(sexos[i], MAX_STRING_LENGTH, stdin);
            sexos[i][strcspn(sexos[i], "\n")] = '\0';

            printf("Digite o novo endereco: ");
            fgets(enderecos[i], MAX_STRING_LENGTH, stdin);
            enderecos[i][strcspn(enderecos[i], "\n")] = '\0';

            printf("Digite a nova altura (entre 1 e 2 metros): ");
            scanf("%lf", &alturas[i]);
            getchar();

            printf("Recebeu a vacina? (1 para sim, 0 para não): ");
            scanf("%d", &vacinas[i]);
            getchar();

            printf("Usuario editado com sucesso!\n\n");
            return;
        }
    }

    printf("Usuario não encontrado.\n\n");
}

void excluirUsuario() {
    int id;
    printf("Digite o ID do usuario que deseja excluir: ");
    scanf("%d", &id);
    getchar();

    int i;
    for (i = 0; i < numUsuarios; i++) {
        if (ids[i] == id) {
            int j;
            for (j = i; j < numUsuarios - 1; j++) {
                ids[j] = ids[j + 1];
                strcpy(nomes[j], nomes[j + 1]);
                strcpy(emails[j], emails[j + 1]);
                strcpy(sexos[j], sexos[j + 1]);
                strcpy(enderecos[j], enderecos[j + 1]);
                alturas[j] = alturas[j + 1];
                vacinas[j] = vacinas[j + 1];
            }

            numUsuarios--;

            printf("Usuario excluido com sucesso!\n\n");
            return;
        }
    }

    printf("Usuario não encontrado.\n\n");
}

void buscarUsuario() {
    char email[MAX_STRING_LENGTH];
    printf("Digite o email do usuario que deseja buscar: ");
    fgets(email, MAX_STRING_LENGTH, stdin);
    email[strcspn(email, "\n")] = '\0';

    int i;
    for (i = 0; i < numUsuarios; i++) {
        if (strcmp(emails[i], email) == 0) {
            printf("Usuario encontrado:\n");
            imprimirUsuario(i);
            return;
        }
    }

    printf("Usuario não encontrado.\n\n");
}

void imprimirUsuarios() {
    int i;
    printf("Lista de Usuarios:\n");
    for (i = 0; i < numUsuarios; i++) {
        imprimirUsuario(i);
    }
}

void fazerBackup() {
    FILE *arquivo;
    arquivo = fopen("backup.txt", "w");

    if (arquivo == NULL) {
        printf("Erro ao criar o arquivo de backup.\n\n");
        return;
    }

    int i;
    for (i = 0; i < numUsuarios; i++) {
        fprintf(arquivo, "%d,%s,%s,%s,%s,%.2f,%d\n", ids[i], nomes[i], emails[i], sexos[i], enderecos[i], alturas[i], vacinas[i]);
    }

    fclose(arquivo);

    printf("Backup realizado com sucesso!\n\n");
}

void restaurarDados() {
    FILE *arquivo;
    arquivo = fopen("backup.txt", "r");

    if (arquivo == NULL) {
        printf("Arquivo de backup não encontrado.\n\n");
        return;
    }

    numUsuarios = 0;
    while (!feof(arquivo) && numUsuarios < MAX_USERS) {
        fscanf(arquivo, "%d,%[^,],%[^,],%[^,],%[^,],%lf,%d\n", &ids[numUsuarios], nomes[numUsuarios], emails[numUsuarios], sexos[numUsuarios], enderecos[numUsuarios], &alturas[numUsuarios], &vacinas[numUsuarios]);
        numUsuarios++;
    }

    fclose(arquivo);

    printf("Dados restaurados com sucesso!\n\n");
}
