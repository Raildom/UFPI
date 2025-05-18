// faça um programa que tenha 4 opções. (Utilizando arquivo.txt)
// 1-escrever uma palavra de ate 50 caracteres e colocar no arquivo

// 2- printar todas as palavras do arquivo, caso estiver vazio printar "arquivo vazio".

// 3- Formatar arquivo, (limpar/excluir arquivo e criar um novo.

// 4- finalizar, fechar o programa

// 5- buscar, deve achar o nome e perguntar se deseja modificalo, se achar, 
//perguntar se deseja modifica-lo, se não achar, printar "nome não encontrado"

// Bonus- fazer uma blindagem para verificar se o arquivo existe, caso não existir criar um novo.

// Iremos definir o nome do arquivo de FRASES.txt

#include <stdio.h>
#include <string.h>

void escrever();
void ler();
void formatar();
void busca();

FILE *arq;
char palavra[50];

int main(){
    int opcao;

    arq = fopen("FRASES.txt", "r");
    fclose(arq);
    if(arq){  
        printf("existe");  
    }
    else{
        printf("nao existe");
        arq = fopen("FRASES.txt", "w");
        fclose(arq); 
    }
    while(opcao != 5){
        printf("\n\n[1] - escrever\n[2] - ler\n[3] - formatar\n[4] - busca\n:");
        if(scanf("%d", &opcao) == 1){
        }else{
            scanf("%*c");
        }

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
    arq = fopen("FRASES.txt", "a");
    fprintf(arq, "%s\n", palavra);
    fclose(arq);
}

void ler(){
    int count = 0;

    arq = fopen("FRASES.txt", "r");
    while(fgets(palavra, sizeof(palavra), arq)){
        printf("%s", palavra);
        count++;
    }
    if(count == 0){
        printf("arquivo vazio\n");
    }
    fclose(arq);
}

void formatar(){
    arq = fopen("FRASES.txt", "w");
    fclose(arq);
}

void busca(){
    int opcao;
    char palavra2[50];

    scanf("%*c");
    printf("Digite a palavra: ");
    fgets(palavra2, sizeof(palavra2), stdin);
    arq = fopen("FRASES.txt", "r+");
    while(!feof(arq)){
        fread(palavra, sizeof(palavra), 1, arq);
        if(strcmp(palavra2, palavra) == 0){
            printf("Deseja modifica-lo?\n[1] - sim\n[2] - nao\n: ");
            scanf("%d", &opcao);
            if(opcao == 1){
            }
        }else{
            printf("\nFrase nao encontrada\n");
        }
    }
    fclose(arq);
}