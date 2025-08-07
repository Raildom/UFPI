#include <stdio.h>
#include <math.h>

typedef struct{
    float x1;
    float x2;
}Raizes;

void calculaRaizes(float a, float b, float c, Raizes *r);
int main(){
    Raizes r;
    float a, b, c;

    while(1){
        scanf("%f %f %f", &a, &b, &c);
        calculaRaizes(a, b, c, &r);
        if(r.x1 == r.x2 && r.x1 == 0){
            printf("Complexo\n");
        }else{
            printf("%.1f %.1f\n", r.x1, r.x2);
        }
    }
    return 0;
}

void calculaRaizes(float a, float b, float c, Raizes *r){
    float delta = b * b - 4 * a * c;
    if (delta >= 0){
        r->x1 = (-b + sqrt(delta)) / (2 * a);
        r->x2 = (-b - sqrt(delta)) / (2 * a);
    }else{
        r->x1 = r->x2 = 0;
    }
}