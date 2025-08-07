#include <stdio.h>

int main(){
    int x, y, soma = 0, multiplicacao = 1;

    scanf("%d %d", &x, &y);
    for(int i = x; i <=y; i++){
        if(i % 2 == 0){
            soma += i;
        } else {
            multiplicacao *= i;
        }
    }
    printf("\n%d \n%d", soma, multiplicacao);
    return 0;
}