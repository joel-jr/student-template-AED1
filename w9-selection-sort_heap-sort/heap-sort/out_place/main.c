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

    printf("•Ordenação 1 elemento:\n");
    printArray(arr, size);
    heapSort(arr, size);
    printArray(arr, size);
    printf("\n");
}

void test_twoElements() {
    Element arr[] = {20, 10};
    int size = 2;

    printf("•Ordenação 2 elementos:\n");
    printArray(arr, size);
    heapSort(arr, size);
    printArray(arr, size);
    printf("\n");
}

void test_manyElements() {
    Element arr[] = {50, 20, 30, 10, 40};
    int size = 5;

    printf("•Ordenação vários elementos:\n");
    printArray(arr, size);
    heapSort(arr, size);
    printArray(arr, size);
    printf("\n");
}

int main() {
    test_oneElement();
    test_twoElements();
    test_manyElements();

    return 0;
}