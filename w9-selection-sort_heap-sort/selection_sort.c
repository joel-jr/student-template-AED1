#include "selection_sort.h"

void selectionSort(Element *arr, int n) {
    // Iterar do 1º até penúltimo elemento:
    for (int i=0; i < n-1; i++) {
        int minIndex = i; // i-ésimo elemento inicia como MENOR valor

        // Iterar do 2º até último elemento:
        for (int j = i+1; j < n; j++) {
            // Verificar se j-ésimos são MENORES que mín inicial:
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        // Verificar se houve troca de índice de min:
        if (minIndex != i) {
            Element aux = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = aux;
        }
    }
}

// TODO: algoritmo JÁ não é estável ? ([j] < [min]) e NÃO [j] <= [min]