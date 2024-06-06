#include <stdio.h>
#include <stdlib.h> 

void exch(int *a, int *b) {
    int troca = *a;
    *a = *b;
    *b = troca;
}

void bubble_sort(int *v, int l, int r) {
    int swap = 1; 
    for (; r > l; --r) {
        swap = 0;
        for (int j = l; j < r; j++) {
            if (v[j] > v[j + 1]) {
                exch(&v[j], &v[j + 1]); 
                swap = 1;
            }
        }
    }
}

int main(void) {
    int v[1000]; 
    int num;
    int count = 0; 
    while (scanf("%d", &num) != EOF && count < 1000) {
        v[count++] = num;
    }
    bubble_sort(v, 0, count - 1);
    for (int i = 0; i < count; i++) {
        printf("%d", v[i]);
        if (i < count - 1) {
            printf(" ");
        } else {
            printf("\n");
        }
    }

    return 0;
}
