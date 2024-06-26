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

// Função para inserir elementos na árvore
no* inserir(no* raiz, int valor) {
    if (raiz == NULL) {
        return criarNo(valor);
    }

    if (valor < raiz->dado) {
        raiz->esq = inserir(raiz->esq, valor);
    } else {
        raiz->dir = inserir(raiz->dir, valor);
    }

    return raiz;
}

// Função para percurso pré-ordem
void pre_ordem(no *raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->dado);
        pre_ordem(raiz->esq);
        pre_ordem(raiz->dir);
    }
}

// Função para percurso em ordem
void em_ordem(no *raiz) {
    if (raiz != NULL) {
        em_ordem(raiz->esq);
        printf("%d ", raiz->dado);
        em_ordem(raiz->dir);
    }
}

// Função para percurso pós-ordem
void pos_ordem(no *raiz) {
    if (raiz != NULL) {
        pos_ordem(raiz->esq);
        pos_ordem(raiz->dir);
        printf("%d ", raiz->dado);
    }
}

int main() {
    no* raiz = NULL;
    int valor;

    // Ler valores até EOF
    while (scanf("%d", &valor) != EOF) {
        raiz = inserir(raiz, valor);
    }

    // Saída conforme especificação
    pre_ordem(raiz);
    printf(".\n");
    em_ordem(raiz);
    printf(".\n");
    pos_ordem(raiz);
    printf(".\n");

    return 0;
}