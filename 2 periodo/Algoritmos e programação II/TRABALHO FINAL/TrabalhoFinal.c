#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define type "type"
#define undo "undo"
#define maximo_de_comandos 50

void processa_dados(FILE *arquivo_entrada);
void processa_linha(FILE *arquivo_saida);
void Undo(int *i);

typedef struct
{
    char comando[5];
    char caractere;
    int numero_undo;
    int segundos;
}COMANDO;

COMANDO comandos[maximo_de_comandos];
int contador = 0;

int main(int argc, char **argav)
{
    FILE *arquivo_entrada = fopen(argav[1], "r"), *arquivo_saida = fopen(argav[2], "w");

    if(arquivo_entrada == NULL || arquivo_saida == NULL || argc != 3)
    {
        printf("Erro ao encontrar os arquivos");
        return 1;
    }

    int conta_linha = 1;
    char auxiliar;

    while((auxiliar = fgetc(arquivo_entrada)) != EOF)
    {
        if(auxiliar == '\n')
        {
            conta_linha++;
        }
    }rewind(arquivo_entrada);
    for(int i = 0; i < conta_linha; i++)
    {
        processa_dados(arquivo_entrada);
        processa_linha(arquivo_saida);
    }
    fclose(arquivo_entrada);
    fclose(arquivo_saida);
    return 0;
}

void processa_dados(FILE *arquivo_entrada)
{
    char auxiliar;

    contador = 0;
    fseek(arquivo_entrada, sizeof(char), SEEK_CUR);
    while(fgets(comandos[contador].comando, sizeof(comandos[contador].comando), arquivo_entrada) && (strcmp(comandos[contador].comando, type) == 0 || strcmp(comandos[contador].comando, undo) == 0))
    {
        if(strcmp(comandos[contador].comando, type) == 0)
        {
            fseek(arquivo_entrada, sizeof(char), SEEK_CUR);
            comandos[contador].caractere = fgetc(arquivo_entrada);
            fseek(arquivo_entrada, sizeof(char), SEEK_CUR);
        }else if(strcmp(comandos[contador].comando, undo) == 0)
        {
            fseek(arquivo_entrada, sizeof(char), SEEK_CUR);
            comandos[contador].numero_undo = 0;
            while((auxiliar = fgetc(arquivo_entrada)) && isdigit(auxiliar))
            {
                comandos[contador].numero_undo *= 10;
                comandos[contador].numero_undo += auxiliar - '0';
            }
        }
        contador++;
    }
    fseek(arquivo_entrada, sizeof(char) * -2, SEEK_CUR);
    contador = 0;
    do{
        comandos[contador].segundos = 0;
        while((auxiliar = fgetc(arquivo_entrada)) != EOF && isdigit(auxiliar))
        {
            comandos[contador].segundos *= 10;
            comandos[contador].segundos += auxiliar - '0';
        }
        fseek(arquivo_entrada, sizeof(char) * -1, SEEK_CUR);
        contador++;
    }while((auxiliar = fgetc(arquivo_entrada)) && auxiliar == ',');
    fseek(arquivo_entrada, sizeof(char) * 2, SEEK_CUR);
}

void processa_linha(FILE *arquivo_saida)
{
    char texto[maximo_de_comandos];
    int i;

    texto[0] = '\0';
    for(i = contador - 1; i >= 0; i--){
        if(strcmp(comandos[i].comando, type) == 0)
        {
            int tam = strlen(texto);
            texto[tam] = comandos[i].caractere;
            texto[tam + 1] = '\0';
        }else if(strcmp(comandos[i].comando, undo) == 0)
        {
            Undo(&i);
        }
    }

    int tam = strlen(texto);

    for(int i = 0; i < (tam / 2); i++)
    {
        char auxiliar = texto[i];
        texto[i] = texto[tam - 1 - i];
        texto[tam - 1 - i] = auxiliar;
    }
    fprintf(arquivo_saida, "%s\n", texto);
}

void Undo(int *i)
{
    int posicao_undo = *i;

    for(int j = 0; j < comandos[posicao_undo].numero_undo; j++)
    {
        if(comandos[*i - 1].segundos == comandos[posicao_undo].segundos - 1 - j)
        {
            *i = *i - 1;
        }
    }
}