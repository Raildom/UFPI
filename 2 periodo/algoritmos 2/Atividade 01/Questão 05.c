#include <stdio.h>

int main(){
    int mulher1, mulher2, homem1, homem2, soma, produto;

    scanf("%d %d %d %d", &homem1, &homem2, &mulher1, &mulher2);
    if(homem1 > homem2 && mulher1 > mulher2){
        soma = homem1 + mulher2;
        produto = homem2 * mulher1;
    } else if(homem1 < homem2 && mulher1 < mulher2){
        soma = homem2 + mulher1;
        produto = homem1 * mulher2;
    }
    printf("\n%d \n%d", soma, produto);
    return 0;
}