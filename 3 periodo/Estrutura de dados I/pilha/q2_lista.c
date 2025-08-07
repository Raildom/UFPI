#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no* prox;
}no;

typedef struct{
    no* topo;
}PILHA;

PILHA* criar(){
    PILHA* pilha = malloc(sizeof(PILHA));

    pilha->topo = NULL;
    return pilha;
}

void push(PILHA* pilha, int valor){
    no* novo = malloc(sizeof(no));

    novo->valor = valor;
    novo->prox = pilha->topo;
    pilha->topo = novo;
}

void pop(PILHA* pilha){
    if(pilha->topo == NULL){
        printf("\nPILHA POP VAZIA\n");
        return;
    }

    no* temp = pilha->topo;

    pilha->topo = pilha->topo->prox;
    free(temp);
}

void imprimir(PILHA* pilha){
    if(pilha->topo == NULL){
        printf("\nPILHA IMPRIMIR VAZIA\n");
        return;
    }

    no* atual = pilha->topo;

    printf("\nTOPO: ");
    while(atual != NULL){
        printf("\n%d", atual->valor);
        atual = atual->prox;
    }
}

void liberar(PILHA* pilha){
    no* temp = NULL, *atual = pilha->topo;

    while(atual != NULL){
        temp = atual;
        atual = atual->prox;
        free(temp);
    }
    free(pilha);
    printf("\nMEMORIA LIBERADA\n");
}

void binario(PILHA* pilha, int valor){
    int resto;

    while(valor > 0){
        resto = valor % 2;
        push(pilha, resto);
        valor /= 2;
    }
}

int main(){
    PILHA* pilha = criar();

    binario(pilha, 10);
    imprimir(pilha);
    liberar(pilha);
    return 0;
}