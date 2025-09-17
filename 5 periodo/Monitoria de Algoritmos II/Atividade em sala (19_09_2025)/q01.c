#include <stdio.h>

int ehPrimo(int n){
    int primo = 1;

    if(n <= 1)
        primo = 0;
    else{
        for(int i = 2; i <= n / 2; i++){
            if(n % i == 0)
                primo = 0;
        }
    }
    return primo;
}

int main(){
    int n;

    printf("Digite um numero inteiro: ");
    scanf("%d", &n);

    if(ehPrimo(n) == 1)
        printf("O numero %d e primo.\n", n);
    else
        printf("O numero %d nao e primo.\n", n);
    return 0;
}
