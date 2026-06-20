#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

int main() {
    Fila minha_fila = fila_criar();
    if (minha_fila == NULL) {
        printf("Erro ao criar a fila.\n");
        return 1;
    }
    printf("Fila criada com sucesso!\n");

    if (fila_vazia(minha_fila)) {
        printf("A fila esta vazia inicialmente (correto).\n\n");
    }

    printf("--- Enfileirando elementos ---\n");
    int valores[] = {10, 20, 30, 40};
    for (int i = 0; i < 4; i++) {
        if (fila_enfileirar(minha_fila, &valores[i])) {
            printf("Inserido: %d\n", valores[i]);
        }
        fila_exibir(minha_fila);
    }
    printf("\n");

    int valor_inicio;
    if (fila_inicio(minha_fila, &valor_inicio)) {
        printf("Elemento no inicio da fila: %d\n\n", valor_inicio);
    }

    printf("--- Desenfileirando elementos ---\n");
    int valor_removido;
    while (!fila_vazia(minha_fila)) {
        if (fila_desenfileirar(minha_fila, &valor_removido)) {
            printf("Removido: %d\n", valor_removido);
            fila_exibir(minha_fila);
        }
    }
    printf("\n");

    printf("--- Destruindo a fila ---\n");
    int extra = 100;
    fila_enfileirar(minha_fila, &extra); 
    printf("Fila antes de destruir: ");
    fila_exibir(minha_fila);

    fila_destruir(minha_fila);
    printf("Fila liberada da memoria com sucesso!\n");

    return 0;
}