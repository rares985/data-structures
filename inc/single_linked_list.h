#ifndef SINGLE_LINKED_LIST_H_
#define SINGLE_LINKED_LIST_H_

#include "single_linked_list_priv.h"

typedef struct single_linked_list {
  sll_node_t *head;
} single_linked_list_t;

void sll_create(single_linked_list_t **list);
void sll_destroy(single_linked_list_t **list);
void sll_add_start(single_linked_list_t *list, void *data, size_t data_size);
void sll_add_end(single_linked_list_t *list, void *data, size_t data_size);
void sll_add_pos(single_linked_list_t *list, void *data, size_t data_size, int pos);
void sll_remove_start(single_linked_list_t *list);
void sll_remove_end(single_linked_list_t *list);
void sll_remove_pos(single_linked_list_t *list, int pos);
int sll_length(single_linked_list_t *list);
void sll_print(single_linked_list_t *list);


#endif /* SINGLE_LINKED_LIST_H_ */