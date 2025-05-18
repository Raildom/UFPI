#include <stdio.h>

int main(){
    int array[5] = {1, 8, 3, 4, 5}, *ptr = array, maior = 0;

    for(int i = 0; i < 5; i++){
        if(*(ptr + i) > maior){
            maior = *(ptr + i);

        }
    }
    printf("O maior numero e: %d\n", maior);
    return 0;
}