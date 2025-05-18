#include <stdio.h>
#include <math.h>

typedef struct{
    float x;
    float y;
}PONTO;

float elevado(float base, int expoente){
    float resultado = 1;
    
    for(int i = 0; i < expoente; i++){
        resultado *= base;
    }
    return resultado;
}

float distancia(PONTO p1, PONTO p2){
    float resultado = elevado(p2.x - p1.x, 2) + elevado(p2.y - p1.y, 2);
    return sqrt(resultado);
}

int main(){
    PONTO p1, p2;

    printf("Digite o valor de x do ponto 1: ");
    scanf("%f", &p1.x);
    printf("Digite o valor de y do ponto 1: ");
    scanf("%f", &p1.y);
    printf("Digite o valor de x do ponto 2: ");
    scanf("%f", &p2.x);
    printf("Digite o valor de y do ponto 2: ");
    scanf("%f", &p2.y);

    printf("A distancia entre os pontos eh: %.4f\n", distancia(p1, p2));
    return 0;
}