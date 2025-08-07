#include <stdio.h>

int main(){
    char nome[20];
    int i = 0, indice[20] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

    printf("Informe uma palavra: ");
    scanf("%[^\n]s", nome);
    
    printf("Cebolinha falaria: ");
    do{
        if(nome[i] == 'r'){
            nome[i] -= 6;
            indice[i]++;
        }
        printf("%c", nome[i]);
        i++;
    } while(nome[i] != '\0');

    printf("\nHouve troca nos caracteres: ");
        for(i = 0; i < 20; i++){
            if(indice[i] > 0){
                printf("%d, ", i + 1);
            }    
        }
        printf("\b\b \n");
    return 0;
}

