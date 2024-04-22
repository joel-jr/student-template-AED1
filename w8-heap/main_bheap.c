#include <stdio.h>
//#include <stdbool.h>

#include "binary_heap.h"

void test_descending() {
    BinaryHeap *heap = bheap_create(10);
    int keys[] = {72, 54, 63, 27, 36, 45, 61, 18};

    printf("•Inserções (heap1):\n");
    for (int i=0; i < 8; i++) {
        bheap_insert(heap, keys[i]);
        bheap_print(heap);
    }
    printf("\n");

    printf("•Remoções:\n");
    bheap_print(heap);
    for (int i=0; i < 8; i++) {
        //element_print(bheap_extract(heap));
        //printf(" ");
        bheap_extract(heap);
        bheap_print(heap);
    }
    printf("\n");

    bheap_destroy(heap);
}

void test_ajusts() {
    BinaryHeap *heap = bheap_create(10);
    int keys[] = {18, 27, 36, 45, 54, 61, 63, 72};

    printf("•Inserções (heap2):\n");
    for (int i=0; i < 8; i++) {
        bheap_insert(heap, keys[i]);
        bheap_print(heap);
    }
    printf("\n");

    printf("•Remoções:\n");
    bheap_print(heap);
    for (int i=0; i < 8; i++) {
        //element_print(bheap_extract(heap));
        //printf(" ");
        bheap_extract(heap);
        bheap_print(heap);
    }

    bheap_destroy(heap);
}

int main() {
    test_descending(); // ordem inserção já ajuda
    test_ajusts(); // precisa ficar ajustando posição nós na heap

    return 0;
}