#include <stdio.h> //entrada e saída de dados   
#include <stdlib.h> //manipulação de memória
#include <string.h> //manipulação de strings


#define MAX_USERS 1000          //constante que determina o máximo de usuários
#define MAX_STRING_LENGTH 100   //constante que determina o comprimento máximo de uma string

//variáveis globais
int ids[MAX_USERS]; //array
char nomes[MAX_USERS][MAX_STRING_LENGTH]; //matriz
char emails[MAX_USERS][MAX_STRING_LENGTH];  //matriz
char sexos[MAX_USERS][MAX_STRING_LENGTH];   //matriz
char enderecos[MAX_USERS][MAX_STRING_LENGTH];   //matriz
double alturas[MAX_USERS];  //array
int vacinas[MAX_USERS];     //array

int numUsuarios = 0; //variável inicializada como "0", que faz o controle do número de usuários atuais

//função que gera um número aleatório entre um minimo e um máximo
int gerarNumeroAleatorio(int min, int max) {
    return min + rand() % (max - min + 1); //função rand() que gera um número aleatório
}

//função que imprime os dados de um usuário, por ser Void, não retorna nenhum valor
void imprimirUsuario(int index) {       //o index serve para localizar o indice/registro 
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

    printf("\nDigite o nome completo: ");
    fgets(nomes[numUsuarios], MAX_STRING_LENGTH, stdin);
    nomes[numUsuarios][strcspn(nomes[numUsuarios], "\n")] = '\0'; // Remove o caractere de nova linha

    do {
        printf("\nDigite o email: ");
        fgets(emails[numUsuarios], MAX_STRING_LENGTH, stdin);
        emails[numUsuarios][strcspn(emails[numUsuarios], "\n")] = '\0';
    } while (strchr(emails[numUsuarios], '@') == NULL);

    printf("\nDigite o sexo (Feminino, Masculino, Indiferente): ");
    fgets(sexos[numUsuarios], MAX_STRING_LENGTH, stdin);
    sexos[numUsuarios][strcspn(sexos[numUsuarios], "\n")] = '\0';

    printf("\nDigite o endereco: ");
    fgets(enderecos[numUsuarios], MAX_STRING_LENGTH, stdin);
    enderecos[numUsuarios][strcspn(enderecos[numUsuarios], "\n")] = '\0';

    printf("\nDigite a altura (entre 1 e 2 metros): ");
    scanf("%lf", &alturas[numUsuarios]);
    getchar();

    printf("\nRecebeu a vacina? (1 para sim, 0 para nao): ");
    scanf("%d", &vacinas[numUsuarios]);
    getchar();

    numUsuarios++;

    printf("\nUsuario cadastrado com sucesso!\n\n");
}

void editarUsuario() {
    int id;
    printf("\nDigite o ID do usuario que deseja editar: ");
    scanf("%d", &id);
    getchar();

    int i;
    for (i = 0; i < numUsuarios; i++) {
        if (ids[i] == id) {
            printf("\nDigite o novo nome completo: ");
            fgets(nomes[i], MAX_STRING_LENGTH, stdin);
            nomes[i][strcspn(nomes[i], "\n")] = '\0';

            do {
                printf("\nDigite o novo email: ");
                fgets(emails[i], MAX_STRING_LENGTH, stdin);
                emails[i][strcspn(emails[i], "\n")] = '\0';
            } while (strchr(emails[i], '@') == NULL);  //strchr procura a primeira ocorrência do @ na string email, caso não encontre, retorna ao começo do loop, Null é um ponteiro inválido.

            printf("\nDigite o novo sexo (Feminino, Masculino, Indiferente): ");
            fgets(sexos[i], MAX_STRING_LENGTH, stdin);
            sexos[i][strcspn(sexos[i], "\n")] = '\0';

            printf("\nDigite o novo endereco: ");
            fgets(enderecos[i], MAX_STRING_LENGTH, stdin);
            enderecos[i][strcspn(enderecos[i], "\n")] = '\0';

            printf("\nDigite a nova altura (entre 1 e 2 metros): ");
            scanf("%lf", &alturas[i]);
            getchar();

            printf("\nRecebeu a vacina? (1 para sim, 0 para nao): ");
            scanf("%d", &vacinas[i]);
            getchar();

            printf("\nUsuario editado com sucesso!\n\n");
            return;
        }
    }

    printf("Usuario nao encontrado.\n\n");
}

void excluirUsuario() {
    int id;
    printf("\nDigite o ID do usuario que deseja excluir: ");
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

            printf("\nUsuario excluido com sucesso!\n\n");
            return;
        }
    }

    printf("\nUsuario nao encontrado.\n\n");
}

void buscarUsuario() {
    char email[MAX_STRING_LENGTH];
    printf("\nDigite o email do usuario que deseja buscar: ");
    fgets(email, MAX_STRING_LENGTH, stdin);
    email[strcspn(email, "\n")] = '\0'; //função para remover o caractere excessivo de "fgets"

    int i;
    for (i = 0; i < numUsuarios; i++) {
        if (strcmp(emails[i], email) == 0) {    //strcmp compara as duas strings, e retorna se o resultado for 0 (ou seja, igual)
            printf("\nUsuario encontrado:\n");
            imprimirUsuario(i);
            return;
        }
    }

    printf("\nUsuario nao encontrado.\n\n");
}

void imprimirUsuarios() {
    int i;
    printf("\nLista de Usuarios:\n");
    for (i = 0; i < numUsuarios; i++) {
        imprimirUsuario(i);
    }
}

void fazerBackup(int ids_backup[], char nomes_backup[][MAX_STRING_LENGTH], char emails_backup[][MAX_STRING_LENGTH], char sexos_backup[][MAX_STRING_LENGTH], char enderecos_backup[][MAX_STRING_LENGTH], double alturas_backup[], int vacinas_backup[]) {
    int i;
    for (i = 0; i < numUsuarios; i++) {
        ids_backup[i] = ids[i];
        strcpy(nomes_backup[i], nomes[i]);      //strcpy copia o dado para a posição de i, que irá copiar para as variáveis (arrays e matrizes) de backup
        strcpy(emails_backup[i], emails[i]);
        strcpy(sexos_backup[i], sexos[i]);
        strcpy(enderecos_backup[i], enderecos[i]);
        alturas_backup[i] = alturas[i];
        vacinas_backup[i] = vacinas[i];
    }

    printf("\nBackup realizado com sucesso!\n\n");
}

void restaurarDados(const int ids_backup[], const char nomes_backup[][MAX_STRING_LENGTH], const char emails_backup[][MAX_STRING_LENGTH], const char sexos_backup[][MAX_STRING_LENGTH], const char enderecos_backup[][MAX_STRING_LENGTH], const double alturas_backup[], const int vacinas_backup[]) {
    int i;
    for (i = 0; i < numUsuarios; i++) {
        ids[i] = ids_backup[i];
        strcpy(nomes[i], nomes_backup[i]);          //strcpy cola o dado da posição de i, para as variáveis (arrays e matrizes) de backup
        strcpy(emails[i], emails_backup[i]);
        strcpy(sexos[i], sexos_backup[i]);          
        strcpy(enderecos[i], enderecos_backup[i]);
        alturas[i] = alturas_backup[i];
        vacinas[i] = vacinas_backup[i];
    }

    printf("\nDados restaurados com sucesso!\n\n");
}