#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int LancarMoedas();

int main(){
    int i, ContaCara = 0, resultado;

    srand(time(NULL));
    for (i = 0; i < 100; i++) {
        resultado = LancarMoedas();
        if (resultado == 1) {
            printf("Cara\n");
            ContaCara++;
        } else {
            printf("Coroa\n");
        }
    }
    printf("\nNumero de vezes que 'cara' apareceu: %d\n", ContaCara);
    return 0;
}

int LancarMoedas(){
    return rand() % 2;
}