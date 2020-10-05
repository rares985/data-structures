#ifndef DOUBLE_LINKED_LIST_H_
#define DOUBLE_LINKED_LIST_H_

#include "double_linked_list_priv.h"
#include "stdlib.h"

typedef struct double_linked_list {
  dll_node_t *head;
} double_linked_list_t;

int dll_create(double_linked_list_t **list);
int dll_destroy(double_linked_list_t **list);

int dll_add_start(double_linked_list_t *list, void *data, size_t data_size);
int dll_add_end(double_linked_list_t *list, void *data, size_t data_size);
int dll_add_pos(double_linked_list_t *list, void *data, size_t data_size, int pos);


int dll_remove_start(double_linked_list_t *list);
int dll_remove_end(double_linked_list_t *list);
int dll_remove_pos(double_linked_list_t *list, int pos);


int dll_length(double_linked_list_t *list);
void dll_print(double_linked_list_t *list);




#endif /* DOUBLE_LINKED_LIST_H_ */