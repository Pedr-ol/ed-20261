#include <stdio.h>
#include <stdlib.h>
#include "tabela_hash.h"

typedef struct no_t {
    int valor;
    struct no_t *proximo;
} no_t;

struct hash_t {
    no_t **tabela; 
    int tamanho;   
};

static int funcao_hash(int chave, int tamanho) {
    
    int idx = chave % tamanho;
    return (idx < 0) ? (idx + tamanho) : idx;
}

TabelaHash hash_criar(int tamanho) {
    if (tamanho <= 0) return NULL;

    TabelaHash hash = (TabelaHash) malloc(sizeof(struct hash_t));
    if (hash == NULL) return NULL;

    hash->tamanho = tamanho;
    // Aloca o vetor de ponteiros para os nós
    hash->tabela = (no_t **) malloc(tamanho * sizeof(no_t *));
    
    if (hash->tabela == NULL) {
        free(hash);
        return NULL;
    }

    // Inicializa todas as posições da tabela como vazias (NULL)
    for (int i = 0; i < tamanho; i++) {
        hash->tabela[i] = NULL;
    }

    return hash;
}

int hash_inserir(TabelaHash hash, int valor) {
    if (hash == NULL) return 0;

    // Evita duplicatas na tabela hash
    if (hash_buscar(hash, valor)) return 0;

    int idx = funcao_hash(valor, hash->tamanho);

    no_t *novo = (no_t *) malloc(sizeof(no_t));
    if (novo == NULL) return 0;

    novo->valor = valor;
    
    // Insere no início da lista encadeada daquela posição (mais rápido: O(1))
    novo->proximo = hash->tabela[idx];
    hash->tabela[idx] = novo;

    return 1;
}

int hash_buscar(TabelaHash hash, int valor) {
    if (hash == NULL || hash_esta_vazia(hash)) return 0;

    int idx = funcao_hash(valor, hash->tamanho);
    no_t *atual = hash->tabela[idx];

    // Percorre a lista encadeada na posição encontrada
    while (atual != NULL) {
        if (atual->valor == valor) {
            return 1; 
        }
        atual = atual->proximo;
    }

    return 0;
}

int hash_remover(TabelaHash hash, int valor) {
    if (hash == NULL || hash_esta_vazia(hash)) return 0;

    int idx = funcao_hash(valor, hash->tamanho);
    no_t *atual = hash->tabela[idx];
    no_t *anterior = NULL;

    // Procura o elemento na lista encadeada correspondente
    while (atual != NULL && atual->valor != valor) {
        anterior = atual;
        atual = atual->proximo;
    }

    // Se não encontrou o valor
    if (atual == NULL) return 0;

    // Se o elemento a ser removido for o primeiro
    if (anterior == NULL) {
        hash->tabela[idx] = atual->proximo;
    } else {
        anterior->proximo = atual->proximo;
    }

    free(atual);
    return 1;
}

void hash_exibir(TabelaHash hash) {
    if (hash == NULL) return;

    printf("\n--- TABELA HASH ---\n");
    for (int i = 0; i < hash->tamanho; i++) {
        printf("[%2d]: ", i);
        no_t *atual = hash->tabela[i];
        
        if (atual == NULL) {
            printf("NULL");
        } else {
            while (atual != NULL) {
                printf("%d -> ", atual->valor);
                atual = atual->proximo;
            }
            printf("NULL");
        }
        printf("\n");
    }
    printf("-------------------\n");
}

int hash_esta_vazia(TabelaHash hash) {
    if (hash == NULL) return 1;

    // Se encontrar qualquer elemento, a tabela não está vazia
    for (int i = 0; i < hash->tamanho; i++) {
        if (hash->tabela[i] != NULL) {
            return 0; 
        }
    }
    return 1;
}

void hash_destruir(TabelaHash hash) {
    if (hash == NULL) return;

    // Libera cada uma das listas encadeadas
    for (int i = 0; i < hash->tamanho; i++) {
        no_t *atual = hash->tabela[i];
        while (atual != NULL) {
            no_t *aux = atual->proximo;
            free(atual);
            atual = aux;
        }
    }

    // Libera o vetor de ponteiros e a estrutura da hash em si
    free(hash->tabela);
    free(hash);
}