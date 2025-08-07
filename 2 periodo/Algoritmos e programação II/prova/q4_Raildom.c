#include <stdio.h>

void mostraSequencia(int n);
int main(){
    int n;

    scanf("%d", &n);
    mostraSequencia(n);
    return 0;
}

void mostraSequencia(int n){
    int i, quadrado, cubo, auxiliar;

    auxiliar = n;
    n = 1;
    for(i = 0; i < auxiliar; i++){
        quadrado = n * n;
        cubo = n * n * n;
        printf("%d %d %d\n", n, quadrado, cubo);
        n++;
    }
}