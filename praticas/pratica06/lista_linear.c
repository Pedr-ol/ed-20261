#include <stdio.h>
#include <stdlib.h>
#include "lista_linear.h"

typedef struct no_t {
    struct no_t *anterior;
    struct no_t *proximo;
    int valor;
} no_t;

struct lista_t {
    no_t *primeiro;
    no_t *ultimo;
};

Lista lista_criar() {
    Lista lista = (Lista)malloc(sizeof(struct lista_t));

    if(lista != NULL){
        lista->primeiro = NULL;
        lista->ultimo = NULL;     
    }
    return lista;
}

int lista_vazia(Lista lista) {
    return (lista == NULL || lista->primeiro == NULL);
}

int lista_inserir(Lista lista, int valor){
    if(lista == NULL) {return 0;}

    no_t* novo = (no_t*)malloc(sizeof(no_t));
    if(novo == NULL) {return 0;}

    novo->valor = valor;
    novo->proximo = NULL;
    novo->anterior = NULL;

    if (lista_vazia(lista)) {
        lista->primeiro = novo;
    } else {
        lista->ultimo->proximo = novo;
    }

    lista->ultimo = novo;
    return 1;
}

int lista_remover(Lista lista, int valor){
    if(lista_vazia(lista)){return 0;}

    no_t* atual = lista->primeiro;
    no_t* anterior = NULL;

    //busca o nó
    while(atual != NULL && atual->valor != valor) {
        anterior = atual;
        atual = atual->proximo;
    }

    //não encontrou
    if(atual==NULL){return -1;}

    //1° da lista
    if(atual == lista->primeiro){
        lista->primeiro = atual->proximo;
        if(lista->primeiro == NULL) {
            lista->ultimo = NULL;
        }
    }

    //No meio ou no fim
    else {
        anterior->proximo = atual->proximo;
        if(atual == lista->ultimo){//se for o ultimo, atualiza o ponteiro para "ultimo"
            lista->ultimo = anterior;
        }
    }

    free(atual);
    return 1;
}

int lista_buscar(Lista lista, int valor) {
    if(lista_vazia(lista)){return 0;}

    no_t* atual = lista->primeiro;
    int posicao = 0;

    while(atual != NULL) {
        if(atual->valor == valor){
            return posicao;
        }
        atual = atual->proximo;
        posicao++;
    }
    return -1;
}

void lista_exibir (Lista lista) {
    if (lista_vazia(lista)) {
        printf("Lista vazia\n");
        return;
    }

    no_t* atual = lista->primeiro;
    printf("Lista: [ ");
    while (atual != NULL) {
        printf("%d ", atual->valor);
        atual = atual->proximo;
    }
    printf("]\n");

}

void lista_destruir(Lista lista) {
    if (lista == NULL) return;

    no_t* atual = lista->primeiro;
    while (atual != NULL) {
        no_t* proximo_no = atual->proximo;
        free(atual); // Libera o nó atual
        atual = proximo_no; // Avança para o próximo
    }
    free(lista); // Por fim, libera o descritor da lista
}