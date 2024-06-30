#include <stdio.h>
#include <string.h>
#include <search.h>

// Estrutura para armazenar as sequências de caracteres
typedef struct {
    int length;    // Comprimento da sequência
    char character;  // Caractere que se repete na sequência
    int position;  // Posição inicial da sequência no texto
} CharacterSequence;

// Função para comparar duas sequências
int sequenceCompare(const void *a, const void *b) {
    CharacterSequence *seqA = (CharacterSequence *)a;
    CharacterSequence *seqB = (CharacterSequence *)b;

    // Prioriza o maior comprimento, depois a posição inicial
    if (seqA->length != seqB->length) {
        return seqB->length - seqA->length;  // Descendente por comprimento
    }
    return seqA->position - seqB->position;  // Ascendente por posição
}

// Função para analisar a string e gerar as sequências de caracteres
void analyzeString(char *str) {
    int totalLength = strlen(str);
    CharacterSequence sequences[100000];
    int sequenceCount = 0;

    int index = 0;
    while (index < totalLength) {
        char currentChar = str[index];
        int startPos = index;
        int length = 0;

        while (index < totalLength && str[index] == currentChar) {
            length++;
            index++;
        }

        sequences[sequenceCount].length = length;
        sequences[sequenceCount].character = currentChar;
        sequences[sequenceCount].position = startPos;
        sequenceCount++;
    }

    // Ordena as sequências por comprimento e posição
    qsort(sequences, sequenceCount, sizeof(CharacterSequence), sequenceCompare);

    // Imprime as sequências ordenadas
    for (int i = 0; i < sequenceCount; i++) {
        printf("%d %c %d\n", sequences[i].length, sequences[i].character, sequences[i].position);
    }
}

int main() {
    char inputString[100001];
    scanf("%s", inputString);
    analyzeString(inputString);
    return 0;
}