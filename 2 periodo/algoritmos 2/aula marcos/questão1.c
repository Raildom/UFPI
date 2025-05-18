// 1 questão
// Faça um programa em C que lê 5 frases de, no máximo, 50 caracteres cada uma e armazene-as em um arquivo texto. Mas, antes de gravar cada 
//frase no arquivo, é necessário converter todas as suas letras para maiúsculas. Os nome do arquivo será fornecido, via teclado, pelo usuário. 
//A função que converte maiuscula para minúscula é o toupper() (biblioteca ctype), ou pela tabela ascii. A seguir, 
//feche o arquivo e reabra para leitura exibindo todas as frases.
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void limpaCaractere(char *palavra);

int main(){
    char frases[50], nomeArquivo[50];

    fgets(nomeArquivo, sizeof(nomeArquivo), stdin);
    limpaCaractere(nomeArquivo);

    FILE *arquivo = fopen(nomeArquivo, "a");
    if(arquivo){
        for(int i = 0; i < 3; i++){
            fgets(frases, sizeof(frases), stdin);
            limpaCaractere(frases);
            for(int j = 0; frases[j] != '\0'; j++){
                frases[j] = toupper(frases[j]);
            }
            fprintf(arquivo, "%s\n", frases);
        }
    }else{
        printf("erro");
    }
    fclose(arquivo);

    arquivo = fopen(nomeArquivo, "r");
    while(fgets(frases, sizeof(frases), arquivo)){
        printf("%s", frases);
    }
    fclose(arquivo);
    return 0;
}

void limpaCaractere(char *palavra){
    int tamanho = strlen(palavra);
    palavra[tamanho - 1] = '\0';
}