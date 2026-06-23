#include <stdio.h>
#include <stdlib.h>
#include "arvore_binaria.h"

No *criar(int valor) {
    No *no = (No *) malloc(sizeof(No));
    if (no == NULL) {
        return NULL;
    }
        
    no->dado = valor;
    no->esquerda = NULL;
    no->direita = NULL;
    
    return no;
}

No *inserir(No *no, int valor) {
    if (no == NULL) {
        return criar(valor);
    }

    if (valor < no->dado) {
        no->esquerda = inserir(no->esquerda, valor);
    } else if (valor > no->dado) {
        no->direita = inserir(no->direita, valor);
    }

    return no;
}

No *buscar(No *no, int valor) {
    if (no == NULL) {
        return NULL;
    }

    if (no->dado == valor) {
        return no;
    }

    if (valor < no->dado) {
        return buscar(no->esquerda, valor);
    } else {
        return buscar(no->direita, valor);
    }
}

void destruir(No *no) {
    if (no == NULL) {
        return;
    }
    destruir(no->esquerda);
    destruir(no->direita);
    free(no);
}

void pre_ordem(No *no) {
    if (no == NULL) {
        return;
    }
    printf("[%i] ", no->dado);
    pre_ordem(no->esquerda);
    pre_ordem(no->direita);
}

void em_ordem(No *no) {
    if (no == NULL) {
        return;
    }

    em_ordem(no->esquerda);
    printf("[%i] ", no->dado); 
    em_ordem(no->direita);
}

void pos_ordem(No *no) {
    if (no == NULL) {
        return;
    }

    pos_ordem(no->esquerda);
    pos_ordem(no->direita);
    printf("[%i] ", no->dado); 
}