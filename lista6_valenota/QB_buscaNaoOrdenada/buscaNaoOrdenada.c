#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int value;
    int originalIndex;
} Element;

// Função de comparação para qsort
int compareElements(const void *a, const void *b) {
    return ((Element*)a)->value - ((Element*)b)->value;
}

int binarySearch(Element *sortedElements, int numElements, int targetValue) {
    int left = 0, right = numElements - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (sortedElements[mid].value == targetValue)
            return sortedElements[mid].originalIndex;
        if (sortedElements[mid].value < targetValue)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;  // Retorna -1 se não encontrar o valor
}

int main() {
    int numElements, numQueries;
    scanf("%d %d", &numElements, &numQueries);

    Element *elements = (Element*) malloc(numElements * sizeof(Element));
    int *queries = (int*) malloc(numQueries * sizeof(int));

    // Leitura dos elementos do conjunto
    for (int i = 0; i < numElements; i++) {
        scanf("%d", &elements[i].value);
        elements[i].originalIndex = i;
    }

    // Leitura dos elementos a serem buscados
    for (int i = 0; i < numQueries; i++) {
        scanf("%d", &queries[i]);
    }

    // Ordenar o conjunto para a busca binária
    qsort(elements, numElements, sizeof(Element), compareElements);

    // Processamento das consultas
    for (int i = 0; i < numQueries; i++) {
        int result = binarySearch(elements, numElements, queries[i]);
        printf("%d\n", result);
    }

    // Limpeza de memória
    free(elements);
    free(queries);

    return 0;
}