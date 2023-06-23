#include <stdio.h>

void bubbleSort(int vetor[], int tamanho){
    int i, j;

    for(i = 0; i < tamanho-1; i++){
        for(j = 0; j < tamanho-i-1; j++){
            if (vetor[j] > vetor [j+1]){
                int temp = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = temp;
            }
        }
    }
}

int main(){

    int vetor[5];
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);

    for (int i = 0; i < tamanho; i++){
        printf("Digite o dado: \n");
        scanf("%d", &vetor[i]);
    }

    bubbleSort(vetor, tamanho);

    printf("Vetor Ordenado:");

    for(int i = 0; i < tamanho; i++){
        printf("%d ", vetor[i]);
    }

    return 0;
}