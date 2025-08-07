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
    if(lista == NULL) return;

    printf("NULL -> ");
    while(lista != NULL){
        printf("%d <-> ", lista->valor);
        lista = lista->prox;
    }
    printf("NULL\n");
}

no* liberar(no* lista){
    if(lista == NULL) return NULL;

    no* temp = lista;
    
    while(lista != NULL){
        temp = lista;
        lista = lista->prox;
        free(temp);
    }
    printf("\nMEMORIA LIBERADA");
    return NULL;
}

no* mesclar_ordenado(no* lista1, no* lista2){
    if(lista1 == NULL) return lista2;
    if(lista2 == NULL) return lista1;
    if(lista1 == NULL && lista2 == NULL) return NULL;

    no* atual1 = lista1, *atual2 = lista2, *inicio = NULL, *andar = NULL;

    if(atual1->valor < atual2->valor){
        inicio = atual1;
        atual1 = atual1->prox;
    }
    else{
        inicio = atual2;
        atual2 = atual2->prox;
    }

    andar = inicio;

    while(atual1 != NULL && atual2 != NULL){
        if(atual1->valor < atual2->valor){
            andar->prox = atual1;
            atual1->ant = andar;
            atual1 = atual1->prox;
            andar = andar->prox;

        }else{
            andar->prox = atual2;
            atual2->ant = andar;
            atual2 = atual2->prox;
            andar = andar->prox;
        }
    }

    if(atual1 == NULL){
        andar->prox = atual2;
        atual2->ant = andar;
        while(atual2 != NULL){
            atual2 = atual2->prox;
        }
    }else{
        andar->prox = atual1;
        atual1->ant = andar;
        while(atual1 != NULL){
            atual1 = atual1->prox;
        }
    }
    return inicio;
}

int main(){
    no* lista1 = NULL, *lista2 = NULL;

    lista1 = final(lista1, 3);
    lista1 = final(lista1, 4);
    lista1 = final(lista1, 7);
    lista2 = final(lista2, 2);
    lista2 = final(lista2, 6);
    lista2 = final(lista2, 6);

    imprimir(lista1);
    printf("\n");
    imprimir(lista2);

    lista1 = mesclar_ordenado(lista1, lista2);
    imprimir(lista1);

    lista1 = liberar(lista1);
    return 0;
}