#include <stdio.h>

int main(){
    int n;
    printf("Insira o tamanho do vetor: ");
    scanf("%d", &n);
    if(n > 0){
        int vetor[n];
        int i, palindromo = 1;
        
        for(i = 0; i < n; i++){
            printf("Insira o valor da posição [%d]: ", i);
            scanf("%d", &vetor[i]);
        }
        
        for(i = 0; i < n; i++){
            printf("%d\t", vetor[i]);
        }
        
        for(i = 0; i < n / 2; i++){
            if (vetor[i] != vetor[n - 1 - i]) {
                palindromo = 0; // Não é palíndromo
                break;
            }
        }
        
        if(palindromo){
            printf("\nO vetor é palíndromo!");
        } else{
            printf("\nO vetor não é palíndromo!");
        }
    } else{
        printf("Valor inválido!");
    }

    return 0;
}