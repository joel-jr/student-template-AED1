#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

#include "element.h"

typedef struct Stack Stack;

Stack *stack_create(int capacity); // criar pilha com capacidade FIXA
void stack_destroy(Stack *stack); // desalocar memória da pilha

bool stack_push(Stack *stack, Element value); // inserir no topo da pilha
Element stack_pop(Stack *stack); // remover e retornar elemento do topo
Element stack_peek(Stack *stack); // retornar elemento do topo
bool stack_is_empty(Stack *stack); // verificar se pilha está vazia
int stack_size(Stack *stack); // retornar qtde de elementos na pilha
void stack_print(Stack *stack); // imprimir toda a pilha

#endif