#include <stdio.h>

void exch (int *a, int *b){
    int troca = *a;
    *a = *b;
    *b = troca; 
}

void bubble_sort(int *v, int l, int r){
    int swap = 1; // Garante que o loop execute pelo menos uma vez
    for(; r>l; --r){
        swap = 0;
        for(int j=l; j<r; j++){
            if(v[j] > v[j+1])
                exch(v[j], v[j+1]);
                swap = 1;
        }
    }
}

int main(void){
    int v[1000000];
    for(int i=0; i<1000000; i++){
        v[i] = rand();
    }
    bubble_sort(v, 0 , 999999);
    return 0;
}