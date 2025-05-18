#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no* prox;
    struct no* ant;
}no;

no* final(no* lista, int valor){
    no* novo = malloc(sizeof(no));

    novo->valor = valor;
    novo->ant = NULL;
    novo->prox = NULL;

    if(lista == NULL) return novo;

    no* atual = lista;

    while(atual->prox != NULL){
        atual = atual->prox;
    }

    atual->prox = novo;
    novo->ant = atual;
    return lista;
}

void imprimir(no* lista){
    if(lista == NULL){
        printf("\nLISTA IMPRIMIR VAZIA\n");
        return;
    }
    printf("\nNULL <-> ");
    while(lista != NULL){
        printf("%d <-> ", lista->valor);
        lista = lista->prox;
    }
    printf("NULL\n");
}

no* liberar(no* lista){
    if(lista == NULL){
        printf("\nLISTA LIBERAR VAZIA\n");
        return NULL;
    }

    no* atual = lista, *temp = NULL;

    while(atual != NULL){
        temp = atual;
        atual = atual->prox;
        free(temp);
    }
    printf("\nMEMORIA LIBERADA\n");
    return NULL;
}

void verifica_palindromo(no* lista){
    if(lista == NULL || lista->prox == NULL){
        printf("\nSIM\n");
        return;
    }

    no* atual = lista, *ultimo = lista;

    while(ultimo->prox != NULL){
        ultimo = ultimo->prox;
    }

    while(atual != ultimo){
        if(atual->valor == ultimo->valor){
            atual = atual->prox;
            ultimo = ultimo->ant;
        }else{
            printf("\nNAO\n");
            return;
        }
        printf("\nquero nao\n");
    }
    printf("\nSIM\n");
}

int main(){
    no* lista = NULL;

    lista = final(lista, 1);
    lista = final(lista, 2);
    lista = final(lista, 3);
    lista = final(lista, 3);
    lista = final(lista, 2);
    lista = final(lista, 1);
    imprimir(lista);
    verifica_palindromo(lista);
    lista = liberar(lista);
    return 0;
}