#include "arquivoes.h"
#include <stdio.h>

int main(){
    int opcao;
    do{
        printf("\nSistema de processamento de informacoes de alunos\n");
        printf("Informe a opcao desejada (1-formatar, 2-escrever, 3-ler, 4-buscar, 0-finalizar):\n");
        scanf("%d", &opcao);
        switch(opcao){
            case 1:
                formatarArquivo();
                break;
            case 2:
                escrita();
                break;
            case 3:
                leitura();
                break;
            case 4:
                busca();
                break;
            case 0:
                break;
            default:
                printf("Opcao invalida.\n");
        }
    }while(opcao != 0);
    return 0;
}