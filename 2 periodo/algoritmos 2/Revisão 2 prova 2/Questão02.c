#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define maxItens 1000
#define tamanhoDescricao 30
#define nomeArquivo "celulareses.bin"

typedef struct{
    int codigo;
    char descricao[tamanhoDescricao];
    float preco;
}Registros;

void cadastrar();
void visualizar();
void remover();
int busca(int codigo);


int main(){
    int opcao;

    while(1){
        printf("\n\n1-Cadastrar\n2-Vizualizar\n3-Remover registro\n4-Finalizar");
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
                remover();
                break;
            case 4:
                return 0;
            default:
                printf("Opcao invalida!\n");
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

    Registros celulares;
    printf("Digite o codigo: ");
    scanf("%d", &celulares.codigo);
    getchar();
    if(busca(celulares.codigo) != -1){
        printf("Codigo ja foi cadastrado!\n");
        fclose(arquivo);
        return;
    }
    printf("Digite a descricao: ");
    fgets(celulares.descricao, tamanhoDescricao, stdin);
    celulares.descricao[strcspn(celulares.descricao, "\n")] = '\0';
    printf("Digite o preco: ");
    scanf("%f", &celulares.preco);
    getchar();
    fwrite(&celulares, sizeof(Registros), 1, arquivo);
    fclose(arquivo);
}

void visualizar(){
    FILE *arquivo = fopen(nomeArquivo, "rb");
    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo");
        return;
    }

    Registros celulares;
    while(fread(&celulares, sizeof(Registros), 1, arquivo)){
        printf("%d, %s, %.2f\n", celulares.codigo, celulares.descricao, celulares.preco);
    }

    fclose(arquivo);
}

void remover(){
    int codigo;
    printf("Digite o código do celulares a ser removido: ");
    scanf("%d", &codigo);
    getchar();

    FILE *arquivo = fopen(nomeArquivo, "rb");
    if(arquivo == NULL){
        perror("Erro ao abrir o arquivo");
        return;
    }

    FILE *temp = fopen("temp.bin", "wb");
    if(temp == NULL){
        perror("Erro ao abrir o arquivo temporário");
        fclose(arquivo);
        return;
    }

    Registros celulares;
    int encontrado = 0;
    while(fread(&celulares, sizeof(Registros), 1, arquivo)){
        if(celulares.codigo == codigo){
            encontrado = 1;
        }else{
            fwrite(&celulares, sizeof(Registros), 1, temp);
        }
    }
    fclose(arquivo);
    fclose(temp);
    remove(nomeArquivo);
    rename("temp.bin", nomeArquivo);
    if(encontrado){
        printf("celulare removido com sucesso!\n");
    }else{
        printf("Codigo nao encontrado!\n");
    }
}

int busca(int codigo){
    FILE *arquivo = fopen(nomeArquivo, "rb");
    if(arquivo == NULL){
        return -1;
    }

    Registros celulares;
    int posicao = 0;
    while(fread(&celulares, sizeof(Registros), 1, arquivo)){
        if(celulares.codigo == codigo){
            fclose(arquivo);
            return posicao;
        }
        posicao++;
    }
    fclose(arquivo);
    return -1;
}