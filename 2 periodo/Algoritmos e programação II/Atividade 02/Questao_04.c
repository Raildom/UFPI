#include <stdio.h>

int main() {
    int array[91] = {0}, n;

    for (int i = 0; i < 10; i++){
        scanf("%d", &n);

        if (n >= 10 && n <= 100){
            if (array[n - 10] == 0) {
                array[n - 10] = 1;
                printf("Numero nao duplicado: %d\n", n); 
            }else{
            }
        }
    }
    return 0;
}