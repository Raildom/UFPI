#include <stdio.h>

int main(){
    int n, m;
    printf("Insira as dimensões da matriz, linha e coluna, respectivamente: ");
    scanf("%d %d", &n, &m);
    if(n > 0 && m > 0){
        int i, j, matriz[n][m];
        
        for(i = 0; i < n; i++){
            for(j = 0; j < m; j++){
                matriz[i][j] = i * j;
            }
        }
        
        for(i = 0; i < n; i++){
            for(j = 0; j < m; j++){
                printf("%d\t", matriz[i][j]);
            }
            printf("\n");
        }
        
    } else{
        printf("Dimensão(ões) inválida(s)!");
    }

    return 0;
}