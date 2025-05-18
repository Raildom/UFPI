#include <stdio.h>

typedef struct{
    char nome[50];
    int idade;
    int matricula;
}aluno;

int main(){
    aluno alunos[5];

    for(int i = 0; i < 5; i++){
        printf("Digite o nome do %d aluno: ", i + 1);
        scanf(" %[^\n]s", alunos[i].nome);
        printf("Digite a idade do %d aluno: ", i + 1);
        scanf("%d", &alunos[i].idade);
        printf("Digite o nome do %d aluno: ", i + 1);
        scanf("%d", &alunos[i].matricula);
    }
    for(int i = 0; i < 5; i++){
        printf("%s\n%d\n%d\n\n", alunos[i].nome, alunos[i].idade, alunos[i].matricula);

    }
    return 0;
}