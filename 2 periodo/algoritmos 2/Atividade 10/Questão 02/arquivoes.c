#include <stdio.h>
#include "arquivoes.h"

void formatarArquivo(){
    FILE *arquivo;
    Aluno aluno = {0, "", "", ""};
    const int tamanhoArquivo = 1000;

    if((arquivo = fopen("dados.bin", "rb")) != NULL){
        printf("O arquivo ja existe. Deseja sobrescreve-lo? (1-sim, 0-nao)\n");
        int opcao;
        scanf("%d", &opcao);
        if(opcao != 1){
            fclose(arquivo);
            return;
        }
    }
    fclose(arquivo);
    if((arquivo = fopen("dados.bin", "wb")) == NULL){
        printf("Nao foi possivel criar o arquivo.\n");
        return;
    }
    for(int i = 0; i < tamanhoArquivo; i++){
        fwrite(&aluno, sizeof(aluno), 1, arquivo);
    }
    fclose(arquivo);
}

void escrita(){
    FILE *arquivo;
    Aluno aluno;

    if((arquivo = fopen("dados.bin", "rb+")) == NULL){
        printf("Arquivo nao encontrado.\n");
        return;
    }
    printf("Digite a chave do aluno (0-finalizar): ");
    scanf("%d", &aluno.chave);
    while(aluno.chave != 0 && aluno.chave <= 1000){
        printf("Digite o nome do aluno: ");
        scanf(" %[^\n]s", aluno.nome);
        printf("Digite o endereco do aluno: ");
        scanf(" %[^\n]s", aluno.endereco);
        printf("Digite o telefone do aluno: ");
        scanf(" %[^\n]s", aluno.telefone);
        fseek(arquivo, (aluno.chave - 1) * sizeof(Aluno), SEEK_SET);
        fwrite(&aluno, sizeof(aluno), 1, arquivo);
        printf("Digite a chave do aluno (0-finalizar): ");
        scanf("%d", &aluno.chave);
    }
    fclose(arquivo);
}

void leitura(){
    FILE *arquivo;
    Aluno aluno;
    int contaRegistros = 0;

    if((arquivo = fopen("dados.bin", "rb")) == NULL){
        printf("Erro ao abrir arquivo.\n");
        return;
    }
    printf("%-8s %-30s %-50s %-14s\n", "Chave", "Nome", "Endereco", "Telefone");
    while(fread(&aluno, sizeof(Aluno), 1, arquivo) == 1){
        if(aluno.chave != 0){
            printf("%-8d %-30s %-50s %-14s\n", aluno.chave, aluno.nome, aluno.endereco, aluno.telefone);
            contaRegistros++;
        }
    }
    if(contaRegistros == 0){
        printf("Nenhum registro encontrado.\n");
    }
    fclose(arquivo);
}

void busca(){
    FILE *arquivo;
    Aluno aluno;
    int chave;

    if((arquivo = fopen("dados.bin", "rb+")) == NULL){
        printf("Arquivo nao encontrado.\n");
        return;
    }
    printf("Digite a chave do aluno: ");
    scanf("%d", &chave);
    if(chave < 1 || chave > 1000){
        printf("Chave invalida.\n");
    }else{
        fseek(arquivo, (chave - 1) * sizeof(aluno), SEEK_SET);
        fread(&aluno, sizeof(aluno), 1, arquivo);
        if(aluno.chave == 0){
            printf("Nenhum registro de aluno com a chave informada foi encontrado.\n");
        }else{
            printf("%-8s %-30s %-50s %-14s\n", "Chave", "Nome", "Endereco", "Telefone");
            printf("%-8d %-30s %-50s %-14s\n", aluno.chave, aluno.nome, aluno.endereco, aluno.telefone);
        }
    }
    fclose(arquivo);
}