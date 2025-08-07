// #include <stdio.h>
// #include <stdlib.h>

// typedef struct lc{
//     int valor;
//     struct lc *prox;
// }lc;

// lc* adicionar(lc *lista, int n){
//     lc *novo = malloc(sizeof(lc)); //aloca memória

//     //verifica se a alocou corretamente
//     if(novo == NULL){
//         printf("Erro ao alocar memória!\n");
//         return lista;
//     }
//     //adiciona o valor "n" ao nó "novo"
//     novo->valor = n;

//     //se for o primeiro elemento da lista
//     if(lista == NULL){
//         //liga o novo elemento para ele mesmo criando a lista circular
//         novo->prox = novo;
//         return novo;
//     }

//     lc *inicio = lista;
//     //percorre a "lista"
//     while(lista->prox != inicio){
//         lista = lista->prox;
//     }
//     //liga o final da lista ao novo nó
//     lista->prox = novo;
//     //liga o novo nó ao inicio da lista
//     novo->prox = inicio;
//     return inicio;
// }

// lc* busca(lc* lista, int valor){
//     lc* p = lista->prox, *inicio = lista;

//     //se a lista estiver vazia
//     if(lista == NULL){
//         return NULL;
//     }

//     //se o valor buscado for o primeiro
//     if(inicio->valor == valor){
//         return inicio;
//     }
//     while(inicio != p){
//         if(p->valor == valor){
//             //valor encontrado no meio ou final da lista
//             return p;
//         }
//         p = p->prox;
//     }
//     //valor não encontrado
//     return NULL;
// }

// lc* remover_caractere(lc* lista, int valor){
//     //verifica se a lista é vazia
//     if(lista == NULL){
//         return NULL;
//     }

//     lc* inicio = lista;
//     lc* p = lista;


//     if(inicio->valor == valor){
//         // Se for o primeiro nó
//         while(p->prox != inicio){
//             p = p->prox;
//         }
//         if(p == inicio){
//             // Lista com apenas um elemento
//             free(inicio);
//             return NULL;
//         }else{
//             //se for o primeiro nó e a lista possuir mais de 1 elemento
//             p->prox = inicio->prox;
//             free(inicio);
//             return p->prox;
//         }
//     }else{
//         // Se for um nó do meio ou final
//         while(p->prox != inicio && p->prox->valor != valor){
//             p = p->prox;
//         }
//         if(p->prox->valor == valor){
//             lc* temp = p->prox;
//             p->prox = temp->prox;
//             free(temp);
//         }
//     }
//     return lista;
// }

// lc* remover_iguais(lc* lista, int valor){
//     if(lista == NULL){
//         //lista vazia
//         return NULL;
//     }

//     lc* p = lista->prox, *inicio = lista;

//     // while(p != inicio){
//     //     p = p->prox;
//     // }
//     if(p == inicio && p->valor == valor){
//         //lista com 1 elemento | valor encontrado
//         free(lista);
//         return NULL;
//     }
//     while(busca(lista, valor) != NULL){
//         lista = remover_caractere(lista, valor);
//     }
//     return lista;
// }

// void imprimir(lc *lista){
//     if(lista == NULL){
//         printf("NULL\n\n");
//         return;
//     }

//     lc *inicio = lista;
//     printf("%d", inicio->valor);
//     lista = lista->prox;

//     while(lista != inicio){
//         printf(" -> %d", lista->valor);
//         lista = lista->prox;
//     }
//     printf("\n\n");
// }

// lc* liberar(lc *lista){
//     if(lista == NULL){
//         printf("\nLista vazia\n");
//         return NULL;
//     }

//     lc *inicio = lista;
//     lc *temp;

//     do{
//         temp = lista;
//         lista = lista->prox;
//         free(temp);
//     }while(lista != inicio);
//     printf("\nLista liberada!\n");
//     return NULL;
// }

// void exibir_menu(){
//     printf("\nMenu:\n");
//     printf("[1] - Adicionar elemento\n");
//     printf("[2] - Imprimir lista\n");
//     printf("[3] - Buscar elemento\n");
//     printf("[4] - Remover elemento\n");
//     printf("[5] - Remover elementos iguais\n");
//     printf("[6] - Sair\n");
//     printf("Escolha uma opcao: ");
// }

// int main(){
//     lc* lista = NULL;
//     int opcao, valor;
//     lc* res;

//     do{
//         exibir_menu();
//         scanf("%d", &opcao);
//         switch(opcao){
//             case 1:
//                 printf("Digite o valor a ser adicionado: ");
//                 scanf("%d", &valor);
//                 lista = adicionar(lista, valor);
//                 break;
//             case 2:
//                 imprimir(lista);
//                 break;
//             case 3:
//                 printf("Digite o valor a ser buscado: ");
//                 scanf("%d", &valor);
//                 res = busca(lista, valor);
//                 if(res != NULL){
//                     printf("Valor encontrado: %d!\n", res->valor);
//                 }else{
//                     printf("Valor nao encontrado!\n");
//                 }
//                 break;
//             case 4:
//                 printf("Digite o valor a ser removido: ");
//                 scanf("%d", &valor);
//                 lista = remover_caractere(lista, valor);
//                 break;
//             case 5:
//                 printf("Digite o valor a ser removido: ");
//                 scanf("%d", &valor);
//                 lista = remover_iguais(lista, valor);
//                 break;
//             case 6:
//                 printf("Saindo...\n");
//                 lista = liberar(lista);
//                 break;
//             default:
//                 printf("Opção inválida! Tente novamente.\n");
//         }
//     }while(opcao != 6);
//     lista = liberar(lista);
//     return 0;
// }
#include<stdio.h>
#include<stdlib.h>

typedef struct LEC{

    int valor;
    int posicao;
    struct LEC* proximo;

}LEC;

void printar_lista(LEC* lista);

LEC* novo_no(int valor, int posicao){
    LEC* no = malloc(sizeof(LEC));
    no->valor = valor;
    no->posicao = posicao;
    no->proximo = no;
    return no;
}

LEC* inserir_final(LEC* lista, int valor, int posicao){
    LEC* novo = novo_no(valor, posicao);

    if (lista == NULL){
        lista = novo;
    }else{
        LEC* ultimo = lista;

        while (ultimo->proximo != lista){
            ultimo = ultimo->proximo;
        }

        ultimo->proximo = novo;
        novo->proximo = lista;
    }
    
    return lista;
}

LEC* remover_elemento_pulando(LEC* lista, int pulos){

    LEC* atual = lista;
    LEC* anterior = NULL;
    printar_lista(lista);

    while (lista != NULL && atual->proximo != atual){
        
        for(int i = 0; i < pulos; i++){
            anterior = atual;
            atual = atual->proximo;
        }

        anterior->proximo = atual->proximo;

        if(lista == atual){
            lista = lista->proximo;
        }
        free(atual);
        atual = anterior->proximo;

        printar_lista(lista);
    }
    return lista;
}

void printar_lista(LEC* lista){

    if(lista == NULL){
        printf("Lista Vazia\n\n");
    }else{

        LEC* aux = lista;

        do{
            printf("[%d:%d]->", aux->valor, aux->posicao);
            aux = aux->proximo;
        } while (aux != lista);
        
        printf("inicio\n\n");
    }
}

LEC* liberar_lista(LEC* lista){
    if(lista != NULL){
        LEC* inicio = lista;
        LEC* aux;

        do{
            aux = lista->proximo;
            free(lista);
            lista = aux;
        } while (inicio != lista);
        lista = NULL;
    }
    return lista;
}



int main(){

    LEC* lista = NULL;

    int tam, num;

    printf("Digite o tamanho da lista: ");
    scanf("%d", &tam);

        for(int i = 0; i < tam; i++){
            printf("Digite o %d nuemro da lista: ", i+1);
            scanf("%d", &num);
            lista = inserir_final(lista, num, i+1);
        }

    printar_lista(lista);
    
    int pulos;

    printf("Digite quantos deve pular: ");
    scanf("%d", &pulos);

    lista = remover_elemento_pulando(lista, pulos);

    printf("Posicao inicial do ultimo elemento restante: %d", lista->posicao);

    lista = liberar_lista(lista);

    return 0;
}   