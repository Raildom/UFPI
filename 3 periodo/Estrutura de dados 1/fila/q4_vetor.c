#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int* valor;
    int inicio;
    int final;
    int tamanho;
    int capacidade;
}no;

no* criar(int capacidade){
    no* fila = malloc(sizeof(no));
    fila->valor = malloc(sizeof(int) * capacidade);
    fila->final = 0;
    fila->inicio = 0;
    fila->tamanho = 0;
    fila->capacidade = capacidade;
    return fila;
}

void final(no* fila, int valor){
    if(fila->tamanho == fila->capacidade){
        printf("\nFILA FINAL CHEIA\n");
        return;
    }
    fila->valor[fila->final] = valor;
    fila->final = (fila->final + 1) % fila->capacidade;
    fila->tamanho++;
}

void imprimir(no* fila){
    if(fila->tamanho == 0){
        printf("\nFILA IMPRIMIR VAZIA\n");
        return;
    }
    printf("\nFILA: ");
    for(int i = 0; i < fila->tamanho; i++){
        int indice = (fila->inicio + i) % fila->capacidade;
        printf("%d ", fila->valor[indice]);
    }
    printf("\n");
}

void liberar(no* fila){
    free(fila->valor);
    free(fila);
    printf("\nMEMORIA LIBERADA\n");
}

void remover(no* fila){
    if(fila->tamanho == 0){
        printf("\nFILA REMOVER VAZIA\n");
        return;
    }
    fila->inicio = (fila->inicio + 1) % fila->capacidade;
    fila->tamanho--;
}

void mercado(no* fila){
    if(fila->tamanho == 0){
        printf("\nFILA MERCADO VAZIA\n");
        return;
    }
    no* caixa1 = criar(5);
    no* caixa2 = criar(5);
    no* caixa3 = criar(5);

    for(int i = 0; i < fila->tamanho; i++){
        int indice = (fila->inicio + i) % fila->capacidade;
        if(caixa1->tamanho <= caixa2->tamanho && caixa1->tamanho <= caixa3->tamanho){
            final(caixa1, fila->valor[indice]);
        }else if(caixa2->tamanho <= caixa1->tamanho && caixa2->tamanho <= caixa3->tamanho){
            final(caixa2, fila->valor[indice]);
        }else{
            final(caixa3, fila->valor[indice]);
        }
    }
    printf("\nCAIXA 1: ");
    imprimir(caixa1);
    printf("\nCAIXA 2: ");
    imprimir(caixa2);
    printf("\nCAIXA 3: ");
    imprimir(caixa3);
}

int main(){
    no* fila = criar(5);

    final(fila, 1);
    final(fila, 2);
    final(fila, 3);
    final(fila, 4);
    final(fila, 5);
    imprimir(fila);
    mercado(fila);
    liberar(fila);
    return 0;
}