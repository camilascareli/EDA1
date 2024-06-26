#include <stdio.h>
#include <stdlib.h>

typedef struct pista {
    int valor;
    int proxima;
} Pista;

int main() {
    int n, id, valor, prox;
    scanf("%d", &n);

    Pista *pistas = calloc(5001, sizeof(Pista));

    if (!pistas) {
        fprintf(stderr, "Erro ao alocar memÃ³ria.\n");
        exit(1);
    }

    int primeiroID = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &id, &valor, &prox);
        pistas[id].valor = valor;
        pistas[id].proxima = prox;
        if (i == 0) {
            primeiroID = id;
        }
    }


    int atual = primeiroID;
    while (atual != -1) {
        printf("%d\n", pistas[atual].valor);
        atual = pistas[atual].proxima;
    }

    free(pistas);
    return 0;
}