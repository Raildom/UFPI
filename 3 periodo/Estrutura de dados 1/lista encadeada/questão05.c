#include <stdio.h>
#include <stdlib.h>

typedef struct SLE{
    int valor;
    struct SLE* proximo;
}SLE;

SLE* inserir_inicio(SLE* lista, int num){
    SLE* novo = malloc(sizeof(SLE));

    if(novo){
        novo->valor = num;
        novo->proximo = lista;
        lista = novo;
    }else{
        printf("\nErro ao alocar\n");
    }
    return lista;
}

void imprimir(SLE* lista){
    while(lista){
        printf("%d -> ", lista->valor);
        lista = lista->proximo;
    }
}

SLE* liberar(SLE* lista){
    SLE *aux = lista;

    while(aux){
        lista = lista->proximo;
        free(aux);
        aux = lista;
    }
    printf("\nMemoria liberada!\n");
    return NULL;
}

SLE* mescla_listas(SLE* lista1, SLE* lista2){
    SLE* aux = lista1;

    while(aux->proximo){
        aux = aux->proximo;
    }
    aux->proximo = lista2;
    return lista1;
}

int main(){
    SLE *lista1 = NULL, *lista2 = NULL;

    lista1 = inserir_inicio(lista1, 5);
    lista1 = inserir_inicio(lista1, 3);
    lista1 = inserir_inicio(lista1, 1);
    lista2 = inserir_inicio(lista2, 6);
    lista2 = inserir_inicio(lista2, 4);
    lista2 = inserir_inicio(lista2, 2);
    imprimir(lista1);
    printf("\n");
    imprimir(lista2);
    lista1 = mescla_listas(lista1, lista2);
    printf("\n\n");
    imprimir(lista1);
    lista1 = liberar(lista1);
    return 0;
}