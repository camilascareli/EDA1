#include <stdio.h>
#include <stdlib.h>

typedef struct pilha {
    int *dados;
    int N;
    int topo;
} pilha;

int empilha(pilha *p, int x) {
    if (p->topo == p->N) {
        int novo_tamanho = p->N * 2;
        int *novo_vetor = realloc(p->dados, novo_tamanho * sizeof(int));
        if (novo_vetor == NULL) return 0;
        p->dados = novo_vetor;
        p->N = novo_tamanho;
    }
    p->dados[p->topo] = x;
    p->topo++;
    return 1;
}