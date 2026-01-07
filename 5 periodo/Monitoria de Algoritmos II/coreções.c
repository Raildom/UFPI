#include <stdio.h>
#include <string.h>

void intercalar(int *v1, int *v2, int *v3, int n1, int n2){
    int *p1 = v1, *p2 = v2, *p3 = v3, i1 = n1, i2 = n2;

    while(i1 > 0 || i2 > 0){
        for(int i = 0; i < 2 && i1 > 0; i++){
            *p3 = *(p1);
            p3++;
            p1++;
            i1--;
        }
        for(int k = 0; k < 2 && i2 > 0; k++){
            *p3 = *(p2);
            p3++;
            p2++;
            i2--;
        }
    }
}

int main(){
    int n1, n2;

    printf("Digite o tamanho do primeiro vetor: ");
    scanf("%d", &n1);
    printf("Digite o tamanho do segundo vetor: ");
    scanf("%d", &n2);

    int v1[n1], v2[n2], v3[n1 + n2];

    for(int c = 0; c < n1; c++){
        printf("Digite o %d elemento do primeiro vetor: ", c + 1);
        scanf("%d", (v1 + c));
    }

    for(int c = 0; c < n2; c++){
        printf("Digite o %d elemento do segundo vetor: ", c + 1);
        scanf("%d", (v2 + c));
    }

    intercalar(v1, v2, v3, n1, n2);

    printf("\nVetor intercalado: ");
    for(int c = 0; c < n1 + n2; c++){
        printf("%d ", *(v3 + c));
    }
    return 0;
}