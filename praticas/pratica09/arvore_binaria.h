#ifndef ARVORE_BINARIA_H
#define ARVORE_BINARIA_H

typedef struct No {
    int dado;
    struct No *esquerda;
    struct No *direita;
} No;

No *criar(int valor);
No *inserir(No *no, int valor);
No *buscar(No *no, int valor);
void destruir(No *no);
void pre_ordem(No *no);
void em_ordem(No *no);
void pos_ordem(No *no);

#endif