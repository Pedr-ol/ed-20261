#include <stdio.h>
#include "pilha.h"

int main()
{
    Pilha *p = criar();

    empilhar(p, 1);
    empilhar(p, 8);
    empilhar(p, 0);

    No *no = p->topo;
    while (no != NULL)
    {
        printf("%i ->", no->dados);
        no = no->proximo;
    }
    printf("\n");

    desempilhar(p);
    no = p->topo;
    while (no != NULL)
    {
        printf("%i ->", no->dados);
        no = no->proximo;
    }
    printf("\n");

    empilhar(p, 6);
    no = p->topo;
    while (no != NULL)
    {
        printf("%i ->", no->dados);
        no = no->proximo;
    }
    printf("\n");

    desempilhar(p);
    no = p->topo;
    while (no != NULL)
    {
        printf("%i ->", no->dados);
        no = no->proximo;
    }
    printf("\n");

    desempilhar(p);
    no = p->topo;
    while (no != NULL)
    {
        printf("%i ->", no->dados);
        no = no->proximo;
    }
    printf("\n");

    destruir(p);

    return 0;
}