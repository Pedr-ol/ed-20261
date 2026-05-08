#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void busca()
{
    int x;
    int vetor[100];
    printf("Digite o valor a ser buscado: ");
    scanf("%d", &x);
    for (int i = 0; i < 100; i++)
    {
        vetor[i] = i;
    }
    int busca = 0;
    int j = 0;
    // O pior caso O(n) vai acontecer quando x estiver no indice 99
    // O melhor caso O(1) vai acontecer quando x estiver no indice 0
    clock_t tempo_incial = clock();
    while (j < 100 && !busca)
    {
        if (vetor[j] == x)
        {
            busca = 1;
        }
        else
        {
            j++;
        }
    }
    clock_t tempo_final = clock();
    if (busca == 1)
    {
        printf("A valor %d que você busca esta no vetor.\n", x);
    }
    if (busca == 0)
    {
        printf("O valor %d que você busca não esta no vetor.\n", x);
    }
    double duracao = (double)(tempo_final - tempo_incial) / CLOCKS_PER_SEC;
    printf("O tempo de execucao foi %.10f seg\n", duracao);
}

int main()
{
    busca();
    return 0;
}