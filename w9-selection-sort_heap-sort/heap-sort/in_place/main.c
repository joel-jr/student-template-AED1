#include <stdio.h>

#include "heap_sort.h"

void printArray(Element *arr, int n) {
    for (int i=0; i < n; i++) {   
        element_print(arr[i]);
        printf(" ");
    }
    printf("\n");
}

void test_oneElement() {
    Element arr[] = {10};
    int size = 1;
    printf("•Array_original: ");
    printArray(arr, size);
    
    heapSort(arr, size);

    printf("•Array_ordenado: ");
    printArray(arr, size);
    printf("\n");
}

void test_twoElements() {
    Element arr[] = {50, 20};
    int size = 2;
    printf("•Array_original: ");
    printArray(arr, size);

    heapSort(arr, size);

    printf("•Array_ordenado: ");
    printArray(arr, size);
    printf("\n\n");
}

void test_manyElements1() { // exp do PDF
    Element arr[] = {52, 87, 19, 38, 21, 60, 9};
    int size = 7;
    printf("•Array original: ");
    printArray(arr, size);
    
    heapSort(arr, size);

    printf("•Array ordenado: ");
    printArray(arr, size);
    printf("\n");
}

void test_manyElements2() { // elementos maiores estão nas FOLHAS da heap
    Element arr[] = {10, 4, 1, 35, 7, 8, 40, 0, 38, 21, 87, 60, 52, 19, 9};
    int size = 15;
    printf("•Array original: ");
    printArray(arr, size);

    heapSort(arr, size);

    printf("•Array ordenado: ");
    printArray(arr, size);
    printf("\n");
}

void test_manyElements3() { // elementos maiores estão nas FOLHAS da heap
    Element arr[] = {28, 17, 99, 64, 3, 85, 12, 51, 70, 46, 2, 92, 10, 5, 31, 88, 61, 40, 96, 23};;
    int size = 20;
    printf("•Array original: ");
    printArray(arr, size);

    heapSort(arr, size);

    printf("•Array ordenado: ");
    printArray(arr, size);
    printf("\n");
}

int main() {
    test_oneElement();
    test_twoElements();
    test_manyElements1();
    test_manyElements2();
    test_manyElements3();

    return 0;
}