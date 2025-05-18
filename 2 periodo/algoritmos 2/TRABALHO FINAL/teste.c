#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ENTRADA "entrada.txt"
#define MAXIMO_DE_SEGUNDOS 100
#define MAXIMO_DE_COMANDOS 100

typedef struct {
    char comando[50];
    int segundos[MAXIMO_DE_SEGUNDOS];
} COMANDOS;

COMANDOS todosComandos[MAXIMO_DE_COMANDOS];
int numComandos = 0;
int todosSegundos[MAXIMO_DE_SEGUNDOS];
int numSegundosTotais = 0;
int vetor[50] = {0};

void processaLinha(char *linha) {
    int i = 0;
    char *token = strtok(linha, ",{}");
    while (token) {
        if (strncmp(token, "type ", 5) == 0) {
            snprintf(todosComandos[numComandos++].comando, 50, "%c", token[5]);
        } else if (strncmp(token, "undo ", 5) == 0) {
            snprintf(todosComandos[numComandos++].comando, 50, "%d", atoi(&token[5]));
            vetor[i] = atoi(&token[5]);
            printf("%d\n", vetor[i]);
        } else {
            todosSegundos[numSegundosTotais++] = atoi(token);
        }
        token = strtok(NULL, ",{}");
    }
}

void calculaUndo() {
    FILE *entrada = fopen(ENTRADA, "r");
    if (!entrada) {
        perror("Erro ao abrir o arquivo entrada");
        return;
    }
    int contaLinha = 1;
    char aux;
    while ((aux = fgetc(entrada)) != EOF) {
        if (aux == '\n') {
            contaLinha++;
        }
    }
    rewind(entrada);
    printf("conta_linha: %d\n", contaLinha);
    fclose(entrada);
}

int main() {
    FILE *entrada = fopen(ENTRADA, "r");
    if (!entrada) {
        perror("Erro ao abrir o arquivo entrada");
        return EXIT_FAILURE;
    }

    char linha[256];
    while (fgets(linha, sizeof(linha), entrada)) {
        processaLinha(linha);
    }
    fclose(entrada);

    for (int i = 0; i < numComandos; i++) {
        printf("%s ", todosComandos[i].comando);
    }
    printf("\n");

    for (int i = 0; i < numSegundosTotais; i++) {
        printf("%d ", todosSegundos[i]);
    }
    printf("\n");

    calculaUndo();

    return 0;
}