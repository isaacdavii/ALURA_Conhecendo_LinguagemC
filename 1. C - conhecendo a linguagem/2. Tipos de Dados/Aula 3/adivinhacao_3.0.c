// 1 - adicionamos esquemas de pontos (primeiro com INT depois com DOUBLE)
// 2- colocamos o DOUBLE
// 3- colocamos o ABS para não ter números negativos
// 4- colocamos o %.2f para mostrar apenas 2 casas decimais
// 5- adicionamos nível de dificuldade no jogo (linha 36)

#include <stdio.h>
#include <stdlib.h>
#include <time.h> // fornece funções para manipulação de tempo ex.: time(0)
// define NUMERO_DE_TENTATIVAS 5

int main()
{

    // Imprime o cabeçalho do jogo
    printf("***********************\n");
    printf("* Jogo de adivinhacao *\n");
    printf("***********************\n");

    int segundos = time(0);
    srand(segundos);
    int numeroSecreto = rand() % 100;

    double pontos = 1000;
    // int numeroSecreto = 42; - usei quando eu queria um número fixo
    // printf("O numero secreto e %d\n", numeroSecreto)
    //  1 byte = 8 bits
    //  short(2 bytes) - int(4 bytes) - long(8 bytes)
    //  float(4 bytes) - double(8 bytes)
    //  %d - número inteiro(int)      // %f - número real(double)
    //  %lf - número real longo       // %c - caractere(char)
    //  %s - string                   // %p - ponteiro
    int chute;
    int tentativas = 1;

    // INSERINDO DIFICULDADE
    int nivel;
    printf("Qual o nivel de dificuldade?\n");
    printf("(1) Facil (2) Medio (3) Dificil\n\n");
    printf("Escolha: ");
    scanf("%d", &nivel);

    int numeroDeTentativas;
    if(nivel == 1){
        numeroDeTentativas = 20;
    } else if(nivel == 2){
        numeroDeTentativas = 13;
    } else {
        numeroDeTentativas = 6;
    }

    printf("Qual e o seu chute? ");
    scanf("%d", &chute);

    while (chute < 0)
    {
        printf("Voce nao pode chutar numeros negativos!\n");
        tentativas = 1;
        printf("Qual e o seu chute? ");
        scanf("%d", &chute);
    }

    int acertou = (chute == numeroSecreto);
    // printf("%d\n", acertou); - Isso é Álgebra Booleana para saber se o chute foi igual ao número secreto
    if (acertou)
    {
        printf("Parabens! Voce acertou!\n");
        printf("Voce acertou na primeira tentativa!\n");
    }
    else
    {
        while (chute != numeroSecreto && chute > 0)
        {
            printf("Voce errou!\n");
            tentativas++;

            // Cálculo de pontos (ADICIONADO AGORA)
            double pontosPerdidos = abs(chute - numeroSecreto) / 2.0; // Coloquei 2.0 para o compilador reconhecer como DOUBLE
            // OU: double pontosPerdidos = (chute - numeroSecreto) / (double) 2;
            pontos = pontos - pontosPerdidos;
            printf("Voce perdeu %.2f pontos!\n", pontosPerdidos);
            printf("Voce ainda tem %.2f pontos.\n", pontos);

            // Quando eu quiser posso usar o ELSE IF
            if (chute > numeroSecreto)
            {
                printf("Seu chute foi MAIOR que o numero secreto!\n");
            }
            else
            {
                printf("Seu chute foi MENOR que o numero secreto!\n");
            }

            printf("\nQual e o seu chute? ");
            scanf("%d", &chute);

            if (chute == numeroSecreto)
            {
                printf("Parabens! Voce acertou!\n");
                printf("Voce acertou em %d tentativas!\n", tentativas);
                printf("Total de pontos: %.1f!\n", pontos);
            }
            if (tentativas == numeroDeTentativas)
            {
                printf("Voce teve %d tentativas e nao conseguiu!\n", numeroDeTentativas);
                printf("Voce perdeu! O numero secreto era %d!\n", numeroSecreto);
                break;
            }
        }
    }
    printf("\nFIM DE JOGO!\n");
}
