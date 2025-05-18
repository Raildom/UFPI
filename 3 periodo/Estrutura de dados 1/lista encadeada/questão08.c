#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct le{
    int valor;
    struct le *prox;
}le;

le *inicio(le *lista, int valor){
    le *novo = malloc(sizeof(le));

    if(novo == NULL){
        printf("\nErro ao alocar!\n");
        return lista;
    }else{
        novo->valor = valor;
        novo->prox = lista;
        lista = novo;
    }
    return lista;
}

void imprimir(le* lista){
    while(lista != NULL){
        printf("%d -> ", lista->valor);
        lista = lista->prox;
    }
    printf("NULL\n");
}

le *liberar(le *lista){
    le *atual = lista;

    while(atual != NULL){
        lista = lista->prox;
        free(atual);
        atual = lista;
    }
    printf("\nMemoria liberada\n");
    return NULL;
}


le *organiza(le* lista, int valor){
    le* atual = lista, *anterior = NULL, *proximo = NULL;

    //lista vazia
    if(lista == NULL){
        printf("\nLista vazia!\n");
        return NULL;

    //lista com 1 elemento
    }else if(atual->prox == NULL){
        //se não tem outros valores, então não acontece nada
        return lista;
    
    //valor no primeiro elemento com uma lista maior que 1
    }else if(lista == atual && lista->valor == valor){
        anterior = lista;
        atual = atual->prox;
        atual->prox = anterior;
        anterior->prox = NULL;
        return atual;
    }

    while(atual != NULL && atual->valor != valor){
        anterior = atual;
        atual = atual->prox;
        proximo = atual->prox;
    }

    //valor não encontrado
    if(atual == NULL){
        printf("\nValor nao encontrado!\n");
        return lista;

    //valor encontrado no meio
    }else if(atual->prox != NULL){
        proximo->prox = atual;
        atual->prox = anterior;
        anterior->prox = NULL;
        return proximo;
    }

    //valor encontrado no final
    lista->prox = atual;
    atual->prox = anterior;
    anterior->prox = NULL;
    return lista;
}

int main(){
    le *lista = NULL;
    int op, valor;

    do{
        printf("\n[1] - INSERIR NO INICIO\n");
        printf("[2] - IMPRIMIR LISTA\n");
        printf("[3] - ORGANIZAR\n");
        printf("[0] - SAIR\n");
        printf("Informe a opcao desejada: ");
        scanf("%d", &op);
        getchar();
        switch(op){
            case 1:
                printf("\nVALOR: ");
                scanf("%d", &valor);
                lista = inicio(lista, valor);
                break;
            case 2:
                imprimir(lista);
                break;
            case 3:
                printf("\nDigite o numero a ser buscado: ");
                scanf("%d", &valor);
                lista = organiza(lista, valor);
                break;
            case 0:
                lista = liberar(lista);
                break;
            default:
                printf("\nOPCAO INVALIDA!\n");
                break;
        }
    }while(op != 0);
    lista = liberar(lista);
    return 0;
}