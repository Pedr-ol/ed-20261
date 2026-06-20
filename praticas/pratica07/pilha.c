#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

typedef struct no_t {
    int valor;
    struct no_t *proximo;
} no_t;

struct pilha_t {
    no_t *topo;
};

Pilha pilha_criar() {
    Pilha pilha = (Pilha)malloc(sizeof(struct pilha_t));

    if(pilha != NULL){
        pilha->topo = NULL;
    }

    return pilha;
}

int pilha_vazia(Pilha pilha){
    return(pilha == NULL || pilha->topo == NULL);
}

int pilha_empilhar(Pilha pilha, int valor){
    if(pilha == NULL) {return 0;}

    no_t* novo = (no_t*)malloc(sizeof(no_t));
    
    if(novo == NULL) {return 0;}

    novo->valor = valor;
    novo->proximo = pilha->topo;
    pilha->topo = novo;

    return 1;
}

int pilha_desempilhar(Pilha pilha, int *valor){
    if(pilha_vazia(pilha)){return 0;}

    no_t* atual = pilha->topo;

    *valor = atual->valor;
    pilha->topo = atual->proximo;

    free(atual);
    return 1;
}

int pilha_topo(Pilha pilha, int *valor){
    if(pilha_vazia(pilha)){return 0;}

    *valor = pilha->topo->valor;

    return -1;
}

void pilha_exibir(Pilha pilha){
    if(pilha_vazia(pilha)){
        printf("A pilha está vazia\n");
        return;
    }

    no_t* atual = pilha->topo;
    
    printf("Pilha: [ ");
    while(atual != NULL) {
        printf("%d ", atual->valor);
        atual = atual->proximo;
    }
    printf("]\n");
}

void pilha_destruir(Pilha pilha){
    if(pilha == NULL) {return;}

    no_t *atual = pilha->topo;
    while(atual != NULL) {
        no_t *proximo_no = atual->proximo;
        free(atual);
        atual = proximo_no;
    }
    free(pilha);
}