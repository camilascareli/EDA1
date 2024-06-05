#include <stdio.h>
#include <stdlib.h>

void exch(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selection_sort(int *v, int l, int r){
    for(int i=l; i<r; i++){
        int menor =i;
        for(int j = i+1; j<=r; j++){
            if (v[j] < v[menor]){
                menor = j;
            }
        }
        if (i != menor){
            exch(v[i], v[menor]);
        }
    }
}
int main(void){
    int v[1000000];
    for(int i=0; i<1000000; i++){
        v[i] = rand();
    }
    selection_sort(v, 0 , 999999);
    return 0;
}

