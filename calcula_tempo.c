#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {
    // Ligou o cronometro
    clock_t tempo_incial = clock();

    int soma =10+20; // O(1)

    //Desligou o cronometro
    clock_t tempo_final = clock();

    double duracao = (double) (tempo_final - tempo_incial) / CLOCKS_PER_SEC;

    printf("O tempo de execucao foi %.10f seg\n", duracao);

    tempo_incial = clock();

    // O(n)
    for (long int i =0; i<1000000000L; i++){
        soma = soma + 1;
    } 

    tempo_final = clock();

    duracao = (double) (tempo_final - tempo_incial) / CLOCKS_PER_SEC;

    printf("O tempo de execucao foi %.10f seg\n", duracao);

        tempo_incial = clock();

    // O(n^2)
    for (long int i =0; i<10000000L; i++){ 
        for(int j=0; j<100; j++){
          soma = soma + 1;  
        }
        
    } 

    tempo_final = clock();

    duracao = (double) (tempo_final - tempo_incial) / CLOCKS_PER_SEC;

    printf("O tempo de execucao foi %.10f seg\n", duracao);

    return 0;
}