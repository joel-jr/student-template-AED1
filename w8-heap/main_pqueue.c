#include <stdio.h>
//#include <stdbool.h>

#include "priority_queue.h"

void test_priority() {
    PriorityQueue *pq = pq_create(5);
    int priorities[] = {10, 20, 30, 40, 50}; // prioridade implícita: a partir dos próprios dados (ordem nº, string)

    printf("•Inserções (priority_queue):\n");
    for (int i=0; i < 5; i++) {
        pq_insert(pq, priorities[i]);
        pq_print(pq);
    }
    printf("\n");

    printf("•Remoções:\n");
    pq_print(pq);
    for (int i=0; i < 5; i++) {
        //element_print(pq_extract(pq));
        //printf(" ");
        pq_extract(pq);
        pq_print(pq);
    }
    printf("\n");

    pq_destroy(pq);
}

int main() {
    test_priority();

    return 0;
}