#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sorting.h"

int COMP = 0, MOV = 0;

void gerarDados(Alunos v[], int n, int ordemChave){
	int i, j;

	if(ordemChave == 0){
		for(i = 0; i < n; i++){
			v[i].chave = i;
		}
	}
	if(ordemChave == 1){
		srand(time(NULL));
		for(i = 0; i < n; i++){
			v[i].chave = rand() % 1000;
		}
	}
	if (ordemChave == 2){
		for(i = n - 1, j = 0; i >= 0; i--, j++){
			v[j].chave = i;
		}
	}
}

void bolha(Alunos v[], int n){
	int i, j;
	Alunos auxiliar;
	MOV = 0;
	COMP = 0;

	for(i = 0; i < n - 1; i++){
		for(j = 1; j < n - i; j++){
			if(v[j].chave < v[j - 1].chave){
				auxiliar = v[j];
				v[j] = v[j - 1];
				v[j - 1] = auxiliar;
				MOV++;
			}
			COMP++;
		}
	}
	printf("\nComparacao: %d\nMovimentacao: %d\n\n", COMP, MOV);
}

void selecao(Alunos v[], int n){
	int i, j, min;
	Alunos auxiliar;
	MOV = 0;
	COMP = 0;

	for(i = 0; i < n; i++){
		min = i;
		for(j = i + 1; j < n; j++){
			if(v[j].chave < v[min].chave){
				min = j;
			}
			COMP++;
		}
		auxiliar = v[i];
		v[i] = v[min];
		v[min] = auxiliar;
		MOV++;
	}
	MOV =  3 * (MOV - 1);
	printf("\nComparacao: %d\nMovimentacao: %d\n", COMP, MOV);
}

void insercao(Alunos v[], int n){
	int i, j;
	Alunos auxiliar;
	MOV = 0;
	COMP = 0;

	for(i = 1; i < n; i++){
		auxiliar = v[i];
		j = i - 1;
		while((j >= 0) && (auxiliar.chave < v[j].chave)){
			v[j + 1] = v[j];
			MOV++;
			j--;
			COMP++;
		}
		v[j + 1] = auxiliar;
		MOV++;
	}
	printf("\nComparacao: %d\nMovimentacao: %d\n", COMP, MOV);
}