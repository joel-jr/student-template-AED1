#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

typedef struct Node {
    Element value;
    struct Node *next;
} Node;

struct Stack {
    Node *top;
    int size;
};

Stack *stack_create() {
    Stack *stack = malloc(sizeof(Stack)); // alocar memória para struct
    stack->top = NULL; // setar 'top': tirar possível 'lixo' guardado
    stack->size = 0;

    return stack;
}

void stack_destroy(Stack *stack) {
    Node *cur = stack->top; // nó atual acessa/copia topo

    while (cur != NULL) {
        Node *trash = cur; // nó 'lixo' copia nó atual
        cur = trash->next; // nó atual (topo) aponta próx. elemento
        free(trash); // liberar nó 'lixo'
    }
    free(stack); // liberar memória da struct
}

bool stack_push(Stack *stack, Element value) {
    Node *newNode = malloc(sizeof(Node)); // alocar novo nó
    newNode->value = value; // inserir valor ao nó

    newNode->next = stack->top; // nó criado aponta para antigo nó 'top'
    stack->top = newNode; // nó criado se torna nó 'top' da pilha
    stack->size++;

    return true;
}

Element stack_pop(Stack *stack) {
    // Verificar se pilha está vazia:
    if (stack_is_empty(stack))
        return ELEMENT_NULL;

    Node *trash = stack->top; // nó 'trash' copia nó 'top'
    Element value = trash->value; // copiar elemento nó 'trash'
    stack->top = trash->next; // novo 'top' aponta próx. elemento
    free(trash); // liberar nó 'lixo'
    stack->size--;

    return value;
}

Element stack_peek(Stack *stack) {
    // Verificar se pilha está vazia:
    if (stack_is_empty(stack))
        return ELEMENT_NULL;

    return stack->top->value;
}

bool stack_is_empty(Stack *stack) {
    return stack->top == NULL;
}

int stack_size(Stack *stack) {
    return stack->size;
}

void stack_print(Stack* stack) {
    printf("top -> ");
    
    if (stack_is_empty(stack)) {
        printf("(*)\n");
        return;
    }

    Node *cur = stack->top; // nó atual acessa/copia nó 'top'
    while (cur != NULL) {
        element_print(cur->value);
        printf(" ");
        cur = cur->next; // nó atual aponta próx. elemento
    }
    printf("\n");
}