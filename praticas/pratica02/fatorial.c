#include <stdio.h>

long int fatorial_repeticao(long int x)
{ // Repetição O(1)
    if (x < 0)
    {
        return 0;
    }
    if (x < 2)
    {
        return 1;
    }
    long int fatorial = 1;
    for (long int i = 1; i < x + 1; i++)
    {
        fatorial = fatorial * i;
    }
    return fatorial;
}

long int fatorial_recursivo(long int y)
{ // Recursividade O(n)
    if (y < 0)
    {
        return 0;
    }
    if (y < 2)
    {
        return 1;
    }
    return y * fatorial_recursivo(y - 1);
}
int main()
{
    long int resultado;
    long int resultado2;
    resultado = fatorial_repeticao(5);
    printf("5! utilizando repeticao: %d\n", resultado);
    resultado2 = fatorial_recursivo(5);
    printf("5! utilizando recursividade: %d\n", resultado2);
    resultado = fatorial_repeticao(10);
    printf("10! utilizando repeticao: %d\n", resultado);
    resultado2 = fatorial_recursivo(10);
    printf("10! utilizando recursividade: %d\n", resultado2);
    return 0;
}