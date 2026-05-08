#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int matriz()
{
    int matriz[10][10];
    int linha;
    int coluna;
    //Laços aninhados O(n^2)
    clock_t inicio2 = clock();
    for (linha = 0; linha < 10; linha++)
    {
        for (coluna = 0; coluna < 10; coluna++)
        {
            matriz[linha][coluna] = linha + coluna;
        }
    }
    clock_t fim2 = clock();
    double tempo2 = (double)(fim2 - inicio2) / CLOCKS_PER_SEC;

    //Um laço - O(n^2)
    clock_t inicio1 = clock();
    int *ptr = &matriz[0][0]; 
    for (int i = 0; i < 100; i++) {
        ptr[i] = i; 
    }
    clock_t fim1 = clock();
    double tempo1 = (double)(fim1 - inicio1) / CLOCKS_PER_SEC;


    printf("Tempo com laços aninhados: %.10f seg\n", tempo2);
    printf("Tempo com um laco: %.10f seg\n", tempo1);
}

int main(){
    matriz();
    return 0;
}
