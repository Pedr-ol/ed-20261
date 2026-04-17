#include "selecao.h"

int busca_sequencial(int v[], int n, int valor)
{
    for (int i = 0; i < n; i++)
    {
        if (v[i] == valor)
        {
            return i;
        }
    }
    return -1; // não achou
}

void troca(int *a, int *b)
{
    int aux = *a;
    *a = *b;
    *b = aux;
}

int particionar_vetor(int v[], int inicio, int fim)
{
    int pivo = v[fim];
    int i = inicio - 1;
    for (int j = inicio; j < fim; j++)
    {
        if (v[j] <= pivo)
        {
            i++;
            troca(&v[i], &v[j]);
        }
    }
    troca(&v[i + 1], &v[fim]);
    return i + 1;
}

int quick_select(int v[], int inicio, int fim, int valor)
{
    if (inicio == fim)
    {
        return inicio;
    }

    int pivo = particionar_vetor(v, inicio, fim);

    if (v[pivo] == valor)
    {
        return pivo;
    }
    else if (v[pivo] < valor)
    {
        // procura antes do pivo
        quick_select(v, inicio, pivo - 1, valor);
    }
    else
    {
        // procura depois do pivo
        quick_select(v, pivo + 1, fim, valor);
    }
}