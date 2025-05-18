#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Função para gerar números aleatórios
void geraNumeros(int arr[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        arr[i] = rand() % 10000; // Você pode ajustar o intervalo conforme necessário
    }
}

// Função para imprimir o array
void imprimeArray(int arr[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Função para trocar dois elementos no array
void troca(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Implementação do Bubble Sort
void bubbleSort(int arr[], int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = 0; j < tamanho - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                troca(&arr[j], &arr[j + 1]);
            }
        }
    }
}

// Implementação do Insertion Sort
void insertionSort(int arr[], int tamanho) {
    int chave, j;
    for (int i = 1; i < tamanho; i++) {
        chave = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > chave) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = chave;
    }
}

// Implementação do Selection Sort
void selectionSort(int arr[], int tamanho) {
    int i, j, min_index;
    for (i = 0; i < tamanho - 1; i++) {
        min_index = i;
        for (j = i + 1; j < tamanho; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        troca(&arr[min_index], &arr[i]);
    }
}

// Função auxiliar para o Merge Sort
void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Implementação do Merge Sort
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

// Implementação do Quick Sort
int particiona(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            troca(&arr[i], &arr[j]);
        }
    }
    troca(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = particiona(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    const int tamanho = 10000; // Tamanho do array

    int *arr = (int *)malloc(tamanho * sizeof(int));

    double mediaBubble = 0, mediaInsertion = 0, mediaSelection = 0, mediaMerge = 0, mediaQuick = 0;

    // Realiza 30 vezes cada algoritmo e mede o tempo
    for (int i = 1; i <= 30; i++) {
        clock_t inicio, fim;
        double tempo;

        // Gera números aleatórios
        geraNumeros(arr, tamanho);

        // Bubble Sort
        int *arr_bubble = (int *)malloc(tamanho * sizeof(int));
        memcpy(arr_bubble, arr, tamanho * sizeof(int));
        inicio = clock();
        bubbleSort(arr_bubble, tamanho);
        fim = clock();
        tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
        printf("Execução %d - Tempo do Bubble Sort: %f segundos\n", i, tempo);
        mediaBubble += tempo;

        // Insertion Sort
        int *arr_insertion = (int *)malloc(tamanho * sizeof(int));
        memcpy(arr_insertion, arr, tamanho * sizeof(int));
        inicio = clock();
        insertionSort(arr_insertion, tamanho);
        fim = clock();
        tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
        printf("Execução %d - Tempo do Insertion Sort: %f segundos\n", i, tempo);
        mediaInsertion += tempo;

        // Selection Sort
        int *arr_selection = (int *)malloc(tamanho * sizeof(int));
        memcpy(arr_selection, arr, tamanho * sizeof(int));
        inicio = clock();
        selectionSort(arr_selection, tamanho);
        fim = clock();
        tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
        printf("Execução %d - Tempo do Selection Sort: %f segundos\n", i, tempo);
        mediaSelection += tempo;

        // Merge Sort
        int *arr_merge = (int *)malloc(tamanho * sizeof(int));
        memcpy(arr_merge, arr, tamanho * sizeof(int));
        inicio = clock();
        mergeSort(arr_merge, 0, tamanho - 1);
        fim = clock();
        tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
        printf("Execução %d - Tempo do Merge Sort: %f segundos\n", i, tempo);
        mediaMerge += tempo;

        // Quick Sort
        int *arr_quick = (int *)malloc(tamanho * sizeof(int));
        memcpy(arr_quick, arr, tamanho * sizeof(int));
        inicio = clock();
        quickSort(arr_quick, 0, tamanho - 1);
        fim = clock();
        tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
        printf("Execução %d - Tempo do Quick Sort: %f segundos\n\n", i, tempo);
        mediaQuick += tempo;

        // Certifique-se de liberar a memória alocada para cada array
        free(arr_bubble);
        free(arr_insertion);
        free(arr_selection);
        free(arr_merge);
        free(arr_quick);
    }

    // Calcula a média para cada algoritmo
    mediaBubble /= 30;
    mediaInsertion /= 30;
    mediaSelection /= 30;
    mediaMerge /= 30;
    mediaQuick /= 30;

    // Exibe as médias
    printf("Média do Bubble Sort: %f segundos\n", mediaBubble);
    printf("Média do Insertion Sort: %f segundos\n", mediaInsertion);
    printf("Média do Selection Sort: %f segundos\n", mediaSelection);
    printf("Média do Merge Sort: %f segundos\n", mediaMerge);
    printf("Média do Quick Sort: %f segundos\n", mediaQuick);

    // Libera o array original
    free(arr);

    return 0;
}