#include <stdio.h>
#include <stdlib.h>
#include "tabela_hash.h"

int main() {
    // Criando uma tabela hash com tamanho 11 (número primo para reduzir colisões)
    TabelaHash minha_hash = hash_criar(11);
    
    if (minha_hash == NULL) {
        printf("Erro ao alocar a tabela hash.\n");
        return 1;
    }
    
    printf("Tabela Hash criada com sucesso!\n");
    printf("Esta vazia? %s\n", hash_esta_vazia(minha_hash) ? "Sim" : "Nao");

    printf("\nInserindo elementos...\n");
    int elementos[] = {15, 22, 33, 44, 26, 12, 7, 18, 29};
    int n = sizeof(elementos) / sizeof(elementos[0]);

    for (int i = 0; i < n; i++) {
        if (hash_inserir(minha_hash, elementos[i])) {
            printf("Inserido: %d\n", elementos[i]);
        } else {
            printf("Falha ao inserir: %d\n", elementos[i]);
        }
    }

    hash_exibir(minha_hash);
    printf("Esta vazia? %s\n", hash_esta_vazia(minha_hash) ? "Sim" : "Nao");

    printf("\n--- Testes de Busca ---\n");
    int buscas[] = {33, 99, 12};
    for (int i = 0; i < 3; i++) {
        if (hash_buscar(minha_hash, buscas[i])) {
            printf("O elemento %d FOI ENCONTRADO na tabela.\n", buscas[i]);
        } else {
            printf("O elemento %d NAO EXISTE na tabela.\n", buscas[i]);
        }
    }

    printf("\n--- Testes de Remocao ---\n");
    int remocoes[] = {22, 15, 100}; // 100 não existe
    for (int i = 0; i < 3; i++) {
        if (hash_remover(minha_hash, remocoes[i])) {
            printf("Elemento %d removido com sucesso.\n", remocoes[i]);
        } else {
            printf("Erro ao remover %d (nao encontrado).\n", remocoes[i]);
        }
    }

    printf("\nTabela apos remocoes:\n");
    hash_exibir(minha_hash);

  
    printf("\nLimpando memoria e destruindo a tabela...\n");
    hash_destruir(minha_hash);
    printf("Programa finalizado com sucesso!\n");

    return 0;
}