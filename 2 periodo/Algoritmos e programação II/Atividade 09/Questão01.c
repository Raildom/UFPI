#include <stdio.h>

void bolha(int array[], int N);

int main(){
    int N, aux = 1;

    scanf("%d", &N);
    int array[N];
    for(int i = 0; i < N; i++){
        scanf("%d", &array[i]);
    }
    bolha(array, N);
    for(int i = 0; i < N; i++){
        if(array[i] != i){
            aux = i;
            break;
        }
    }
    printf("%d", aux);
    return 0;
}

void bolha(int array[], int N){
	int i, j;
	int auxiliar;

	for(i = 0; i < N - 1; i++){
		for(j = 1; j < N - i; j++){
			if(array[j] < array[j - 1]){
				auxiliar = array[j];
				array[j] = array[j - 1];
				array[j - 1] = auxiliar;
			}
		}
	}
}