#ifndef PILHA_H
#define PILHA_H

typedef struct pilha_t* Pilha;

Pilha pilha_criar();
int pilha_empilhar(Pilha pilha, int valor);
int pilha_desempilhar(Pilha pilha, int *valor);
int pilha_topo(Pilha pilha, int *valor);
int pilha_vazia(Pilha pilha);
void pilha_exibir(Pilha pilha);
void pilha_destruir(Pilha pilha);

#endif