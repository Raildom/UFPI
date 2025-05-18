#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    float* dados;
    int inicio;
    int fim;
    int tamanho;
    int capacidade;
}no;

no* fila_vetor(int capacidade){
    no* fila = malloc(sizeof(no));
    fila->dados = malloc(capacidade * sizeof(float));
    fila->inicio = 0;
    fila->fim = 0;
    fila->tamanho = 0;
    fila->capacidade = capacidade;
    return fila;
}

void final(no* fila, float valor){
    if(fila->tamanho == fila->capacidade){
        printf("\nFILA CHEIA\n");
        return;
    }
    fila->dados[fila->fim] = valor;
    fila->fim = (fila->fim + 1) % fila->capacidade;
    fila->tamanho++;
}

void remover(no* fila){
    if(fila->tamanho == 0){
        printf("\nFILA VAZIA\n");
        return;
    }

    fila->inicio = (fila->inicio + 1) % fila->capacidade;
    fila->tamanho--;
}

void imprimir(no* fila){
    if(fila->tamanho == 0){
        printf("\nFILA VAZIA\n");
        return;
    }
    printf("\nFILA: ");
    for(int i = 0; i < fila->tamanho; i++){
        int index = (fila->inicio + i) % fila->capacidade;
        printf("%.0f ", fila->dados[index]);
    }
    printf("\n");
}

void liberar(no* fila){
    free(fila->dados);
    free(fila);
    printf("\nMEMORIA LIBERADA\n");
}

void impar_par(no* fila){
    int im = 0, p = 0;

    for(int i = 0; i < fila->tamanho; i++){
        int indice = (fila->inicio + i) % fila->capacidade;
        if((int)fila->dados[indice] % 2 == 0){
            p++;
        }else{
            im++;
        }
    }

    no* impar = fila_vetor(im);
    no* par = fila_vetor(p);

    for(int i = 0; i < fila->tamanho; i++){
        int indice = (fila->inicio + i) % fila->capacidade;
        if((int)fila->dados[indice] % 2 == 0){
            final(par, fila->dados[indice]);
        }else{
            final(impar, fila->dados[indice]);
        }
    }
    imprimir(par);
    imprimir(impar);
}

int main(){
    no* fila = fila_vetor(5);

    final(fila, 1);
    final(fila, 2);
    final(fila, 3);
    final(fila, 4);
    final(fila, 5);
    imprimir(fila);

    impar_par(fila);
    liberar(fila);
    return 0;
}