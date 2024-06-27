#include <stdio.h>
#include <stdlib.h>

typedef struct fila {
    int *dados; // Vetor para armazenar os elementos da fila
    int N;      // Tamanho total do vetor dados
    int p;      // Índice do primeiro elemento na fila
    int u;      // Índice logo após o último elemento na fila
} fila;

int desenfileira(fila *f, int *y) {
    // Verifica se a fila está vazia
    if (f->p == f->u) {
        return 0; // Não há elementos para remover
    }

    *y = f->dados[f->p]; // Salva o elemento desenfileirado
    f->p = (f->p + 1) % f->N; // Move o índice do primeiro elemento

    // Verifica se é necessário reduzir o tamanho do vetor
    int tamanho_atual = (f->u - f->p + f->N) % f->N;
    if (tamanho_atual < f->N / 4) {
        int novo_tamanho = f->N / 2;
        int *novo_vetor = (int *)malloc(novo_tamanho * sizeof(int));

        if (!novo_vetor) return 0; // Falha ao alocar novo vetor

        // Copia os elementos para o novo vetor
        for (int i = 0, j = f->p; i < tamanho_atual; ++i) {
            novo_vetor[i] = f->dados[(j + i) % f->N];
        }

        free(f->dados); // Libera o vetor antigo
        f->dados = novo_vetor;
        f->N = novo_tamanho;
        f->p = 0;
        f->u = tamanho_atual;
    }

    return 1; // Sucesso ao remover o elemento
}