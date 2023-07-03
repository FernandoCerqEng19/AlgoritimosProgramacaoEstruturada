#include <stdio.h>  // biblioteca de entrada e saída de dados
#include <stdlib.h> // biblioteca que contém funções para alocação de memória
#include <string.h> // biblioteca de manipulação de strings
#include <time.h>   // biblioteca para trabalhar com srand (funções que mexem com tempo real)

typedef struct {            // estrutura chamada Usuário com os campos que contém as informações de um usuário
    int id;
    char nome[50];
    char email[50];
    char sexo[15];
    char endereco[100];
    double altura;
    int vacina;
} Usuario; // tipo das variáveis

// função para gerar um ID aleatório
int gerarID() {
    srand(time(NULL));          // inicia a semente do gerador
    return rand() % 10000 + 1;  // gera IDs entre 1 e 10000 e retorna como id de usuário
}

void cadastrarUsuario(Usuario **usuarios, int *numUsuarios) {
    // nova variável de tipo Usuário, para armazenar os dados do novo usuário a ser cadastrado
    Usuario *novoUsuario = (Usuario*) malloc(sizeof(Usuario));

    // Verifica se a alocação foi bem-sucedida
    if(novoUsuario == NULL) {
        printf("Erro ao armazenar usuário.\n");
        return;
    }
 
    novoUsuario->id = gerarID(); // chama a função e gera um ID aleatório para esse usuário específico
    
    printf("Nome completo: ");
    fgets(novoUsuario->nome, sizeof(novoUsuario->nome), stdin); // A função sizeof() retorna o tamanho do campo "nome" para garantir que a entrada não exceda esse tamanho.
    novoUsuario->nome[strcspn(novoUsuario->nome, "\n")] = '\0'; // remove o caractere de nova linha ('\n') do final da string
    
    printf("Email: ");
    fgets(novoUsuario->email, sizeof(novoUsuario->email), stdin);
    novoUsuario->email[strcspn(novoUsuario->email, "\n")] = '\0';  
    
    do{
        printf("Email invalido. Tente novamente.\n");
        printf("\n....................\n\n");
        printf("Email: ");
        fgets(novoUsuario->email, sizeof(novoUsuario->email), stdin);
        novoUsuario->email[strcspn(novoUsuario->email, "\n")] = '\0'; 
    } while (strstr(novoUsuario->email, "@") == NULL);
    
    printf("Sexo: (Feminino, Masculino ou Indiferente): ");
    fgets(novoUsuario->sexo, sizeof(novoUsuario->sexo), stdin);
    novoUsuario->sexo[strcspn(novoUsuario->sexo, "\n")] = '\0';

    do{
        printf("Sexo invalido. Tente novamente.\n");
        printf("\n....................\n\n");
        printf("Sexo: (Feminino, Masculino ou Indiferente): ");
        fgets(novoUsuario->sexo, sizeof(novoUsuario->sexo), stdin);
        novoUsuario->sexo[strcspn(novoUsuario->sexo, "\n")] = '\0';
    // compara as strings "strcmp"
    }while (strcmp(novoUsuario->sexo, "Feminino") != 0 && strcmp(novoUsuario->sexo, "Masculino") != 0 && strcmp(novoUsuario->sexo, "Indiferente") != 0);
      
    printf("Endereco: ");
    fgets(novoUsuario->endereco, sizeof(novoUsuario->endereco), stdin);
    novoUsuario->endereco[strcspn(novoUsuario->endereco, "\n")] = '\0';
    
    printf("Altura (entre 1 e 2 metros): ");
    scanf("%lf", &novoUsuario->altura);
    getchar();

    do{
        printf("Altura inválida. Tente novamente.\n");
        printf("\n....................\n\n");
        printf("Sexo: (Feminino, Masculino ou Indiferente): ");
        fgets(novoUsuario->sexo, sizeof(novoUsuario->sexo), stdin);
        novoUsuario->sexo[strcspn(novoUsuario->sexo, "\n")] = '\0';
    }while (novoUsuario->altura < 1 || novoUsuario->altura > 2);
    
    printf("Vacina (1 - Sim, 0 - Nao): ");
    scanf("%d", &novoUsuario->vacina);
    getchar();
    
    // adiciona o novo usuário e realoca o vetor para acomodar o novo usuário
    *usuarios = (Usuario*) realloc(*usuarios, (*numUsuarios + 1) * sizeof(Usuario)); 

    // verifica se a realocação foi bem-sucedida
    if (*usuarios == NULL) {
        printf("Erro ao realocar memória.\n");
        printf("\n....................\n\n");
        free(novoUsuario);
        return;
    }
    
    // adiciona o novo usuário ao vetor
    (*usuarios)[*numUsuarios] = *novoUsuario;
    (*numUsuarios)++;

    // libera o espaço da memória
    free(novoUsuario);
    
    printf("\nUsuario cadastrado com sucesso.\n");
    printf("\n....................\n\n");

}

void editarUsuario(Usuario *usuarios, int numUsuarios) {
    int id;

    printf("Digite o ID do usuario que deseja editar: ");
    scanf("%d", &id);
    getchar();
    
    int i; // indice a ser armazenado
    // percorre o vetor de usuários até encontra o id correspondente
    for (i = 0; i < numUsuarios; i++) {
        if (usuarios[i].id == id) {

            // declaração da variável usuarioEditado do tipo usuário, e iguala ao usuário da posição do indice
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
    
    // declaração e inicialização do indice "i" e da variável "usuarioEncontrado"
    int i, usuarioEncontrado = 0;

    // loop que percorre o vetor de usuários, até encontrar o usuário com o mesmo ID inserido
    for (i = 0; i < *numUsuarios; i++) {
        if (usuarios[i].id == id) {
            usuarioEncontrado = 1;
            break;
        }
    }
    
    if (usuarioEncontrado) {

        // esse loop move cada usuário uma posição para trás no vetor
        for (; i < *numUsuarios - 1; i++) {
            usuarios[i] = usuarios[i + 1];
        }
        
        // Atualiza a quantidade de usuários atual, após a exclusão
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
    // definir ponteiro para o arquivo "backup"
    // o arquivo backup está enderaçado (*), para o tipo de dado FILE (arquivo)
    FILE *backup = fopen("backup.txt", "w"); // inicializa com a função fopen, que abre o arquivo em formato txt no modelo de escrita "w".
    
    //* o uso do modelo de escrita "w", significa que o arquivo aberto será usado para escrita 
    
    
    // verificação se o arquivo é nulo
    if (backup == NULL) {
        printf("Erro ao criar o arquivo de backup.\n");

        printf("\n....................\n\n");
        return;
    }
    
    // percorre todos os usuários existentes e registra eles no arquivo de backup
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
    
    fclose(backup); // fecha o arquivo
    
    printf("Backup realizado com sucesso.\n");

    printf("\n....................\n\n");
}

void fazerRestauracao(Usuario *usuarios, int numUsuarios) {
    FILE *backup = fopen("backup.txt", "r");

    //* o uso do modelo de escrita "r", significa que o arquivo aberto será usado para leitura
    
    if (backup == NULL) {
        printf("Arquivo de backup Nao encontrado.\n");

        printf("\n....................\n\n");
        return;
    }
    
    // inicializa a variável para leitura dos dados do backup
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
    
    // fecha o arquivo de backup
    fclose(backup);
    
    printf("Restauracao realizada com sucesso.\n");

    printf("\n....................\n\n");
}