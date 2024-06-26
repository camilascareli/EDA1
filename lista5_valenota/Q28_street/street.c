#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

// Estrutura para representar um caminhão
typedef struct {
    int id;
} Truck;

int main() {
    int n, i, truck_id, current, top;
    Truck sideStreet[MAX]; // Simula a pilha para a rua lateral

    while (1) {
        scanf("%d", &n);
        if (n == 0) break; // Encerra a leitura quando encontra 0

        int order[MAX];
        for (i = 0; i < n; i++) {
            scanf("%d", &order[i]);
        }

        current = 1; // Número atual que estamos tentando organizar
        top = -1; // Topo da pilha (rua lateral)

        for (i = 0; i < n; i++) {
            truck_id = order[i];

            while (top != -1 && sideStreet[top].id == current) {
                top--; // Remove da rua lateral
                current++; // Incrementa o número que estamos tentando organizar
            }

            if (truck_id == current) {
                current++; // O caminhão está na ordem correta, continue
            } else if (top == -1 || truck_id < sideStreet[top].id) {
                sideStreet[++top].id = truck_id; // Empilha na rua lateral
            } else {
                printf("no\n");
                goto next_test_case; // Encerra este caso de teste, pois não é possível ordenar
            }
        }

        // Verifica se todos os caminhões da rua lateral podem ser retirados em ordem
        while (top != -1 && sideStreet[top].id == current) {
            top--;
            current++;
        }

        if (current - 1 == n) {
            printf("yes\n");
        } else {
            printf("no\n");
        }

        next_test_case:
        continue;
    }

    return 0;
}