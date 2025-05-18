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

    if(lista == NULL){
        return novo;
    }

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
    printf("NULL\n\n");
}

no* liberar(no* lista){
    if(lista == NULL){
        printf("\nLISTA LIBERAR VAZIA\n");
        return NULL;
    }

    no* temp = lista;

    while(lista != NULL){
        temp = lista;
        lista = lista->prox;
        free(temp);
    }
    printf("\nMEMORIA LIBERADA\n");
    return NULL;
}

no* remover_buscado(no* lista, int valor){
    if(lista == NULL){
        printf("\nLISTA REMOVER_BUSCADO VAZIA\n");
        return NULL;
    }

    no* atual = lista, *temp = NULL;
    
    while(atual != NULL){
        if(atual->valor == valor){
            if(atual->ant != NULL && atual->prox != NULL){
                temp = atual;
                atual = atual->prox;
                atual->ant = temp->ant;
                atual->ant->prox = atual;
            }else if(atual->prox == NULL){
                temp = atual;
                atual->ant->prox = NULL;
                atual = atual->prox;
            }else{
                temp = atual;
                atual = atual->prox;
                lista = atual;
                atual->ant = NULL;
            }
            free(temp);
        }else{
            atual = atual->prox;
        }
    }
    return lista;
}

int main(){
    no* lista = NULL;

    lista = final(lista, 4);
    lista = final(lista, 2);
    lista = final(lista, 4);
    lista = final(lista, 6);
    lista = final(lista, 4);
    lista = final(lista, 7);

    imprimir(lista);
    lista = remover_buscado(lista, 4);
    imprimir(lista);
    lista = liberar(lista);
    return 0;
}