// faça um programa que tenha 4 opções. (Utilizando arquivo.txt)
// 1-escrever uma palavra de ate 50 caracteres e colocar no arquivo

// 2- printar todas as palavras do arquivo, caso estiver vazio printar "arquivo vazio".

// 3- Formatar arquivo, (limpar/excluir arquivo e criar um novo.

// 4- finalizar, fechar o programa

// Bonus- fazer uma blindagem para verificar se o arquivo existe, caso não existir criar um novo.

// Iremos definir o nome do arquivo de FRASES.txt

#include <stdio.h>
#include <string.h>

char palavra[50];
FILE *arq;

void escrever();
void ler();
void formatar();
void busca();

int main(){
    int opcao;

    arq = fopen("FRASES.bin", "rb");
    fclose(arq);
    if(arq){  
        printf("existe");  
    }
    else{
        printf("nao existe");
        arq = fopen("FRASES.bin", "wb");
        fclose(arq); 
    }
    while(opcao != 5){
        printf("\n\n1 - escrever 2 - ler 3 - formatar 4 - busca 5 - sair\n:");
        scanf(" %d", &opcao);
        switch(opcao){
            case 1:
                escrever();
                break;
            case 2:
                ler();
                break;
            case 3:
                formatar();
                break;
            case 4:
                busca();
                break;
        }
    }
    return 0;
}

void escrever(){
    scanf(" %[^\n]", palavra);
    arq = fopen("FRASES.bin", "ab");
    fwrite(palavra, sizeof(palavra), 1, arq);
    fclose(arq);
}

void ler(){
    int count = 0;

    arq = fopen("FRASES.bin", "rb");
    if(arq == NULL){
        printf("erro\n");
    }
    while(fread(palavra, sizeof(palavra), 1, arq)){
        printf("%s\n", palavra);
        count++;
    }
    if(count == 0){
        printf("arquivo vazio\n");
    }
    fclose(arq);
}

void formatar(){
    arq = fopen("FRASES.bin", "wb");
    fclose(arq);
}

void busca(){
    char palavra2[50];

    arq = fopen("FRASES.bin", "rb");
    if(arq == NULL){
        printf("erro\n");
    }
    printf("Digite a palavra: ");
    scanf(" %[^\n]", palavra2);
    while(fread(palavra, sizeof(palavra), 1, arq)){
        if(strcmp(palavra, palavra2) == 0){
            printf("\n\n%s\n", palavra);
            return;
        }
    }
    printf("nao esta contido\n");
    fclose(arq);
}