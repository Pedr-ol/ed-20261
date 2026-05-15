#include <stdio.h>
#include "lista_encadeada.h"

int main(){
    ListaEncadeada *lista = criar();

    adicionar_final(lista, 50);
    adicionar_final(lista, 25);
    adicionar_final(lista, 10);
    adicionar_final(lista, 60);
    adicionar_final(lista, 5);
    adicionar_final(lista, 41);
    adicionar_final(lista, 9);

    printf("A lista tem %i nos \n", lista->quantidade);
    No *no = lista->primeiro;
    while(no!=NULL) {
        printf("%i ", no->dado);
        no = no->proximo;
    }

    printf("\n");

    no=buscar(lista, 60);
    printf("O valor 60 esta no No %p\n", no);
    no=buscar(lista, 100);
    printf("O valor 100 esta no No %p\n", no);


    remover(lista, 50);//remove no inicio
    remover(lista, 10);//remove no meio
    remover(lista, 9);//remove no fim

    printf("A lista em %i nos =>", lista->quantidade);
    no = lista->primeiro;
    while(no!=NULL) {
        printf("%i ", no->dado);
        no = no->proximo;
    }

    printf("\n");





    return 0;
}