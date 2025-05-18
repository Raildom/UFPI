#include<stdio.h>
#include<stdlib.h>

typedef struct no{
    int valor;
    struct no* proximo;
}no;

typedef struct PILHA{
    no* topo;
}PILHA;

PILHA* criar(){
    PILHA* pilha = malloc(sizeof(PILHA));
    pilha->topo = NULL;
    return pilha;
}

void push(PILHA* pilha, int valor){
    no* lista = malloc(sizeof(no));

    lista->valor = valor;
    lista->proximo = pilha->topo;
    pilha->topo = lista;
}

void pop(PILHA* pilha){
    no* temp;

    if(pilha->topo == NULL){
        printf("\nPILHA VAZIA\n");
        return;
    }
    temp = pilha->topo;
    pilha->topo = temp->proximo;
    free(temp);
}

void imprimir(PILHA* pilha){
    if(pilha->topo == NULL){
        printf("\nPILHA IMPRIMIR VAZIA\n");
        return;
    }

    no* lista = pilha->topo;

    printf("\nTOPO DA PILHA\n");
    while(lista != NULL){    
        printf("%d\n", lista->valor);
        lista = lista->proximo;   
    }
}

PILHA* liberar(PILHA* pilha){
    no* atual = pilha->topo;
    no* temp;

    while(atual != NULL){
        temp = atual;
        atual = atual->proximo;
        free(temp);
    }
    free(pilha);
    printf("\nMEMORIA LIBERADA\n");
    return NULL;
}

void inverter(PILHA* pilha){
    if(pilha->topo == NULL) return;

    PILHA* pilha2 = criar();

    no* atual = pilha->topo;

    while(atual != NULL){
        push(pilha2, atual->valor);
        atual = atual->proximo;
    }
    imprimir(pilha2);
    pilha2 = liberar(pilha2);
}

int main(){
    PILHA* pilha = criar();
    int num;

    while(scanf("%d", &num) == 1){
        push(pilha, num);
    }while(getchar() != '\n');
    imprimir(pilha);
    inverter(pilha);
    pilha = liberar(pilha);
    return 0;
}