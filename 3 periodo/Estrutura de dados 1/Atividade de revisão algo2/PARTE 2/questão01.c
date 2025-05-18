#include <stdio.h>

int soma(int num){
    if(num == 0)
        return 0;
    else{
        return num + soma(num - 1);
    }
}

int main(){
    int num;

    printf("DIgite um numero: ");
    scanf("%d", &num);
    int resultado = soma(num);
    printf("SOMA: %d", resultado);

    return 0;
}