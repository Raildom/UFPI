#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sorting.h"

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

	for(i = 0; i < n - 1; i++){
		for(j = 1; j < n - i; j++){
			if(v[j].chave < v[j - 1].chave){
				auxiliar = v[j];
				v[j] = v[j - 1];
				v[j - 1] = auxiliar;
			}
		}
	}
}

void selecao(Alunos v[], int n){
	int i, j, min;
	Alunos auxiliar;

	for(i = 0; i < n; i++){
		min = i;
		for(j = i + 1; j < n; j++){
			if(v[j].chave < v[min].chave){
				min = j;
			}
		}
		auxiliar = v[i];
		v[i] = v[min];
		v[min] = auxiliar;
	}
}

void insercao(Alunos v[], int n){
	int i, j;
	Alunos auxiliar;

	for(i = 1; i < n; i++){
		auxiliar = v[i];
		j = i - 1;
		while((j >= 0) && (auxiliar.chave < v[j].chave)){
			v[j + 1] = v[j];
			j--;
		}
		v[j + 1] = auxiliar;
	}
}