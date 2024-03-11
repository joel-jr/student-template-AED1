#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"

typedef struct Node {
    Element element;
    struct Node *next;
} Node;

struct LinkedList {
    Node *head;
};

LinkedList *list_create() {
    LinkedList *list = malloc(sizeof(LinkedList)); // alocar memória para a estrutura
    list->head = NULL; // tirar "lixo" para nó cabeça não apontar para ninguém
    return list;
}

void list_destroy(LinkedList *list) {
    Node *cur = list->head; // nó atual acessa/copia nó cabeça
    
    while (cur != NULL) {
        Node *trash = cur; // nó 'lixo' copia nó atual
        cur = cur->next; // nó atual aponta próx. elemento
        free(trash); // liberar nó 'lixo'
    }
    free(list); // liberar memória da estrutura
}

void list_insertFirst(LinkedList *list, Element element) {
    Node *newNode = malloc(sizeof(Node)); // alocar novo nó
    newNode->element = element; // inserir elemento ao nó criado
    
    newNode->next = list->head; // nó criado aponta para antigo nó cabeça
    list->head = newNode; // nó criado se torna nó cabeça da lista
}

void list_insertLast(LinkedList *list, Element element) {
    Node *cur = list->head; // nó atual acessa/copia nó cabeça
    if (cur == NULL)
        list_insertFirst(list, element); // lista vazia: insere cabeça na lista
    else {
        while (cur->next != NULL)
            cur = cur->next; // nó atual aponta próx. elemento

        Node *newNode = malloc(sizeof(Node)); // alocar novo nó
        newNode->element = element; // inserir elemento ao nó criado
        
        newNode->next = NULL; // nó criado aponta para NULL
        cur->next = newNode; // nó atual aponta para nó criado
    }
}

void list_insertAfter(LinkedList *list, int position, Element element) {
    if (list->head == NULL || position < 0)
        list_insertFirst(list, element); // lista vazia ou posição < 0: insere cabeça na lista
    else {
        Node *cur = list->head; // nó atual acessa/copia nó cabeça

        int i=0;
        while (cur->next != NULL && i < position) {
            cur = cur->next; // nó atual aponta próx. elemento
            i++; // atualizar contador
        }

        Node *newNode = malloc(sizeof(Node)); // alocar novo nó
        newNode->element = element; // inserir elemento ao nó criado

        newNode->next = cur->next; // nó criado aponta para próx. nó atual
        cur->next = newNode; // nó atual aponta para nó criado
    }
}

bool list_removeFirst(LinkedList *list) {
    if (list->head == NULL) // verificar se lista está vazia
        return false;
    
    Node *trash = list->head; // nó 'lixo' copia nó cabeça
    list->head = trash->next; // nó cabeça aponta próx. elemento
    free(trash); // liberar nó 'lixo'

    return true;
}

bool list_remove(LinkedList *list, int position) {
    if (list->head == NULL) // lista vazía
        return false;
    if (position < 0) // posição inválida
        return false;
    if (position == 0) // inserir início
        return list_removeFirst(list);
    
    else {
        Node *prev = list->head; // nó anterior acessa nó cabeça

        int i=0;
        while (prev->next != NULL && i < position - 1) {
            prev = prev->next; // nó anterior aponta próx. elemento
            i++; // atualizar contador
        }
        if (prev->next == NULL)
            return false;

        Node *trash = prev->next; // nó 'lixo' copia próx. nó anterior (elemento atual)
        prev->next = trash->next; // nó anterior aponta elemento seguinte ao atual
        free(trash);
        return true;
    }
}

Element list_search(LinkedList *list, int position) {
    Node *cur = list->head; // nó atual acessa/copia nó cabeça

    int i=0;
    while (cur != NULL && i < position) {
        cur = cur->next; // nó atual aponta próx. elemento
        i++; // atualizar contador
    }

    if (cur != NULL)
        return cur->element; // elemento achado!
    else
        return ELEMENT_NULL; // elemento NÃO achado, retornar nº 'queimado'
}

void list_print(LinkedList *list) {
    Node *cur = list->head; // nó atual acessa/copia nó cabeça
    
    while (cur != NULL) {
        element_print(cur->element);
        if (cur->next != NULL)
            printf(" -> ");
        cur = cur->next; // nó atual aponta próx. elemento
    }
    printf("\n");
}