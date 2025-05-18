#include <stdio.h>

int troco(int valorCompra, int valorPago);

int main(){
    int valorCompra, valorPago;
    FILE *entrada = fopen("entrada.txt", "r");
    FILE *saida = fopen("saida.txt", "w");

    if(entrada == NULL || saida == NULL){
        printf("Erro ao abrir o arquivo!\n");
    }
    while(fscanf(entrada, "%d%d", &valorCompra, &valorPago) == 2){
        if(troco(valorCompra, valorPago)){
            fprintf(saida, "possible\n");
        }else{
            fprintf(saida, "impossible\n");
        }
    }
    fclose(entrada);
    fclose(saida);
    return 0;
}

int troco(int valorCompra, int valorPago){
    int notas[] = {2, 5, 10, 20, 50, 100};
    int numeroNotas = 6;
    
    for(int i = 0; i < numeroNotas; i++){
        for(int j = 0; j < numeroNotas; j++){
            if(notas[i] + notas[j] == valorPago - valorCompra){
                return 1;
            }
        }
    }
    
    return 0;
}