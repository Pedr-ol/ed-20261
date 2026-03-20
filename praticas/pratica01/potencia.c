#include <stdio.h>

int calc_potencia(int base, int expoente)
{
    if (base <= 0 || expoente <= 0)
    {
        return 0;
    }
   
    else 
        {
            int potencia = 1;
            for (int i = 0; i < expoente; i++)

            {
                potencia = potencia * base;

            }
            return 1;
        }
}

int main()
{
    
    int resultado;

    resultado = calc_potencia(2, 5);
    printf("Teste 1: base=2 expoente=5, resultado=%d\n", resultado);

    resultado = calc_potencia(1, 0);
    printf("Teste 2: base=1 expoente=0, resultado=%d\n", resultado);

    resultado = calc_potencia(3, 2);
    printf("Teste 3: base=3 expoente=2, resultado=%d\n", resultado);

    resultado = calc_potencia(-1, -5);
    printf("Teste 4: base=(-1) expoente=(-5), resultado=%d\n", resultado);
    return 0;
}