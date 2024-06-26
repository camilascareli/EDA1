#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int dado;
    struct no *esq, *dir;
} no;

no* criarNo(int valor) {
    no* novo = (no*)malloc(sizeof(no));
    if (!novo) {
        fprintf(stderr, "Erro de alocação de memória\n");
        exit(1);
    }
    novo->dado = valor;
    novo->esq = novo->dir = NULL;
    return novo;
}

void pos_ordem(no *raiz) {
    if (raiz == NULL) return;

    no **pilha1 = (no**)malloc(sizeof(no*) * 100);
    no **pilha2 = (no**)malloc(sizeof(no*) * 100);
    int topo1 = 0, topo2 = 0;

    pilha1[topo1++] = raiz;

    while (topo1 > 0) {
        no *noAtual = pilha1[--topo1];
        pilha2[topo2++] = noAtual;

        if (noAtual->esq) {
            pilha1[topo1++] = noAtual->esq;
        }
        if (noAtual->dir) {
            pilha1[topo1++] = noAtual->dir;
        }
    }

    while (topo2 > 0) {
        no *noAtual = pilha2[--topo2];
        printf("%d ", noAtual->dado);
    }

    free(pilha1);
    free(pilha2);
}