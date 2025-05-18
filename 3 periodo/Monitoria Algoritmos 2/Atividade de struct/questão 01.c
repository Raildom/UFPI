#include <stdio.h>

#define tam 3

typedef struct{
    char nome[50];
    int idade;
    float notas[tam];
}ALUNO;

void  imprimir(ALUNO alunos[]){
    for(int i = 0; i < tam; i++){
        printf("NOME: %s\nIDADE: %d\n", alunos[i].nome, alunos[i]. idade);
        for(int j = 0; j < tam; j++){
            printf("%.2f\n",  alunos[i].notas[j]);
        }
    }
}

int main(){
    ALUNO alunos[tam];

    for(int i = 0; i < tam; i++){
        printf("Digite o nome do %d aluno: ", i + 1);
        scanf("%[^\n]", alunos[i].nome);
        printf("Digite a idade do %d aluno: ", i + 1);
        scanf("%d", &alunos[i].idade);
        printf("Digite as 3 notas do %d aluno: ", i + 1);
        for(int j = 0; j < tam; j++){
            printf("\nNOTA %d: ", j + 1);
            scanf("%f", &alunos[i].notas[j]);
        }
        getchar();
    }
    imprimir(alunos);
    return 0;
}