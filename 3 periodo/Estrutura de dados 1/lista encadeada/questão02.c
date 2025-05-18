#include <stdio.h>
#include <stdlib.h>

typedef struct sle{
    int valor;
    struct sle *proximo;
}SLE;

SLE *inserir_inicio(SLE *lista, int num){
    SLE *novo = malloc(sizeof(SLE));

    if(novo){
        novo->valor = num;
        novo->proximo = lista;
        lista = novo;
    }else{
        printf("Erro ao alocar\n");
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

SLE* busca(SLE* lista, int *num){
    SLE* aux = lista;
    int count = 1;

    while(aux->proximo && *num != aux->valor){
        aux = aux->proximo;
        count++;
    }
    if(*num == aux->valor){
        *num = count;
        return aux;
    }else{
        printf("Numero nao encontrado!\n");
        count = -1;
        return NULL;
    }
}

int main(){
    SLE *lista = NULL;
    int num;

    lista = inserir_inicio(lista, 7);
    lista = inserir_inicio(lista, 3);
    lista = inserir_inicio(lista, 1);
    imprimir(lista);
    printf("\nDigite o numero da busca: ");
    scanf("%d", &num);

    SLE* resultado = busca(lista, &num);

    if(resultado){
        printf("Numero: %d, posicao: %d\n", resultado->valor, num);
    }
    imprimir(lista);
    lista = liberar(lista);
    return 0;
}