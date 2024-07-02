// ERRADO

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define a estrutura para os parâmetros do problema
typedef struct {
    int f; // Total de andares no prédio
    int s; // Andar inicial
    int g; // Andar do objetivo
    int u; // Andares subidos pelo botão UP
    int d; // Andares descidos pelo botão DOWN
} Elevator;

// Função para realizar a busca em largura e encontrar a solução
int bfs(Elevator elevator) {
    if (elevator.s == elevator.g) {
        return 0; // Já está no andar desejado
    }

    int* visitados = (int*)calloc(elevator.f + 1, sizeof(int));
    int* queue = (int*)malloc((elevator.f + 1) * sizeof(int));
    int front = 0, rear = 0;

    // Inicializa a fila com o andar inicial
    queue[rear++] = elevator.s;
    visitados[elevator.s] = 1;

    while (front < rear) {
        int current = queue[front++];
        int next;

        // Tentar mover para cima
        if (elevator.u > 0) {
            next = current + elevator.u;
            if (next == elevator.g) {
                free(visitados);
                free(queue);
                return visitados[current];
            }
            if (next <= elevator.f && visitados[next] == 0) {
                queue[rear++] = next;
                visitados[next] = visitados[current] + 1;
            }
        }

        // Tentar mover para baixo
        if (elevator.d > 0) {
            next = current - elevator.d;
            if (next == elevator.g) {
                free(visitados);
                free(queue);
                return visitados[current];
            }
            if (next >= 1 && visitados[next] == 0) {
                queue[rear++] = next;
                visitados[next] = visitados[current] + 1;
            }
        }
    }

    free(visitados);
    free(queue);
    return -1; // Não é possível chegar ao andar desejado
}

