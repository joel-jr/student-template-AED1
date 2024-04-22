#include <stdlib.h>

#include "priority_queue.h"
#include "binary_heap.h"

struct PriorityQueue {
    BinaryHeap *bheap;
};

PriorityQueue *pq_create(int capacity) {
    PriorityQueue *pq = malloc(sizeof(PriorityQueue));
    pq->bheap = bheap_create(capacity);

    return pq;
}

void pq_destroy(PriorityQueue *pq) {
    bheap_destroy(pq->bheap);
    free(pq);
}

void pq_insert(PriorityQueue *pq, Element key) {
    bheap_insert(pq->bheap, key);
}

Element pq_extract(PriorityQueue *pq) {
    return bheap_extract(pq->bheap);
}

bool pq_isEmpty(PriorityQueue *pq) {
    return bheap_isEmpty(pq->bheap);
}

int pq_size(PriorityQueue *pq) {
    return bheap_size(pq->bheap);
}

bool pq_isFull(PriorityQueue *pq) {
    return bheap_isFull(pq->bheap);
}

void pq_print(PriorityQueue *pq) {
    return bheap_print(pq->bheap);
}