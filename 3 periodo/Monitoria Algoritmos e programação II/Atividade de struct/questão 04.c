#include <stdio.h>

typedef struct{
    int jovem;
    int velho;
}IDADE;

int soma(IDADE homem, IDADE mulher){
    return homem.velho + mulher.jovem;
}

float produto(IDADE homem, IDADE mulher){
    return homem.jovem * mulher.velho;
}


int main(){
    IDADE homem, mulher;

    printf("Digite a idade do homem mais jovem: ");
    scanf("%d", &homem.jovem);
    printf("Digite a idade do homem mais velho: ");
    scanf("%d", &homem.velho);
    printf("Digite a idade da mulher mais jovem: ");
    scanf("%d", &mulher.jovem);
    printf("Digite a idade da mulher mais velha: ");
    scanf("%d", &mulher.velho);

    printf("A soma das idades eh: %d\n", soma(homem, mulher));
    printf("O produto das idades eh: %.2f\n", produto(homem, mulher));
    return 0;
}