#include <stdio.h>

void hanoi(int n, char A, char B, char C){
    if(n > 0){
        hanoi(n - 1, A, C, B);
        printf("Moveu de %c para %c\n", A, C);
        hanoi(n - 1, B, A, C);
    }
}

int main(){
    hanoi(4, 'A', 'B', 'C');
    return 0;
}