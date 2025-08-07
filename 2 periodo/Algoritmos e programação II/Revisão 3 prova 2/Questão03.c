#include <stdio.h>

typedef struct{
    int x; 
    int y;
}botao;

int main(){
    int C, i, soma;
    botao numero;

    scanf("%d", &C);
    for(i = 0; i < C; i++){
        scanf("%d%d", &numero.x, &numero.y);
        soma = numero.x + numero.y;
        switch(soma){
            case 0:
                printf("PROXYCITY\n");
                break;
            case 1:
                printf("P.Y.N.G.\n");
                break;
            case 2:
                printf("DNSUEY!\n");
                break;
            case 3:
                printf("SERVERS\n");
                break;
            case 4:
                printf("HOST!\n");
                break;
            case 5:
                printf("CRIPTONIZE\n");
                break;
            case 6:
                printf("OFFLINE DAY\n");
                break;
            case 7:
                printf("SALT\n");
                break;
            case 8:
                printf("ANSWER!\n");
                break;
            case 9:
                printf("RAR?\n");
                break;
            case 10:
                printf("WIFI ANTENNAS\n");
                break;
            default:
                printf("opcao invalida\n");
                i--;
                break;
        }
    }
    return 0;
}