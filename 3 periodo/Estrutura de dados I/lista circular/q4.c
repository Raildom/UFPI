#include <stdio.h>
#include <stdlib.h>

typedef struct lc{
    int valor;
    struct lc* prox;
}lc;

lc* inserir(lc* lista, int valor){
    lc* novo = malloc(sizeof(lc));

    if(novo == NULL){
        printf("\nERRO AO ALOCAR!\n");
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
        printf("\nLISTA VAZIA!!\n");
        return NULL;
    }

    lc* inicio = lista;
    lc* temp = NULL;

    do{
        temp = lista;
        lista = lista->prox;
        free(temp);
    }while(lista != inicio);
    printf("\nLISTA LIBERADA!\n");
    return NULL;
}

void imprimir(lc* lista){
    if(lista == NULL){
        printf("\nLISTA VAZIA!!\n");
        return;
    }

    lc* inicio = lista;

    do{
        printf("%d ->> ", lista->valor);
        lista = lista->prox;
    }while(lista != inicio);
    printf("\n");
}

lc* busca(lc* lista, int valor){
    if(lista == NULL){
        printf("\nLISTA VAZIA!\n");
        return NULL;
    }

    lc* atual = lista;

    do{
        if(atual->valor == valor){
            return atual;
        }
        atual = atual->prox;
    }while(atual != lista);
    return NULL;
}

lc* remover(lc* lista, int valor){
    if(lista == NULL){
        printf("\nLISTA REMOVER VAZIA\n");
    }

    lc* atual = lista, *inicio = lista;

    if(inicio->valor == valor){
        while(atual->prox != inicio && atual->valor != valor){
            atual = atual->prox;
        }
        if(atual->prox == inicio){
            free(atual);
            printf("\nPAGOU 1\n");
            return NULL;
        }else{
            while(atual->prox != inicio){
                atual = atual->prox;
            }
            atual->prox = inicio->prox;
            free(inicio);
            inicio = atual->prox;
            
            printf("\nPAGOU 2\n");
            return inicio;
        }
    }else{
        while(atual->prox != inicio && atual->prox->valor != valor){
            atual = atual->prox;
        }
        if(atual->prox->valor == valor){
            lc* temp = atual->prox;
            atual->prox = temp->prox;
            free(temp);
            printf("\nPAGOU 3\n");
            return inicio;
        }
    }
    return lista;
}

lc* remover_iguais(lc* lista, int valor){
    if(lista == NULL){
        printf("\nLISTA DE REMOVER_IGUAIS VAZIA\n");
    }

    while(busca(lista, valor) != NULL){
        lista = remover(lista, valor);
    }
    return lista;
}

int main(){
    lc* lista = NULL;

    lista = inserir(lista, 3);
    lista = inserir(lista, 7);
    lista = inserir(lista, 3);
    lista = inserir(lista, 9);
    lista = inserir(lista, 3);
    imprimir(lista);
    lista = remover_iguais(lista, 3);
    imprimir(lista);
    lista = liberar(lista);
    return 0;
}