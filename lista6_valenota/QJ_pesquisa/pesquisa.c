#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura para armazenar uma instrução
typedef struct {
    int code;
    char keyword[16];
} Instruction;

// Função para comparar duas instruções por código (usada para ordenar)
int compareInstructions(const void *a, const void *b) {
    return ((Instruction*)a)->code - ((Instruction*)b)->code;
}

// Função para buscar uma instrução pelo código usando pesquisa binária
char* searchByCode(Instruction *sortedInstructions, int totalCount, int searchCode) {
    int low = 0, high = totalCount - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (sortedInstructions[mid].code == searchCode) {
            return sortedInstructions[mid].keyword;
        } else if (sortedInstructions[mid].code < searchCode) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return "undefined";  // Retorna "undefined" se não encontrar o código
}

int main() {
    int instructionCount;
    scanf("%d", &instructionCount);

    Instruction *instructionList = (Instruction*)malloc(instructionCount * sizeof(Instruction));

    for (int i = 0; i < instructionCount; i++) {
        scanf("%d %s", &instructionList[i].code, instructionList[i].keyword);
    }

    // Ordena as instruções por código para viabilizar a busca binária
    qsort(instructionList, instructionCount, sizeof(Instruction), compareInstructions);

    int queryCode;
    while (scanf("%d", &queryCode) != EOF) {
        printf("%s\n", searchByCode(instructionList, instructionCount, queryCode));
    }

    free(instructionList);
    return 0;
}