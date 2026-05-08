#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "selecao.h"

#define TAM 100

// Copiar vetor
void copiar_vetor(int origem[], int destino[], int n)
{
    for (int i = 0; i < n; i++)
    {
        destino[i] = origem[i];
    }
}

int main()
{
    int vetor_original[TAM];
    int v[TAM];

    srand(time(NULL));

    // Vetor aleatório
    for (int i = 0; i < TAM; i++)
    {
        vetor_original[i] = rand() % 1000;
    }

    int alvo = vetor_original[rand() % TAM]; // valor que existe no vetor
    int k = TAM / 2;                     // mediana

    clock_t inicio, fim;

    // Linear Search
    copiar_vetor(vetor_original, v, TAM);
    inicio = clock();
    int pos = linear_search(v, TAM, alvo);
    fim = clock();
    printf("Linear Search (valor %d): índice %d | tempo: %.10lf segundos\n",
           alvo, pos, (double)(fim - inicio) / CLOCKS_PER_SEC);

    // Quick Select
    copiar_vetor(vetor_original, v, TAM);
    inicio = clock();
    int kth = quick_select(v, 0, TAM - 1, k);
    fim = clock();
    printf("Quick Select (k=%d): valor %d | tempo: %.10lf segundos\n",
           k, kth, (double)(fim - inicio) / CLOCKS_PER_SEC);

    return 0;
}