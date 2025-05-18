#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct{
    char naipe[4][10];
    char valores[13][10];
} CARTAS;

void CartasOrdenadas(CARTAS baralho);
void CartasAleatorias(CARTAS baralho);
int NaipeAleatorio();
int ValorAleatorio();

int main(){
    CARTAS baralho = {{"Paus", "Ouros", "Copas", "Espadas"}, {"As", "Dois", "Tres", "Quatro", "Cinco", "Seis", "Sete", "Oito", "Nove", "Dez", "Valete", "Dama", "Rei"}};
    int numero;

    scanf("%d", &numero);
    if(numero == 1){
        CartasOrdenadas(baralho);
    }else if(numero == 0){
        CartasAleatorias(baralho);
    }
    return 0;
}

void CartasOrdenadas(CARTAS baralho){
    int i, j;
    for (i = 0; i < 4; i++){
        for (j = 0; j < 13; j++){
            printf("%s de %s\n", baralho.valores[j], baralho.naipe[i]);
        }
    }
}

void CartasAleatorias(CARTAS baralho){
    int naipeAleatorio, valorAleatorio, CartasRestantes = 52, CartaUnica[4][13] = {0};
    srand(time(NULL));
    while(CartasRestantes > 0){
        naipeAleatorio = NaipeAleatorio();
        valorAleatorio = ValorAleatorio();
        if(CartaUnica[naipeAleatorio][valorAleatorio] == 0){
            printf("%s de %s\n", baralho.valores[valorAleatorio], baralho.naipe[naipeAleatorio]);
            CartaUnica[naipeAleatorio][valorAleatorio] = 1;
            CartasRestantes--;
        }
    }
}

int NaipeAleatorio(){
    return rand() % 4;
}

int ValorAleatorio(){
    return rand() % 13;
}