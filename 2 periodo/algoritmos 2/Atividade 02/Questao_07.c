#include <stdio.h>

int main(){
    int numeros[10] = {2,4,6,8,10,12,14,16,18,20};

    printf(" Elemento\tValor\n");
    for(int i = 0; i < 10; i++){
        printf("\t%d \t%d\n", i, numeros[i]);
    }
    return 0;
}