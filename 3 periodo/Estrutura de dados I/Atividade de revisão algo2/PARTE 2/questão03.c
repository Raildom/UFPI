#include <stdio.h>

int produto(int n1, int n2){
    if(n1 == 0 || n2 == 0){
        return 0;
    }else{
        return n1 + produto(n1, n2 - 1);
    }

}

int main(){
    int num1, num2, resultado;

    printf("Digite dois numeros: ");
    scanf("%d%d", &num1, &num2);
    resultado = produto(num1, num2);
    printf("RESULTADO: %d", resultado);
    return 0;
}   