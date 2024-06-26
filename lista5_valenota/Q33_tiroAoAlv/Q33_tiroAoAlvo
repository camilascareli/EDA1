#include <stdio.h>

int n,m;
long long int r[100010];

int busca_bin(long long int val){
    int inicio = 1;
    int fim = n;
    if(val > r[n])	return 0;

    while(inicio < fim){
        int me = (inicio + fim) / 2;

        if(r[me] >= val){
            fim = me;
        }
        else{
            inicio = me+1;
        }
    }
    return n + 1 - fim;
}


int main(){

    scanf("%d %d",&n, &m);

    for(int i = 1; i <= n; i++){
        scanf("%lld",&r[i]);
        r[i] = r[i] * r[i];
    }

    long long int resp = 0;

    for(int i = 1; i <= m; i++){
        long long int x,y;
        scanf("%lld %lld",&x,&y);

        resp += busca_bin(x*x+y*y);
    }

    printf("%lld\n",resp);

    return 0;
}