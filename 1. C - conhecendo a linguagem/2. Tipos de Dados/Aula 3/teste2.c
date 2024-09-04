#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int semente = time(0);
    srand(semente);
    int n1 = rand();
    int n2 = rand();
    // Números randômicos
    printf("%d %d", n1, n2);
}