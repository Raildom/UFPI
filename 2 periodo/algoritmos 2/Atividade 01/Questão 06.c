#include <stdio.h>

int main(){
    int n, soma = 0.0;

    do{
    scanf("%d", &n);
    if(n >= 0){
        soma += n;
    } else{
        break;
    }
    }while(n >= 0);

    printf("\n%d", soma);
    return 0;
}