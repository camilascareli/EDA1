#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int coluna;
    int valor;
} Elemento;

typedef struct no {
    Elemento elem;
    struct no *prox;
} No;

void adicionarElemento(No **linha, int coluna, int valor) {
    No *novo = malloc(sizeof(No));
    if (!novo) {
        perror("Erro ao alocar memória para um novo nó.");
        exit(1);
    }
    novo->elem.coluna = coluna;
    novo->elem.valor = valor;
    novo->prox = *linha;
    *linha = novo;
}

void produtoMatrizVetor(No **matriz, int *vetor, int m, int n, int *resultado) {
    for (int i = 0; i < m; i++) {
        resultado[i] = 0;
        No *atual = matriz[i];
        while (atual) {
            resultado[i] += atual->elem.valor * vetor[atual->elem.coluna];
            atual = atual->prox;
        }
    }
}

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    No **matriz = calloc(m, sizeof(No*));
    if (!matriz) {
        perror("Erro ao alocar memória para a matriz.");
        exit(1);
    }

    int linha, coluna, valor;
    while (scanf("%d %d %d", &linha, &coluna, &valor), linha != -1) {
        adicionarElemento(&matriz[linha], coluna, valor);
    }

    int *vetor = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &vetor[i]);
    }

    int *resultado = malloc(m * sizeof(int));
    produtoMatrizVetor(matriz, vetor, m, n, resultado);

    for (int i = 0; i < m; i++) {
        printf("%d\n", resultado[i]);
    }

    for (int i = 0; i < m; i++) {
        No *atual = matriz[i];
        while (atual) {
            No *tmp = atual;
            atual = atual->prox;
            free(tmp);
        }
    }
    free(matriz);
    free(vetor);
    free(resultado);

    return 0;
}