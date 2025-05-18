#include <stdio.h>

int inverter(int numero);
int main(){
    int numero, numeroInvertido;

    scanf("%d", &numero);
    numeroInvertido = inverter(numero);
    if (numero < 1000 || numero > 9999) {
        printf("Número inválido.\n");
    }else{
        printf("%d\n", numeroInvertido);
    }
    return 0;
}

int inverter(int numero){
    int invertido = 0;

    while (numero > 0) {
        invertido = invertido * 10 + numero % 10;
        numero /= 10;
    }
    return invertido;
}