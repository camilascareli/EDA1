#include <stdio.h>
#include <stdlib.h>

typedef struct fila {
    int *dados;
    int N, p, u;
} fila;

int desenfileira(fila *f, int *y) {
    if (f->p == f->u) { // Verifica se a fila está vazia
        return 0; // Retorna 0 se a fila estiver vazia
    }
    *y = f->dados[f->p]; // Salva o elemento no início da fila em y
    f->p = (f->p + 1) % f->N; // Atualiza o início da fila de forma circular
    return 1; // Retorna 1 se a remoção foi bem sucedida
}