#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no* prox;
}no;

typedef struct{
    no* inicio;
    no* fim;
}FILA;

FILA* criar(){
    FILA* fila = malloc(sizeof(FILA));
    fila->inicio = NULL;
    fila->fim = NULL;
    return fila;
}

void final(FILA* fila, int valor){
    no* novo = malloc(sizeof(no));

    novo->valor = valor;
    novo->prox = NULL;

    if(fila->fim != NULL){
        fila->fim->prox = novo;
    }else{
        fila->inicio = novo;
    }
    fila->fim = novo;
}

void remover(FILA* fila){
    if(fila->inicio == NULL){
        printf("\nFILA REMOVER VAZIA\n");
        return;
    }

    no* temp = fila->inicio;
    fila->inicio = temp->prox;

    if(fila->inicio == NULL){
        fila->fim = NULL;
    }
    free(temp);
}

void imprimir(FILA* fila){
    if(fila->inicio == NULL){
        printf("\nFILA VAZIA\n");
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
    no* atual = fila->inicio;
    
    while(atual != NULL){
        no* temp = atual;
        atual = atual->prox;
        free(temp);
    }
    free(fila);
    printf("\nMEMORIA LIBERADA\n");
}

void impar_par(FILA* fila){
    if(fila->inicio == NULL){
        printf("\nFILA IMPAR_PAR VAZIA\n");
        return;
    }

    no *atual = fila->inicio; 
    FILA* impar = criar(), *par = criar();

    while(atual != NULL){
        if(atual->valor % 2 == 0){
            final(par, atual->valor);
        }else{
            final(impar, atual->valor);
        }
        atual = atual->prox;
    }
    imprimir(par);
    imprimir(impar);
}

int main(){
    FILA* fila = criar();

    final(fila, 1);
    final(fila, 2);
    final(fila, 3);
    final(fila, 4);
    final(fila, 5);
    imprimir(fila);
    impar_par(fila);
    liberar(fila);
    return 0;
}