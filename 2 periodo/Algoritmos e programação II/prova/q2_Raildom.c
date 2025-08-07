#include <stdio.h>

void mostraNFibonacci(int n);
int main(){
    int n, i;

    for(i = 0; i < 1; i++){
        scanf("%d", &n);
        if(n > 0 && n < 46){
            mostraNFibonacci(n);
        }else{
            i--;
        }

    }
    return 0;
}

void mostraNFibonacci(int n){
    int numero1 = 0, numero2 = 1, numero3, i;
    
    printf("%d %d ", numero1, numero2);
    for(i = 0; i < n; i++){
        numero3 = numero1 + numero2;
        if(numero3 == n){
            break;
        }else{
            printf("%d ",numero3);
            numero1 = numero2;
            numero2 = numero3;

        }
    }
}