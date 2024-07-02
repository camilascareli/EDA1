#include <stdio.h>
#include <stdlib.h>

typedef struct  celula 
{
    int dado;
    struct celula *prox;
}celula;

int desempilha (celula *p, int *y) {
    if (p->prox == NULL) return 0;

    *y = p->prox->dado;

    celula *temp = p->prox;
    p->prox = p->prox->prox;

    free(temp);

    return 1;
}