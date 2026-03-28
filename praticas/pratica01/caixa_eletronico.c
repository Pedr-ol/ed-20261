#include <stdio.h>

void caixa_ele(int valor)
{
    int notas200;
    int notas100; 
    int notas50;
    int notas20; 
    int notas10;
    int notas5; 
    int notas2;

    if (valor <= 0 || valor > 1000)
    {
        printf("Esse valor está fora do limite permitido!\n");
    }
    else
    {
        notas200 = valor / 200;
        valor = valor % 200;

        notas100 = valor / 100;
        valor = valor % 100;

        notas50 = valor / 50;
        valor = valor % 50;

        notas20 = valor / 20;
        valor = valor % 20;

        notas10 = valor / 10;
        valor = valor % 10;

        notas5 = valor / 5;
        valor = valor % 5;

        notas2 = valor / 2;
        valor = valor % 2;

        if (valor != 0)
        {
            printf("Nao é possível sacar esse valor com as notas disponíveis.\n");
        }
        else
        {
            printf("Notas de 200: %d\n", notas200);
            printf("Notas de 100: %d\n", notas100);
            printf("Notas de 50: %d\n", notas50);
            printf("Notas de 20: %d\n", notas20);
            printf("Notas de 10: %d\n", notas10);
            printf("Notas de 5: %d\n", notas5);
            printf("Notas de 2: %d\n", notas2);
        }
    }
}

int main()
{
    printf("============\n");
    printf("Teste 1:\n");
    caixa_ele(400);
    printf("============\n");
    printf("Teste 2:\n");
    caixa_ele(531);
    printf("============\n");
    printf("Teste 3:\n");
    caixa_ele(1200);
    printf("============\n");
    printf("Teste 4:\n");
    caixa_ele(12);
    printf("============\n");
    printf("Teste 5:\n");
    caixa_ele(-21);
    printf("============\n");
    printf("Teste 6:\n");
    caixa_ele(847);

    return 0;
}