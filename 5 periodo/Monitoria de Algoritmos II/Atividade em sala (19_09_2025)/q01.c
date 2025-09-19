#include <stdio.h>

void preencher_matriz(int linhas, int colunas, int matriz[linhas][colunas]){
    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            printf("Digite o valor para a posicao [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
}

int eh_esparsa(int linhas, int colunas, int matriz[linhas][colunas]){
    int quant_zeros = 0, esparsa = 0;

    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++)
            if(matriz[i][j] == 0) quant_zeros++;  
    }

    float proporcao = (float)quant_zeros / (linhas * colunas) * 100;
    
    if(proporcao > 50)
        esparsa = 1;

    return esparsa;
}

int main(){
    int linhas, colunas;

    printf("Digite o numero de linhas e colunas: ");
    scanf("%d %d", &linhas, &colunas);

    int matriz[linhas][colunas];

    preencher_matriz(linhas, colunas, matriz);

    if(eh_esparsa(linhas, colunas, matriz))
        printf("A matriz e esparsa.\n");
    else
        printf("A matriz nao e esparsa.\n");

    return 0;
}
