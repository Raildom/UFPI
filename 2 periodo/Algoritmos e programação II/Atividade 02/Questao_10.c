#include<stdio.h>

void fase(int jogos, char times[], char ganhadores[]){
    int primeiro, segundo;

    for(int i = 0; i < jogos; i++){
        scanf("%d %d", &primeiro, &segundo);
        if(primeiro > segundo){
            ganhadores[i] = times[i * 2];
        }else{
            ganhadores[i] = times[i * 2 + 1];
        }
    }
}

int main(){
    char oitavas[] = "ABCDEFGHIJKLMNOP", quartas[8], semifinal[4], final[2], vencedor[2];

    fase(8, oitavas, quartas);
    fase(4, quartas, semifinal);
    fase(2, semifinal, final);
    fase(1, final, vencedor);
    printf("\n%c", vencedor[0]);
    return 0;
}