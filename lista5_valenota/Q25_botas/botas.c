#include <stdio.h>
#include <string.h>

#define MAX_SIZE 61  // Tamanho máximo + 1 para facilitar o acesso direto ao índice

int main() {
    int right[MAX_SIZE], left[MAX_SIZE];  // Arrays para contar botas direitas e esquerdas
    memset(right, 0, sizeof(right));  // Inicializa os contadores de botas direitas
    memset(left, 0, sizeof(left));    // Inicializa os contadores de botas esquerdas

    int size;    // Tamanho da bota
    char foot;   // Pé da bota ('D' para direito, 'E' para esquerdo)

    // Leitura das entradas até EOF
    while (scanf("%d %c", &size, &foot) != EOF) {
        if (foot == 'D') {
            right[size]++;  // Incrementa o contador de botas direitas do tamanho correspondente
        } else if (foot == 'E') {
            left[size]++;   // Incrementa o contador de botas esquerdas do tamanho correspondente
        }
    }

    int pairs = 0;  // Contador de pares formados
    // Calcular o número de pares para cada tamanho possível
    for (int i = 30; i <= 60; i++) {
        pairs += (right[i] < left[i] ? right[i] : left[i]);  // Adiciona o menor dos contadores de cada pé
    }

    printf("%d\n", pairs);  // Imprime o número total de pares que podem ser formados

    return 0;
}