#include <stdio.h>
#include <stdlib.h>
#include "arvore_binaria.h"

int main() {
    No *raiz = NULL;
    
    raiz = inserir(raiz, 50);
    inserir(raiz, 30);
    inserir(raiz, 70);
    inserir(raiz, 20);
    inserir(raiz, 40);
    inserir(raiz, 60);
    inserir(raiz, 80);

    printf("Pre ordem:\n");
    pre_ordem(raiz);
    printf("\n\n");

    printf("Em ordem (Deve aparecer ordenado):\n");
    em_ordem(raiz);
    printf("\n\n");

    printf("Pos ordem:\n");
    pos_ordem(raiz);
    printf("\n\n");

    int alvo = 60;
    No *no_encontrado = buscar(raiz, alvo);
    if (no_encontrado != NULL) {
        printf("SUCESSO: Encontrei o No contendo o valor %i\n", no_encontrado->dado);
    } else {
        printf("ERRO: Nao achei o No %i\n", alvo);
    }

    destruir(raiz);
    
    return 0;
}