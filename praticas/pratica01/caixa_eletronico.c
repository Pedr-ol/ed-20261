#include <stdio.h>

int caixa_ele(int valor, int *n200, int *n100, int *n50, int *n20, int *n10, int *n5, int *n2)
{
    if (valor <= 0 || valor > 1000)
    {
        return -1;
    }

    *n200 = valor / 200; valor %= 200;
    *n100 = valor / 100; valor %= 100;
    *n50  = valor / 50;  valor %= 50;
    *n20  = valor / 20;  valor %= 20;
    *n10  = valor / 10;  valor %= 10;
    *n5   = valor / 5;   valor %= 5;
    *n2   = valor / 2;   valor %= 2;

    if (valor != 0)
    {
        return -2;
    }

    return 1;
}

void imprimir_resultado(int valor, int resultado, int n200, int n100, int n50, int n20, int n10, int n5, int n2)
{
    printf("Valor solicitado: R$ %d\n", valor);

    if (resultado == -1)
    {
        printf("Erro: valor fora do limite permitido.\n");
    }
    else if (resultado == -2)
    {
        printf("Erro: nao é possível formar esse valor com as notas disponíveis.\n");
    }
    else
    {
        printf("Distribuicao de notas:\n");
        printf("  200: %d\n", n200);
        printf("  100: %d\n", n100);
        printf("   50: %d\n", n50);
        printf("   20: %d\n", n20);
        printf("   10: %d\n", n10);
        printf("    5: %d\n", n5);
        printf("    2: %d\n", n2);
    }

    printf("----------------------------\n");
}

int main()
{
    int n200, n100, n50, n20, n10, n5, n2;
    int resultado;

    printf("===== TESTES CAIXA ELETRONICO =====\n\n");

    resultado = caixa_ele(400, &n200, &n100, &n50, &n20, &n10, &n5, &n2);
    imprimir_resultado(400, resultado, n200, n100, n50, n20, n10, n5, n2);

    resultado = caixa_ele(531, &n200, &n100, &n50, &n20, &n10, &n5, &n2);
    imprimir_resultado(531, resultado, n200, n100, n50, n20, n10, n5, n2);

    resultado = caixa_ele(1200, &n200, &n100, &n50, &n20, &n10, &n5, &n2);
    imprimir_resultado(1200, resultado, n200, n100, n50, n20, n10, n5, n2);

    resultado = caixa_ele(12, &n200, &n100, &n50, &n20, &n10, &n5, &n2);
    imprimir_resultado(12, resultado, n200, n100, n50, n20, n10, n5, n2);

    return 0;
}