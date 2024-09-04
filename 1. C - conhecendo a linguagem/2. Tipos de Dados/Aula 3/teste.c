#include <stdio.h>

int main(){
    int a = 3;
    int b = 2; 
    double pontos = a / (double)b; // casting to double
    printf("%.1f\n", pontos);

    double pi = 3.1415;
    int piConvertido = (int)pi;
    printf("%f\n", pi);
    printf("%d\n", piConvertido);
}