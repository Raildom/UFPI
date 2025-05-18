#include <stdio.h>

#define tamanho 21 

struct aluno {
    char nome[tamanho];
    float altura, peso, ira;
};

void LerValores(struct aluno alunos[]);
float Media(float medidas[]);

int main() {
    struct aluno alunos[5];
    float MediasAltura[5], MediasPeso[5], MediasIra[5], MediaAltura, MediaPeso, MediaIra; 
    int MaiorAluno = 0, MaiorPeso = 0, MaiorIra = 0, i;

    LerValores(alunos);

    for (i = 0; i < 5; i++) {
        MediasAltura[i] = alunos[i].altura;
        MediasPeso[i] = alunos[i].peso;
        MediasIra[i] = alunos[i].ira;
    }
    MediaAltura = Media(MediasAltura);
    MediaPeso = Media(MediasPeso);
    MediaIra = Media(MediasIra);
    printf("\nMedia de peso: %.3f\n", MediaPeso);
    printf("Media de altura: %.3f\n", MediaAltura);
    printf("Media de ira: %.3f\n", MediaIra);
    for (i = 1; i < 5; i++) {
        if (alunos[i].altura > alunos[MaiorAluno].altura) {
            MaiorAluno = i;
        }
        if (alunos[i].peso > alunos[MaiorPeso].peso) {
            MaiorPeso = i;
        }
        if (alunos[i].ira > alunos[MaiorIra].ira) {
            MaiorIra = i;
        }
    }
    printf("\nMaior peso: %s (%.3f)\n", alunos[MaiorPeso].nome, alunos[MaiorPeso].peso);
    printf("Maior altura: %s (%.3f)\n", alunos[MaiorAluno].nome, alunos[MaiorAluno].altura);
    printf("Maior ira: %s (%.3f)\n", alunos[MaiorIra].nome, alunos[MaiorIra].ira);
    return 0;
}

void LerValores(struct aluno alunos[]){
    int i;
    for (i = 0; i < 5; i++) {
        scanf("%20s %f %f %f", alunos[i].nome, &alunos[i].altura, &alunos[i].peso, &alunos[i].ira);
    }
}

float Media(float medidas[]) {
    float soma = 0;
    for (int i = 0; i < 5; i++) {
        soma += medidas[i];
    }
    return soma / 5;
}