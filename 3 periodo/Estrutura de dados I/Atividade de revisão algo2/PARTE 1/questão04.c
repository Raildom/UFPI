#include <stdio.h>

int main(){
    float notas[10], media = 0;

    for(int i = 0; i < 10; i++){
        printf("Digite a nota do aluno %d: ", i + 1);
        scanf("%f", &notas[i]);
        media += notas[i];
    }
    media /= 10;  
    printf("A media das notas e %.2f\n", media);
    return 0;
}