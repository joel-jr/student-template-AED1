#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <stdbool.h>

#include "element.h"

typedef struct PriorityQueue PriorityQueue;

PriorityQueue *pq_create(int capacity);
void pq_destroy(PriorityQueue *pq);
void pq_insert(PriorityQueue *pq, Element data);
Element pq_extract(PriorityQueue *pq);
bool pq_isEmpty(PriorityQueue *pq);
bool pq_isFull(PriorityQueue *pq);
int pq_size(PriorityQueue *pq);
void pq_print(PriorityQueue *pq);

#endif