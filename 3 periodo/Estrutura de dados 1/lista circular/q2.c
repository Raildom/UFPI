#include <stdio.h>
#include <stdlib.h>

typedef struct lc{
    int valor;
    struct lc* prox;
}lc;

lc* inserir(lc* lista, int valor){
    lc* novo = malloc(sizeof(lc));

    novo->valor = valor;

    if(novo == NULL){
        printf("\nERRO AO ALOCAR!!\n");
        return lista;
    }
    if(lista == NULL){
        novo->prox = novo;
        return novo;
    }

    lc* inicio = lista;

    while(lista->prox != inicio){
        lista = lista->prox;
    }

    lista->prox = novo;
    novo->prox = inicio;
    return inicio;
}

lc* liberar(lc* lista){
    if(lista == NULL){
        printf("\nLISTA VAZIA!!\n");
        return NULL;
    }

    lc* inicio = lista;
    lc* temp = NULL;

    do{
        temp = lista;
        lista = lista->prox;
        free(temp);
    }while(lista != inicio);
    printf("\nLISTA LIBERADA!!\n");
    return NULL;
}

void imprimir(lc* lista){
    if(lista == NULL){
        printf("\nLISTA VAZIA!!\n");
        return;
    }

    lc* inicio = lista;

    do{
        printf("%d ->> ", lista->valor);
    }while(lista != inicio);
    printf("\n");
}

int primo(int n){
    if(n < 2){
        return 0;
    }
    for(int i = 2; i * i <= n; i++){
        if(n % i == 0){
            return 0;
        }
    }
    return 1;
}

lc* verifica_primo(lc* lista, int n){
    int count = 0, numero = 0;

    while(count != n){
        while(1){
            if(primo(numero)){
                lista = inserir(lista, numero);
                imprimir(lista);
                count++;
                numero++;
                break;
            }else{
                numero++;
            }
        }
    }
    return lista;
}

int main(){
    lc* lista = NULL;

    lista = verifica_primo(lista, 6);
    lista = liberar(lista);
    return 0;
}