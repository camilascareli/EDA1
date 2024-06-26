#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int x;
    int y;
} Position;

// Movimentos possíveis de um cavalo em um tabuleiro de xadrez
int movesX[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int movesY[8] = {1, 2, 2, 1, -1, -2, -2, -1};

// Função para verificar se a posição está dentro do tabuleiro
bool isValid(int x, int y) {
    return (x >= 0 && x < 8 && y >= 0 && y < 8);
}

// Função BFS para encontrar o menor número de movimentos do cavalo
int bfs(Position start, Position end) {
    if (start.x == end.x && start.y == end.y) {
        return 0;
    }

    int visited[8][8] = {0}; // Tabuleiro para marcar posições visitadas
    Position queue[64]; // Fila para posições a serem exploradas
    int front = 0, rear = 0;

    // Inicializa a fila com a posição inicial
    queue[rear++] = start;
    visited[start.x][start.y] = 1;

    while (front < rear) {
        Position current = queue[front++];

        // Explora todos os movimentos possíveis do cavalo
        for (int i = 0; i < 8; i++) {
            Position next;
            next.x = current.x + movesX[i];
            next.y = current.y + movesY[i];

            if (isValid(next.x, next.y) && !visited[next.x][next.y]) {
                visited[next.x][next.y] = visited[current.x][current.y] + 1;
                if (next.x == end.x && next.y == end.y) {
                    return visited[next.x][next.y] - 1;
                }
                queue[rear++] = next;
            }
        }
    }

    return -1; // Caso não encontre uma rota
}

int main() {
    char start[3], end[3];
    while (scanf("%s %s", start, end) != EOF) {
        Position startPos = {start[0] - 'a', start[1] - '1'};
        Position endPos = {end[0] - 'a', end[1] - '1'};
        int result = bfs(startPos, endPos);
        printf("To get from %s to %s takes %d knight moves.\n", start, end, result);
    }
    return 0;
}