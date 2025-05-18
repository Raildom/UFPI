#include <stdio.h>
#define tam 3

typedef struct{
    char nome[50];
    float altura;
}PESSOA;

int pessoa_mais_alta(PESSOA pessoas[]){
    int indice_maior = 0;
    for(int i = 1; i < tam; i++){
        if(pessoas[i].altura > pessoas[indice_maior].altura){
            indice_maior = i;
        }
    }
    return indice_maior;
}

int main(){
    PESSOA pessoas[tam];

    for(int i = 0; i < tam; i++){
        printf("Digite o nome da %d pessoa: ", i + 1);
        scanf("%[^\n]", pessoas[i].nome);
        printf("Digite a altura da %d pessoa: ", i + 1);
        scanf("%f", &pessoas[i].altura);
        getchar();
    }

    int indice_maior = pessoa_mais_alta(pessoas);

    printf("A pessoa mais alta e: %s\n", pessoas[indice_maior].nome);
    return 0;
}