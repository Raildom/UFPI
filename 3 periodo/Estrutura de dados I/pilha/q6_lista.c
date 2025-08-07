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

void remover(PILHA *pilha1, PILHA *pilha2){
    if(pilha1->topo == NULL || pilha2->topo == NULL){
        printf("Uma das pilhas está vazia\n");
        return;
    }

    PILHA *aux = criar();

    while(pilha1->topo != NULL){
        int valor = pilha1->topo->valor;
        pop(pilha1);

        no *atual2 = pilha2->topo;
        int encontrado = 0;

        while(atual2 != NULL){
            if(atual2->valor == valor){
                encontrado = 1;
                break;
            }
            atual2 = atual2->prox;
        }
        if(encontrado == 0){
            push(aux, valor);
        }
    }
    while(aux->topo != NULL){
        push(pilha1, aux->topo->valor);
        pop(aux);
    }
    liberar(aux);
    imprimir(pilha1);
}


int main(){
    PILHA* pilha1 = criar();
    PILHA* pilha2 = criar();

    push(pilha1, 1);
    push(pilha1, 2);
    push(pilha1, 3);
    push(pilha1, 4);
    push(pilha1, 5);
    push(pilha2, 1);
    push(pilha2, 3);
    push(pilha2, 5);
    imprimir(pilha1);
    imprimir(pilha2);
    remover(pilha1, pilha2);
    liberar(pilha1);
    liberar(pilha2);
    return 0;
}