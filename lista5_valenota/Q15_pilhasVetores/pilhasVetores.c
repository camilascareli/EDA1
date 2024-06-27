#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *v;
    int N;
    int topo;
} pilha;

void empilha(pilha *p, int x) {
    if (p->topo == p->N) {
        p->N *= 2;
        p->v = (int *)realloc(p->v, p->N * sizeof(int));
    }
    p->v[p->topo] = x;
    p->topo++;
}

int desempilha(pilha *p, int *y) {
    if (p->topo == 0) {
        return 0;
    }
    p->topo--;
    *y = p->v[p->topo];
    return 1;
}