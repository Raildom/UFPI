#include <stdio.h>
#include <stdlib.h>

typedef struct sle{
    int valor;
    struct sle *proximo;
}SLE;

SLE* inserir_inicio(SLE* lista, int num){
    SLE* novo = malloc(sizeof(SLE));

    if(novo){
        novo->valor = num;
        novo->proximo = lista;
        lista = novo;
    }else{
        printf("Erro ao alocar!\n");
    }
    return lista;
}

SLE* liberar(SLE* lista){
    SLE *aux = lista, *temp;

    while(aux){
        temp = aux;
        aux = aux->proximo;
        free(temp);
    }
    printf("\nMemoria liberada!\n");
    return NULL;
}

void imprimir(SLE* lista){
    while(lista){
        printf("%d -> ", lista->valor);
        lista = lista->proximo;
    }
}

float media(SLE* lista){
    int count = 0;
    float media = 0;

    while(lista){
        media += lista->valor;
        count++;
        lista = lista->proximo;
    }
    return media /= count;
}

int main(){
    SLE* lista = NULL;

    lista = inserir_inicio(lista, 23);
    lista = inserir_inicio(lista, 16);
    lista = inserir_inicio(lista, 15);
    lista = inserir_inicio(lista, 8);
    lista = inserir_inicio(lista, 4);
    
    imprimir(lista);
    float media_ = media(lista);
    printf("\n%.2f", media_);
    lista = liberar(lista);
    return 0;
}