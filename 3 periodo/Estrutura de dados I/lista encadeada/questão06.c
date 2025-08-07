#include <stdio.h>
#include <stdlib.h>

typedef struct sle{
    int valor;
    struct sle *proximo;
}sle;

sle* inserir_inicio(sle* lista, int num){
    sle* novo = malloc(sizeof(sle));

    if(novo){
        novo->valor = num;
        novo->proximo = lista;
        lista = novo;
    }else{
        printf("\nErro ao alocar!\n");
    }
    return lista;
}

sle* liberar(sle* lista){
    sle *aux = lista;

    while(aux){
        lista = lista->proximo;
        free(aux);
        aux = lista;
    }
    printf("\nMemoria liberada\n");
    return NULL;
}

void imprimir(sle* lista){
    while(lista){
        printf("%d -> ", lista->valor);
        lista = lista->proximo;
    }
}

sle* encontrar_elemento_igual(sle* lista1, sle* lista2, sle* final){
    sle* aux = lista2;

    while(lista1){
        aux = lista2;
        while(aux){
            if(lista1->valor == aux->valor){
                final = inserir_inicio(final, lista1->valor);
                break;
            }
            aux = aux->proximo;
        }
        aux = lista2;
        lista1 = lista1->proximo; 
    }
    return final;
}

int main(){
    sle *lista1 = NULL, *lista2 = NULL, *final = NULL;

    lista1 = inserir_inicio(lista1, 8);
    lista1 = inserir_inicio(lista1, 6);
    lista1 = inserir_inicio(lista1, 4);
    lista1 = inserir_inicio(lista1, 2);
    lista2 = inserir_inicio(lista2, 9);
    lista2 = inserir_inicio(lista2, 6);
    lista2 = inserir_inicio(lista2, 4);
    lista2 = inserir_inicio(lista2, 3);

    imprimir(lista1);
    printf("\n");
    imprimir(lista2);
    printf("\n");
    final = encontrar_elemento_igual(lista1, lista2, final);
    imprimir(final);
    lista1 = liberar(lista1);
    lista2 = liberar(lista2);
    final = liberar(final);
    return 0;
}