#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"

typedef struct Node {
    Element element;
    struct Node *next;
} Node;

struct LinkedList {
    Node *head;
    int size;
};

LinkedList *list_create() {
    LinkedList *list = malloc(sizeof(LinkedList)); // alocar memória para a estrutura
    list->head = NULL; // setar nó cabeça: tirar possível 'lixo' guardado
    list->size = 0;
    return list;
}

void list_destroy(LinkedList *list) {
    Node *cur = list->head; // nó atual acessa/copia nó cabeça

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
    
    newNode->next = list->head; // nó criado aponta para antigo nó cabeça
    list->head = newNode; // nó criado se torna nó cabeça da lista
    list->size++;
}

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
}

bool list_removeFirst(LinkedList *list) {
    if (list->head == NULL) // verificar se lista está vazia
        return false;
    
    Node *trash = list->head; // nó 'lixo' copia nó cabeça
    list->head = trash->next; // nó cabeça aponta próx. elemento
    free(trash); // liberar nó 'lixo'
    list->size--;

    return true;
}

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
}

Element get(LinkedList *list, int pos) {
    Node *cur = list->head; // nó atual acessa/copia nó cabeça

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
    return list->head == NULL;
}

void list_print(LinkedList *list) {
    if (list->size == 0) {
        printf("*\n");
        return;
    }

    Node *cur = list->head; // nó atual acessa/copia nó cabeça
    
    while (cur != NULL) {
        element_print(cur->element);
        if (cur->next != NULL)
            printf("-> ");
        cur = cur->next; // nó atual aponta próx. elemento
    }
    printf("\n");
}