#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define ARQ_ENT "entrada.txt"
#define ARQ_SAI "saida.txt"
#define type "type"
#define undo "undo"
#define MAX_COMANDOS 50
#define MAX_TAM_TEXT 51

typedef struct{
    char comando[5];
    char caracter;
    int num_undo;
    int tempo;
}Comando;

Comando comandos[MAX_COMANDOS];
int contador = 0;
int contaLinha = 0;

void Undo(int *i){
    int posicao_undo = *i;

    for(int j = 0; j < comandos[posicao_undo].num_undo; j++){
        if (comandos[*i - 1].tempo == comandos[posicao_undo].tempo - 1 - j){
            *i = *i - 1;
        }
    }
}

void processa_linha(FILE *arq_sai){
    char texto[MAX_TAM_TEXT];
    int i;

    texto[0] = '\0';
    // Processar comandos
    for(i = contador - 1; i >= 0; i--){
        if(strcmp(comandos[i].comando, type) == 0){
            int tam = strlen(texto);
            texto[tam] = comandos[i].caracter;
            texto[tam + 1] = '\0';
        }
        if(strcmp(comandos[i].comando, undo) == 0){
            Undo(&i);
        }
    }

    int tam = strlen(texto);

    for(int i = 0; i < (tam / 2); i++){
        char aux = texto[i];
        texto[i] = texto[tam - 1 - i];
        texto[tam - 1 - i] = aux;
    }
    printf("%s\n", texto);
    fprintf(arq_sai, "%s\n", texto);
}

void coletar_comandos(FILE *arq_ent){
    contador = 0;
    char aux;

    fseek(arq_ent, sizeof(char), SEEK_CUR);
    while(fgets(comandos[contador].comando, sizeof(comandos[contador].comando), arq_ent) && (strcmp(comandos[contador].comando, type) == 0 || strcmp(comandos[contador].comando, undo) == 0)){
        if(strcmp(comandos[contador].comando, type) == 0){
            fseek(arq_ent, sizeof(char), SEEK_CUR);
            comandos[contador].caracter = fgetc(arq_ent);
            fseek(arq_ent, sizeof(char), SEEK_CUR);
        }
        if(strcmp(comandos[contador].comando, undo) == 0){
            fseek(arq_ent, sizeof(char), SEEK_CUR);
            comandos[contador].num_undo = 0;
            while((aux = fgetc(arq_ent)) && isdigit(aux)){
                comandos[contador].num_undo *= 10;
                comandos[contador].num_undo += aux - '0';
            }
        }
        contador++;
    }
    fseek(arq_ent, sizeof(char) * -2, SEEK_CUR);
    contador = 0;
    do{
        comandos[contador].tempo = 0;
        while((aux = fgetc(arq_ent)) != EOF && isdigit(aux)){
            comandos[contador].tempo *= 10;
            comandos[contador].tempo += aux - '0';
        }
        fseek(arq_ent, sizeof(char) * -1, SEEK_CUR);
        contador++;
    }while((aux = fgetc(arq_ent)) && aux == ',');
    fseek(arq_ent, sizeof(char) * 2, SEEK_CUR);
}

int main(){
    FILE *arq_ent = fopen(ARQ_ENT, "r");
    FILE *arq_sai = fopen(ARQ_SAI, "w");

    if(arq_ent == NULL || arq_sai == NULL){
        printf("Erro ao abrir o arquivo!!\n");
        return EXIT_FAILURE;
    }
    
    for(int i = 0; i < 10; i++){
        coletar_comandos(arq_ent);
        processa_linha(arq_sai);
    }
    fclose(arq_ent);
    fclose(arq_sai);
    return 0;
}