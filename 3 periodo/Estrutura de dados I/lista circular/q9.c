#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no* prox;
}no;

no* inserir(no* lista, int valor){
    no* novo = malloc(sizeof(no));

    if(novo == NULL){
        printf("\nERRO AO ALOCAR MEMORIA\n");
        return lista;
    }

    novo->valor = valor;

    if(lista == NULL){
        novo->prox = novo;
        return novo;
    }

    no* inicio = lista;

    while(lista->prox != inicio){
        lista = lista->prox;
    }

    lista->prox = novo;
    novo->prox = inicio;
    return inicio;
}

no* liberar(no* lista){
    if(lista == NULL){
        printf("\nLISTA LIBERAR VAZIA\n");
        return NULL;
    }

    no* inicio = lista, *temp = NULL;
    
    do{
        temp = lista;
        lista = lista->prox;
        free(temp);
    }while(lista != inicio);
    printf("\nMEMORIA LIBERADA\n");
    return NULL;
}

void imprimir(no* lista){
    if(lista == NULL){
        printf("\nLISTA IMPRIMIR VAZIA\n");
        return;
    }

    no* inicio = lista;

    do{
        printf("%d -> ", lista->valor);
        lista = lista->prox;
    }while(lista != inicio);
    printf(">> %d\n", lista->valor);
}

no* impar_par(no* lista){
    if(lista == NULL || lista->prox == lista){
        return lista;
    }

    no *inicio = lista, *atual = lista;
    no *inicioPar = NULL, *inicioImpar = NULL;
    no *fimPar = NULL, *fimImpar = NULL;

    do{
        if(atual->valor % 2 == 0){
            if(inicioPar == NULL){
                inicioPar = atual;
                fimPar = atual;
            }else{
                fimPar->prox = atual;
                fimPar = fimPar->prox;
            }
        }else{
            if(inicioImpar == NULL){
                inicioImpar = atual;
                fimImpar = atual;
            }else{
                fimImpar->prox = atual;
                fimImpar = fimImpar->prox;
            }

        }
        atual = atual->prox;
    }while(atual != inicio);

    if(fimPar != NULL){
        if(inicioImpar != NULL){
            fimPar->prox = inicioImpar;
        }else{
            fimPar->prox = inicioPar;
        }
    }

    if(fimImpar != NULL){
        if(inicioPar != NULL){
            fimImpar->prox = inicioPar;
        }else{
            fimImpar->prox = inicioImpar;
        }
    }

    if(inicioPar != NULL) {
        return inicioPar;
    }else{
        return inicioImpar;
    }
}

int main(){
    no* lista = NULL;

    lista = inserir(lista, 3);
    lista = inserir(lista, 8);
    lista = inserir(lista, 5);
    lista = inserir(lista, 10);
    lista = inserir(lista, 1);
    lista = inserir(lista, 6);

    imprimir(lista);
    lista = impar_par(lista);
    imprimir(lista);
    lista = liberar(lista);
    return 0;
}