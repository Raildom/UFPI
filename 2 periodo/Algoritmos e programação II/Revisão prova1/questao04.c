#include <stdio.h>

// Função para verificar se uma risada é engraçada
char risada_engracada(const char* const risada) {
    char vogais[] = "aeiou";
    char risada_vogais[51]; // Tamanho máximo da risada é 50, adicionamos 1 para o caractere nulo
    int contador_vogais = 0;

    // Filtrando as vogais da risada
    int i = 0;
    while (risada[i] != '\0') {
        char caractere_atual = risada[i];
        int eh_vogal = 0;
        
        // Verifica se o caractere atual é uma vogal
        for (int k = 0; k < 5; k++) {
            if (caractere_atual == vogais[k]) {
                eh_vogal = 1;
                break;
            }
        }
        
        // Se for vogal, adiciona ao array de vogais da risada
        if (eh_vogal) {
            risada_vogais[contador_vogais] = caractere_atual;
            contador_vogais++;
        }
        
        i++;
    }
    risada_vogais[contador_vogais] = '\0';

    // Verificando se a sequência de vogais é igual quando lida da esquerda para a direita e vice-versa
    int tamanho_risada_vogais = contador_vogais;
    for (int i = 0; i < tamanho_risada_vogais / 2; i++) {
        if (risada_vogais[i] != risada_vogais[tamanho_risada_vogais - i - 1]) {
            return 'N'; // Não é engraçada
        }
    }
    return 'S'; // É engraçada
}

int main() {
    char risada[51]; // Tamanho máximo da risada é 50

    // Leitura da entrada
    scanf("%s", risada);

    // Verificando se a risada é engraçada
    printf("%c\n", risada_engracada(risada));

    return 0;
}
