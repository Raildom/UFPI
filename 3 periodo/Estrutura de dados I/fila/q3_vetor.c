#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int* valor;
    int inicio;
    int final;
    int tamanho;
    int capacidade;
}no;

no* criar(int capacidade){
    no* fila = malloc(sizeof(no));
    fila->valor = malloc(capacidade * sizeof(no));
    fila->capacidade = capacidade;
    fila->final = 0;
    fila->inicio = 0;
    fila->tamanho = 0;
    return fila;
}

void final(no* fila, int valor){
    if(fila->capacidade == fila->tamanho){
        printf("\nFILA CHEIA\n");
        return;
    }
    fila->valor[fila->final] = valor;
    fila->final = (fila->final + 1) % fila->capacidade;
    fila->tamanho++;
}

void imprimir(no* fila){
    if(fila->tamanho == 0){
        printf("\nFILA IMPRIMIR VAZIA\n");
        return;
    }

    printf("\nFILA: ");
    for(int i = 0; i < fila->tamanho; i++){
        int indice = (fila->inicio + i) % fila->capacidade;
        printf("%d ", fila->valor[indice]);
    }
    printf("\n");
}

void liberar(no* fila){
    free(fila->valor);
    free(fila);
    printf("\nMEMORIA LIBERADA\n");
}

void remover(no* fila){
    if(fila->tamanho == 0){
        printf("\nFILA REMOVER VAZIA\n");
        return;
    }
    fila->inicio = (fila->inicio + 1) % fila->capacidade;
    fila->tamanho--;
}

void inverter(no* fila){
    if(fila->tamanho == 0 || fila->tamanho == 1){
        printf("\nFILA INVERTER VAZIA OU COM 1 ELEMENTO\n");
        return;
    }

    int indice1, indice2;
    for(int i = 0; i < fila->tamanho - 1; i++){
        indice1 = (fila->inicio + i) % fila->capacidade;
        indice2 = (fila->inicio + fila->tamanho - 1 - i) % fila->capacidade;
        int temp;

        temp = fila->valor[indice1];
        fila->valor[indice1] = fila->valor[indice2];
        fila->valor[indice2] = temp;   
    }
    imprimir(fila);
}

int main(){
    no* fila = criar(4);

    final(fila, 10);
    final(fila, 20);
    final(fila, 30);
    final(fila, 40);
    imprimir(fila);
    inverter(fila);
    liberar(fila);
    return 0;
}