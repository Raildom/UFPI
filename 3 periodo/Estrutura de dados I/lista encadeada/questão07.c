#include <stdio.h>
#include <stdlib.h>

typedef struct sle{
    int valor;
    struct sle* proximo;
}sle;



sle* inicio(sle* lista, int num){
    sle* novo = malloc(sizeof(sle));

    if(novo){
        novo->valor = num;
        novo->proximo = lista;
        lista = novo; 
    }else{
        printf("Erro ao alocar\n");
    }
    return lista;
}

sle* liberar(sle* lista){
    sle* aux = lista;

    while(aux){
        lista = lista->proximo;
        free(aux);
        aux = lista;
    }
    printf("\nMemoria liberada!\n");
    return NULL;
}

void imprimir(sle* lista){
    while(lista){
        printf("%d -> ", lista->valor);
        lista = lista->proximo;
    }
    printf("NULL\n");
}

sle* SubLista(int busca){
    sle* listaAux = NULL;
    for(int i = busca; i >= 1; i--){
        listaAux = inicio(listaAux, i);
    }
    return listaAux;
}

sle* sequencia(sle* lista, int busca){
    sle* aux = lista;
    sle* listaA = NULL;
    sle* listaB = NULL;
    sle* guarda;
    sle* anterior = lista;
    
    while(aux){
        if(aux->proximo != NULL && aux->proximo->proximo == NULL){
            guarda = aux;
        }
        if(anterior->valor == aux->valor && aux->valor == busca){
            //lista com elemento buscado no inicio
            listaA = SubLista(busca);
            listaB = SubLista(busca);
        
            sle* aux2 = listaA;
            while(aux2->proximo){
                aux2 = aux2->proximo;
            }

            guarda = aux->proximo;
            aux2->proximo = aux;
            sle* aux3 = listaB;
            aux->proximo = aux3;

            while(aux3->proximo){
                aux3 = aux3->proximo;
            }
            aux3->proximo = guarda;
            lista = aux2;
            break;
        }else if(aux->valor == busca && aux->proximo == NULL){
            //lista com elemento buscado no final (ultimo)
            listaA = SubLista(busca);
            listaB = SubLista(busca);

            sle* aux2 = listaA;
            guarda->proximo = listaA;
            while(aux2->proximo){
                aux2 = aux2->proximo;
            }
            aux2->proximo = aux;
            sle* aux3 = listaB;
            aux->proximo = aux3;
            break;
        }else if(aux->valor == busca){
            //lista com elemento buscado no meio
            listaA = SubLista(busca);
            listaB = SubLista(busca);
            sle* proximo = aux->proximo;

            sle* aux2 = listaA;
            anterior->proximo = listaA;
            while(aux2->proximo){
                aux2 = aux2->proximo;
            }
            aux2->proximo = aux;
            sle* aux3 = listaB;
            aux->proximo = aux3;

            while(aux3->proximo){
                aux3 = aux3->proximo;
            }
            aux3->proximo = proximo;
            break;
        }
        if(anterior != aux){
            anterior = anterior->proximo;
        }
        aux = aux->proximo;
    }
    return lista;
}


int main(){
    sle* lista = NULL;

    lista = inicio(lista, 13);    
    lista = inicio(lista, 10);    
    lista = inicio(lista, 9);    
    lista = inicio(lista, 5);    
    lista = inicio(lista, 2);    
    lista = inicio(lista, 1);   
    imprimir(lista);
    lista = sequencia(lista, 5);
    imprimir(lista);


    // int num;
    // printf("Digite o numero que dejesa buscarr: ");
    // scanf("%d", &num); 
    lista = liberar(lista);
    return 0;
}