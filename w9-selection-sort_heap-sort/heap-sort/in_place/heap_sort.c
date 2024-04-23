#include <stdio.h>
//#include <stdlib.h>
#include <stdbool.h>

#include "heap_sort.h"

// Funções auxiliares: CÁLCULO dos índices
int left(int index) {
    return (2 * index) + 1;
}
int right(int index) {
    return (2 * index) + 2;
}
int parent(int index) {
    return (index - 1) / 2;
}
int last(int size) {
    return size - 1;
}

// Funções auxiliares: EXISTÊNCIA dos nós
bool hasLeft(int size, int index) {
    return left(index) < size;
}
bool hasRight(int size, int index) {
    return right(index) < size;
}
bool hasParent(int index) {
    return index > 0; // índice DEVE ser maior que raiz da heap
}

// Funções auxiliares: CHAVE dos nós (existentes)
Element get(Element* data, int size, int index) {
    // Verificar se índice NÃO é válido:
    if (index >= size)
        return ELEMENT_NULL;

    return data[index];
}

void swapAt(Element* data, int i, int j) {
    Element parent = data[j]; // copiar chave nó pai
    data[j] = data[i]; // nó pai recebe chave do filho
    data[i] = parent; // nó filho recebe chave do pai
}

// Remoção:
int maximumAt(Element* data, int size, int pos1, int pos2) {
    return get(data, size, pos1) > get(data, size, pos2) ? pos1 : pos2;
}

void siftDownAt(Element *data, int size, int index_parent) {
    int cur = index_parent; // acessar índice último nó interno vigente

    while (hasLeft(size, cur)) {
        int maxChild = maximumAt(data, size, left(cur), right(cur)); // índice do filho com MAIOR chave

        //printf("%d > %d ?\n", get(data, size, cur), get(data, size, maxChild));
        // Verificar se nó atual é > filho MAIOR chave (PARA de descer):
        if (get(data, size, cur) > get(data, size, maxChild))
            break;

        swapAt(data, cur, maxChild);
        cur = maxChild; // nó atual recebe índice do maior filho (descendo)
    }
}

// Transformar array em heap (in-place):
void heapify(Element *data, int size) {
    for (int i = parent(size-1); i >= 0; i--) // último nó interno: pai último nó folha do último nível
        siftDownAt(data, size, i);
}

void heapSort(Element *data, int size) {
    int heapSize = size; // heap inicia MSM qtd elementos do array
    
    heapify(data, heapSize); // transforma array em heap (in-place)

    printf("-Array_heap: ");
    for (int i=0; i < size; i++)
        printf("%d ", data[i]);
    printf("\n");
    /*
    */

    // Ordenar array:
    for (int i=0; i < size; i++) {
        swapAt(data, 0, heapSize - 1);
        heapSize--;
        siftDownAt(data, heapSize, 0);
    }
}