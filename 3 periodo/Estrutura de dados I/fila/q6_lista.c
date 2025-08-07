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

    novo->inicio = NULL;
    novo->final = NULL;
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

    printf("\nFILA: ");
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

FILA* concatena(FILA* fila1, FILA* fila2){
    if(fila1->inicio == NULL && fila2->inicio == NULL) return NULL;
    
    FILA* aux = criar();

    if(fila1->inicio != NULL){
        no* atual = fila1->inicio;

        while(atual != NULL){
            final(aux, atual->valor);
            atual = atual->prox;
        }
    }
    if(fila2->inicio != NULL){
        no* atual = fila2->inicio;

        while(atual != NULL){
            final(aux, atual->valor);
            atual = atual->prox;
        }
    }
    return aux;
}

int main(){
    FILA* fila1 = criar();
    FILA* fila2 = criar();
    FILA* FilaF = criar();

    final(fila1, 1);
    final(fila1, 2);
    final(fila2, 3);
    final(fila2, 4);
    // final(fila, 50);
    printf("Fila apos inseresco:\n");
    imprimir(fila1);
    printf("Fila apos insercoes:\n");
    imprimir(fila2);

    FilaF = concatena(fila1, fila2);
    imprimir(FilaF);

    liberar(fila1);
    liberar(fila2);
    liberar(FilaF);
    return 0;
}