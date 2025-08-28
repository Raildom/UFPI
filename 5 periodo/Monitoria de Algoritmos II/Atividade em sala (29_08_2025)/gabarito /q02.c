#include <stdio.h>

int main(){
    int m, n;

    printf("Digite a quantidade de linhas: \n");
    scanf("%d", &m);
    printf("Digite a quantidade de colunas: \n");
    scanf("%d", &n);

    int matriz[m][n], quant = 0, soma_pares = 0, produto_impares = 1;

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            printf("Digite o numero [%d][%d]\n", i, j);
            scanf("%d", &matriz[i][j]);
            quant++;

            if(matriz[i][j] % 2 == 0){
                soma_pares += matriz[i][j];
            }else{
                produto_impares *= matriz[i][j];
            }
        }
    }

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    printf("Soma dos pares: %d\n", soma_pares);
    printf("produto dos imapres: %d\n", produto_impares);
    printf("Quantidade de numeros na matriz %d\n", quant);

    return 0;
}