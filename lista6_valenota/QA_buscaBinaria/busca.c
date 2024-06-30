#include <stdio.h>

int buscaBinaria(int v[], int n, int x) {
    int esq = 0, dir = n; // 'dir' começa fora do range do vetor
    while (esq < dir) {
        int meio = esq + (dir - esq) / 2;
        if (v[meio] < x) {
            esq = meio + 1;
        } else {
            dir = meio;
        }
    }
    return dir;
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    int v[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &v[i]);
    }

    for (int i = 0; i < M; i++) {
        int x;
        scanf("%d", &x);
        printf("%d\n", buscaBinaria(v, N, x));
    }

    return 0;
}
