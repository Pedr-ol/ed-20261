#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

typedef struct no_t {
    struct no_t *proximo;
    int valor;
} no_t;

struct fila_t {
    no_t *inicio;
    no_t *fim;
};

Fila fila_criar(){
    Fila fila = (Fila)malloc(sizeof(struct fila_t));

    if(fila != NULL){
        fila->inicio = NULL;
        fila->fim = NULL;
    }

    return fila;
}

int fila_vazia(Fila fila) {
    return(fila == NULL || fila->inicio == NULL);
}

int fila_enfileirar(Fila fila, int *valor) { // Mantendo o int* que você colocou no .h
    if(fila == NULL) {return 0;}

    no_t *novo = malloc(sizeof(no_t));
    if(novo == NULL){
        return 0;
    }

    novo->valor = *valor; // <--- CORREÇÃO: Adicionado o '*' para pegar o valor de fato, e não o endereço de memória
    novo->proximo = NULL;

    if(fila_vazia(fila)){
        fila->inicio = novo;
        fila->fim = novo;
    } else {
        fila->fim->proximo = novo;
        fila->fim = novo;
    }

    return 1;
}

int fila_desenfileirar(Fila fila, int *valor){
    if(fila_vazia(fila)){
        return 0;
    }

    no_t *removido = fila->inicio;

    *valor = removido->valor;

    fila->inicio = removido->proximo;

    if(fila->inicio == NULL){
        fila->fim = NULL;
    }

    free(removido);

    return 1;
}

int fila_inicio(Fila fila, int *valor) {
    if(fila_vazia(fila)){
        return 0;
    }

    *valor = fila->inicio->valor;
    return 1;
}

void fila_exibir(Fila fila) {
    if(fila_vazia(fila)){
        printf("A fila esta vazia!");
        return;
    }

    no_t* atual = fila->inicio;

    printf("Fila: [ "); 
    while(atual != NULL) { 
        printf("%d ", atual->valor); 
        atual = atual->proximo; 
    } 
    printf("]\n");
 
}

void fila_destruir(Fila fila) {
   if(fila == NULL) {return;}
   
   no_t *atual = fila->inicio;

   while(atual != NULL) {
    no_t *proximo_no = atual->proximo;
    free(atual);
    atual = proximo_no;
   }
   free(fila);
}