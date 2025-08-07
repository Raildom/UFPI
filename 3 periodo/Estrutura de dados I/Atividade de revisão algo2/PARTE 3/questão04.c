#include <stdio.h>

int main(){
    int array[5] = {1, 2, 3, 4, 5}, *ptr1 = array, *ptr2 = array + 4, aux;

    for(int i = 0; i < 5; i++){
        printf("array inicio[%d] = %d\n", i, array[i]);
    }
    for(int i = 0; i < 5 / 2; i++){
        aux = *ptr1;
        *ptr1 = *ptr2;
        *ptr2 = aux;
        ptr1++;
        ptr2--;
    }
    for(int i = 0; i < 5; i++){
        printf("array fim[%d] = %d\n", i, array[i]);
    }
    return 0;
}