#include <stdio.h>

int main(){
    int array[5] = {1, 2, 3, 4, 5}, *ptr = array;

    for(int i = 0; i < 5; i++){
        *(ptr + i) *= 2;
        printf("array[%d] = %d\n", i, *(ptr + i));
    }
    return 0;
}   