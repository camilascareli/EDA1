#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int dado;
    struct no *esq, *dir;
} no;

// Função para criar um novo nó
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

// Função para implementar o percurso em ordem sem recursão
void em_ordem(no *raiz) {
    // Capacidade inicial da pilha
    int capacidade = 10;
    no **pilha = (no**)malloc(capacidade * sizeof(no*));
    int topo = 0;

    no *atual = raiz;

    while (topo > 0 || atual != NULL) {
        // Ir o mais à esquerda possível
        while (atual != NULL) {
            if (topo == capacidade) {
                capacidade *= 2;
                pilha = (no**)realloc(pilha, capacidade * sizeof(no*));
            }
            pilha[topo++] = atual;
            atual = atual->esq;
        }

        // Retroceder um nível e visitar o nó
        atual = pilha[--topo];
        printf("%d ", atual->dado);

        // Visitar o lado direito
        atual = atual->dir;
    }

    free(pilha);
}