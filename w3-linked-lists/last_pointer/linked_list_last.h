#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdbool.h>

#include "element.h"

typedef struct LinkedList LinkedList;

LinkedList *list_create(); // criar lista ligada
void list_destroy(LinkedList *list); // desalocar memória da lista ligada

void list_insertFirst(LinkedList *list, Element element); // inserir no início da lista
void list_insertLast(LinkedList *list, Element element); // inserir no fim da lista
void list_insertAfter(LinkedList *list, int pos, Element element); // inserir numa posição específica

bool list_removeFirst(LinkedList *list); // remover 1º elemento
bool list_removeAt(LinkedList *list, int pos); // remover numa posição específica

Element get(LinkedList *list, int pos); // retornar valor duma posição específica (achar ou não)
int list_size(LinkedList *list); // retornar qtde de nós da lista
bool list_isEmpty(LinkedList *list); // verificar se lista está vazia
void list_print(LinkedList *list); // imprimir toda a lista

#endif