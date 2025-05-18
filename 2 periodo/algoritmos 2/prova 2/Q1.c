#include <stdio.h>

void bolhaCrescente(int numero[], int execucoes);
void bolhaDecrecente(int numero[], int execucoes);

int main(){
    int execucoes = 0, numero, contaPares = 0, contaImpares = 0;

    scanf("%d", &execucoes);
    int pares[execucoes], impares[execucoes];

    for(int i = 0; i < execucoes; i++){
        scanf("%d", &numero);
        if(numero % 2 == 0){
            pares[contaPares++] = numero;
        }else{
            impares[contaImpares++] = numero;
        }
    }
    bolhaCrescente(pares, contaPares);
    bolhaDecrecente(impares, contaImpares);
    return 0;
}

void bolhaCrescente(int numero[], int execucoes){
    int i, j, auxiliar;

    for(i = 0; i < execucoes - 1; i++){
        for(j = 0; j < execucoes - i - 1; j++){
            if(numero[j] > numero[j + 1]){
                auxiliar = numero[j];
                numero[j] = numero[j + 1];
                numero[j + 1] = auxiliar;
            }
        }
    }

    for(i = 0; i < execucoes; i++){
        printf("%d\n", numero[i]);
    }
}

void bolhaDecrecente(int numero[], int execucoes){
    int i, j, auxiliar;

    for(i = 0; i < execucoes - 1; i++) {
        for(j = 0; j < execucoes - i - 1; j++){
            if(numero[j] < numero[j + 1]){
                auxiliar = numero[j];
                numero[j] = numero[j + 1];
                numero[j + 1] = auxiliar;
            }
        }
    }

    for(i = 0; i < execucoes; i++){
        printf("%d\n", numero[i]);
    }
}
