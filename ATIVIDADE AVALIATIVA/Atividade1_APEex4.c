#include <stdio.h>

int main()
{
    double x, y;

    printf("Insira o valor de X no plano cartesiano: ");
    scanf("%lf", &x);
    printf("\nInsira o valor de Y no plano cartesiano: ");
    scanf("%lf", &y);

    if ((x == 0) & (y == 0))
    {
        printf("\nO ponto esta na origem.");
    }
    else if ((x == 0) & (y > 0))
    {
        printf("\nO ponto esta sob o eixo Y.");
    }
    else if ((x == 0) & (y < 0))
    {
        printf("\nO ponto esta sob o eixo Y.");
    }
    else if ((x > 0) & (y == 0))
    {
        printf("\nO ponto esta sob o eixo X.");
    }
    else if ((x < 0 ) & (y == 0))
    {
        printf("\nO ponto esta sob o eixo X.");
    }
    else if ((x > 0) & (y > 0))
    {
        printf("\nO ponto esta no quadrante 1.");
    }
    else if ((x > 0) & (y < 0))
    {
        printf("\nO ponto esta no quadrante 4.");
    }
    else if ((x < 0) & (y > 0))
    {
        printf("\nO ponto esta no quadrante 2.");
    }
    else if ((x < 0) & (y < 0))
    {
        printf("\nO ponto esta no quadrante 3.");
    }



}