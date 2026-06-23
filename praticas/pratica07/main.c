#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main() {
    printf("\n");
    Pilha pilha = pilha_criar();

    pilha_exibir(pilha);

    printf("\nEmpilhando 40, 23, 54, 65, 12\n");

    pilha_empilhar(pilha, 40);
    pilha_empilhar(pilha, 23);
    pilha_empilhar(pilha, 54);
    pilha_empilhar(pilha, 65);
    pilha_empilhar(pilha, 12);

    pilha_exibir(pilha);

    int valor;
    printf("\nDesempilhando o topo...\n");
    if(pilha_desempilhar(pilha, &valor)){
        printf("Valor removido: %d\n", valor);//12
    }
    printf("\nDesempilhando o topo...\n");
    if(pilha_desempilhar(pilha, &valor)){
        printf("Valor removido: %d\n", valor);//65
    }

    pilha_exibir(pilha);

    printf("\nMostrando o topo...\n");
    if(pilha_topo(pilha, &valor)){
        printf("Topo: %d\n", valor);
    }

    printf("\nDestruindo a pilha...\n");
    pilha_destruir(pilha);
    pilha_exibir(pilha);//apenas para ver se foi destruida.

    return 0;
}