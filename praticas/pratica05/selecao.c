#include "selecao.h"

// Busca linear
int linear_search(int v[], int n, int alvo)
{
    for (int i = 0; i < n; i++)
    {
        if (v[i] == alvo)
        {
            return i;
        }
    }
    return -1;
}

// Função auxiliar (partição)
int particionar(int v[], int inicio, int fim)
{
    int pivo = v[fim];
    int i = inicio - 1;

    for (int j = inicio; j < fim; j++)
    {
        if (v[j] <= pivo)
        {
            i++;
            int temp = v[i];
            v[i] = v[j];
            v[j] = temp;
        }
    }

    int temp = v[i + 1];
    v[i + 1] = v[fim];
    v[fim] = temp;

    return i + 1;
}

// Quick Select
int quick_select(int v[], int inicio, int fim, int k)
{
    if (inicio == fim)
    {
        return v[inicio];
    }

    int p = particionar(v, inicio, fim);

    if (k == p)
    {
        return v[p];
    }
    else if (k < p)
    {
        return quick_select(v, inicio, p - 1, k);
    }
    else
    {
        return quick_select(v, p + 1, fim, k);
    }
}