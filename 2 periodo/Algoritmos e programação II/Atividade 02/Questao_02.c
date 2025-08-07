#include <stdio.h>

int main(){
    char nome[20];
    int i = 0;

    scanf("%[^\n]s", nome);
    
    do{
        printf("%c ", nome[i] - 32);
        i++;
    } while(nome[i] != '\0');
    return 0;
}