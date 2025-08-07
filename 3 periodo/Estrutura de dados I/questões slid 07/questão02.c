#include <stdio.h>

typedef struct{
    char nome[50];
    float nota1;
    float nota2;
    float nota3;
}aluno;

int main(){
    aluno alunos[10];

    for(int i = 0; i < 10; i++){
        printf("Digite o nome do %d aluno: ", i + 1);
        scanf(" %[^\n]s", alunos[i].nome);
        printf("Digite a primeira nota do aluno %d: ", i + 1);
        scanf("%f", &alunos[i].nota1);
        printf("Digite a segunda nota do aluno %d: ", i + 1);
        scanf("%f", &alunos[i].nota2);
        printf("Digite a terceira nota do aluno %d: ", i + 1);
        scanf("%f", &alunos[i].nota3);
    }
    for(int i = 0; i < 10; i++){
        float media = (alunos[i]. nota1 + alunos[i]. nota2 + alunos[i]. nota3 ) / 3;
        printf("A media do aluno %s e: %.2f\n", alunos[i].nome, media);
    }
    return 0;
}