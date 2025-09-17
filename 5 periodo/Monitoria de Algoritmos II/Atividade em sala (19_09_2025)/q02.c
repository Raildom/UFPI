#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int LancarDados(){
    return rand() % 6 + 1;
}

void MensagemResultado(int primeiro, int segundo, int soma){
    if(soma == 7 || soma == 11){
        printf("A soma dos dados %d + %d = %d \nO Jogador ganhou :)\n", primeiro, segundo, soma);
    }else if(soma == 2 || soma == 3 || soma == 12){
        printf("A soma dos dados %d + %d = %d \nO Jogador perdeu :(\n", primeiro, segundo, soma);
    }else if(soma == 4 || soma == 5 || soma == 6 || soma == 8 || soma == 9 || soma == 10){
        printf("A soma dos dados %d + %d = %d \n\nO ponto e %d \n\n", primeiro, segundo, soma, soma);
        JogoPonto(soma);
    }
}

void JogoPonto(int ponto){
    int primeiro, segundo, auxiliar;

    while(1){
        primeiro = LancarDados();
        segundo = LancarDados();
        auxiliar = primeiro + segundo;

        printf("A soma dos dados %d + %d = %d \n", primeiro, segundo, auxiliar);
        if(auxiliar == ponto){
            printf("O Jogador ganhou :)\n");
            break;
        }else if(auxiliar == 7){
            printf("O Jogador perdeu :(\n");
            break;
        }
    }
}

int main(){
    int primeiro, segundo, soma;

    srand(time(NULL));

    primeiro = LancarDados();
    segundo = LancarDados();
    soma = primeiro + segundo;

    MensagemResultado(primeiro, segundo, soma);
    return 0;
}