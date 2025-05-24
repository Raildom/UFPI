#include <stdio.h>

char* maiusculo(char* nome){
    int i = 0;
    
    while(nome[i] != '\0'){
        if(nome[i] >= 'a' && nome[i] <= 'z'){
            nome[i] -= 32;
        }
        i++;
    }
    return nome;
}   

int main(){
    char nome[50];

    printf("Digite seu nomee: ");
    scanf("%[^\n]", nome);

    printf("Nome em maiusculo: %s\n", maiusculo(nome));

    return 0;
}