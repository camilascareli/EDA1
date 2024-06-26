#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;


void enfileira(celula **f, int x) {
    celula *nova = malloc(sizeof(celula));
    nova->prox = (*f)->prox;
    (*f)->prox = nova;
    (*f)->dado = x;
    *f = nova;
}

int desenfileira(celula *f, int *y) {

    celula *temp = f->prox;
    if (temp == f) return 0;
    *y = temp->dado;
    f->prox = temp->prox;
    free(temp);
    return 1;
}