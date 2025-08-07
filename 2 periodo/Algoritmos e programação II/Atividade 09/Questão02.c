#include <stdio.h>

void contaProblema(int tempo, int n, int k);

int main(){
    int n, k, tempo = 5;

    scanf("%d%d", &n, &k);
    while(1){
        if(n < 1 || n > 10 || k < 1 || k > 240){
            scanf("%d%d", &n, &k);
        }else{
            break;
        }
    }
    contaProblema(tempo, n, k);
    return 0;
}

void contaProblema(int tempo, int n, int k){
    int i, acumulador = 0;
    for(i = 1; i <= n; i++){
        tempo *= i;
        acumulador += tempo;
        if(acumulador + k > 240){
            break;
        }
        tempo = 5;
    }
    printf("%d", i - 1);
}