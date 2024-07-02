#include <stdio.h>
#include <string.h>

int verifica_palindromo(char *sequencia) {
    int i, j;
    int tamanho = strlen(sequencia);

    for (i = 0, j = tamanho - 1; i < j; i++, j--) {
        if (sequencia[i] != sequencia[j]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int N;
    char sequencia[100];

    scanf("%d", &N);
    scanf("%s", sequencia);

    int resultado = verifica_palindromo(sequencia);

    printf("%d\n", resultado);

    return 0;
}