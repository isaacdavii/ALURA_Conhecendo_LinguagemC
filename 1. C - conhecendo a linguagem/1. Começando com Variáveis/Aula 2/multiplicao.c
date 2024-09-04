#include <stdio.h>

int main() {
    int x, y, resultado;

    printf("Digite o valor de x: ");
    scanf("%d", &x);

    printf("Digite o valor de y: ");
    scanf("%d", &y);

    resultado = x * y;

    printf("O resultado da multiplicação entre %d e %d é: %d\n", x, y, resultado);

    return 0;
}