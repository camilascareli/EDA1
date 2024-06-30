#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    int *houseNumbers = malloc(N * sizeof(int));
    int *positions = malloc(1000000001 * sizeof(int)); // Inicializa array para posições (tamanho baseado no número máximo da casa)
    for (int i = 0; i < N; i++) {
        scanf("%d", &houseNumbers[i]);
        positions[houseNumbers[i]] = i; // Mapeia o número da casa para a sua posição na rua
    }

    int *deliverySequence = malloc(M * sizeof(int));
    for (int i = 0; i < M; i++) {
        scanf("%d", &deliverySequence[i]);
    }

    // Inicia o carteiro na primeira casa
    int currentPosition = positions[houseNumbers[0]];
    int totalTime = 0;
    for (int i = 0; i < M; i++) {
        int nextPosition = positions[deliverySequence[i]];
        totalTime += abs(nextPosition - currentPosition); // Calcula a distância absoluta entre as posições
        currentPosition = nextPosition; // Atualiza a posição do carteiro para a próxima entrega
    }

    printf("%d\n", totalTime); // Imprime o tempo total necessário

    // Libera memória alocada
    free(houseNumbers);
    free(positions);
    free(deliverySequence);

    return 0;
}