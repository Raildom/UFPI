#include <stdio.h>
#include <stdlib.h>
#define  MAX 50

typedef struct{
    int topo;
    int vet[MAX];
}no;

no* criar(){
    no* pilha = malloc(sizeof(no));
    pilha->topo = 0;
    return pilha;
}

void push(no* pilha, int valor){
    if(pilha->topo == MAX){
        printf("\nPILHA PUSH CHEIA\n");
        return;
    }
    pilha->vet[pilha->topo] = valor;
    pilha->topo++;
}

void pop(no* pilha){
    if(pilha->topo == 0){
        printf("\nPILHA POP VAZIA\n");
    }
    pilha->topo--;
}

void liberar(no* pilha){
    free(pilha);
    printf("\nMEMORIA LIBERADA\n");
}

void imprimir(no* pilha){
    if(pilha->topo == 0){
        printf("\nPILHA IMPRIMIR VAZIA\n");
        return;
    }
    for(int i = pilha->topo - 1; i >= 0; i--){
        printf("%d\n", pilha->vet[i]);
    }
    printf("\n");
}

void binario(no* pilha, int valor){
    int resto = 0;

    while(valor > 0){
        resto = valor % 2;
        push(pilha, resto);
        valor /= 2;
    }
}

int main(){
    no* pilha = criar();
    
    binario(pilha, 15);
    imprimir(pilha);
    liberar(pilha);
    return 0;
}