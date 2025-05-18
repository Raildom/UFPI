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

lc* liberar(lc* lista){
    if(lista == NULL){
        printf("\nLISTA LIBERAR VAZIA\n");
        return NULL;
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

void imprimir(lc* lista){
    if(lista == NULL){
        printf("\nLISTA IMPRIMIR VAZIA\n");
        return;
    }

    lc* inicio = lista;

    do{
        printf("%d -> ", lista->valor);
        lista = lista->prox;
    }while(lista != inicio);
    printf(">> %d\n", lista->valor);
}

lc* intercalar(lc* lista1, lc* lista2){
    if(lista1 == NULL && lista2 == NULL){
        return NULL;
    }else if(lista1 == NULL){
        return lista2;
    }else if(lista2 == NULL){
        return lista1;
    }

    lc* inicio1 = lista1, *inicio2 = lista2;
    lc* atual1 = lista1, *atual2 = lista2;
    lc* aux1 = lista1, *aux2 = lista2;

    do{
        atual1 = atual1->prox;
        aux1->prox = atual2;
        aux1 = atual1;

        atual2 = atual2->prox;
        aux2->prox = atual1;
        aux2 = atual2;        
    }while(atual1->prox != inicio1 && atual2->prox != inicio2);

    if(atual1->prox == inicio1){
        atual1->prox = atual2;
        while(atual2->prox != inicio2){
            atual2 = atual2->prox;
        }
        atual2->prox = inicio1;
    }
    if(atual2->prox == inicio2){
        atual1 = atual1->prox;
        aux1->prox = atual2;
        atual2->prox = atual1;
        while(atual1->prox != inicio1){
            atual1 = atual1->prox;
        }
    }
    return inicio1;
}

int main(){
    lc* lista = NULL, *lista1 = NULL, *lista2 = NULL;

    lista1 = inserir(lista1, 1);
    lista1 = inserir(lista1, 3);
    lista1 = inserir(lista1, 5);
    lista1 = inserir(lista1, 7);
    lista2 = inserir(lista2, 2);
    lista2 = inserir(lista2, 4);
    lista2 = inserir(lista2, 6);
    lista2 = inserir(lista2, 8);
    imprimir(lista1);
    imprimir(lista2);

    lista = intercalar(lista1, lista2);
    imprimir(lista);

    lista1 = liberar(lista1);
    lista = liberar(lista);
    return 0;
}