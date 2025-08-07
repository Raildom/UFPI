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
    printf(">>%d\n", lista->valor);
}

void verifica_sequencia(lc* lista1, lc* lista2){
    if(lista1 == NULL || lista2 == NULL){
        printf("\nUMA LISTA VAZIA!\n");
        return;
    }

    lc* inicio1 = lista1, *inicio2 = lista2, *atual2 = lista2, *atual1 = lista1, *anterior1 = lista1, *anterior2 = lista2;

    do{
        if(atual1->valor == atual2->valor){
            while(atual1 != inicio1){
                anterior1 = atual1;
                atual1 = atual1->prox;
                anterior2 = atual2;
                atual2 = atual2->prox;
                if(atual1->valor != atual2->valor){
                    break;
                }
            }
            if(atual1->prox == inicio1 && atual1->valor == atual2->valor && anterior1->valor == anterior2->valor){
                printf("\nSIM\n");
                return;
            }

        }
        atual1 = inicio1;
        anterior2 = atual2;
        atual2 = atual2->prox;
    }while(atual2 != inicio2);
    printf("\nNAO\n");
}

int main(){
    lc* lista1 = NULL, *lista2 = NULL;

    lista1 = inserir(lista1, 10);
    lista1 = inserir(lista1, 30);
    lista1 = inserir(lista1, 10);
    lista2 = inserir(lista2, 10);
    lista2 = inserir(lista2, 20);
    lista2 = inserir(lista2, 10);
    lista2 = inserir(lista2, 30);
    lista2 = inserir(lista2, 50);

    imprimir(lista1);
    printf(":\n");
    imprimir(lista2);

    verifica_sequencia(lista1, lista2);

    lista1 = liberar(lista1);
    lista2 = liberar(lista2);
    return 0;
}