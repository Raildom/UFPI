#include <stdio.h>

int maior(int *num1, int *num2){
    if(*num1 > *num2){
        return *num1;
    }
    return *num2;
}

int main(){
    int num1, num2;

    printf("Digite dois numeros: ");
    scanf("%d%d", &num1, &num2);
    int resposta = maior(&num1, &num2);
    printf("O maior numero e: %d\n", resposta);
    return 0;
}