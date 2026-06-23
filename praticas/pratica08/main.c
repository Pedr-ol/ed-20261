#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

int main() {
    // 1. Criar a fila
    Fila minha_fila = fila_criar();
    if (minha_fila == NULL) {
        printf("Erro ao criar a fila.\n");
        return 1;
    }
    printf("Fila criada com sucesso!\n");

    // 2. Testar se está vazia no início
    if (fila_vazia(minha_fila)) {
        printf("A fila esta vazia inicialmente (correto).\n\n");
    }

    // 3. Inserir elementos (Enfileirar)
    printf("--- Enfileirando elementos ---\n");
    int valores[] = {10, 20, 30, 40};
    for (int i = 0; i < 4; i++) {
        // Passamos o endereço do valor, já que sua função pede int*
        if (fila_enfileirar(minha_fila, &valores[i])) {
            printf("Inserido: %d\n", valores[i]);
        }
        fila_exibir(minha_fila);
    }
    printf("\n");

    // 4. Espiar o início da fila
    int valor_inicio;
    if (fila_inicio(minha_fila, &valor_inicio)) {
        printf("Elemento no inicio da fila: %d\n\n", valor_inicio);
    }

    // 5. Remover elementos (Desenfileirar)
    printf("--- Desenfileirando elementos ---\n");
    int valor_removido;
    while (!fila_vazia(minha_fila)) {
        if (fila_desenfileirar(minha_fila, &valor_removido)) {
            printf("Removido: %d\n", valor_removido);
            fila_exibir(minha_fila);
        }
    }
    printf("\n");

    // 6. Testar destruição com fila vazia (ou reinserir e destruir)
    printf("--- Destruindo a fila ---\n");
    int extra = 100;
    fila_enfileirar(minha_fila, &extra); // Coloca um elemento só para testar a limpeza
    printf("Fila antes de destruir: ");
    fila_exibir(minha_fila);

    fila_destruir(minha_fila);
    printf("Fila liberada da memoria com sucesso!\n");

    return 0;
}