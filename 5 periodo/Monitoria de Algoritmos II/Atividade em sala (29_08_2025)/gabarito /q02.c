#include <stdio.h>
#define LINHAS 5
#define COLUNAS 5

int main(){
    int matriz[LINHAS][COLUNAS] = {
        {1, 0, 0, 0, 1},
        {0, 1, 1, 1, 0},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {1, 1, 1, 0, 1}
    };

    int contador_padrao = 0;

    printf("--- Matriz de Entrada ---\n");
    for(int i = 0; i < LINHAS; i++){
        for(int j = 0; j < COLUNAS; j++){
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

   
    for(int i = 0; i < LINHAS - 1; i++){
        for(int j = 0; j < COLUNAS - 1; j++){
            if(matriz[i][j] == 1 && matriz[i][j+1] == 0 && matriz[i+1][j] == 0 && matriz[i+1][j+1] == 1){
                contador_padrao++; 
            }
        }
    }

    printf("O padrao [[1, 0], [0, 1]] foi encontrado %d vez(es).\n", contador_padrao);
    return 0;
}
