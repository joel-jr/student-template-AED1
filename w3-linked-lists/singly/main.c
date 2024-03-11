#include <stdio.h>

#include "linked_list.h"

int main() {
    LinkedList* list = list_create();

    list_insertFirst(list, 30);
    list_insertFirst(list, 20);
    list_insertFirst(list, 10);
    list_print(list);

    list_insertLast(list, 40);
    list_print(list);

    list_insertAfter(list, 1, 25);
    list_print(list);

    list_removeFirst(list);
    list_print(list);

    list_remove(list, -1);
    list_remove(list, 0);
    list_remove(list, 2);
    list_print(list);
    list_remove(list, 5);
    list_print(list);

    list_destroy(list);

    return 0;
}