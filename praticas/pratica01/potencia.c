#include <stdio.h>

int calc_potencia(int base, int expoente)
{
    if (expoente < 0)
    {
        printf("ERRO, o expoente não pode ser menor que 0!");
        return -1; // erro
    }

    int potencia = 1;

    for (int i = 0; i < expoente; i++)
    {
        potencia *= base;
    }

    return potencia;
}

int main()
{
    int resultado;

    printf("=================\nTeste 1:\n");
    resultado = calc_potencia(2, 5);
    printf("Resultado(2^5): %d\n", resultado);

    printf("=================\nTeste 2:\n");
    resultado = calc_potencia(1, 0);
    printf("Resultado(1^0): %d\n", resultado);

    printf("=================\nTeste 3:\n");
    resultado = calc_potencia(3, 2);
    printf("Resultado(3^2): %d\n", resultado);

    printf("=================\nTeste 4:\n");
    resultado = calc_potencia(-1, -5);
    printf("Resultado(-1^-5): %d\n", resultado);

    return 0;
}