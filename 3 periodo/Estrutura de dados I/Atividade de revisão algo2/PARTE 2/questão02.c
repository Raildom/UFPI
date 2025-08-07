#include <stdio.h>

float potencia(float x, int n){
    if(n == 0){
        return 1;
    }else if(n == 1){
        return x;
    }else{
        return x * potencia(x, n - 1);
    }
}

int main(){
    float x;
    int n;

    printf("Digite a base e o espoente respectivamente: ");
    scanf("%f%d", &x, &n);
    float resultado = potencia(x, n);
    printf("RESULTADO: %.2f", resultado);
    return 0;
}