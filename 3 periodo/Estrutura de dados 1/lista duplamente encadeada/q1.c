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
    printf("NULL <-> ");
    while(lista != NULL){
        printf("%d <-> ", lista->valor);
        lista = lista->prox;
    }
    printf("NULL\n");
}

no* liberar(no* lista){
    if(lista == NULL){
        printf("\nLISTA IMPRIMIR VAZIA\n");
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

no* remove_segundo_maior(no* lista){
    if(lista == NULL){
        printf("\nLISTA REMOVE_SEGUNDO_MAIOR VAZIA");
        return NULL;
    }
    if(lista->prox == NULL){
        return lista;
    }

    no* atual = lista;
    int maior = 0;

    while(atual != NULL){
        if(atual->valor > maior){
            maior = atual->valor;
        }
        atual = atual->prox;
    }

    atual = lista;
    no* segundo_maior = lista;

    while(atual != NULL){
        if(atual->valor > segundo_maior->valor && atual->valor < maior){
            segundo_maior = atual;
        }
        atual = atual->prox;
    }
    if(segundo_maior->ant == NULL){
        lista = lista->prox;
        lista->ant = NULL;
    }else if(segundo_maior->prox == NULL){
        segundo_maior->ant->prox = NULL;
    }else{
        segundo_maior->ant->prox = segundo_maior->prox;
        segundo_maior->prox->ant = segundo_maior->ant;
    }
    free(segundo_maior);
    return lista;
}

int main(){
    no* lista = NULL;

    lista = final(lista, 3);
    lista = final(lista, 5);
    lista = final(lista, 6);
    lista = final(lista, 7);
    lista = final(lista, 4);
    imprimir(lista);

    lista = remove_segundo_maior(lista);

    imprimir(lista);
    lista = liberar(lista);
    return 0;
}