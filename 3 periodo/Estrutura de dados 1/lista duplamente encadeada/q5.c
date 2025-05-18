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
    novo->prox = NULL;
    novo->ant = NULL;

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

no* rotaciona(no* lista, int valor){
    if(lista == NULL || lista->prox == NULL) return lista;

    no* ultimo = lista, *inicio = lista;

    while(ultimo->prox != NULL){
        ultimo = ultimo->prox;
    }

    for(int i = 0; i < valor; i++){
        ultimo->prox = inicio;
        inicio->ant = ultimo;
        inicio = ultimo;
        ultimo = ultimo->ant;
        inicio->ant = NULL;
        ultimo->prox = NULL;
    }
    return inicio;
}

int main(){
    no* lista = NULL;

    lista = final(lista, 10);
    lista = final(lista, 20);
    lista = final(lista, 30);

    imprimir(lista);
    lista = rotaciona(lista, 5);
    imprimir(lista);
    lista = liberar(lista);
    return 0;
}