#include <stdio.h>
#include <string.h>

int main() {
    char numero_quebrado, numero[10100];
    int quantidade_digitos;

    scanf("%c %s", &numero_quebrado, numero);
    while (numero_quebrado != '0'){
        quantidade_digitos = strlen(numero);
        for (int i = 0; i < quantidade_digitos; i++){
            if (numero[i] == numero_quebrado) {
               for (int j = i; j < quantidade_digitos; j++){
                    numero[j] = numero[j + 1];
                }
                quantidade_digitos--;
                i--;
            }
        }
        for (int i = 0; i < quantidade_digitos - 1; i++){
            if (numero[i] == '0') {
                for (int j = i; j < quantidade_digitos; j++){
                    numero[j] = numero[j + 1];
                }
                quantidade_digitos--;
                i--;
            }
        }
        if (quantidade_digitos == 0){
            numero[0] = '0';
            numero[1] = '\0';
        }
        printf("%s\n", numero);
        scanf(" %c", &numero_quebrado);
        scanf("%s", numero);
    }
    return 0;
}