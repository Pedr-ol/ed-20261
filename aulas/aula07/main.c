#include <stdio.h>
#include "tabela_hash.h"

int main() {
    TabelaHash *tabela = criar(10);

    inserir(tabela, 3);
    inserir(tabela, 12);
    inserir(tabela, 20);
    inserir(tabela, 5);
    
    printf("A tabela hash  tem %i elementos: \n", tabela->quantidade);

    //funcao para printar a tabela hash
    for(int i = 0; i < tabela->tamanho; i++) {
        printf("[%d]-> ", i);
        No *no = tabela->dados[i];
        while(no != NULL){
            printf("%i -> ", no->dado);
            no = no->proximo;
        }
        printf("\n");
    }
    
    printf("Procure o valor 12 na tabela hash: ");
    int achei = buscar(tabela, 12);
    if (achei < 0){
        printf("Nao achei!\n");
    } else {
        printf("Achei na posicao %i\n", achei);
    }

    printf("\nProcure o valor 21 na tabela hash: ");
    achei = buscar(tabela, 21);
    if (achei < 0){
        printf("Nao achei!\n");
    } else {
        printf("Achei na posicao %i\n", achei);
    }

    remover(tabela, 5);

    printf("\n\nA tabela hash  tem %i elementos: \n", tabela->quantidade);
    
    //funcao para printar a tabela
    for(int i = 0; i < tabela->tamanho; i++) {
        printf("[%d]-> ", i);
        No *no = tabela->dados[i];
        while(no != NULL){
            printf("%i -> ", no->dado);
            no = no->proximo;
        }
        printf("\n");
    }

    destruir(tabela);

    return 0;
}