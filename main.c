
#include "stdio.h"
#include "stdlib.h"

/* 3rd party includes */
#include "single_linked_list.h"
#include "double_linked_list.h"
#include "stack.h"
#include "queue.h"
#include "hashtable.h"

#include "log.h"
#include "types.h"


int main( void )
{
  hashtable_t *ht = NULL;

  // uint32_t value1 = 10;

  ht_create(&ht, 10);

  ht_print(ht);

  ht_destroy(&ht);

  return 0;
}