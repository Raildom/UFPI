#include <stdio.h>
#include <stdlib.h>
#define N 50

typedef struct{
    int n;
    int vet[N];
}no;

no* criar(){
    no* pilha = malloc(sizeof(no));
    pilha->n = 0;
    return pilha;
}

void push(no* pilha, int valor){
    if(pilha->n == N){
        printf("\nPILHA CHEIA\n");
        return;
    }
    pilha->vet[pilha->n] = valor;
    pilha->n++;
}

void pop(no* pilha){
    if(pilha->n == 0){
        printf("\nPILHA pop VAZIA\n");
    return;
    }
    pilha->n--;
}

void liberar(no* pilha){
    free(pilha);
    printf("\nMEMORIA LIBERADA\n");
}

void imprimir(no* pilha){
    if(pilha->n == 0){
        printf("\nPILHA IMPRIMIR VAZIA\n");
        return;
    }
    for(int i = pilha->n - 1; i >= 0; i--){
        printf("%d\n", pilha->vet[i]);
    }
}

void inverter(no* pilha){
    if(pilha->n == 0 || pilha->n == 1) return;

    no* pilha2 = criar();

    for(int i = pilha->n - 1; i >= 0; i--){
        push(pilha2, pilha->vet[i]);
    }
    imprimir(pilha2);
    liberar(pilha2);
}

int main(){
    no* pilha = criar();

    push(pilha, 1);
    push(pilha, 2);
    push(pilha, 3);
    push(pilha, 4);
    push(pilha, 5);
    imprimir(pilha);
    printf("\n\n");
    inverter(pilha);
    liberar(pilha);
    return 0;
}