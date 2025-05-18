#include <stdio.h>

double  leInteiros(double auxiliar, int count);
int main(){
    int idade, count = 0;
    double  auxiliar = 0, media;

    while(1){
        scanf("%d", &idade);
        if(idade > 0){
            auxiliar += idade;
            count++;
        }else{
            break;
        }
    }
    media = leInteiros(auxiliar, count);
    printf("%.2lf\n", media);
    return 0;
}

double  leInteiros(double auxiliar, int count){
    return auxiliar / count;
}