#include "arquivoes.h"
#include <stdio.h>

int main(){
    int opcao, auxiliar = 0;
    char nomeArquivo[50];
    Alunos turma[1000];

    do{
        printf("\nSistema de backup de dados");
        printf("\nInforme a operacao desejada (1-salvar, 2-restaurar):\n");
        scanf("%d", &opcao);
        scanf("%*c");
        switch(opcao){
            case 1:
                if(auxiliar == 0){
                    printf("Digite o nome do arquivo (com o .txt incluso): ");
                    fgets(nomeArquivo, 50, stdin);
                    auxiliar++;
                }
                salvarDados(turma, nomeArquivo);
                break;
            case 2:
                printf("Digite o nome do arquivo (com o .txt incluso): ");
                fgets(nomeArquivo, 50, stdin);
                restaurarDados(nomeArquivo, turma);
                break;
        }
    }while(opcao != 0);
    return 0;
}