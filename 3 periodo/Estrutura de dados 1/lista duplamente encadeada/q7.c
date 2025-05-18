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
    novo->ant = NULL;
    novo->prox = NULL;

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

no* inverter_intervalo(no* lista, int busca_x, int busca_y){
    if(lista == NULL || lista->prox == NULL) return lista;

    no *x = NULL, *y = NULL, *atual = lista;

    while(atual != NULL){
        if(atual->valor == busca_x){
            x = atual;
            break;
        }
        atual = atual->prox;
    }

    atual = lista;

    while(atual != NULL){
        if(atual->valor == busca_y){
            y = atual;
            break;
        }
        atual = atual->prox;
    }

    x = x->prox;
    y = y->ant;

    while(x != y && x->ant != y){
        no *temp_prox = x->prox;
        no *temp_ant = y->ant;

        if(x->ant != NULL) x->ant->prox = y;
        if(y->prox != NULL) y->prox->ant = x;

        x->prox = y->prox;
        x->ant = y;

        y->prox = temp_prox;
        y->ant = temp_ant;

        if(temp_prox != NULL) temp_prox->ant = y;
        if(temp_ant != NULL) temp_ant->prox = x;

        x = temp_prox;
        y = temp_ant;
    }
    return lista;
}

int main(){
    no* lista = NULL;

    lista = final(lista, 1);
    lista = final(lista, 2);
    lista = final(lista, 3);
    lista = final(lista, 7);
    lista = final(lista, 20);
    lista = final(lista, 30);
    lista = final(lista, 28);
    imprimir(lista);
    lista = inverter_intervalo(lista, 1, 28);
    imprimir(lista);
    lista = liberar(lista);
    return 0;
}