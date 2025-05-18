#include <stdio.h>

void cubo(int *nPtr);
int main(){
    int numero;

    do{
        if(numero != 0){
            scanf("%d", &numero);
            cubo(&numero);
            printf("%d \n", numero);
        }
    }while(numero != 0);
    return 0;
}

void cubo(int *nPtr){
    *nPtr = (*nPtr) * (*nPtr) * (*nPtr);
}
