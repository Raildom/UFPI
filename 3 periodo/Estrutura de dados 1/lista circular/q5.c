#include <stdio.h>
#include <stdlib.h>

typedef struct lc{
    int valor;
    struct lc* prox;
}lc;

lc* inserir(lc* lista, int valor){
    lc* novo = malloc(sizeof(lc));

    if(novo == NULL){
        printf("\nERRO AO ALOCAR\n");
        return lista;
    }

    novo->valor = valor;

    if(lista == NULL){
        novo->prox = novo;
        return novo;
    }

    lc* inicio = lista;

    while(lista->prox != inicio){
        lista = lista->prox;
    }

    lista->prox = novo;
    novo->prox = inicio;
    return inicio;
}

void imprimir(lc* lista){
    if(lista == NULL){
        printf("\nLISTA IMPRIMIR VAZIA\n");
        return;
    }

    lc* inicio = lista;

    do{
        printf("%d ->> ", lista->valor);
        lista = lista->prox;
    }while(lista != inicio);
    printf("\n");
}

lc* liberar(lc* lista){
    if(lista == NULL){
        printf("\nLISTA LIBERAR VAZIA\n");
        return lista;
    }

    lc* inicio = lista, *temp = NULL;

    do{
        temp = lista;
        lista = lista->prox;
        free(temp);
    }while(lista != inicio);
    printf("\nMEMORIA LIBERADA\n");
    return NULL;
}

lc* remove_repetidos(lc* lista){
    if(lista == NULL || lista->prox == lista){
        return NULL;
    }

    lc* inicio = lista, *atual = lista;

    do{
        lc* aux = atual->prox;
        while(aux != inicio){
            if(atual->valor == aux->valor){
                atual->prox = aux->prox;
                free(aux);
                aux = atual->prox;
            }else{
                aux = aux->prox;
            }
        }
        atual = atual->prox;
    }while(atual != inicio);
    return inicio;
}

int main(){
    lc* lista = NULL;

    lista = inserir(lista, 1);
    lista = inserir(lista, 2);
    lista = inserir(lista, 2);
    lista = inserir(lista, 3);
    lista = inserir(lista, 4);
    lista = inserir(lista, 4);
    imprimir(lista);
    lista = remove_repetidos(lista);
    imprimir(lista);
    lista = liberar(lista);
    return 0;
}