#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct{
    char face[10];
    char naipe[10];
}Carta;

void preenche(Carta *deck, char *face[], char *naipe[]);
void embaralha(Carta *deck);
void imprime(Carta *deck);

int main(){
    int opcao;
    char *face[] = {"As", "Dois", "Tres", "Quatro", "Cinco", "Seis", "Sete", "Oito", "Nove", "Dez", "Valete", "Dama", "Rei"};
    char *naipe[] = {"Paus", "Ouros", "Copas", "Espadas"};
    Carta deck[52];

    preenche(deck, face, naipe);
    scanf("%d", &opcao);
    if(opcao == 1){
        imprime(deck);
    }else if(opcao == 0){
        embaralha(deck);
        imprime(deck);
    }
}

void preenche(Carta *deck, char *face[], char *naipe[]){
    int posicao = 0, i, j, k;

    for(i = 0; i < 13; i++){
        for(j = 0; j < 4; j++){
            for(k = 0; face[i][k] != '\0'; k++){
                deck[posicao].face[k] = face[i][k];
            }
            deck[posicao].face[k] = '\0'; 
            for(k = 0; naipe[j][k] != '\0'; k++){
                deck[posicao].naipe[k] = naipe[j][k];
            }
            deck[posicao].naipe[k] = '\0'; 
            posicao++;
        }
    }
}

void embaralha(Carta *deck){
    int i, j;
    Carta auxiliar;

    srand(time(NULL));
    for(i = 0; i < 52; i++){
        j = rand() % 52;
        auxiliar = deck[i];
        deck[i] = deck[j];
        deck[j] = auxiliar;
    }
}

void imprime(Carta *deck){
    int i;
    for(i = 0; i < 52; i++){
        printf("%s de %s\n", deck[i].face, deck[i].naipe);
    }
}