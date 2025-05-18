#include <stdio.h>

void maiusculo(char *sPtr);
int main(){
    char vet[100];

    do{
        scanf(" %[^\n]", vet);
        if(vet[0] != '0'){
            maiusculo(vet);
            printf("%s\n\n", vet);
        }
    }while(vet[0] != '0');
    return 0;
}

void maiusculo(char *sPtr){
    while(*sPtr != '\0'){
        if(*sPtr >= 'a' && *sPtr <= 'z'){
            *sPtr = *sPtr - 32;
        }
        ++sPtr;
    }
}
