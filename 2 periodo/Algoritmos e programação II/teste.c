#include <stdio.h>
float raiz_quadrada(float numero);

int main() {
    float numero;
    while(1){
        printf("Digite um numero: ");
        scanf("%f", &numero);
        float resultado = raiz_quadrada(numero);
        printf("\nA raiz quadrada de %.2f e: %.5f\n", numero, resultado);
    }
}
float raiz_quadrada(float numero) {
    float estimativa = numero / 2.0, anterior;

    do {
        anterior = estimativa;
        estimativa = (estimativa + numero / estimativa) / 2.0;
    } while (anterior != estimativa);
    return estimativa;
}