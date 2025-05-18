#include <stdio.h>

typedef struct
{
    float base;
    float altura;
} retangulo;

float area(retangulo var);
float perimetro(retangulo var);

int main()
{

    retangulo var;

    scanf("%f", &var.altura);
    scanf("%f", &var.base);



    printf("\narea: %.2f\nperimetro: %.2f", area(var), perimetro(var));

    return 0;
}

float area(retangulo var)
{
    return var.base * var.altura;
}

float perimetro(retangulo var)
{
    return (var.base + var.altura) * 2;
}