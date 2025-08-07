#include <stdio.h>
#include <math.h>

float distancia(float x1, float y1, float x2, float y2);

int main(){
    float x1, y1, x2, y2, DistanciaAB;

    scanf("%f%f%f%f", &x1, &y1, &x2, &y2);
    DistanciaAB = distancia(x1, y1, x2, y2);
    printf("%.2f ", DistanciaAB);
    return 0;
}

float distancia(float x1, float y1, float x2, float y2){
    float A, B, DistanciaAB;
    A = (x2 - x1) * (x2 - x1);
    B = (y2 - y1) * (y2 - y1);
    DistanciaAB = A + B;
    DistanciaAB = sqrt(DistanciaAB);
    return DistanciaAB;
}