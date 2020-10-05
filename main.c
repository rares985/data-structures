
#include "stdio.h"
#include "stdlib.h"

/* 3rd party includes */
#include "single_linked_list.h"
#include "double_linked_list.h"
#include "stack.h"

#include "log.h"
#include "types.h"


int main( void )
{
  stack_t *st = NULL;
  int value = 30;

  stack_create(&st);

  stack_push(st, &value, sizeof(value));
  value = 20;
  stack_push(st, &value, sizeof(value));
  value = 10;
  stack_push(st, &value, sizeof(value));

  LOG_INF("Peeked value: %d", *(int*)stack_peek(st));

  int popped_value = 500;

  stack_pop(st, &popped_value, sizeof(int));
  LOG_INF("Popped value: %d", popped_value);

  sll_print(st);

  stack_destroy(&st);

  return 0;
}