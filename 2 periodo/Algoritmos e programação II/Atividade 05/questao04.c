#include <stdio.h>

typedef struct{
    float real;
    float imag;
}Complexo;

void somaComplexo(Complexo num1, Complexo num2, Complexo *num3);
int main(){
    Complexo z1, z2, z3;
    while(1){
        scanf("%f %f %f %f", &z1.real, &z1.imag, &z2.real, &z2.imag);
        somaComplexo(z1, z2, &z3);
        printf("Resultado: %.1lf + %.1lfi\n", z3.real, z3.imag);
    }
    return 0;
}

void somaComplexo(Complexo num1, Complexo num2, Complexo *num3){
    num3->real = num1.real + num2.real;
    num3->imag = num1.imag + num2.imag;
}