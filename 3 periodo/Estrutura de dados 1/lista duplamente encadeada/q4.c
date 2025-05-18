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

    printf("NULL <-> ");
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

    no* temp = lista;

    while(lista != NULL){
        temp = lista;
        lista = lista->prox;
        free(temp);
    }
    printf("\nMEMORIA LIBERADA\n");
    return NULL;
}

no* remove_duplicatas(no* lista){
    if(lista == NULL){
        printf("\nLISTA REMOVE_DUPLICATA VAZIA\n");
        return NULL;
    }

    no* atual = lista, *temp = lista, *andar = lista;

    while(atual != NULL){
        andar = atual->prox;
        while(andar != NULL){
            if(atual->valor == andar->valor){
                if(andar->prox == NULL){
                    temp = andar;
                    andar = andar->prox;
                    temp->ant->prox = NULL;
                }else{
                    temp = andar;
                    andar = andar->prox;
                    temp->ant->prox = andar;
                    andar->ant = temp->ant;
                }
                free(temp);
            }else{
                andar = andar->prox;
            }
        }
        atual = atual->prox;
    }
    return lista;
}

int main(){
    no* lista = NULL;

    lista = final(lista, 3);
    lista = final(lista, 5);
    lista = final(lista, 3);
    lista = final(lista, 7);
    lista = final(lista, 5);
    lista = final(lista, 8);
    lista = final(lista, 7);
    imprimir(lista);
    lista = remove_duplicatas(lista);
    imprimir(lista);
    lista = liberar(lista);
    return 0;
}