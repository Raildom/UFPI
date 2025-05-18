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
    FILA* novo = malloc(sizeof(FILA));

    novo->final = NULL;
    novo->inicio = NULL;
    return novo;
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

    while(atual != NULL){
        printf("%d ", atual->valor);
        atual = atual->prox;
    }
    printf("\n");
}

void liberar(FILA* fila){
    no* atual = fila->inicio, *temp = NULL;

    while(atual != NULL){
        temp = atual;
        atual = atual->prox;
        free(temp);
    }
    free(fila);
    printf("\nMEMORIA LIBERADA\n");
}

void remover(FILA* fila){
    if(fila->inicio == NULL){
        printf("\nFILA REMOVER VAZIA\n");
        return;
    }

    no* temp = fila->inicio;
    fila->inicio = fila->inicio->prox;

    if(fila->inicio == NULL){
        fila->final = NULL;
    }
    free(temp);
}

void verifica_crescente(FILA* fila){
    if(fila->inicio == NULL){
        printf("\nFILA VERIFICA_CRESCENTE VAZIA\n");
        return;
    }
    if(fila->inicio->prox == NULL){
        printf("\nVERDADEIRO\n");
        return;
    }

    no* atual = fila->inicio, *proximo = fila->inicio->prox;

    while(atual != NULL){
        if(proximo == NULL){
            break;
        }
        if(atual->valor > proximo->valor){
            printf("\nFALSO\n");
            return;
        }
        atual = atual->prox;
        proximo = proximo->prox;
    }
    printf("\nVERDADEIRO\n");
}

int main(){
    FILA* fila = criar();

    final(fila, 1);
    final(fila, 2);
    final(fila, 3);
    final(fila, 4);
    imprimir(fila);
    verifica_crescente(fila);
    liberar(fila);
    return 0;
}