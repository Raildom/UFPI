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
    fila->valor = malloc(sizeof(no));
    fila->capacidade = capacidade;
    fila->final = 0;
    fila->inicio = 0;
    fila->tamanho = 0;
    return fila;
}

void final(no* fila, int valor){
    if(fila->capacidade == fila->tamanho){
        printf("\nFILA FINAL CHEIA\n");
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
    printf("\nFILA: \n");
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

void verifica_crescente(no* fila){
    if(fila->tamanho == 0){
        printf("\nFILA VERIFICA_CRESCENTE VAZIA\n");
        return;
    }
    for(int i = 0; i < fila->tamanho - 1; i++){
        int indice = (fila->inicio + i) % fila->capacidade;
        if(fila->valor[indice] > fila->valor[indice + 1]){
            printf("\nFALSO\n");
            return;
        }
    }
    printf("\nVERDADEIRO\n");
}

int main(){
    no* fila = criar(4);

    final(fila, 1);
    final(fila, 2);
    final(fila, 3);
    final(fila, 4);
    imprimir(fila);
    verifica_crescente(fila);
    liberar(fila);
    return 0;
}