#include <stdio.h>

int calculaAgua(int n, int x, int vet[]);

int main(){
    int t;

    scanf("%d", &t);
    for(int i = 0; i < t; i++){
        int n, x;
        scanf("%d %d", &n, &x);
        int vet[n];
        for(int j = 0; j < n; j++){
            scanf("%d", &vet[j]);
        }
        int resultado = calculaAgua(n, x, vet);
        printf("%d\n", resultado);
    }
    return 0;
}

int calculaAgua(int n, int x, int vet[]){
    int h = 1;
    int aguaUsada = 0;

    while(aguaUsada <= x){
        aguaUsada = 0;
        for(int j = 0; j < n; j++){
            if(vet[j] < h){
                aguaUsada += (h - vet[j]);
            }
        }
        if(aguaUsada <= x){
            h++;
        }
    }
    return h - 1;
}