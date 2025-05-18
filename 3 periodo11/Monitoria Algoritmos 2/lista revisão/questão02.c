#include <stdio.h>

typedef struct{
    float base;
    float altura;
}retangulo;

float area(retangulo A){
    return A.base * A.altura;
}

float perimetro(retangulo A){
    float p;

    p = 2 * (A.base + A.altura);
    return p;
}


int main(){
    retangulo A;

    printf("Digite a base do retangulo: ");
    scanf("%f", &A.base);
    printf("Digite a altura do retangulo: ");
    scanf("%f", &A.altura);

    printf("Area do retangulo: %.2f\n", area(A));
    printf("Perimetro do retangulo: %.2f\n", perimetro(A));
    return 0;
}