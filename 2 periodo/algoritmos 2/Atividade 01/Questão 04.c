#include <stdio.h>

int main(){
    int quantidade;
    float valor;

    scanf("%d", &quantidade);
    if(quantidade < 12){
        valor = quantidade * 1.30;
    } else{
        valor = quantidade * 1.0;
    }
    printf("\n%.2f", valor);
    return 0;
}