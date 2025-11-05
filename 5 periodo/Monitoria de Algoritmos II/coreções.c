#include <stdio.h>
#include <string.h>

void triangulo(int n){
    for(int i=1; i<n; i++){
        for(int j=1; j<=i; j++){
            printf("*");
        }
        printf("\n");
    }

    for(int i=n-1; i>=1; i--){
        for(int j=1; j<=i; j++){
            printf("*");
        }
        printf("\n");
    }
}

int main(){
    
    int n;
    printf("Digite um numero inteiro positivo: ");
    scanf("%d", &n);
    triangulo(n);

    return 0;
} 