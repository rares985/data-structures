
#include "stdio.h"
#include "stdlib.h"

/* 3rd party includes */
#include "single_linked_list.h"
#include "double_linked_list.h"


int main( void )
{
  double_linked_list_t *list = NULL;
  
  dll_create(&list);

  int value2 = 20;
  int value1 = 10;

  dll_add_end(list, &value1, sizeof(value2));

  dll_remove_end(list);


  dll_print(list);

  dll_destroy(&list);

  return 0;
}