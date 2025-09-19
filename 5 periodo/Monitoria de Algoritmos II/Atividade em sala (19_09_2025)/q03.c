#include <stdio.h>

// Função para preencher o vetor com 10 inteiros positivos
void preencherVetor(int vet[], int tamanho)
{
    printf("Digite %d numeros inteiros positivos:\n", tamanho);
    for (int i = 0; i < tamanho; i++)
    { // Pegando os 10 valores
        scanf("%d", &vet[i]);
    }
}

// Função que retorna o valor da posição antecessora da última ocorrência de N
int buscaAntecessorUltimaOcorrencia(int vet[], int tamanho, int N)
{
    int ultimaPos = -1; // variável para guardar a última posição encontrada
    int resultado; // retorno

    // percorre o vetor procurando a última ocorrência
    for (int i = 0; i < tamanho; i++)
    {
        if (vet[i] == N)
        {
            ultimaPos = i; // guarda a posição sempre que encontra
        }
    }
    
    // Verifica o resultado baseado na última posição encontrada
    if (ultimaPos == -1)
    {
        resultado = 0; // não encontrou
    }
    else if (ultimaPos == 0)
    {
        resultado = -1; // última ocorrência na primeira posição
    }
    else
    {
        resultado = vet[ultimaPos - 1]; // valor da posição anterior
    }

    return resultado;
}

int main()
{
    int vetor[10];
    int N, resultado;

    preencherVetor(vetor, 10);

    printf("Digite o numero N: ");
    scanf("%d", &N);

    resultado = buscaAntecessorUltimaOcorrencia(vetor, 10, N);

    printf("Resultado: %d\n", resultado);

    return 0;
}