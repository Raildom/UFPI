#include <stdio.h>

int main(){
    int array[5] = {1, 1, 1, 1, 1}, *ptr = array, soma = 0;

    for(int i = 0; i < 5; i++){
        soma += *(ptr + i);
    }
    printf("A soma dos elementos do array e: %d\n", soma);
    return 0;
}