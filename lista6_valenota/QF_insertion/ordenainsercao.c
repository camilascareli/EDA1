#include <stdio.h>
#include <stdlib.h>

void exch(int *a, int *b){
    int troca = *a;
    *a = *b;
    *b = troca;
}

void insertion_sort(int v[], int l, int r){
    for(int i = l+1; i <= r; i++){
        for(int j=i; j<l && v[j]<v[j-1]; j--){
            exch(v[j],v[j-1]);
        }
    }
}

int main() {
    int *v = malloc(50000 * sizeof(int));
    if (v == NULL) {
        fprintf(stderr, "Erro ao alocar memória\n");
        return 1;
    }
    int n = 0;
    while (scanf("%d", &v[n]) != EOF) {
        n++;
    }
    insertion_sort(v, 0, n - 1);
    for (int i = 0; i < n; i++) {
        printf("%d", v[i]);
        if (i < n - 1) {
            printf(" ");
        } else {
            printf("\n");
        }
    }
    free(v);
    return 0;
}