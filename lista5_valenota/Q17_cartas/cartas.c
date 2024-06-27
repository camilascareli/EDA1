#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *cartas;
    int frente;  // Indica o índice do elemento na frente da fila
    int tras;    // Indica o índice do elemento no final da fila
    int tamanho; // Tamanho atual da fila
    int capacidade; // Capacidade máxima da fila
} Fila;

// Função para criar uma fila de tamanho 'capacidade'
Fila* criaFila(int capacidade) {
    Fila *fila = (Fila *)malloc(sizeof(Fila));
    fila->capacidade = capacidade;
    fila->frente = 0;
    fila->tamanho = 0;
    fila->tras = capacidade - 1;
    fila->cartas = (int *)malloc(fila->capacidade * sizeof(int));
    return fila;
}

// Função para adicionar uma carta à fila
void enfileira(Fila *fila, int carta) {
    if (fila->tamanho == fila->capacidade) return;
    fila->tras = (fila->tras + 1) % fila->capacidade;
    fila->cartas[fila->tras] = carta;
    fila->tamanho++;
}

// Função para remover a carta da frente da fila
int desenfileira(Fila *fila) {
    if (fila->tamanho == 0) return -1;
    int carta = fila->cartas[fila->frente];
    fila->frente = (fila->frente + 1) % fila->capacidade;
    fila->tamanho--;
    return carta;
}

// Função principal para simular o jogo de cartas
void simulaCartas(int n) {
    Fila *fila = criaFila(n);
    for (int i = 1; i <= n; i++) {
        enfileira(fila, i);
    }

    printf("Cartas descartadas: ");
    while (fila->tamanho > 1) {
        printf("%d", desenfileira(fila));
        enfileira(fila, desenfileira(fila));
        if (fila->tamanho > 1) printf(", ");
    }
    printf("\nCarta restante: %d\n", desenfileira(fila));
    free(fila->cartas);
    free(fila);
}

int main() {
    int n;
    scanf("%d", &n);
    simulaCartas(n);
    return 0;
}