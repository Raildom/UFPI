///////////////////////////////////////////////LISTA CIRCULAR//////////////////////////////////////////////////////////////
// #include <stdio.h>
// #include <stdlib.h>

// typedef struct no{
//     int valor;
//     struct no* prox;
// }no;

// no* final(no* lista, int valor){
//     no* novo = malloc(sizeof(no));

//     novo->valor = valor;
    
//     if(lista == NULL){
//         novo->prox = novo;
//         return novo;
//     }

//     no* inicio = lista;

//     while(lista->prox != inicio){
//         lista = lista->prox;
//     }
//     lista->prox = novo;
//     novo->prox = inicio;
//     return inicio;    
// }

// void imprimir(no* lista){
//     if(lista == NULL){
//         printf("\nLISTA IMPIRMIR VAZIA\n");
//         return;
//     }

//     no* inicio = lista;

//     do{
//         printf("%d -> ", lista->valor);
//         lista = lista->prox;
//     }while(lista != inicio);
//     printf(">> %d\n", lista->valor);
// }

// no* liberar(no* lista){
//     if(lista == NULL){
//         printf("\nLISTA LIBERAR VAZIA\n");
//         return NULL;
//     }

//     no* atual = lista, *temp = NULL;

//     do{
//         temp = atual;
//         atual = atual->prox;
//         free(temp);
//     }while(atual != lista);
//     printf("\nMEMORIA LIBERADA\n");
//     return NULL;
// }

// no* intercala(no* lista1, no* lista2){
//     if(lista1 == NULL) return lista2;
//     if(lista2 == NULL) return lista1;
//     if(lista1 == NULL && lista2 == NULL){
//         printf("\nAMBAS AS LISTAS VAZIAS\n");
//         return NULL;
//     }

//     no* inicio1 = lista1, *atual1 = lista1, *aux1 = lista1;
//     no* inicio2 = lista2, *atual2 = lista2, *aux2 = lista2;

//     do{
//         atual1 = atual1->prox;
//         aux1->prox = atual2;
//         aux1 = atual1;

//         atual2 = atual2->prox;
//         aux2->prox = atual1;
//         aux2 = atual2;
//     }while(atual1->prox != inicio1 && atual2->prox != inicio2);

//     if(atual1->prox == inicio1 && atual2->prox != inicio2){
//         atual1->prox = atual2;
//         while(atual2->prox != inicio2){
//             atual2 = atual2->prox;
//         }
//         atual2->prox = inicio1;
//     }else if(atual2->prox == inicio2 && atual1->prox != inicio1){
//         atual1 = atual1->prox;
//         aux1->prox = atual2;
//         atual2->prox = atual1;
//     }else{
//         atual1->prox = atual2;
//         atual2->prox = inicio1;
//     }
//     return inicio1;
// }

// int main(){
//     no* lista1 = NULL;
//     no* lista2 = NULL;

//     lista1 = final(lista1, 1);
//     lista1 = final(lista1, 3);
//     lista1 = final(lista1, 5);
//     lista2 = final(lista2, 2);
//     lista2 = final(lista2, 4);
//     lista2 = final(lista2, 6);
//     // lista2 = final(lista2, 8);
//     imprimir(lista1);
//     imprimir(lista2);
//     lista1 = intercala(lista1, lista2);
//     imprimir(lista1);
//     lista1 = liberar(lista1);
//     return 0;
// }


//////////////////////////////////////////////////////////LISTA DUPLAMENTE ENCADEADA/////////////////////////////////////////////////////////////////

// #include <stdio.h>
// #include <stdlib.h>

// typedef struct no{
//     int valor;
//     struct no* prox;
//     struct no* ant;
// }no;

// no* final(no* lista, int valor){
//     no* novo = malloc(sizeof(no));

//     novo->valor = valor;
//     novo->ant = NULL;
//     novo->prox = NULL;

//     if(lista == NULL) return novo;

//     no* atual = lista;

//     while(atual->prox != NULL){
//         atual = atual->prox;
//     }

//     atual->prox = novo;
//     novo->ant = atual;
//     return lista;
// }

// void imprimir(no* lista){
//     if(lista == NULL){
//         printf("\nLISTA IMPRIMIR VAZIA\n");
//         return;
//     }

//     printf("\nNULL <-> ");
//     while(lista != NULL){
//         printf("%d <-> ", lista->valor);
//         lista = lista->prox;
//     }
//     printf("NULL\n");
// }

// no* liberar(no* lista){
//     if(lista == NULL){
//         printf("\nLISTA LIBERAR VAZIA\n");
//         return NULL;
//     }

//     no* temp = NULL;

//     while(lista != NULL){
//         temp = lista;
//         lista = lista->prox;
//         free(temp);
//     }
//     printf("\nMEMORIA LIBERADA\n");
//     return NULL;
// }

// no* remove_repetidos(no* lista){
//     if(lista == NULL || lista->prox == NULL) return lista;


//     no* atual = lista, *aux = NULL, *temp = NULL;
//     do{
//         aux = atual->prox;
//         while(aux != NULL){
//             if(atual->valor == aux->valor && aux->prox == NULL){
//                 temp = aux;
//                 aux = aux->ant;
//                 aux->prox = NULL;
//                 free(temp);
//             }else if(atual->valor == aux->valor){
//                 temp = aux;
//                 aux->ant->prox = aux->prox;
//                 aux = aux->prox;
//                 aux->ant = temp->ant;
//                 free(temp);
//             }else{
//                 aux = aux->prox;
//             }
//         }
//         atual = atual->prox;
//     }while(atual != NULL);
//     return lista;
// }

// int main(){
//     no* lista = NULL;

//     lista = final(lista, 3);
//     lista = final(lista, 5);
//     lista = final(lista, 3);
//     lista = final(lista, 7);
//     lista = final(lista, 5);
//     lista = final(lista, 8);
//     lista = final(lista, 7);
//     imprimir(lista);
//     lista = remove_repetidos(lista);
//     imprimir(lista);
//     lista = liberar(lista);
//     return 0;
// }

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no *prox;
}no;

no *inicio(no *lista, int valor){
    no *novo = malloc(sizeof(no));

    if(novo == NULL){
        printf("\nErro ao alocar!\n");
        return lista;
    }else{
        novo->valor = valor;
        novo->prox = lista;
        lista = novo;
    }
    return lista;
}

void imprimir(no* lista){
    while(lista != NULL){
        printf("%d -> ", lista->valor);
        lista = lista->prox;
    }
    printf("NULL\n");
}

no *liberar(no *lista){
    no *atual = lista;

    while(atual != NULL){
        lista = lista->prox;
        free(atual);
        atual = lista;
    }
    printf("\nMemoria liberada\n");
    return NULL;
}

// Função para concatenar 3 listas
no* concatenar(no* menor, no* pivo, no* maior) {
    no *resultado = menor;

    // Se houver elementos em 'menor', avance até o final
    if (resultado != NULL) {
        no* atual = resultado;
        while (atual->prox != NULL) {
            atual = atual->prox;
        }
        atual->prox = pivo; // Conecta o pivô ao final de 'menor'
    } else {
        resultado = pivo; // Se 'menor' for nulo, 'resultado' é o pivô
    }

    pivo->prox = maior; // Conecta 'maior' após o pivô
    return resultado;
}

// Função para particionar a lista em relação ao pivô
no* particionar(no* lista, no** menor, no** maior) {
    no* pivo = lista;        // O primeiro elemento é o pivô
    *menor = NULL;
    *maior = NULL;

    no* atual = lista->prox;
    while (atual != NULL) {
        no* proximo = atual->prox;
        if (atual->valor < pivo->valor) {
            atual->prox = *menor;
            *menor = atual;
        } else {
            atual->prox = *maior;
            *maior = atual;
        }
        atual = proximo;
    }
    pivo->prox = NULL; // Garante que o pivô seja isolado
    return pivo;
}

// Função principal do QuickSort recursivo
no* quick_sort_lista(no* lista) {
    if (lista == NULL || lista->prox == NULL) {
        return lista; // Base da recursão: lista vazia ou com 1 elemento
    }

    no *menor, *maior, *pivo = particionar(lista, &menor, &maior);

    // Ordena recursivamente as partes 'menor' e 'maior'
    menor = quick_sort(menor);
    maior = quick_sort(maior);

    // Concatena 'menor', 'pivo' e 'maior' em uma lista final
    return concatenar(menor, pivo, maior);
}

no* MergeSort(no* lista){

    //caso base: lista com 0 ou 1 so elemento
    if (lista == NULL || lista->prox ==  NULL){
        return lista;
    }
    
    //Passo 1: Divide a lista ao meio
    no* segunda_metade = dividir(lista);

    //Passo 2: Ordenar as duas metades
    lista = MergeSort(lista);
    segunda_metade = MergeSort(segunda_metade);

    //Passo 3: Mesclar as duas metades ordenadas
    return mesclar(lista, segunda_metade);
}

no* dividir(no* lista){

    //Caso não seja possivel dividir
    if (lista == NULL || lista->prox == NULL){
        return NULL;
    }

    no* meio = lista;
    no* fim = lista->prox;

    //Encontrar meio da lista
    while (fim != NULL && fim->prox != NULL){
        meio = meio->prox;
        fim = fim->prox->prox;
    }

    //Desconectar a lista em duas partes
    no* segunda_metade = meio->prox;
    meio->prox = NULL;
    
    return segunda_metade;
}

no* mesclar(no* lista1, no* lista2){
    no* resultado = NULL;

    //Caso base: uma das duas listas estar vazia;
    if(lista1 == NULL) return lista2;
    if(lista2 == NULL) return lista1;

    //Ordena os elementos e mescla
    if (lista1->valor <= lista2->valor){
        resultado = lista1;
        resultado->prox = mesclar(lista1->prox, lista2);
    }else{
        resultado = lista2;
        resultado->prox = mesclar(lista1, lista2->prox);
    }
    
    return resultado;
}

no* BubbleSortLista(no* lista){
    no* aux1 = lista, *aux2;
    int temp;

    while (aux1 != NULL){
        aux2 = aux1->prox;

        while (aux2 != NULL){
            if (aux1->valor > aux2->valor){ 
                temp = aux1->valor;
                aux1->valor = aux2->valor;
                aux2->valor = temp;
            }
            aux2 = aux2->prox;
        }
        aux1 = aux1->prox;
    }
    return lista;
}

int main() {
    no *lista = NULL;
    int op, valor;

    do {
        printf("\n[1] - INSERIR NO INICIO\n");
        printf("[2] - IMPRIMIR LISTA\n");
        printf("[3] - ORGANIZAR COM QUICKSORT\n");
        printf("[4] - ORGANIZAR COM BUBBLESORT\n");
        printf("[0] - SAIR\n");
        printf("Informe a opcao desejada: ");
        scanf("%d", &op);

        switch (op) {
            case 1:
                printf("\nVALOR: ");
                scanf("%d", &valor);
                lista = inicio(lista, valor);
                break;
            case 2:
                imprimir(lista);
                break;
            case 3:
                lista = quick_sort(lista);
                printf("\nLista organizada com QuickSort:\n");
                imprimir(lista);
                break;
            case 4:
                lista = BubbleSortLista(lista);
                printf("\nLista organizada com BubbleSort:\n");
                imprimir(lista);
                break;
            case 0:
                lista = liberar(lista);
                break;
            default:
                printf("\nOPCAO INVALIDA!\n");
                break;
        }
    } while (op != 0);

    return 0;
}