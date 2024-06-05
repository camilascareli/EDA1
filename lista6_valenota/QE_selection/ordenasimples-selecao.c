#include <stdio.h>
#include <stdlib.h>

void exch(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selection_sort(int *v, int l, int r){
    for(int i=l; i<r; i++){
        int menor = i;
        for(int j = i+1; j<=r; j++){
            if (v[j] < v[menor]){
                menor = j;
            }
        }
        if (i != menor){
            exch(&v[i], &v[menor]);
        }
    }
}

int main(void){
    int numeros[1000];
    int tamanho = 0;

    while (scanf("%d", &numeros[tamanho]) != EOF && tamanho < 1000) {
        tamanho++;
    }

    selection_sort(numeros, 0, tamanho - 1);

    for(int i = 0; i < tamanho; i++){
        printf("%d", numeros[i]);
        if (i < tamanho - 1) {
            printf(" ");
        }
    }
    printf("\n");

    return 0;
}
