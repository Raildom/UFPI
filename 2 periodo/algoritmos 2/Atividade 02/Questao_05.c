#include <stdio.h>

int main() {
    char nome[5][20];
    float medidas[5][3], media[3] = {0};
    int i, j, menor[3] = {0}, maior[3] = {0};

    for (i = 0; i < 5; i++) {
        scanf("%s %f %f %f", nome[i], &medidas[i][0], &medidas[i][1], &medidas[i][2]);
        media[0] += medidas[i][0];
        media[1] += medidas[i][1];
        media[2] += medidas[i][2];

        if (i == 0) continue;
        for (j = 0; j < 3; j++) {
            if (medidas[i][j] < medidas[menor[j]][j]) {
                menor[j] = i;
            }
            if (medidas[i][j] > medidas[maior[j]][j]) {
                maior[j] = i;
            }
        }
    }
    for (i = 0; i < 3; i++) {
        //O programa irá imprimir as três medidas consecutivamente na seguinte ordem: [1] - altura, [2] - peso, [3] - IRA
        printf("Medida %d:\n", i + 1);
        printf("Media: %.2f\n", media[i] / 5);
        printf("Maior: %s - %.2f\n", nome[maior[i]], medidas[maior[i]][i]);
        printf("Menor: %s - %.2f\n", nome[menor[i]], medidas[menor[i]][i]);
        printf("\n");
    }
    return 0;
}