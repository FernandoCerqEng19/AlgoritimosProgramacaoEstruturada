#include<stdio.h>
#include<math.h>


int main(){

    double x1,x2,y1,y2,distancia;

    printf("Insira o valor do x1: ");
    scanf("%lf", &x1);
    printf("\nInsira o valor de y1: ");
    scanf("%lf", &y1);
    printf("\nInsira o valor do x2: ");
    scanf("%lf", &x2);
    printf("\nInsira o valor de y2: ");
    scanf("%lf", &y2);

    distancia = sqrt(pow(x2 - x1, 2) + pow(y2 - y2, 2));
    printf("\nA distancia do ponto 1 ate o ponto 2 e: %4.lf", distancia);

    return 0;
}