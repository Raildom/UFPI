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
        printf("\nPILHA POP VAIZA\n");
        return;
    }

    no* temp = pilha->topo;
    pilha->topo = temp->prox;
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
    printf("\n");
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

void comparar(PILHA* pilha1, PILHA* pilha2){
    if(pilha1->topo == NULL && pilha2->topo == NULL){
        printf("\nSIM\n");
        return;
    }
    if(pilha1->topo == NULL || pilha2->topo == NULL){
        printf("\nNAO\n");
        return;
    }

    no* atual1 = pilha1->topo, *atual2 = pilha2->topo;

    while(atual1 != NULL && atual2 != NULL){
        if(atual1->valor == atual2->valor){
            atual1 = atual1->prox;
            atual2 = atual2->prox;
        }else{
            printf("\nNAO\n");
            return;
        }
    }
    if(atual1 == NULL && atual2 == NULL){
        printf("\nSIM\n");
    }else{
        printf("\nNAO\n");
    }
}

int main(){
    PILHA* pilha1 = criar();
    PILHA* pilha2 = criar();

    push(pilha1, 1);
    push(pilha1, 2);
    push(pilha1, 3);
    push(pilha2, 1);
    push(pilha2, 2);
    push(pilha2, 3);
    imprimir(pilha1);
    imprimir(pilha2);
    comparar(pilha1, pilha2);
    liberar(pilha1);
    liberar(pilha2);
    return 0;
}