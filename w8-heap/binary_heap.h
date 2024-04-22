#ifndef BINARY_HEAP_H
#define BINARY_HEAP_H

#include <stdbool.h>

#include "element.h"

typedef struct BinaryHeap BinaryHeap;

BinaryHeap *bheap_create(int capacity);
void bheap_destroy(BinaryHeap *bheap);

void bheap_insert(BinaryHeap *bheap, Element key); // inserir nó na heap binária (último nível: esq -> dir)
Element bheap_extract(BinaryHeap *bheap); // remover nó na heap binária ()
Element bheap_peek(BinaryHeap *bheap); // consultar chave do nó raiz (MÁX / MÍN)

// bheap_increment(Binary *bheap, Element key, int index)
// bheap_decrement(Binary *bheap, Element key, int index)

int bheap_size(BinaryHeap *bheap);
bool bheap_isEmpty(BinaryHeap *bheap);
bool bheap_isFull(BinaryHeap *bheap);
void bheap_print(BinaryHeap *bheap);

#endif