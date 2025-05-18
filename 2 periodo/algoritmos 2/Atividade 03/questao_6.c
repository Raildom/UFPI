#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define tamanho 5

int aleatorio(int maximo);
void PrimeiraLetra(char palavra[]);

void frases(char artigo[][20], char substantivo[][20], char verbo[][20], char preposicao[][20]){
    char frase[100];
    sprintf(frase, "%s %s %s %s %s %s.", artigo[aleatorio(tamanho - 1)], substantivo[aleatorio(tamanho - 1)], verbo[aleatorio(tamanho - 1)], preposicao[aleatorio(tamanho - 1)], artigo[aleatorio(tamanho - 1)], substantivo[aleatorio(tamanho - 1)]);
    PrimeiraLetra(frase);
    printf("%s\n", frase);
}

int main(){
    char artigo[tamanho][20] = {"o", "um", "algum", "todo", "qualquer"}, substantivo[tamanho][20] = {"menino", "homem", "cachorro", "carro", "gato"}, verbo[tamanho][20] = {"passou", "pulou", "correu", "saltos", "andou"}, preposicao[tamanho][20] = {"sobre", "sob", "ante", "ate", "com"};
    srand(time(NULL));
    for (int i = 0; i < 20; i++) {
        frases(artigo, substantivo, verbo, preposicao);
    }
    return 0;
}

int aleatorio(int maximo){
    return rand() % maximo + 1;
}

void PrimeiraLetra(char palavra[]){
    palavra[0] = palavra[0] - 32;
}