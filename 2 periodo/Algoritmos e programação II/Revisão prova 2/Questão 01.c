#include <stdio.h>

int main(){
    int numeroCasas, soma;

    scanf("%d", &numeroCasas);

    int linhas[numeroCasas];
    for(int i = 0; i < numeroCasas; i++){
        scanf("%d", &linhas[i]);
    }
    scanf("%d", &soma);
    
    for(int i = 0; i < numeroCasas; i++){
        if(linhas[i] + linhas[i + 1] == soma){
            printf("%d %d\n", linhas[i], linhas[i + 1]);
        }
    }
    return 0;
}