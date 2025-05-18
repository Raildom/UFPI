#include <stdio.h>

void compara(int numeros[], int x, int tamanho);

int main(){
    int tamanho, x;

    scanf("%d", &tamanho);

    int numeros[tamanho];

    for(int i = 0; i < tamanho; i++){
        scanf("%d", &numeros[i]);
    }
    scanf("%d", &x);
    compara(numeros, x, tamanho);
    return 0;
}

void compara(int numeros[], int x, int tamanho){
    int count = 0;

    for(int i = 0; i < tamanho; i++){
        if(numeros[i] <= x){
            count++;
        }
    }
    printf("\n%d", count);
}