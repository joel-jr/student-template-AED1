#include "heap_sort.h"
#include "binary_heap.h" 

void heapSort(Element *array, int n) {
    // Criar heap + inserir elementos array nele:
    BinaryHeap *bheap = bheap_create(n);
    for (int i=0; i < n; i++)
        bheap_insert(bheap, array[i]);

    // Extrair elementos da heap + preencher array:
    for (int i = n-1; i >= 0; i--) // Máx-Heap: começar do fim para deixar ordem crescente
        array[i] = bheap_extract(bheap);

    // Liberar memória heap:
    bheap_destroy(bheap);
}