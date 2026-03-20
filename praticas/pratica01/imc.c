#include <stdio.h>

float calc_imc(float peso, float altura)
{
    float imc = peso / (altura * altura);
    if (peso <= 0.0 || altura <= 0.0)
    {
        printf("Peso ou altura invalidos!\n");
    }
    else
    {
        if (imc <= 18.5)
        {
            printf("Abaixo do peso\n");
        }
        else if (imc > 18.5 && imc < 24.9)
        {
            printf("Peso normal\n");
        }
        else if (imc > 25 && imc <= 29.9)
        {
            printf("Sobrepeso\n");
        }
        else
        {
            printf("Obesidade\n");
        }
        return imc;
    }
}

int main()
{
    float imc;

    printf("Teste 1 (Abaixo do peso):\n");
    imc = calc_imc(50, 1.70);
    printf("IMC: %.2f\n\n", imc);

    printf("Teste 2 (Peso normal):\n");
    imc = calc_imc(65, 1.70);
    printf("IMC: %.2f\n\n", imc);

    printf("Teste 3 (Sobrepeso):\n");
    imc = calc_imc(80, 1.70);
    printf("IMC: %.2f\n\n", imc);

    printf("Teste 4 (Obesidade):\n");
    imc = calc_imc(95, 1.70);
    printf("IMC: %.2f\n\n", imc);

    printf("Teste 5 (Dados invalidos):\n");
    imc = calc_imc(-10, 1.70);
    printf("IMC: %.2f\n\n", imc);

    return 0;
}