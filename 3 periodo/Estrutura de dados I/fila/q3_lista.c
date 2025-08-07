#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no* prox;
}no;

typedef struct{
    no* final;
    no* inicio;
}FILA;

typedef struct{
    no* topo;
}PILHA;

PILHA* criaP(){
    PILHA* novo = malloc(sizeof(PILHA));

    novo->topo = NULL;
    return novo;
}

void push(PILHA* pilha, int valor){
    no* novo = malloc(sizeof(no));

    novo->valor = valor;
    novo->prox = pilha->topo;
    pilha->topo = novo;
}

void imprimir_pilha(PILHA* pilha){
    if(pilha->topo == NULL){
        printf("\nPILHA IMPRIMIR_PILHA VAZIA\n");
        return;
    }

    printf("\nTOPO: ");
    while(pilha->topo != NULL){
        printf("\n%d", pilha->topo->valor);
        pilha->topo = pilha->topo->prox;
    }
    printf("\n");
}

void liberar_pilha(PILHA* pilha){
    no* atual = pilha->topo, *temp = NULL;

    while(atual != NULL){
        temp = atual;
        atual = atual->prox;
        free(temp);
    }
    free(pilha);
    printf("\nMEMORIA da pilha LIBERADA\n");
}

FILA* criar(){
    FILA* fila = malloc(sizeof(FILA));

    fila->final = NULL;
    fila->inicio = NULL;
    return fila;
}

void final(FILA* fila, int valor){
    no* novo = malloc(sizeof(no));

    novo->valor = valor;
    novo->prox = NULL;

    if(fila->final != NULL){
        fila->final->prox = novo;
    }else{
        fila->inicio = novo;
    }
    fila->final = novo;
}

void imprimir(FILA* fila){
    if(fila->inicio == NULL){
        printf("\nFILA IMPRIMIR VAZIA\n");
        return;
    }

    no* atual = fila->inicio;

    printf("\nFILA: \n");
    while(atual != NULL){
        printf("%d ", atual->valor);
        atual = atual->prox;
    }
    printf("\n");
}

void liberar(FILA* fila){
    if(fila->inicio == NULL){
        printf("\nFILA LIBERAR VAZIA\n");
        return;
    }

    no* atual = fila->inicio, *temp = NULL;

    while(atual != NULL){
        temp = atual;
        atual = atual->prox;
        free(temp);
    }
    free(fila);
    printf("\nMEMORIA LIBERADA\n");
}

void remover(FILA* fila){
    if(fila->inicio == NULL){
        printf("\nFILA REMOVER VAZIA\n");
        return; 
    }

    no* temp = fila->inicio;
    fila->inicio = fila->inicio->prox;

    if(fila->inicio == NULL){
        fila->final = NULL;
    }
    free(temp);
}

void inverter(FILA* fila){
    if(fila->inicio == NULL || fila->inicio->prox == NULL){
        printf("\nLISTA INVERTER VAZIA OU COM APENAS 1 ELEMENTO\n");
        return;
    }
    
    PILHA* pilha = criaP();
    no* atual = fila->inicio;

    while(atual != NULL){
        push(pilha, atual->valor); 
        atual = atual->prox;
        remover(fila);
    }
    
    atual = pilha->topo;

    while(atual != NULL){
        final(fila, atual->valor);
        atual = atual->prox;
    }
    imprimir_pilha(pilha);
    liberar_pilha(pilha);
}

int main(){
    FILA* fila = criar();

    final(fila, 1);
    final(fila, 2);
    final(fila, 3);
    imprimir(fila);
    inverter(fila);
    imprimir(fila);
    liberar(fila);
    return 0;
}