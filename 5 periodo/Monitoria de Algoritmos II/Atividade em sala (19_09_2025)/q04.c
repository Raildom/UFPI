#include <stdio.h>

// Função que verifica e exibe o tipo de triângulo
void verificarTriangulo(float x, float y, float z) {
    // Verifica a condição para ser um triângulo
    if (x < y + z && y < x + z && z < x + y) {
        // Verifica tipo do triângulo
        if (x == y && y == z) {
            printf("Triangulo Equilatero\n");
        } else if (x == y || y == z || x == z) {
            printf("Triangulo Isosceles\n");
        } else {
            printf("Triangulo Escaleno\n");
        }
    } else {
        printf("Nao forma um triangulo\n");
    }
}

int main() {
    float a, b, c;

    printf("Digite os tres lados do triangulo: ");
    scanf("%f %f %f", &a, &b, &c);

    verificarTriangulo(a, b, c);

    return 0;
}