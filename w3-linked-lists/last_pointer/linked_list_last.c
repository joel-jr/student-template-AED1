#include <stdio.h>
#include <stdlib.h>

#include "linked_list_last.h"

typedef struct Node {
    Element element;
    struct Node *next;
} Node;

struct LinkedList {
    Node *first;
    Node *last;
    int size;
};

LinkedList *list_create() {
    LinkedList *list = malloc(sizeof(LinkedList)); // alocar memória para a estrutura
    list->first = list->last = NULL; // setar nó 'first' e 'last': tirar possível 'lixo' guardado
    list->size = 0;
    return list;
}

void list_destroy(LinkedList *list) {
    Node *cur = list->first; // nó atual acessa/copia nó cabeça

    while (cur != NULL) {
        Node *trash = cur; // nó 'lixo' copia nó atual
        cur = cur->next; // nó atual (cabeça) aponta próx. elemento
        free(trash); // liberar nó 'lixo'
    }
    free(list); // liberar memória da estrutura
}

void list_insertFirst(LinkedList *list, Element element) {
    Node *newNode = malloc(sizeof(Node)); // alocar novo nó
    newNode->element = element; // inserir elemento ao nó criado
    newNode->next = list->first; // nó criado aponta para antigo nó 'first'
    
    list->first = newNode; // nó criado se torna nó 'first' da lista
    if (list->last == NULL)
        list->last = newNode; // nó criado se torna nó 'last' da lista

    list->size++;
}

void list_insertLast(LinkedList *list, Element element) {
    Node *newNode = malloc(sizeof(Node)); // alocar novo nó
    newNode->element = element; // inserir elemento ao nó criado
    newNode->next = NULL; // nó criado aponta para NULL

    // Verificar se lista está vazia:
    if (list->first == NULL)
        list->first = list->last = newNode; // 'first' e 'last' apontam para nó criado
    else {
        list->last->next = newNode; // antigo nó 'last' aponta nó criado
        list->last = newNode; // nó criado se tornar novo 'last'
    }
    list->size++;
}

// TODO: adaptar funções respeitar novo controle de ponteiros!!!
/*
void list_insertAfter(LinkedList *list, int pos, Element element) {
    if (list->head == NULL || pos < 0)
        list_insertFirst(list, element); // lista vazia ou posição < 0: insere cabeça na lista
    else {
        Node *cur = list->head; // nó atual acessa/copia nó cabeça

        int i=0;
        while (cur->next != NULL && i < pos) {
            cur = cur->next; // nó atual aponta próx. elemento
            i++; // atualizar contador
        }

        Node *newNode = malloc(sizeof(Node)); // alocar novo nó
        newNode->element = element; // inserir elemento ao nó criado

        newNode->next = cur->next; // nó criado aponta para próx. nó atual
        cur->next = newNode; // nó atual aponta para nó criado
        list->size++;
    }
}*/
/*
bool list_removeFirst(LinkedList *list) {
    if (list->head == NULL) // verificar se lista está vazia
        return false;
    
    Node *trash = list->head; // nó 'lixo' copia nó cabeça
    list->head = trash->next; // nó cabeça aponta próx. elemento
    free(trash); // liberar nó 'lixo'
    list->size--;

    return true;
}*/
/*
bool list_removeAt(LinkedList *list, int pos) {
    if (list->head == NULL || pos >= list->size) // lista vazia ou índice maior que o tamanho
        return false;
    if (pos <= 0) // remover no início
        return list_removeFirst(list);
    
    else {
        Node *prev = list->head; // nó anterior acessa nó cabeça

        int i=0;
        while (i < pos - 1) {
            prev = prev->next; // nó anterior aponta próx. elemento
            i++; // atualizar contador
        }

        Node *trash = prev->next; // nó 'lixo' copia nó seguinte do anterior (elemento atual)
        prev->next = trash->next; // nó anterior aponta elemento seguinte ao atual
        free(trash);
        list->size--;
    }
    return true;
}*/

Element get(LinkedList *list, int pos) {
    Node *cur = list->first; // nó atual acessa/copia nó 'first'

    int i=0;
    while (cur != NULL && i < pos) {
        cur = cur->next; // nó atual aponta próx. elemento
        i++; // atualizar contador
    }

    if (cur != NULL)
        return cur->element; // elemento achado!

    return ELEMENT_NULL; // elemento NÃO achado, retornar nº 'queimado'
}

int list_size(LinkedList *list) {
    return list->size;
}

bool list_isEmpty(LinkedList *list) {
    return list->first == NULL;
}

void list_print(LinkedList *list) {
    if (list->size == 0) {
        printf("*\n");
        return;
    }

    Node *cur = list->first; // nó atual acessa/copia nó 'first'
    
    while (cur != NULL) {
        element_print(cur->element);
        if (cur->next != NULL)
            printf("-> ");
        cur = cur->next; // nó atual aponta próx. elemento
    }
    printf("\n");
}