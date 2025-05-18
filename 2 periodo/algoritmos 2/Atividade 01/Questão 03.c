#include <stdio.h>

int main(){
    char Destino, IdaVolta;

    scanf("%c %c", &Destino, &IdaVolta);
    if(Destino == 'a' && IdaVolta == '0'){
        printf("500.00");
    } else if(Destino == 'a' && IdaVolta == '1'){
        printf("900.00");
    } else if(Destino == 'b' && IdaVolta == '0'){
        printf("350.00");
    } else if(Destino == 'b' && IdaVolta == '1'){
        printf("650.00");
    } else if(Destino == 'c' && IdaVolta == '0'){
        printf("350.00");
    } else if(Destino == 'c' && IdaVolta == '1'){
        printf("600.00");
    } else if(Destino == 'd' && IdaVolta == '0'){
        printf("300.00");
    } else if(Destino == 'd' && IdaVolta == '1'){
        printf("550.00");
    }
    return 0;
}