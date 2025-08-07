#include <stdio.h>

int main(){
    int vetor[5];

    for(int i = 0; i < 5; i++){
        printf("Digite o valor do vetor[%d]: ", i);
        scanf("%d", &vetor[i]);
    }
    for(int i = 0; i < 5; i++){
        printf("vetor[%d] * 3 = %d\n", i, vetor[i] * 3);
    }
    return 0;
}