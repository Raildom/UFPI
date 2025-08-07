#include <stdio.h>

void bolha(int vetor[], int M);
int main() {
    int N, M, i, j, numeros;

    scanf("%d", &N);
    for (i = 0; i < N; i++) {
        scanf("%d", &M);
        int vetor[M];
        for (j = 0; j < M; j++) {
            scanf("%d", &numeros);
            vetor[j] = numeros;
        }
        bolha(vetor, M);
    }
    return 0;
}

void bolha(int vetor[], int M){
    int i, j, auxiliar, naotrocou = 0;
    int copia[M];

    for(int k = 0; k < M; k++){
        copia[k] = vetor[k];
    }
    for(i = 0; i < M - 1; i++){
        for(j = 0; j < M - i - 1; j++){
            if(vetor[j] < vetor[j + 1]){
                auxiliar = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = auxiliar;
            }
        }
    }
    for(int k = 0; k < M; k++){
        if(copia[k] == vetor[k]){
            naotrocou++;
        }
    }
    printf("%d\n", naotrocou);
}