#include <stdio.h>

float calc_media_arit()
{
    int n;
    printf("Digite a quantidade de números necessários para realizar a média: ");
    scanf("%d", &n);
    if (n>100 || n<=0)
    {
        printf("O maximo é 100 e o mínimo é 1!\n");
    }

    else
    {
        float soma = 0;
        for (int i = 1; i < n + 1; i++)
        {
            int x;
            printf("Digite o %d° número: ", i);
            scanf("%d", &x);
            soma = soma + (x);
        }
        float media = (soma) / n;
        return media;
    }
}

int main()
{
    float media;
    media = calc_media_arit();
    printf("O resultado é: %.2f\n", media);
    return 0;
}