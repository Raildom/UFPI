#include <stdio.h>
#include <math.h>

struct Distancia{
    float x, y;
};

float distancia(struct Distancia A, struct Distancia B);

int main(){
    struct Distancia pontoA, pontoB;
    float DistanciaAB;
    scanf("%f %f %f %f", &pontoA.x, &pontoA.y, &pontoB.x, &pontoB.y);
    DistanciaAB = distancia(pontoA, pontoB);
    printf("%.4f\n", DistanciaAB);
    return 0;
}

float distancia(struct Distancia A, struct Distancia B){
    float pontoA, pontoB;
    pontoA = B.x - A.x;
    pontoB = B.y - A.y;
    return sqrt(pontoA * pontoA + pontoB * pontoB);
}