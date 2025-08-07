#include <stdio.h>
int main() {
    int n1, n2, min, mdc = 1;

    scanf("%d %d", &n1, &n2);
    if (n1 < n2) {
        min = n1;
    } else {
        min = n2;
    }
    for (int i = 1; i <= min; i++) {
        if (n1 % i == 0 && n2 % i == 0) {
            mdc = i;
        }
    }
    printf("%d\n", mdc);
    return 0;
}