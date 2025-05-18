#include <stdio.h>
#include <stdlib.h>

typedef struct sle{
    int valor;
    struct sle *proximo;
}SLE;

SLE* inserir_inicio(SLE *lista, int num){
    SLE *novo = malloc(sizeof(SLE));

    if(novo){
        novo->valor = num;
        novo->proximo = lista;
        lista = novo;
    }else{
        printf("Erro ao alocar!\n");
    }
    return lista;
}

void imprimir(SLE *lista){
    while(lista){
        printf("%d -> ", lista->valor);
        lista = lista->proximo;
    }
}

SLE* liberar(SLE *lista){
    SLE *aux = lista, *temp;

    while(aux){
        temp = aux;
        aux = aux->proximo;
        free(temp);
    }
    printf("\nMemoria liberada!\n");
       return NULL;
}

int tamanho(SLE *lista){
    int count = 0;

    while(lista){
        count++;
        lista = lista->proximo;
    }
    return count;
}
int main(){
    SLE *lista = NULL;

    lista = inserir_inicio(lista, 6);
    lista = inserir_inicio(lista, 2);
    lista = inserir_inicio(lista, 9);
    lista = inserir_inicio(lista, 4);
    imprimir(lista);
    printf("\n%d\n", tamanho(lista));
    lista = liberar(lista);
    return 0;
}