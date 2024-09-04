#include <stdio.h>
// define NUMERO_DE_TENTATIVAS 5

int main() {
    
    // Imprime o cabeçalho do jogo
    printf("***********************\n");
    printf("* Jogo de adivinhacao *\n");
    printf("***********************\n");

    int numeroSecreto = 42;
    //printf("O numero secreto e %d\n", numeroSecreto);

                // %d - número inteiro      // %f - número real
                // %lf - número real longo  // %c - caractere
                // %s - string              // %p - ponteiro
    int chute;
    int tentativas = 1;

    
    printf("Qual e o seu chute? ");
    scanf("%d", &chute);

    while (chute < 0){
        printf("Voce nao pode chutar numeros negativos!\n");
        tentativas = 1;
        printf("Qual e o seu chute? ");
        scanf("%d", &chute);
    } 

    int acertou = (chute == numeroSecreto);
    // printf("%d\n", acertou); - Isso é Álgebra Booleana para saber se o chute foi igual ao número secreto
        if (acertou){
            printf("Parabens! Voce acertou!\n");
            printf("Voce acertou na primeira tentativa!\n");

        } else {
            while (chute != numeroSecreto && chute > 0){
                printf("Voce errou!\n");
                tentativas++;

                // Quando eu quiser posso usar o ELSE IF
                if(chute > numeroSecreto){
                    printf("Seu chute foi MAIOR que o numero secreto!\n");
                } else {    
                    printf("Seu chute foi MENOR que o numero secreto!\n");
                }
                printf("Qual e o seu chute? ");
                scanf("%d", &chute);

                if (chute == numeroSecreto){
                    printf("Parabens! Voce acertou!\n");
                    printf("Voce acertou em %d tentativas!\n", tentativas);
                }
            }
        } 
    printf("FIM DE JOGO!\n");                       
}

