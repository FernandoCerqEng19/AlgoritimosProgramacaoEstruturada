#include <stdio.h>

int fibonacci(int n) {
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        int a = 0;
        int b = 1;
        int resultado;
        for (int i = 2; i <= n; i++) {
            resultado = a + b;
            a = b;
            b = resultado;
        }
        return resultado;
    }
}

int main() {
    int n;
    printf("Digite o valor de n (numero inteiro maior ou igual a 0): ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Erro: n deve ser maior ou igual a 0.\n");
    } else {
        int resultado = fibonacci(n);
        printf("O %d termo da sequencia de Fibonacci e: %d\n", n, resultado);
    }

    return 0;
}