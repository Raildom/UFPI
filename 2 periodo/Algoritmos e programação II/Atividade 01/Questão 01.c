#include <stdio.h>

int main(){
    float compra, venda;

    scanf("%f", &compra);
    if(compra < 20.0){
        venda = compra * 1.45;
    } else{
        venda = compra * 1.30;
    }
    printf("\n%.2f", venda);
    return 0;
}