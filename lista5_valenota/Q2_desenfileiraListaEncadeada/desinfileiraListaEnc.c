#include <stdio.h>
#include <stdlib.h>

// Definindo a estrutura de célula que será usada na fila
typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

// Função para desenfileirar um elemento da fila
int desenfileira(celula *f, int *y) {
    // A função assume que 'f' é a cabeça da fila e sempre existe
    celula *primeiro = f->prox;

    // Verificar se a fila está vazia
    if (primeiro == NULL) {
        return 0; // Retorna 0 se a fila estiver vazia
    }

    // Remover o primeiro elemento da fila
    *y = primeiro->dado; // Salva o valor do dado em y
    f->prox = primeiro->prox; // Atualiza o ponteiro da cabeça para o próximo elemento
    free(primeiro); // Libera a memória do elemento removido
    return 1; // Retorna 1 indicando sucesso na remoção
}

