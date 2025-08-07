#include <stdio.h>

typedef struct{
    float x1;
    float x2;
} Raiz;

Raiz calculaRaiz(float a, float b, float c);
int main(){
    float a, b, c;
    Raiz resultado;

    while(1){
        scanf("%f %f %f", &a, &b, &c);
        resultado = calculaRaiz(a, b, c);
        if(resultado.x1 != -1 && resultado.x2 != -1){
            printf("R1 = %.5f\nR2 = %.5f\n", resultado.x1, resultado.x2);
        }else{
            printf("Impossivel calcular\n");
        }
    }
    return 0;
}

Raiz calculaRaiz(float a, float b, float c){
    Raiz raiz;
    float delta, raizDelta, raizDeltaAproximada;

    delta = (b * b) - ((4 * a) * c);
    if(delta >= 0 && a != 0){
        raizDeltaAproximada = delta / 2;
        do{
            raizDelta = raizDeltaAproximada;
            raizDeltaAproximada = (raizDelta + delta / raizDelta) / 2.0;
        }while(raizDelta != raizDeltaAproximada);
        raiz.x1 = (-b + raizDeltaAproximada) / (2.0 * a);
        raiz.x2 = (-b - raizDeltaAproximada) / (2.0 * a);
    }else{
        raiz.x1 = raiz.x2 = -1;
    }
    return raiz;
}