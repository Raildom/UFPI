#include <stdio.h>

int main(){
    int N;
    char palavra[50][50];

    scanf("%d", &N);
    for(int k = 0; k < N; k++){
        for(int i = 0; palavra != 0; i++){
            for(int j = 0; palavra != 0; j++){
                scanf("%s", palavra[i][j]);
                fflush(stdin);
            }
        }
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            printf("%s", palavra[i][j]);
        }
    }
}