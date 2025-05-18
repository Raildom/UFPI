#include <stdio.h>

int main(){
    int numeros[10], i, j;

    for(i = 0; i < 10; i++){
        scanf("%d", &numeros[i]);
    }
    printf("\n");
    for(i = 0; i < 10; i++){
        printf("%d %d \t", i, numeros[i]);
        for(j = 0; j < numeros[i]; j++){
            printf("*");
        }
        printf("\n");
    }
    return 0;
}