#ifndef FILA_H
#define FILA_H

typedef struct fila_t* Fila;

Fila fila_criar();
int fila_enfileirar(Fila fila, int *valor);
int fila_desenfileirar(Fila fila, int *valor);
int fila_inicio(Fila fila, int *valor);
void fila_exibir(Fila fila);
int fila_vazia(Fila fila);
void fila_destruir(Fila fila);

#endif