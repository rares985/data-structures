#ifndef STACK_H_
#define STACK_H_

#include "single_linked_list.h"

typedef single_linked_list_t stack_t;

int stack_create(stack_t **stack);
int stack_push(stack_t *stack, void *data, size_t data_size);
int stack_pop(stack_t *stack, void *data, size_t data_size);
void *stack_peek(stack_t *stack);
int stack_size(stack_t *stack);
int stack_destroy(stack_t **stack);

#endif /* STACK_H_ */