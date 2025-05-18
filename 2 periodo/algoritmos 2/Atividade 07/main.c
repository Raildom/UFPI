#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sorting.h"

int main(){
	int n, i, ordem, algoritmo, quantidade, j = 0;
	scanf("%d %d",&n, &quantidade);
	Alunos aluno[n];

	while(j < quantidade){
		scanf("%d %d",&ordem, &algoritmo);
		if(algoritmo == 0){
			gerarDados(aluno, n, ordem);
			for(i = 0; i < n; i++){
				printf("%d ",aluno[i].chave);
			}
			printf("\n");
			printf("bolha\n");
			bolha(aluno, n);
			for(i = 0; i < n; i++){
				printf("%d ",aluno[i].chave);
			}
			printf("\n");
		}else if(algoritmo == 1){
			gerarDados(aluno, n, ordem);
			for(i = 0; i < n; i++){
				printf("%d ",aluno[i].chave);
			}
			printf("\n");
			printf("selecao\n");
			selecao(aluno, n);
			for(i = 0; i < n; i++){
				printf("%d ",aluno[i].chave);
			}
			printf("\n");
		}else if(algoritmo == 2){
			gerarDados(aluno, n, ordem);
			for(i = 0; i < n; i++){
				printf("%d ",aluno[i].chave);
			}
			printf("\n");
			printf("insercao\n");
			insercao(aluno, n);
			for(i = 0; i < n; i++){
				printf("%d ",aluno[i].chave);
			}
			printf("\n");
		}
		j++;
	}
} 