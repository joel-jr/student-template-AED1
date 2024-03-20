#include <stdio.h>

#include "stack.h"

void test_push() {
    Stack *stack = stack_create();
    printf("•stack_empty? '%s'\n", stack_is_empty(stack) ? "true" : "false");
    stack_print(stack);
    printf("\n");

    stack_push(stack, 30);
    stack_push(stack, 20);
    stack_push(stack, 10);
    stack_print(stack);

    printf("•stack_size: %d\n", stack_size(stack));
    printf("•stack_empty? '%s'\n", stack_is_empty(stack) ? "true" : "false");

    stack_destroy(stack);
}

void test_pop() {
    Stack *stack = stack_create();
    printf("•stack_empty? '%s'\n", stack_is_empty(stack) ? "true" : "false");
    stack_print(stack);
    printf("\n");

    stack_push(stack, 30);
    stack_push(stack, 20);
    stack_push(stack, 10);
    stack_print(stack);

    printf("•Stack size: %d\n", stack_size(stack));
    printf("•stack_empty? '%s'\n", stack_is_empty(stack) ? "true" : "false");
    printf("\n");

    printf("Stack peek: ");
    element_print(stack_peek(stack));
    printf("\n");
    printf("Stack pop: ");
    element_print(stack_pop(stack));
    printf("\n");
    stack_print(stack);
    printf("Stack pop: ");
    element_print(stack_pop(stack));
    printf("\n");
    stack_print(stack);
    printf("Stack pop: ");
    element_print(stack_pop(stack));
    printf("\n");
    stack_print(stack);

    printf("\n•stack_size (new): %d\n", stack_size(stack));

    stack_destroy(stack);
}

int main() {
    //test_push();
    test_pop();

    return 0;
}