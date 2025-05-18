#include <stdio.h>

float raizQuadrada(float numero);

int main(){
    int t, n, soma = 0, resultado;

    scanf("%d", &t);
    scanf("%d", &n);
    int Ai[n];
    for(int j = 0; j < t; j++){
        for(int i = 0; i < n; i++){
            scanf("%d", &Ai[i]);
            soma += Ai[i];
        }
        resultado = raizQuadrada(soma);
        if(resultado * resultado == soma){
            printf("Yes\n\n");
        }else{
            printf("No\n\n");
        }
        soma = 0;
        if(j < t - 1){
            scanf("%d", &n);
        }
    }
    return 0;
}

float raizQuadrada(float numero){
    float estimativa = numero / 2, anterior;

    do{
        anterior = estimativa;
        estimativa = (estimativa + numero / estimativa) / 2;
    }while(anterior != estimativa);
    return estimativa;
}