// Fazer um programa semelhante a questão 2 da lista 10, faça 4 opções.

// 1- Ler duas variáveis char "nome" e int "posicao", e registrar o nome de ate 50 caracteres, 
// e a posição que varia de 1 a 20 dentro do  arquivo binário, de modo que fique na posição que foi digitado.

// 2- buscar, aqui o usuário digitara uma posição e devera ver se essa posição tem um nome salvo no arquivo, 
// caso tenha printar e perguntar se deseja modificar o nome, caso sim modifque o nome na mesma posição, caso não tenha um nome salvo na 
// posição printar "posição vazia".

// 3- formatar, deverar limpar/excluir e preparar um novo arquivo binário.

// 4- finalizar

// Nome do arquivo sera definido como NOMES.bin

// Você deve preparar o arquivo para ate 20 nomes, dica, preencha ele com caracteres nulos.

// bônus- fazer uma blindagem para verificar se o arquivo existe, caso não existir criar um novo.

#include <stdio.h>
#include <string.h>

FILE *arq;
char nome[50];
int posicao = 0;

void escrever();

int main(){
    int opcao;

    if(arq == NULL){  
        printf("existe");  
    }
    else{
        printf("nao existe");
        arq = fopen("NOMES.bin", "wb");
        fclose(arq); 
    }
    while(opcao != 5){
        printf("\n\n1 - escrever 2 - ler 3 - formatar 4 - busca 5 - sair\n:");
        if(scanf("%d", &opcao) == 1){
        }else{
            scanf("%*c");
        }
        switch(opcao){
            case 1:
                escrever();
                break;
            // case 2:
            //     ler();
            //     break;
            // case 3:
            //     formatar();
            //     break;
            // case 4:
            //     busca();
            //     break;
        }
    }
    return 0;
}

void escrever(){
    printf("Digite o nome: ");
    scanf(" %[^\n]", nome);
    printf("Digite a posicao de 1 a 20: ");
    scanf(" %d", &posicao);

    arq = fopen("NOMES.bin", "ab");
    fseek(arq, sizeof(nome) * posicao, SEEK_SET);
    fwrite(nome, sizeof(nome), 1, arq);
    fclose(arq);
}