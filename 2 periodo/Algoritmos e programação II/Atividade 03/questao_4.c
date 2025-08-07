#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int LancarDados();

int main(){
    int primeiro, segundo, soma, i, auxiliar;

    srand(time(NULL));
    primeiro = LancarDados();
    segundo = LancarDados();
    soma = primeiro + segundo;

    if(soma == 7 || soma == 11){
        printf("A soma dos dados %d + %d = %d \nO Jogador ganhou :)\n", primeiro, segundo, soma);
    } else if(soma == 2 || soma == 3 || soma == 12){
        printf("A soma dos dados %d + %d = %d \nO Jogador perdeu :(\n", primeiro, segundo, soma);
    }else if(soma == 4 || soma == 5 || soma == 6 || soma == 8 || soma == 9 ||soma == 10){
        printf("A soma dos dados %d + %d = %d \nO ponto e %d \n", primeiro, segundo, soma, soma);
        for(i = 0; i < 100; i++){
            primeiro = LancarDados();
            segundo = LancarDados();
            auxiliar = primeiro + segundo;
            if(auxiliar == soma){
                 printf("A soma dos dados %d + %d = %d \nO Jogador ganhou :)\n", primeiro, segundo, auxiliar);
                 break;
            }else if(auxiliar == 7){
                 printf("A soma dos dados %d + %d = %d \nO Jogador perdeu :(\n", primeiro, segundo, auxiliar);
                 break;
            }
        }
    }
    return 0;
}

int LancarDados(){
    return rand() % 6 + 1;
}