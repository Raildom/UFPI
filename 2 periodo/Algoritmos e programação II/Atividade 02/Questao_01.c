#include <stdio.h>

int main(){
    int frequencia[11] = {0}, busca, i = 0;

    do{
        scanf("%d", &busca);
        if(busca != -1){
            frequencia[busca]++;
        }
    }while(busca != -1);

    printf("\n");

    for(i = 0; i < 11; i++){
        printf("\n%d %d ", i, frequencia[i]);
    }
    return 0;
}