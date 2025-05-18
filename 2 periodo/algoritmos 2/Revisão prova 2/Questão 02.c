#include <stdio.h>

void selecao(int instancias[], int numeroInstacias);

int main(){
    int numeroInstancias, numeroInterios;

    scanf("%d", &numeroInstancias);
    scanf("%*c");
    while(numeroInstancias > 0){
        scanf("%d", &numeroInterios);
        int instancias[numeroInterios];
        for(int i = 0; i < numeroInterios; i++){
            scanf("%d", &instancias[i]);
        }
        scanf("%*c");
        selecao(instancias, numeroInterios);
        numeroInstancias--;
    }
    return 0;
}

void selecao(int instancias[], int numeroInteiros){
	int i, j, min, auxiliar, MOV = 0;

	for(i = 0; i < numeroInteiros; i++){
		min = i;
		for(j = i + 1; j < numeroInteiros; j++){
			if(instancias[j] < instancias[min]){
				min = j;
			}
		}
		if(instancias[i] != instancias[min]){
            auxiliar = instancias[i];
            instancias[i] = instancias[min];
            instancias[min] = auxiliar;
		    MOV++;
        }
	}
	printf("\nComparacao: selecao %d\n", MOV);
}