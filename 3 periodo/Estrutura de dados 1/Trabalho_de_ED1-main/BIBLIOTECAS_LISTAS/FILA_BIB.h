
#include "../BIBLIOTECAS_SISTEMA/Tipos_bib.h"
#include "LISTA_ENCADEADA_BIB.h"

#ifndef FILA_BIB_H
#define FILA_BIB_H

// typedef struct Fila_encadeada
// {
//     INFO *info;
//     struct Fila_encadeada *proximo;
// } Fila_encadeada;

typedef struct Fila
{
    Lista_encadeada *inicio;
    Lista_encadeada *fim;
} Fila;

void adicionar_elemento_fila(Fila **f, void *info, TIPO_INFO tipo);

void atribuir_Lista_encadeada_a_fila(Lista_encadeada *lista, Fila **f);

void *remover_elemento_fila(Fila *f);

void printar_inicio_fila(Fila *f);

void printar_fim_fila(Fila *f);

void printar_fila(Fila *f);

void liberar_fila(Fila **f, bool liberar_info);

#endif // FILA_BIB_H