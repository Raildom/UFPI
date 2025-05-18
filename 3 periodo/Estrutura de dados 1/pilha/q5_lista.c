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

void pop(PILHA* pilha){
    if(pilha->topo == NULL){
        printf("\nPILHA POP VAZIA\n");
        return;
    }

    no* temp = pilha->topo;

    pilha->topo = temp->prox;
    free(temp);
}

void liberar(PILHA* pilha){
    no* atual = pilha->topo, *temp = NULL;

    while(atual != NULL){
        temp = atual;
        atual = atual->prox;
        free(temp);
    }
    free(pilha);
    printf("\nMEMORIA LIBERADA\n");
}

void imprimir(PILHA* pilha){
    if(pilha->topo == NULL){
        printf("\nPILHA IMPRIMIR VAZIA\n");
        return;
    }
    
    no* atual = pilha->topo;

    printf("\nTOPO: ");
    while(atual != NULL){
        printf("%d ", atual->valor);
        atual = atual->prox;
    }
    printf("\n");
}

void remover_menor(PILHA* pilha, int valor){
    if(pilha->topo == NULL){
        printf("\nPILHA REMOVER_MENOR VAZIA\n");
        return;
    }

    no* atual = pilha->topo;
    PILHA* aux = criar();


    while(atual != NULL){
        if(atual->valor >= valor){
            push(aux, atual->valor);
        }
        atual = atual->prox;
    }
    imprimir(aux);
    liberar(aux);
}

int main(){
    PILHA* pilha = criar();

    push(pilha, 5);
    push(pilha, 15);
    push(pilha, 25);
    push(pilha, 35);
    imprimir(pilha);
    remover_menor(pilha, 10);
    liberar(pilha);
    return 0;
}