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
        printf("\nErro ao alocar!\n");
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
    printf("\nMemoria liberada\n");
    return NULL;
}

void imprimir(SLE* lista){
    while(lista){
        printf("%d -> ", lista->valor);
        lista = lista->proximo;
    }
}

SLE* remove_duplicata(SLE* lista){
    SLE* aux = lista;

    while(aux){
        SLE* aux2 = aux;
        while(aux2->proximo){
            if(aux2->proximo->valor == aux->valor){
                SLE* temp = aux2->proximo;
                aux2->proximo = aux2->proximo->proximo;
                free(temp);
            }else{
                aux2 = aux2->proximo;
            }
        }
        aux = aux->proximo;
    }
    return lista;
}

int main(){
    SLE* lista = NULL;

    lista = inserir_inicio(lista, 2);
    lista = inserir_inicio(lista, 5);
    lista = inserir_inicio(lista, 4);
    lista = inserir_inicio(lista, 2);
    lista = inserir_inicio(lista, 4);

    imprimir(lista);
    lista = remove_duplicata(lista);
    printf("\n");
    imprimir(lista);
    lista = liberar(lista);
    return 0;
}