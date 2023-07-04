#include <stdio.h>  
#include <stdlib.h>
#include <string.h> 
#include <time.h>  

typedef struct {            
    int id;
    char nome[50];
    char email[50];
    char sexo[15];
    char endereco[100];
    double altura;
    int vacina;
} Usuario; 

int gerarID() {
    srand(time(NULL));          
    return rand() % 10000 + 1;  
}

void cadastrarUsuario(Usuario **usuarios, int *numUsuarios) {
   
    Usuario *novoUsuario = (Usuario*) malloc(sizeof(Usuario));

   
    if(novoUsuario == NULL) {
        printf("Erro ao armazenar usuário.\n");
        return;
    }
 
    novoUsuario->id = gerarID(); 
    
    printf("Nome completo: ");
    fgets(novoUsuario->nome, sizeof(novoUsuario->nome), stdin); 
    novoUsuario->nome[strcspn(novoUsuario->nome, "\n")] = '\0'; 
    
    printf("Email: ");
    fgets(novoUsuario->email, sizeof(novoUsuario->email), stdin);
    novoUsuario->email[strcspn(novoUsuario->email, "\n")] = '\0';  
    
    if(strstr(novoUsuario->email, "@") == NULL){

        do{
            printf("Email invalido. Tente novamente.\n");
            printf("\n....................\n\n");
            printf("Email: ");
            fgets(novoUsuario->email, sizeof(novoUsuario->email), stdin);
            novoUsuario->email[strcspn(novoUsuario->email, "\n")] = '\0'; 
        } while (strstr(novoUsuario->email, "@") == NULL);

    }
    
    printf("Sexo: (Feminino, Masculino ou Indiferente): ");
    fgets(novoUsuario->sexo, sizeof(novoUsuario->sexo), stdin);
    novoUsuario->sexo[strcspn(novoUsuario->sexo, "\n")] = '\0';

    if((strcmp(novoUsuario->sexo, "Feminino") != 0 && strcmp(novoUsuario->sexo, "Masculino") != 0 && strcmp(novoUsuario->sexo, "Indiferente") != 0)){
        do{
            printf("Sexo invalido. Tente novamente.\n");
            printf("\n....................\n\n");
            printf("Sexo: (Feminino, Masculino ou Indiferente): ");
            fgets(novoUsuario->sexo, sizeof(novoUsuario->sexo), stdin);
            novoUsuario->sexo[strcspn(novoUsuario->sexo, "\n")] = '\0';
            
        }while (strcmp(novoUsuario->sexo, "Feminino") != 0 && strcmp(novoUsuario->sexo, "Masculino") != 0 && strcmp(novoUsuario->sexo, "Indiferente") != 0);

    }
    
    printf("Endereco: ");
    fgets(novoUsuario->endereco, sizeof(novoUsuario->endereco), stdin);
    novoUsuario->endereco[strcspn(novoUsuario->endereco, "\n")] = '\0';
    
    printf("Altura (entre 1 e 2 metros): ");
    scanf("%lf", &novoUsuario->altura);
    getchar();

    if (novoUsuario->altura < 1 || novoUsuario->altura > 2) {
        printf("Altura invalida. Tente novamente.\n");
        return;
    }
    
    printf("Vacina (1 - Sim, 0 - Nao): ");
    scanf("%d", &novoUsuario->vacina);
    getchar();
    
    *usuarios = (Usuario*) realloc(*usuarios, (*numUsuarios + 1) * sizeof(Usuario)); 


    if (*usuarios == NULL) {
        printf("Erro ao realocar memória.\n");
        printf("\n....................\n\n");
        free(novoUsuario);
        return;
    }
    
    (*usuarios)[*numUsuarios] = *novoUsuario;
    (*numUsuarios)++;

    free(novoUsuario);
    
    printf("\nUsuario cadastrado com sucesso.\n");
    printf("\n....................\n\n");

}

void editarUsuario(Usuario *usuarios, int numUsuarios) {
    int id;

    printf("Digite o ID do usuario que deseja editar: ");
    scanf("%d", &id);
    getchar();
    
    int i;

    for (i = 0; i < numUsuarios; i++) {
        if (usuarios[i].id == id) {

            Usuario usuarioEditado = usuarios[i]; 
            
            printf("Nome completo [%s]: ", usuarioEditado.nome);
            fgets(usuarioEditado.nome, sizeof(usuarioEditado.nome), stdin);
            usuarioEditado.nome[strcspn(usuarioEditado.nome, "\n")] = '\0';
            
            printf("Email [%s]: ", usuarioEditado.email);
            fgets(usuarioEditado.email, sizeof(usuarioEditado.email), stdin);
            usuarioEditado.email[strcspn(usuarioEditado.email, "\n")] = '\0';
            
            if (strstr(usuarioEditado.email, "@") == NULL) {
                printf("Email invalido. Edição cancelada.\n");
                return;
            }
            
            printf("Sexo [%s]: ", usuarioEditado.sexo);
            fgets(usuarioEditado.sexo, sizeof(usuarioEditado.sexo), stdin);
            usuarioEditado.sexo[strcspn(usuarioEditado.sexo, "\n")] = '\0';
            
            if (strcmp(usuarioEditado.sexo, "Feminino") != 0 && strcmp(usuarioEditado.sexo, "Masculino") != 0 && strcmp(usuarioEditado.sexo, "Indiferente") != 0) {
                printf("Sexo invalido. Edição cancelada.\n");
                return;
            }
            
            printf("Endereco [%s]: ", usuarioEditado.endereco);
            fgets(usuarioEditado.endereco, sizeof(usuarioEditado.endereco), stdin);
            usuarioEditado.endereco[strcspn(usuarioEditado.endereco, "\n")] = '\0';
            
            printf("Altura (entre 1 e 2 metros) [%.2lf]: ", usuarioEditado.altura);
            scanf("%lf", &usuarioEditado.altura);
            getchar();
            
            if (usuarioEditado.altura < 1 || usuarioEditado.altura > 2) {
                printf("Altura invalida. Edição cancelada.\n");
                return;
            }
            
            printf("Vacina (1 - Sim, 0 - Nao) [%d]: ", usuarioEditado.vacina);
            scanf("%d", &usuarioEditado.vacina);
            getchar();
            
            usuarios[i] = usuarioEditado;
            
            printf("Usuario editado com sucesso.\n");
            printf("\n....................\n\n");
            return;       
        }
    }
    
    printf("usuario Nao encontrado.\n");
}

void excluirUsuario(Usuario *usuarios, int *numUsuarios) {
    int id;

    printf("Digite o ID do usuario que deseja excluir: ");
    scanf("%d", &id);
    getchar();
    
    int i, usuarioEncontrado = 0;

    for (i = 0; i < *numUsuarios; i++) {
        if (usuarios[i].id == id) {
            usuarioEncontrado = 1;
            break;
        }
    }
    
    if (usuarioEncontrado) {

        for (; i < *numUsuarios - 1; i++) {
            usuarios[i] = usuarios[i + 1];
        }
        
        (*numUsuarios)--;

        printf("Usuario excluido com sucesso.\n");
        printf("\n....................\n\n");
    } 
    
    else {
        printf("Usuario Nao encontrado.\n");
        printf("\n....................\n\n");
    }
}

void buscarUsuarioPorEmail(Usuario *usuarios, int numUsuarios) {
    char email[50];

    printf("Digite o email do usuario que deseja buscar: ");
    fgets(email, sizeof(email), stdin);
    email[strcspn(email, "\n")] = '\0';
    
    int i, usuarioEncontrado = 0;
    for (i = 0; i < numUsuarios; i++) {
        if (strcmp(usuarios[i].email, email) == 0) {
            usuarioEncontrado = 1;
            break;
        }
    }
    
    if (usuarioEncontrado) {
        printf("usuario encontrado:\n");
        printf("ID: %d\n", usuarios[i].id);
        printf("Nome: %s\n", usuarios[i].nome);
        printf("Email: %s\n", usuarios[i].email);
        printf("Sexo: %s\n", usuarios[i].sexo);
        printf("Endereco: %s\n", usuarios[i].endereco);
        printf("Altura: %.2lf\n", usuarios[i].altura);
        printf("Vacina: %s\n", usuarios[i].vacina ? "Sim" : "Nao");

        printf("\n....................\n\n");
    } 
    else {
        printf("Usuario Nao encontrado.\n");

        printf("\n....................\n\n");
    }
}

void imprimirUsuariosCadastrados(Usuario *usuarios, int numUsuarios) {
    if (numUsuarios == 0) {
        printf("Nenhum usuario cadastrado.\n");

        printf("\n....................\n\n");
    } 
    else {
        printf("Usuarios cadastrados: %d\n", numUsuarios);

        printf("\n....................\n\n");
        
        int i;
        for (i = 0; i < numUsuarios; i++) {
            printf("ID: %d\n", usuarios[i].id);
            printf("Nome: %s\n", usuarios[i].nome);
            printf("Email: %s\n", usuarios[i].email);
            printf("Sexo: %s\n", usuarios[i].sexo);
            printf("Endereco: %s\n", usuarios[i].endereco);
            printf("Altura: %.2lf\n", usuarios[i].altura);
            printf("Vacina: %s\n\n", usuarios[i].vacina ? "Sim" : "Nao");

            printf("\n....................\n\n");
        }
    }
}

void fazerBackup(Usuario *usuarios, int numUsuarios) {

    FILE *backup = fopen("backup.txt", "w"); 
    
    
    if (backup == NULL) {
        printf("Erro ao criar o arquivo de backup.\n");

        printf("\n....................\n\n");
        return;
    }
    
    int i;
    for (i = 0; i < numUsuarios; i++) {
        fprintf(backup, "%d\n", usuarios[i].id);
        fprintf(backup, "%s\n", usuarios[i].nome);
        fprintf(backup, "%s\n", usuarios[i].email);
        fprintf(backup, "%s\n", usuarios[i].sexo);
        fprintf(backup, "%s\n", usuarios[i].endereco);
        fprintf(backup, "%.2lf\n", usuarios[i].altura);
        fprintf(backup, "%d\n", usuarios[i].vacina);
    }
    
    fclose(backup); 
    
    printf("Backup realizado com sucesso.\n");

    printf("\n....................\n\n");
}

void fazerRestauracao(Usuario *usuarios, int numUsuarios) {
    FILE *backup = fopen("backup.txt", "r");

    
    if (backup == NULL) {
        printf("Arquivo de backup Nao encontrado.\n");

        printf("\n....................\n\n");
        return;
    }
    
    numUsuarios = 0;
    
    
    while (fscanf(backup, "%d\n", &usuarios[numUsuarios].id) == 1) {
        fgets(usuarios[numUsuarios].nome, sizeof(usuarios[numUsuarios].nome), backup);
        usuarios[numUsuarios].nome[strcspn(usuarios[numUsuarios].nome, "\n")] = '\0';
        
        fgets(usuarios[numUsuarios].email, sizeof(usuarios[numUsuarios].email), backup);
        usuarios[numUsuarios].email[strcspn(usuarios[numUsuarios].email, "\n")] = '\0';
        
        fgets(usuarios[numUsuarios].sexo, sizeof(usuarios[numUsuarios].sexo), backup);
        usuarios[numUsuarios].sexo[strcspn(usuarios[numUsuarios].sexo, "\n")] = '\0';
        
        fgets(usuarios[numUsuarios].endereco, sizeof(usuarios[numUsuarios].endereco), backup);
        usuarios[numUsuarios].endereco[strcspn(usuarios[numUsuarios].endereco, "\n")] = '\0';
        
        fscanf(backup, "%lf\n", &usuarios[numUsuarios].altura);
        fscanf(backup, "%d\n", &usuarios[numUsuarios].vacina);
        
        numUsuarios++;
    }
    
    fclose(backup);
    
    printf("Restauracao realizada com sucesso.\n");

    printf("\n....................\n\n");
}