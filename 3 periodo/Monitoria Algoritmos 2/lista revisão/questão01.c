#include <stdio.h>

int absoluto(int n){
    if(n < 0){
        n *= -1;
    }
    return n;
}
    
int main(){
    int n;

    for(int i = 0; i < 5; i++){
        printf("\nDigite um numero: ");
        scanf("%d", &n);
        printf("%d\n", absoluto(n));
    }
    return 0;
}