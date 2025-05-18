#include <stdio.h>

int main(){
    float SalarioBruto, Desconto;

    scanf("%f", &SalarioBruto);
    if(SalarioBruto <= 600.0){
        Desconto = 0.0;
    } else if(SalarioBruto > 600.0 && SalarioBruto <= 1200.0){
        Desconto = SalarioBruto * 0.20;
    } else if(SalarioBruto > 1200.0 && SalarioBruto <= 2000.0){
        Desconto = SalarioBruto * 0.25;
    } else if(SalarioBruto > 2000.0){
        Desconto = SalarioBruto * 0.30;
    }
    printf("\n%.2f \n%.2f", Desconto, SalarioBruto - Desconto);
    return 0;
}