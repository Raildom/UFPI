#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no* prox;
}no;

typedef struct{
    no* inicio;
    no* final;
}FILA;

FILA* criar(){
    FILA* fila = malloc(sizeof(FILA));

    fila->final = NULL;
    fila->inicio = NULL;
    return fila;
}

void final(FILA* fila, int valor){
    no* novo = malloc(sizeof(no));

    novo->valor = valor;
    novo->prox = NULL;

    if(fila->final != NULL){
        fila->final->prox = novo;
    }else{
        fila->inicio = novo;
    }
    fila->final = novo;
}

void imprimir(FILA* fila){
    if(fila->inicio == NULL){
        printf("\nFILA IMPRIMIR VAZIA\n");
        return;
    }

    no* atual = fila->inicio;

    printf("\nFILA: ");
    while(atual != NULL){
        printf("%d ", atual->valor);
        atual = atual->prox;
    }
    printf("\n");
}

void liberar(FILA* fila){
    if(fila->inicio == NULL){
        printf("\nFILA LIBERAR VAZIA\n");
        return;
    }

    no* atual = fila->inicio;

    while(atual != NULL){
        no* temp = atual;
        atual = atual->prox;
        free(temp);
    }
    free(fila);
    printf("\nMEMORIA LIBERADA\n");
}

void soma(FILA* fila){
    if(fila->inicio == NULL){
        printf("\nFILA SOMA VAZIA\n");
        return;
    }

    no* atual = fila->inicio;
    int soma = 0;

    while(atual != NULL){
        soma += atual->valor;
        atual = atual->prox;
    }
    printf("\nSOMA: %d\n", soma);
}

int main(){
    FILA* fila = criar();

    final(fila, 1);
    final(fila, 2);
    final(fila, 3);
    imprimir(fila);
    soma(fila);
    liberar(fila);
    return 0;
}