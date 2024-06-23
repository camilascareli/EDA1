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