#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

struct Stack {
    Element *elements;
    int top; // índice topo da pilha
    int capacity; // tamanho MÁX. da pilha
};

Stack *stack_create(int capacity) {
    Stack *stack = malloc(sizeof(Stack)); // alocar memória para struct
    stack->elements = malloc(sizeof(Element) * capacity); // alocar memória para vetor

    stack->top = -1; // convensão pilha vazia índice do topo será 1
    stack->capacity = capacity;

    return stack;
}

void stack_destroy(Stack *stack) {
    free(stack->elements); // liberar memória do vetor
    free(stack); // liberar memória da struct
}

bool stack_push(Stack *stack, Element value) {
    // Verificar se pilha está cheia:
    if (stack_is_full(stack))
        return false;

    // Inserir no topo da pilha:
    stack->elements[++stack->top] = value; // pré-incrementa índice e add elemento
    return true;
}

Element stack_pop(Stack *stack) {
    // Verificar se pilha está vazia:
    if (stack_is_empty(stack))
        return ELEMENT_NULL;

    return stack->elements[stack->top--]; // retorna elemento e pós-decrementa índice
}

Element stack_peek(Stack *stack) {
    // Verificar se pilha está vazia:
    if (stack_is_empty(stack))
        return ELEMENT_NULL;

    return stack->elements[stack->top]; // retorna elemento
}

bool stack_is_empty(Stack *stack) {
    return stack->top == -1;
}

bool stack_is_full(Stack *stack) {
    return stack->top == stack->capacity - 1;
}

int stack_size(Stack *stack) {
    return stack->top + 1;
}

void stack_print(Stack* stack) {
    if (stack_is_empty(stack)) {
        printf("(*)\n");
        return;
    }

    printf("top -> ");
    for (int i = stack->top; i >= 0; i--) {
        element_print(stack->elements[i]);
        printf(" ");
    }
    printf("\n");
}