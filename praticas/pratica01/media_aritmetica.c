#include <stdio.h>

float calc_media_arit(int n, int valores[])
{
    if (n <= 0 || n > 100)
    {
        return -1;
    }

    float soma = 0;

    for (int i = 0; i < n; i++)
    {
        soma += valores[i];
    }

    return soma / n;
}

void imprimir_vetor(int n, int valores[])
{
    printf("Valores: [");

    for (int i = 0; i < n; i++)
    {
        printf("%d", valores[i]);

        if (i < n - 1)
        {
            printf(", ");
        }
    }

    printf("]\n");
}

void imprimir_resultado(int n, int valores[], float resultado)
{
    imprimir_vetor(n, valores);

    if (resultado == -1)
    {
        printf("Erro: quantidade de valores inválida.\n");
    }
    else
    {
        printf("Média aritmética: %.2f\n", resultado);
    }

    printf("----------------------------\n");
}

int main()
{
    printf("===== TESTES MEDIA ARITMETICA =====\n\n");

    int v1[] = {10, 20, 30};
    float r1 = calc_media_arit(3, v1);
    imprimir_resultado(3, v1, r1);

    int v2[] = {5, 5, 5, 5};
    float r2 = calc_media_arit(4, v2);
    imprimir_resultado(4, v2, r2);

    int v3[] = {-1};
    float r3 = calc_media_arit(0, v3);
    imprimir_resultado(0, v3, r3);

    return 0;
}