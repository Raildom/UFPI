#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int NumeroSecreto();

int main(){
    int numero, NumeroSecret, i = 0;

    srand(time(NULL));
    NumeroSecret = NumeroSecreto();
    printf("Eu tenho um numero entre 1 e 1000\nVoce pode adivinhar meu numero?\n");
    printf("Digite seu Primeiro palpite: ");
    do{
        scanf("%d", &numero);
        if(numero == NumeroSecret){
            printf("\nExelente! Voce adivinhou o numero!\nNumero de tentativas: %d", i + 1);
        }else if(numero < NumeroSecret){
            printf("\nMuito baixo. Tente novamente.\n");
        }else if(numero > NumeroSecret){
            printf("\nMuito alto. Tente novamente.\n");
        }
        i++;
    }while(numero != NumeroSecret);

    return 0;
}

int NumeroSecreto(){
    return rand() % 1000 + 1;
}