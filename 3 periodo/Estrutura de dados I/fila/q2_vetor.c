#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int* valor;
    int final;
    int inicio;
    int tamanho;
    int capacidade;
}no;

no* criar(int capacidade){
    no* fila = malloc(sizeof(no));
    fila->valor = malloc(capacidade * sizeof(int));
    fila->final = 0;
    fila->inicio = 0;
    fila->tamanho = 0;
    fila->capacidade = capacidade;
    return fila;
}

void final(no* fila, int valor){
    if(fila->tamanho == fila->capacidade){
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

void soma(no* fila){
    if(fila->tamanho == 0){
        printf("\nFILA SOMA VAZIA\n");
        return;
    }

    int soma = 0;

    for(int i = 0; i < fila->tamanho; i++){
        int indice = (fila->inicio + i) % fila->capacidade;
        soma += fila->valor[indice];
    }
    printf("\nA SOMA DA FILA E: %d\n", soma);
}

int main(){
    no* fila = criar(3);

    final(fila, 5);
    final(fila, -5);
    final(fila, 10);
    imprimir(fila);
    soma(fila);
    liberar(fila);
    return 0;
}