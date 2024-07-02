#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct fila {
    int* dados;
    int N, p, u;
} fila;

int enfileira(fila* f, int x) {
    if (f->u == f->N) {
        int* aux = (int*) realloc(f->dados, 2 * f->N * sizeof(int));
        if (!aux) return 0;
        f->dados = aux;
        f->N *= 2;
    }
    f->dados[f->u] = x;
    f->u++;
    return 1;
}