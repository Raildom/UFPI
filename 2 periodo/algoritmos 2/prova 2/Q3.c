#include <stdio.h>

int main(){
    int segundos, horas, minutos;
    FILE *entrada = fopen("entrada.txt", "r");
    FILE *saida = fopen("saida.txt", "w");


    if(entrada == NULL || saida == NULL){
        printf("Erro ao abrir o arquivo!\n");
    }
    while(fscanf(entrada, "%d", &segundos) == 1){
        horas = segundos / 3600;
        minutos = (segundos % 3600) / 60;
        segundos = segundos % 60;
        fprintf(saida, "%d:%d:%d\n", horas, minutos, segundos);
    }
    fclose(entrada);
    fclose(saida);
    return 0;
}