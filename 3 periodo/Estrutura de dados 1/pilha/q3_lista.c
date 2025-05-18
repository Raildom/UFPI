#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    char valor;
    struct no* prox;
}no;

typedef struct{
    no* topo;
}PILHA;

PILHA* criar(){
    PILHA* novo = malloc(sizeof(PILHA));

    novo->topo = NULL;
    return novo;
}

void push(PILHA* pilha, char valor){
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
        printf("\n%c", atual->valor);
        atual = atual->prox;
    }
    printf("\n");
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

void sequencia(PILHA* pilha){
    if(pilha->topo == NULL){
        printf("\nPILHA SEQUENCIA VAZIA\n");
        return;
    }

    no* atual = pilha->topo;

    while(atual != NULL && atual->prox != NULL){
        if(atual->valor == atual->prox->valor){
            no* temp = atual->prox;
            atual->prox = temp->prox;
            free(temp);
        }else{
            atual = atual->prox;
        }
    }
}

int main(){
    PILHA* pilha = criar();

    push(pilha, 'd');
    push(pilha, 'd');
    push(pilha, 'c');
    push(pilha, 'c');
    push(pilha, 'b');
    push(pilha, 'b');
    push(pilha, 'a');
    push(pilha, 'a');
    imprimir(pilha);
    sequencia(pilha);
    imprimir(pilha);
    liberar(pilha);
    return 0;
}