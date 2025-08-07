#include <stdio.h>
#include <stdlib.h>

typedef struct ldp{
    int valor;
    struct ldp* prox;
    struct ldp* ant;
}ldp;

ldp* inicio(ldp* lista, int valor){
    ldp* novo = (ldp*)malloc(sizeof(ldp));

    novo->valor = valor;
    novo->prox = lista;
    novo->ant = NULL;

    if(lista != NULL){
        lista->ant = novo;
    }else{
        novo->prox = NULL;
    }
    return novo;
}

ldp* fim(ldp* lista, int valor){
    ldp* novo = (ldp*)malloc(sizeof(ldp));
    ldp* aux = lista;

    novo->valor = valor;
    novo->prox = NULL;

    if(lista == NULL){
        novo->ant = NULL;
        return novo;
    }
    while(aux->prox != NULL){
        aux = aux->prox;
    }

    aux->prox = novo;
    novo->ant = aux;
    
    return lista;
}

void imprimir(ldp* lista){
    ldp* aux = lista;

    while(aux != NULL){
        printf("%d -> ", aux->valor);
        aux = aux->prox;
    }
    printf("NULL\n");
}

ldp* liberar(ldp* lista){
    ldp* aux = lista;

    while(aux != NULL){
        ldp* temp = aux->prox;
        free(aux);
        aux = temp;
    }
    printf("\nMemoria liberada\n");
    return NULL;
}


           
int main(){
    ldp* lista = NULL;

    lista = inicio(lista, 10);
    lista = fim(lista, 20);
    lista = inicio(lista, 5);
    lista = fim(lista, 30);
    lista = inicio(lista, 1);

    imprimir(lista);
    lista = liberar(lista);
    return 0;
}