#include <stdio.h>
#include <math.h>

typedef struct{
    float x;
    float y;
}ponto;

void distancia(ponto p1, ponto p2, float *DISTANCIA);
int main(){
    ponto p1, p2;
    float dist;

    scanf("%f %f %f %f", &p1.x, &p1.y, &p2.x, &p2.y);
    distancia(p1, p2, &dist);
    printf("%.4f\n", dist);
    return 0;
}

void distancia(ponto p1, ponto p2, float *DISTANCIA){
    *DISTANCIA = sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}