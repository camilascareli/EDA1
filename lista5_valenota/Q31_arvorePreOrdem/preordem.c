#include <stdio.h>
#include <stdlib.h>

// Definição da struct no conforme especificado no documento
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

// Função para realizar o percurso pré-ordem sem recursão
void pre_ordem(no *raiz) {
    if (raiz == NULL) return;

    // Pilha para armazenar os nós da árvore
    no **pilha = (no**)malloc(sizeof(no*) * 100); // Ajuste o tamanho conforme necessário
    int topo = 0;

    // Empilhar o nó raiz
    pilha[topo++] = raiz;

    while (topo > 0) {
        no *noAtual = pilha[--topo];
        printf("%d ", noAtual->dado);

        // Empilhar o filho direito primeiro para que o filho esquerdo seja processado primeiro
        if (noAtual->dir) {
            pilha[topo++] = noAtual->dir;
        }
        if (noAtual->esq) {
            pilha[topo++] = noAtual->esq;
        }
    }

    free(pilha);
}