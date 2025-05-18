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
    printf(" ->> %d", lista->valor);
    printf("\n");
}

lc* inserir_ordenado(lc* lista, int valor){
    if(lista == NULL){
        lista = inserir(lista, valor);
        return lista;
    }

    lc* inicio = lista, *atual = lista, *proximo = lista->prox, *aux = NULL, *ultimo = lista;

    while(ultimo->prox != inicio){
        ultimo = ultimo->prox;
    }

        if(valor > ultimo->valor && valor > inicio->valor){
            aux = inserir(aux, valor);
            ultimo->prox = aux;
            aux->prox = inicio;
            return inicio;
        }

    do{
        if(valor > atual->valor && valor < proximo->valor){
            aux = inserir(aux, valor);
            atual->prox = aux;
            aux->prox = proximo;
            break;
        }else if(valor < inicio->valor && valor < ultimo->valor){
            aux = inserir(aux, valor);
            aux->prox =  inicio;
            ultimo->prox = aux;
            inicio = aux;
            break;
        }else if(atual == ultimo && valor > atual->valor){

        }else{
            proximo = proximo->prox;
            atual = atual->prox;
        }
    }while(atual != inicio);
    return inicio;
}

int main(){
    lc* lista = NULL;

    lista = inserir(lista, 10);
    lista = inserir(lista, 20);
    lista = inserir(lista, 30);
    lista = inserir(lista, 40);
    imprimir(lista);
    lista = inserir_ordenado(lista, 25);
    imprimir(lista);
    lista = liberar(lista);
    return 0;
}