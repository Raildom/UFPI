#include <stdio.h>


double calculaArea(char operacao, double M[][12]);
int main(){
    double M[12][12], resultado;
    int i, j;
    char operacao;

    scanf("%c", &operacao);
    if(operacao == 'S' || operacao == 'M'){
        for(i = 0; i < 12; i++){
            for(j = 0; j < 12; j++){
                scanf("%lf", &M[i][j]);
            }
        }
        resultado = calculaArea(operacao, M);
        printf("\n%lf", resultado);
    }else{
        printf("opcao invalida");
    }
    
    return 0;
}

double calculaArea(char operacao, double M[][12]){
    double auxiliar = 0;
    int i, j, count = 0;

    if(operacao == 'S'){
        for(i = 0; i < 12; i++){
            for(j = 0; j < 12; j++){
                if(j >= 12 - i){
                    auxiliar += M[i][j];
                
                }
            }
        }
    }else if(operacao == 'M'){
        for(i = 0; i < 12; i++){
            for(j = 0; j < 12; j++){
                if(j >= 12 - i){
                    auxiliar += M[i][j];
                    count++;
                }
            }
        }
        auxiliar /= count;
    }
    return auxiliar;
}