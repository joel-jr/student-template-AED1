#include <stdio.h>

#include "linked_list.h"

void test_inserts() {
    LinkedList *list = list_create();

    list_insertFirst(list, 40);
    list_insertFirst(list, 20);
    list_insertFirst(list, 10);
    printf("insertFirst: ");
    list_print(list);

    printf("insertAfter: ");
    list_insertAfter(list, 1, 30);
    list_insertAfter(list, 99, 50);
    list_print(list);

    printf("\n");
    list_destroy(list);
}

void test_removeFirst() {
    LinkedList *list = list_create();

    list_print(list);
    bool res = list_removeFirst(list);
    printf("removeFirst: %s\n", (res) ? "true" : "false");

    list_insertFirst(list, 30);
    list_insertFirst(list, 20);
    list_insertFirst(list, 10);
    list_print(list);

    res = list_removeFirst(list);
    printf("removeFirst: %s\n", (res) ? "true" : "false");

    list_print(list);
    res = list_removeFirst(list);
    printf("removeFirst: %s\n", (res) ? "true" : "false");

    list_print(list);
    res = list_removeFirst(list);
    printf("removeFirst: %s\n", (res) ? "true" : "false");

    list_print(list);
    res = list_removeFirst(list);
    printf("removeFirst: %s\n", (res) ? "true" : "false");
    list_print(list);

    printf("\n");
    list_destroy(list);
}

void test_removeAt() {
    LinkedList *list = list_create();

    list_print(list);
    bool res = list_removeAt(list, 2);
    printf("removeAt: %s\n", (res) ? "true" : "false");

    list_insertFirst(list, 30);
    list_insertFirst(list, 20);
    list_insertFirst(list, 10);
    list_print(list);

    res = list_removeAt(list, 3);
    printf("removeAt: %s\n", (res) ? "true" : "false");

    list_print(list);
    res = list_removeAt(list, -1);
    printf("removeAt: %s\n", (res) ? "true" : "false");

    list_print(list);
    res = list_removeAt(list, 1);
    printf("removeAt: %s\n", (res) ? "true" : "false");

    list_print(list);
    res = list_removeAt(list, 0);
    printf("removeAt: %s\n", (res) ? "true" : "false");

    list_print(list);
    res = list_removeAt(list, 0);
    printf("removeAt: %s\n", (res) ? "true" : "false");
    list_print(list);

    printf("\n");
    list_destroy(list);
}

int main() {
    test_inserts();
    test_removeFirst();
    test_removeAt();

    return 0;
}