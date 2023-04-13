#include<stdio.h>
#include<stdlib.h>
#define PI 3.14159

int main()
{
    double raio, area, volume;

    printf("Digite o valor do raio da esfera: ");
    scanf("%lf", &raio);

    volume = (4.0 / 3) * PI * (raio * raio * raio);
    area = 4 * PI * (raio * raio);

    printf("\nO volume da esfera é %2.lf", volume);
    printf("\nA área da esfera é: %2.lf", area);

    return 0;

}