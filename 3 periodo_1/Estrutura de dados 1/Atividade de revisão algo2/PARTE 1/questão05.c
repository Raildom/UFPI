#include <stdio.h>

int main(){
    int num[10];

    for(int i = 0; i < 10; i++){
        printf("Digite o valor do vetor[%d]: ", i);
        scanf("%d", &num[i]);
        if(num[i] % 2 == 0){
            printf("PAR\n");
        }else{
            printf("IMPAR\n");
        }
    }
    return 0;
}