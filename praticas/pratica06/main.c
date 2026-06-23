#include <stdio.h>
#include <stdlib.h>
#include "lista_linear.h"

int main() {
    Lista lista = lista_criar();

    printf("Adicionando 50, 25, 10, 60, 20\n");
    lista_inserir(lista, 50);
    lista_inserir(lista, 25);
    lista_inserir(lista, 10);
    lista_inserir(lista, 60);
    lista_inserir(lista, 20);
    lista_exibir(lista);

    printf("\nBuscando o elemento 20...\n");
    int pos = lista_buscar(lista, 20);
    if(pos != -1) {
        printf("Encontrado na posicao: %d\n", pos);
    }

    printf("\nRemovendo o elemento 60:\n");
    lista_remover(lista, 60);
    lista_exibir(lista);

    printf("\nDestruindo lista...\n");
    lista_destruir(lista);
    lista_exibir(lista);//Segmeatation fault, pois a lista foi destruida

    return 0;
}