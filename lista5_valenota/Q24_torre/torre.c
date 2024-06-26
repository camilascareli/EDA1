#include <stdio.h>
#include <stdlib.h>

#define MAX_N 102
#define MAX_H 100

char terreno[MAX_N][MAX_N];
int alturas[MAX_N * MAX_N];
int n, m, t;

void marcar_visivel(int x, int y, int h) {
    for (int dx = -h; dx <= h; ++dx) {
        for (int dy = -h; dy <= h; ++dy) {
            int nx = x + dx;
            int ny = y + dy;
            if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                if (terreno[nx][ny] == '#') {
                    terreno[nx][ny] = '.';
                }
            }
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; ++i) {
        scanf("%s", terreno[i]);
    }

    t = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (terreno[i][j] == 't') {
                scanf("%d", &alturas[t++]);
            }
        }
    }

    int torre = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (terreno[i][j] == 't') {
                marcar_visivel(i, j, alturas[torre++]);
            }
        }
    }

    int visiveis = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (terreno[i][j] == '.') {
                visiveis++;
            }
        }
    }

    printf("%d\n", visiveis);
    for (int i = 0; i < n; ++i) {
        printf("%s\n", terreno[i]);
    }

    return 0;
}