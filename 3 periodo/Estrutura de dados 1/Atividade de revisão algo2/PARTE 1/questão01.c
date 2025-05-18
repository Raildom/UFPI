#include <stdio.h>

int main(){
    int N, M;

    printf("Digite o valor de N e M respectivamente: ");
    scanf("%d%d", &N, &M);

    int matriz[N][M];

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            printf("Digite o valor da matriz[%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
    return 0;
}