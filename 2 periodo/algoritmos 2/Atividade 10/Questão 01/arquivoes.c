#include <stdio.h>
#include "arquivoes.h"

void cadastrarDados(Alunos *turma);
void imprimir(Alunos *turma);
char *limpaCaractere(char *palavra);
void ordenaChave(Alunos *turma);
void ordenaNome(Alunos *turma);

int quantidade = 0;

int salvarDados(Alunos *turma, char *nomeArquivo){
    limpaCaractere(nomeArquivo);
    cadastrarDados(turma);

    FILE *arquivo = fopen(nomeArquivo, "a");
    
    fprintf(arquivo, "%d\n", turma[quantidade - 1].chave);
    fprintf(arquivo, "%s", turma[quantidade - 1].nome);
    fprintf(arquivo, "%s", turma[quantidade - 1].endereco);
    fprintf(arquivo, "%s", turma[quantidade - 1].telefone);
    if(arquivo){
        fclose(arquivo);
        printf("Operacao concluida com sucesso!\n");
        return 1;
    }else{
        printf("\nERRO\n");
        return 0;
    }
}

int restaurarDados(char *nomeArquivo, Alunos *turma){
    limpaCaractere(nomeArquivo);
    Alunos aluno;
    FILE *arquivo = fopen(nomeArquivo, "r");

    quantidade = 0;
    if(arquivo){
        while(!feof(arquivo)){
            fscanf(arquivo, "%d\n", &aluno.chave);
            fgets(aluno.nome, 30, arquivo);
            fgets(aluno.endereco, 50, arquivo);
            fgets(aluno.telefone, 14, arquivo);
            turma[quantidade] = aluno;
            quantidade++;
        }
        quantidade--;
        fclose(arquivo);

        int opcao;

        printf("1 - chave 2 - nome\n:");
        scanf("%d", &opcao);
        scanf("%*c");
        switch(opcao){
            case 1:
                ordenaChave(turma);
                break;
            case 2:
                ordenaNome(turma);
                break;
        }
        printf("Operacao concluida com sucesso!\n");
        return 1;
    }else{
        printf("\nERRO\n");
        return 0;
    }
}

void ordenaChave(Alunos *turma){
	Alunos auxiliar;

	for(int i = 0; i < quantidade - 1; i++){
		for(int j = 1; j < quantidade - i; j++){
			if(turma[j].chave < turma[j - 1].chave){
				auxiliar = turma[j];
				turma[j] = turma[j - 1];
				turma[j - 1] = auxiliar;
			}
		}
	}
    imprimir(turma);
}

void ordenaNome(Alunos *turma){
    Alunos auxiliar;
    char vetor[1000][1000];  
    for(int i = 0; i < quantidade; i++){
        for(int j = 0; turma[i].nome[j] != '\0'; j++){
            vetor[i][j] = turma[i].nome[j];
            if(turma[i].nome[j] >= 'a' && turma[i].nome[j] <= 'z'){
                vetor[i][j] -= 32;
            }
        }
    }
    for(int i = 0; i < quantidade - 1; i++){
		for(int j = i + 1; j < quantidade; j++){
            for(int k = 0; turma[j].nome[k] != '\0' && turma[i].nome[k] != '\0'; k++){
			    if(vetor[i][k] > vetor[j][k]){
				    auxiliar = turma[i];
				    turma[i] = turma[j];
				    turma[j] = auxiliar;
                    break;
			    }
            }
		}
	}
    imprimir(turma);
}

void cadastrarDados(Alunos *turma){
    Alunos aluno;

    scanf("%d", &aluno.chave);
    scanf("%*c");
    fgets(aluno.nome, 30, stdin);
    fgets(aluno.endereco, 50, stdin);
    fgets(aluno.telefone, 14, stdin);
    turma[quantidade] = aluno;
    quantidade++;
}

void imprimir(Alunos *turma){
    for(int i = 0; i < quantidade; i++){
        printf("%d\n", turma[i].chave);
        printf("%s", turma[i].nome);
        printf("%s", turma[i].endereco);
        printf("%s\n", turma[i].telefone);
    }
}

char *limpaCaractere(char *palavra){
    for(int i = 0; palavra[i] != '\0'; i++){
        if(palavra[i] == '\n'){
            palavra[i] = '\0';
            break;
        }
    }
    return palavra;
}