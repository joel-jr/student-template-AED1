#include <stdio.h>

#include "stack.h"

void test_push() {
    Stack *stack = stack_create(3);

    stack_push(stack, 30);
    stack_push(stack, 20);
    stack_push(stack, 10);
    stack_print(stack);
    printf("\n");

    printf("•Stack size: %d\n", stack_size(stack));
    printf("•Stack empty? '%s'\n", stack_is_empty(stack) ? "true" : "false");
    printf("•Stack full? '%s'\n\n", stack_is_full(stack) ? "true" : "false");

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

    printf("\n•Stack size (new): %d\n", stack_size(stack));

    stack_destroy(stack);
}

int main() {
    test_push();

    return 0;
}