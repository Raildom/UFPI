#include <stdio.h>

void preencher(int linha, int coluna, char matriz[linha][coluna]);
void imprimir(int linha, int coluna, char matriz[linha][coluna]);

int main()
{
    int coluna, linha;

    printf("Digite a coluna e a linha:\n");
    scanf("%d", &coluna);
    scanf("%d", &linha);

    char matriz[linha][coluna];

    preencher(linha, coluna, matriz);

    imprimir(linha, coluna, matriz);

    return 0;
}

void preencher(int linha, int coluna, char matriz[linha][coluna])
{

    for (int i = 0; i < linha; i++)
    {
        for (int j = 0; j < coluna; j++)
        {
            if (i == 0 || i == linha - 1 || j == 0 || j == coluna - 1)
            {
                matriz[i][j] = '*';
            }
            else
            {
                matriz[i][j] = '0';
            }
        }
    }
}

void imprimir(int linha, int coluna, char matriz[linha][coluna])
{
    printf("\n");

    for (int i = 0; i < linha; i++)
    {
        for (int j = 0; j < coluna; j++)
        {
            printf("%c  ", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
