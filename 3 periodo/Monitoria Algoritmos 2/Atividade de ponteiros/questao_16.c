#include <stdio.h>

char* mystrcpy(char* origem, const char* destino){
    int i = 0;

    while(destino[i] != '\0'){
        origem[i] = destino[i];
        i++;
    }
    origem[i] = '\0';
    return origem;
}

int main(){
    char str[50];

    printf("Digite uma string: ");
    scanf("%[^\n]", str);

    char str2[50];

    mystrcpy(str2, str);
    printf("String copiada: %s\n", str2);
    return 0;
}