#include <stdio.h>
#include <stdlib.h>

typedef struct lc{
    int valor;
    int posicao;
    struct lc* prox;
}lc;

int quant = 0;

lc* inserir(lc* lista, int valor){
    lc* novo = malloc(sizeof(lc));

    if(novo == NULL){
        printf("\nerro ao alocar!\n");
        return lista;
    }

    novo->valor = valor;

    if(lista == NULL){
        novo->posicao = 1;
        novo->prox = novo;
        return novo;
    }
    quant++;

    lc* inicio = lista;
    int posicao = 1;

    while(lista->prox != inicio){
        lista = lista->prox;
        posicao++;
    }

    novo->posicao = posicao + 1 ;
    lista->prox = novo;
    novo->prox = inicio;
    return inicio;
}

lc* liberar(lc* lista){
    if(lista == NULL){
        printf("\nlista vazia!!\n");
        return NULL;
    }

    lc *inicio = lista;
    lc *temp;

    do{
        temp = lista;
        lista = lista->prox;
        free(temp);
    }while(lista != inicio);
    printf("\nLista liberada!\n");
    return NULL;
}

void imprimir(lc* lista){
    if(lista == NULL){
        printf("\nlista vazia!\n");
        return;
    }

    lc* inicio = lista;

    do{
        printf("%d ->> ", lista->valor);
        lista = lista->prox;
    }while(lista != inicio);
}

lc* remove_circular(lc* lista, int busca){
    lc* atual = lista;
    lc* anterior = NULL;

    while(lista != NULL && atual->prox != atual){
        for(int i = 0; i < busca; i++){
            anterior = atual;
            atual = atual->prox;
        }
        anterior->prox = atual->prox;
        if(lista == atual){
            lista = lista->prox;
        }
        free(atual);
        quant--;
        atual = anterior->prox;
    }
    printf("\nposicao inicial do ultimo elemento: %d\n", lista->posicao);
    return lista;
}

int main(){
    lc* lista = NULL;
    lista = inserir(lista, 10);
    lista = inserir(lista, 20);
    lista = inserir(lista, 30);
    lista = inserir(lista, 40);
    lista = inserir(lista, 50);

    imprimir(lista);
    lista = remove_circular(lista, 2);
    imprimir(lista);
    lista = liberar(lista);
    return 0;
}