
#include "stdio.h"
#include "stdlib.h"

/* 3rd party includes */
#include "single_linked_list.h"
#include "double_linked_list.h"
#include "stack.h"
#include "queue.h"

#include "log.h"
#include "types.h"


int main( void )
{
  queue_t *q = NULL;
  int value = 10;

  queue_create(&q, 20);

  queue_enqueue(q, &value, sizeof(value));
  value = 20;
  queue_enqueue(q, &value, sizeof(value));
  value = 30;
  queue_enqueue(q, &value, sizeof(value));

  int dequeued_value = 200;
  queue_dequeue(q, &dequeued_value, sizeof(dequeued_value));

  LOG_INF("Peeked value: %d", *(int*)queue_peek(q));

  queue_print(q);
  LOG_INF("deqd value: %d", dequeued_value);
  

  queue_destroy(&q);

  return 0;
}