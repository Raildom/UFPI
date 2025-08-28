#include <stdio.h>
#define TAM 10

int main(){
    int vetor[TAM], i = 0;

    for(i = 0; i < TAM; i++){
        printf("Digite o %d numero: ", i + 1);
        scanf("%d", &vetor[i]);  
    }

    int final = i - 1, aux;

    for(i = 0; i < TAM/2; i++){
        aux = vetor[i];
        vetor[i] = vetor[final];
        vetor[final] = aux;
        final--;
    }
    
    for(i = 0; i < TAM; i++){
        printf(":%d\n", vetor[i]);
    }
    
    return 0;
}