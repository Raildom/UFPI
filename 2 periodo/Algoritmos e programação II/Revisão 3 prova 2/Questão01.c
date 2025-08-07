#include <stdio.h>
#include <string.h>

typedef struct{
    char nome[21];
}Alunos;

void ordenaNome(Alunos *nomes, int quantidade);

int main(){
    int numeroSorteado, quantidadeAlunos;

    scanf("%d%d", &quantidadeAlunos, &numeroSorteado);

    Alunos nomes[quantidadeAlunos];

    for(int i = 0; i < quantidadeAlunos; i++){
        scanf("%s", nomes[i].nome);
    }
    ordenaNome(nomes, quantidadeAlunos);
    printf("\n%s\n", nomes[numeroSorteado - 1].nome);
    return 0;
}

void ordenaNome(Alunos *nomes, int quantidade){
    Alunos auxiliar;
    for(int i = 0; i < quantidade - 1; i++){
        for(int j = i + 1; j < quantidade; j++) {
            if(strcmp(nomes[i].nome, nomes[j].nome) > 0){
                auxiliar = nomes[i];
                nomes[i] = nomes[j];
                nomes[j] = auxiliar;
            }
        }
    }
}
