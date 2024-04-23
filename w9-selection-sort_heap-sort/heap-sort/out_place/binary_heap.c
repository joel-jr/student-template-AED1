#include <stdio.h>
#include <stdlib.h>
//#include <stdbool.h> 

#include "binary_heap.h"

struct BinaryHeap {
	Element *data;
	int size; // qtd ATUAL nós ocupados na heap
	int capacity; // qtd TOTAL nós na heap
};

BinaryHeap *bheap_create(int capacity) {
	BinaryHeap *bheap = malloc(sizeof(BinaryHeap)); // alocar memória struct
	bheap->data = malloc(sizeof(Element) * capacity); // alocar memória para array
	bheap->size = 0;
	bheap->capacity = capacity;
	
	return bheap;
}

void bheap_destroy(BinaryHeap *bheap) {
	free(bheap->data); // desalocar memória do array
	free(bheap); // desalocar memória da struct
}

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

// Funções auxiliares: EXISTÊNCIA dos nós
bool hasLeft(BinaryHeap *bheap, int index) {
	return left(index) < bheap->size;
}
bool hasRight(BinaryHeap *bheap, int index) {
	return right(index)	< bheap->size;
}
bool hasParent(BinaryHeap *bheap, int index) {
	return index > 0; // índice DEVE ser maior raiz da bheap
}

// Funções auxiliares: CHAVE dos nós (existentes)
Element getLeft(BinaryHeap *bheap, int index) {
	// Verificar se NÃO há filho ESQUERDA:
	if (!hasLeft(bheap, index))
		return ELEMENT_NULL;
	
	return bheap->data[left(index)];
}
Element getRight(BinaryHeap *bheap, int index) {
	// Verificar se NÃO há filho DIREITA:
	if (!hasRight(bheap, index))
		return ELEMENT_NULL;
	
	return bheap->data[right(index)];
}
Element getParent(BinaryHeap *bheap, int index) {
	// Verificar se nó É raiz da heap:
	if (!hasParent(bheap, index))
		return ELEMENT_NULL;
	
	return bheap->data[parent(index)];
}
Element get(BinaryHeap *bheap, int index) {
	// Verificar se índice NÃO é válido:
	if (index >= bheap->size)
		return ELEMENT_NULL;
	
	return bheap->data[index];
}

void swapAt(BinaryHeap *bheap, int i, int j) {
    Element parent = bheap->data[j]; // copiar chave nó pai
    bheap->data[j] = bheap->data[i]; // nó pai recebe chave do filho
    bheap->data[i] = parent; // nó filho recebe chave do pai
}

// Inserção:
void siftUp(BinaryHeap *bheap) {
    int cur = bheap->size-1; // acessar índice do último nó add

    while (hasParent(bheap, cur) && get(bheap, cur) > getParent(bheap, cur)) {
        swapAt(bheap, cur, parent(cur));
        cur = parent(cur); // nó atual recebe índece do pai (subindo)
    }    
}

void bheap_insert(BinaryHeap *bheap, Element key) {
    // Verificar se array está cheio:
    if (bheap_isFull(bheap))
        return;

    bheap->data[bheap->size++] = key; // inserir no último nível (esq -> dir)
    siftUp(bheap); // subir nó até nível correto
}

// Remoção:
int maximumAt(BinaryHeap *bheap, int pos1, int pos2) {
    return get(bheap, pos1) > get(bheap, pos2) ? pos1 : pos2;
}

void siftDown(BinaryHeap *bheap) {
    int cur = 0; // acessar índice da raiz
        
    while (hasLeft(bheap, cur)) {
        int maxChild = maximumAt(bheap, left(cur), right(cur)); // índice do filho com MAIOR chave
        
        // Verificar se nó atual é > filho MAIOR chave:
        if (get(bheap, cur) > get(bheap, maxChild))
            break;
                
        swapAt(bheap, cur, maxChild);
        cur = maxChild; // nó atual recebe índice do maior filho (descendo)
    }
}

Element bheap_extract(BinaryHeap *bheap) {
	// Verificar se array está VAZIO:
    if (bheap_isEmpty(bheap))
        return ELEMENT_NULL;

    Element root = bheap->data[0]; // copiar chave da raiz
    bheap->data[0] = bheap->data[bheap->size-1]; // substituir raiz pelo último elemento
    bheap->size--; // "eliminar" último elemento
    siftDown(bheap); // descer nó até nível correto
    
    return root;
}

Element bheap_peek(BinaryHeap *bheap) {
    // Verificar se array está VAZIO:
    if (bheap_isEmpty(bheap))
            return ELEMENT_NULL;

    return bheap->data[0];
}

// TODO: bheap_increment(Binary *bheap, Element key, int index)
// TODO: bheap_decrement(Binary *bheap, Element key, int index)
// TODO: implementar uma MÍN HEAP!!

int bheap_size(BinaryHeap *bheap) {
	return bheap->size;
}

bool bheap_isEmpty(BinaryHeap *bheap) {
	return bheap->size == 0;
}

bool bheap_isFull(BinaryHeap *bheap) {
	return bheap->size >= bheap->capacity;
}

void bheap_print(BinaryHeap *bheap) {
    for (int i=0; i < bheap->size; i++) {
        element_print(bheap->data[i]);
        printf(" ");
    }
    printf("\n");
}