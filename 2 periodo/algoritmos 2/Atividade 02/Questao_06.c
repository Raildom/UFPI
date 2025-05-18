#include <stdio.h>
#define M 3
#define N 4
#define P 2

int main() {
    int i, j, k, A[M][N] = { {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12} }, B[N][P] = { {13, 14}, {15, 16}, {17, 18}, {19, 20} }, C[M][P] = {0};
    for (i = 0; i < M; i++) {
        for (j = 0; j < P; j++) {
            for (k = 0; k < N; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    for (i = 0; i < M; i++) {
        for (j = 0; j < P; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }
    return 0;
}