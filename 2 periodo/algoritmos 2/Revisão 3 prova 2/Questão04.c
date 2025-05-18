#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define maxFuncionarios 1000
#define tamanhoNome 50
#define nomeArquivo "funcionarios.bin"

typedef struct{
    int codigo;
    char nome[tamanhoNome];
}Registros;

void cadastrar();
void visualizar();
int busca(int codigo);

int main(){
    int opcao;

    while(1){
        printf("\n\n1-Cadastrar\n2-Vizualizar\n3-Finalizar");
        printf("\nInforme o modulo desejado: ");
        scanf("%d", &opcao);
        getchar();
        switch(opcao){
            case 1:
                cadastrar();
                break;
            case 2:
                visualizar();
                break;
            case 3:
                return;
        }
    }
    return 0;
}

void cadastrar(){
    FILE *arquivo = fopen(nomeArquivo, "ab+");
    if(arquivo == NULL) {
        printf("Erro ao abrir o arquivo");
        return;
    }

    Registros funcionarios;
    printf("Digite o codigo: ");
    scanf("%d", &funcionarios.codigo);
    getchar();
    if(busca(funcionarios.codigo) != -1){
        printf("Codigo ja foi cadastrado!\n");
        fclose(arquivo);
        return;
    }
    printf("Digite o nome: ");
    fgets(funcionarios.nome, tamanhoNome, stdin);
    funcionarios.nome[strcspn(funcionarios.nome, "\n")] = '\0';
    fwrite(&funcionarios, sizeof(Registros), 1, arquivo);
    fclose(arquivo);
}

void visualizar(){
    FILE *arquivo = fopen(nomeArquivo, "rb");

    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo");
        return;
    }

    Registros funcionarios;
    while(fread(&funcionarios, sizeof(Registros), 1, arquivo)){
        printf("%d, %s\n", funcionarios.codigo, funcionarios.nome);
    }
    fclose(arquivo);
}

int busca(int codigo){
    int posicao = 0;
    FILE *arquivo = fopen(nomeArquivo, "rb");

    if(arquivo == NULL){
        return -1;
    }

    Registros funcionarios;
    while(fread(&funcionarios, sizeof(Registros), 1, arquivo)){
        if(funcionarios.codigo == codigo){
            fclose(arquivo);
            return posicao;
        }
        posicao++;
    }
    fclose(arquivo);
    return -1;
}