#include <stdio.h>

int main(){
    int matriz[3][3], soma = 0;

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            printf("Digite o valor da matriz[%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
    for(int i = 0; i < 3; i++){
        soma = 0;
        for(int j = 0; j < 3; j++){
            soma += matriz[j][i];
        }
        printf("A soma das colunas e %d\n", soma);
    }
    return 0;
}