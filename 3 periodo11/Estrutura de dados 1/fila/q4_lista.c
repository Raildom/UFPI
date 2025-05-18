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

int tam1 = 0;
int tam2 = 0;
int tam3 = 0;

FILA* criar(){
    FILA* fila = malloc(sizeof(no));
    
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
    
    no* atual = fila->inicio;
    fila->inicio = fila->inicio->prox;

    if(fila->inicio == NULL){
        fila->final = NULL;
    }
    free(atual);
}

void mercado(FILA* fila){
    if(fila->inicio == NULL){
        printf("\nFILA MERCADO VAZIA\n");
        return;
    }

    no* atual = fila->inicio;
    FILA* caixa1 = criar();
    FILA* caixa2 = criar();
    FILA* caixa3 = criar();

    while(atual != NULL){
        if(tam1 <= tam2 && tam1 <= tam3){
            final(caixa1, atual->valor);
            tam1++;
        }else if(tam2 <= tam1 && tam2 <= tam3){
            final(caixa2, atual->valor);
            tam2++;
        }else{
            final(caixa3, atual->valor);
            tam3++;
        }
        atual = atual->prox;
    }
    printf("\nCAIXA 1: ");
    imprimir(caixa1);
    printf("\nCAIXA 2: ");
    imprimir(caixa2);
    printf("\nCAIXA 3: ");
    imprimir(caixa3);
}

int main(){
    FILA* fila = criar();

    final(fila, 1);
    final(fila, 2);
    final(fila, 3);
    final(fila, 4);
    final(fila, 5);
    imprimir(fila);
    mercado(fila);
    liberar(fila);
    return 0;
}