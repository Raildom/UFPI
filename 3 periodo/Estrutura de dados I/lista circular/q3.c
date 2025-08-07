#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct lc{
    char valor[50];
    struct lc* prox;
}lc;

int quant = 0;

lc* inserir(lc* lista, char* valor){
    lc* novo = malloc(sizeof(lc));

    if(novo == NULL){
        printf("\nERRO DE ALOCACAO\n");
        return lista;
    }
    
    strcpy(novo->valor, valor);

    if(lista == NULL){
        novo->prox = novo;
        quant++;
        return novo;
    }

    lc* inicio = lista;

    while(lista->prox != inicio){
        lista = lista->prox;
    }
    lista->prox = novo;
    novo->prox = inicio;
    quant++;
    return inicio;
}

lc* liberar(lc* lista){
    if(lista == NULL){
        printf("\nLISTA VAZIA\n");
        return NULL;
    }

    lc* inicio = lista;
    lc* temp = NULL;

    do{
        temp = lista;
        lista = lista->prox;
        free(temp);
    }while(lista != inicio);
    printf("\nLISTA LIBERADA!!\n");
    return NULL;
}

void imprimir(lc* lista){
    if(lista == NULL){
        printf("\nLISTA VAZIA!\n");
        return;
    }

    lc* inicio = lista;

    do{
        printf("%s ->> ", lista->valor);
        lista = lista->prox;
    }while(lista != inicio);
    printf("\naaa->> %s\n", lista->valor);
}

lc* inverter(lc* lista){
    if(lista == NULL || lista->prox == lista){
        return lista;
    }
    
    lc* anterior = NULL, *atual = lista, *proximo = NULL;
    do{
        proximo = atual->prox;
        atual->prox = anterior;
        anterior = atual;
        atual = proximo;
    }while(atual != lista);

    lista->prox = anterior;
    lista = anterior;
    return lista;
}

int main(){
    lc* lista = NULL;

    lista = inserir(lista, "ANA");
    lista = inserir(lista, "JOAO");
    lista = inserir(lista, "PEDRO");
    lista = inserir(lista, "MARIA");
    imprimir(lista);
    lista = inverter(lista);
    imprimir(lista);

    lista = liberar(lista);
    return 0;
}